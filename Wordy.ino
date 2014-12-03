// Wordy: the ring for people with an unhealthy obsession with vocabulary
//  by: Elecia White
// 		Logical Elegance and Embedded.fm
//  date: November 15, 2014
// license: Beerware - Use this code however you'd like. If you 
// find it useful you can buy me a beer some time.
// Note the accelerometer library cam from Adafruit as I use their 
// 5V tolerant sensor  (https://github.com/adafruit/Adafruit_MMA8451_Library)

// This is made with a MicroView, accelerometer and small battery:
//	* MicroView: https://www.sparkfun.com/products/12923
//  * 5V tolerant accelerometer: https://www.adafruit.com/products/2019
//  * Small lipo battery

// Wordy listens to the accelerometer, when the device moves suddenly from a 
// quiet state, it displays a word for 5s. If it gets a double tap in that time
// it displays (scrolls) the definition for 10s. 
// After display is complete, the system sets the accelerometer for a new interrupt
// and goes to sleep.

// I want this to fit into a ring so that drives the miniscule side of my 
// battery. Because of that, the goal of this sketch is to be power efficient.
// I found http://www.gammon.com.au/forum/?id=11497 to be incredibly helpful in
// getting the standby current down to .13mA (w/out accel)


// Hardware setup
//  MMA8451 Breakout ---------- MicroView
//  5Vin ---------------------- 5V out (P15))
//  GND ---------------------- GND (P8)
//  INT2 ---------------------- D3 (P12)
//  SCL ----------------------- A5 (P2)
//  SDA ----------------------- A4 (P3)


#include <MicroView.h>		// include MicroView library
#include <avr/sleep.h>
#include "wordlist.h"
#include <Wire.h>
#include "MicroPong.h"
#include "MagicAnswers.h"
#include "PunchResponses.h"

#include "Adafruit_MMA8451.h"
Adafruit_MMA8451 mma = Adafruit_MMA8451();

#define MOVED_DISPLAY_TIMEOUT 5000 // ms = 5s

int accelerometerTapPin = 2; 
enum {BORED=0, 
	SHOW_WORD=1, WAIT_FOR_DEFN_TAP=2, SHOW_DEFN=3, 
	PLAY_PONG=4, 
	MAGIC_QUESTION =5, WAIT_FOR_ANSWER_SHAKE=6, MAGIC_ANSWER =7,
	AIR_PUNCH =8,
	JUST_WOKE_UP = 0xFD, 
	FORCE_SLEEP = 0xFE,
	GOING_TO_SLEEP=0xFF };
byte gSystemState = BORED;

#define INVERTED_SHAKE_INDICATOR 0x90 // in motion interrupt on accel
#define PUNCH_INDICATOR 0xB0 // in motion interrupt on accel


unsigned long gTimeOfLastDisplay = 0;

struct sWord getRandomWord()
{
	struct sWord word;
	long randomNumber = random(gWordListLength);
	word.word = (char*)pgm_read_word(&(gWordList[randomNumber].word));
	word.definition = (char*)pgm_read_word(&(gWordList[randomNumber].definition));
	return word;	
}
char* getRandomString(char** list, int len)
{
	struct sWord word;
	long randomNumber = random(len);
	return((char*)pgm_read_word(&(list[randomNumber])));
}

unsigned long displayMessage(char *displayStr, int x, int y)
{
	#define MAX_STRING 100
	char stringBuffer[MAX_STRING]; // flash to RAM
	strncpy_P(stringBuffer, displayStr, MAX_STRING);

	uView.begin();				// start MicroView
	uView.clear(PAGE);			// clear page
	uView.setCursor(x,y);		// set cursor at position given
	uView.print(stringBuffer);	// display the string on LCD
	uView.display();
	
	return (millis());
}

void setup() {
	Serial.begin(9600); 
	Serial.println(F("WORDY!"));
	
	uView.begin();				// start MicroView
	uView.clear(PAGE);			// clear page
	
	pinMode(accelerometerTapPin, INPUT);  	// initialize the pushbutton pin as an input
	digitalWrite(accelerometerTapPin, HIGH);  // set Internal pull-up
	
	randomSeed(analogRead(1));
	gTimeOfLastDisplay = displayMessage((char*)F("Let's get  WORDY!!"), 8, 10);

	// disable ADC
	ADCSRA = 0;  
	initAccelerometer(); //use button method, skip accel for now
	
	updateStateMachine(gSystemState ); // not using output of statemachine, starting in sleep
	attachInterrupt (0, wakeInterrupt , LOW);
}

void initAccelerometer() 
{
	Serial.println("Looking for MMA...");
	if (! mma.begin()) {
		Serial.println("Couldnt start");
		while (1);
	}
	Serial.println("MMA8451 found!");
	
    
	mma.writeRegister8(MMA8451_REG_CTRL_REG1, 0); // in standby, can change stuff 
	
	mma.writeRegister8(MMA8451_REG_PULSE_CFG, 0x7F); // tap or double tap on each axis. latch event

	mma.writeRegister8(MMA8451_REG_PULSE_THSX, 0x30); // 48 counts, 3G
	mma.writeRegister8(MMA8451_REG_PULSE_THSY, 0x30); // 
	mma.writeRegister8(MMA8451_REG_PULSE_THSZ, 0x30); // 
	mma.writeRegister8(MMA8451_REG_PULSE_TMLT, 0x06); // Tap time of 30ms, this is data rate dependent
	mma.writeRegister8(MMA8451_REG_PULSE_LTCY, 0x14); // Time between pulses (latency) = 200ms
	mma.writeRegister8(MMA8451_REG_PULSE_WIND, 0x80); //0x1D); // Window for 2nd pulse: ~300ms
  
	mma.writeRegister8(MMA8451_REG_FF_MT_CFG, 0xF8); // interrupt when any thing over its threshold
	mma.writeRegister8(MMA8451_REG_FF_MT_THS, 0x20); // 0.063g so 2G =32
	mma.writeRegister8(MMA8451_REG_FF_MT_COUNT, 0x50); //10); // 20*10ms = 200
  
	mma.writeRegister8(MMA8451_REG_CTRL_REG3, 0x19); // motion, pulse wake, open drain and active low
    mma.writeRegister8(MMA8451_REG_CTRL_REG4, 0x0C); // configure motion, pulse detection to an interrupt pin, leave on INT2

	mma.setRange(MMA8451_RANGE_8_G);
    mma.setDataRate(MMA8451_DATARATE_50_HZ); // also puts it in active mode
}

int gotWakeInterrrupt =0;
void wakeInterrupt ()
{
	gotWakeInterrrupt ++;
	
	// cancel sleep as a precaution
	sleep_disable();
	// must do this as the pin will probably stay low for a while
	detachInterrupt (0);
}  // end of wake

// To reduce power usage, the 
void gotoSleep() {
	set_sleep_mode (SLEEP_MODE_PWR_DOWN);  
	sleep_enable();
	
	// Do not interrupt before we go to sleep, or the
	// ISR will detach interrupts and we won't wake.
	noInterrupts ();
	
	// will be called when pin D2 goes low  
	attachInterrupt (0, wakeInterrupt , LOW);
	
	// turn off brown-out enable in software
	// BODS must be set to one and BODSE must be set to zero within four clock cycles
	MCUCR = bit (BODS) | bit (BODSE);
	// The BODS bit is automatically cleared after three clock cycles
	MCUCR = bit (BODS); 
	
	// We are guaranteed that the sleep_cpu call will be done
	// as the processor executes the next instruction after
	// interrupts are turned on.
	interrupts ();  // one cycle
	sleep_cpu ();   // one cycle
}

#define FILTER_SIZE 4
#define FILTER_DIVIDE_SHIFT 2
#define FILTER_INDEX_MASK 0x03
#define POSITION_CENTER_HEIGHT 100

int getFilteredPos() {
	static int16_t positionFilter[FILTER_SIZE ];
	static int index = 0;
	int i;
	int16_t sum, ave;
	int32_t tmp;

	mma.read();
	
	// make the result be -100 to +100
	tmp = mma.y;
	tmp *= POSITION_CENTER_HEIGHT; // don't overflow a uint16
	tmp = tmp >> mma.getRangeShift();
	positionFilter[index] = tmp; 

	index = (index + 1) & FILTER_INDEX_MASK ; // go back to zero when reach size
	sum = 0;
	for (int i = 0; i < FILTER_SIZE ; i++) {
		sum += positionFilter[i];
	}
	
	ave = sum >> FILTER_DIVIDE_SHIFT; // average is sum /size
	ave += POSITION_CENTER_HEIGHT; // now 0-200
	ave = ave >> 1;
	return (ave); // now 0-100 for -1 to +1 G, may be outside these bounds for more
}

byte updateStateMachine(byte currentState)
{
	byte newState = BORED;
	byte src = mma.readRegister8(MMA8451_REG_INT_SRC);

	if (currentState == JUST_WOKE_UP) {
		newState = FORCE_SLEEP; // need a reason to stay awake
		currentState = BORED;
	}

	// check interrupts
	Serial.print("cs " +  String(currentState)); 
	Serial.print(" int " +  String(src, HEX)); 
	if (src & MMA8451_INT_SRC_PULSE) {	
		src = mma.readRegister8(MMA8451_REG_PULSE_SRC);
		Serial.println(" psrc " +  String(src, HEX)); 
		if (src & MMA8451_PULSE_SRC_DTAP ) {
			if (currentState == PLAY_PONG) {
				newState = GOING_TO_SLEEP;
			} else {
				setupPong();
				newState = PLAY_PONG;
			}
		} 
		else if (currentState == PLAY_PONG) 		{ newState = PLAY_PONG; } // stay in game 
		else if (currentState == BORED) 			{ newState = SHOW_WORD;}
		else if (currentState == WAIT_FOR_DEFN_TAP)  { newState = SHOW_DEFN;}
		
	} else if (src & MMA8451_INT_SRC_MOTION) {
		src = mma.readRegister8(MMA8451_REG_FF_MT_SRC);
		Serial.println(" mtsrc " +  String(src, HEX)); 
		if ((src & PUNCH_INDICATOR) == PUNCH_INDICATOR) {
			if (currentState == BORED) 				   { newState = AIR_PUNCH; }
			if (currentState == WAIT_FOR_ANSWER_SHAKE) { newState = MAGIC_ANSWER;} // easier to get this
		}  else if ((src & INVERTED_SHAKE_INDICATOR) == INVERTED_SHAKE_INDICATOR) {
			if (currentState == BORED) 				   { newState = MAGIC_QUESTION; }
			if (currentState == WAIT_FOR_ANSWER_SHAKE) { newState = MAGIC_ANSWER;}
		} else {
			if (currentState == BORED) 				   { newState = AIR_PUNCH; }
		}
	}
	if (newState == GOING_TO_SLEEP || currentState == GOING_TO_SLEEP) {
		Serial.println(F("SLEEP"));
		uView.end();
		gotoSleep(); // interrupt will wake us up then we'll continue from here
		return (JUST_WOKE_UP);
	}
	return newState;

}
void drawAirPunch()
{
	const int delayMs = 100; // ms
	char * sound = getRandomString((char**)gPunchSoundsList, gPunchSoundsListLength);
	#define MAX_PUNCH_STRING 10
	char stringBuffer[MAX_PUNCH_STRING]; // flash to RAM
	strncpy_P(stringBuffer, sound, MAX_PUNCH_STRING);

	uView.begin();				// start MicroView
	uView.clear(PAGE);
	uView.setCursor(0,16);		// set cursor at position given
	uView.setFontType(1); // larger
	uView.print(stringBuffer);	// display the string on LCD
	uView.display();
	
	gTimeOfLastDisplay = millis();

	uView.setDrawMode(XOR);
	for (int i = 0; i < 3; i++) {
		delay(delayMs);
		int h2 = uView.getLCDHeight() >> 1;
		int w2 = uView.getLCDWidth() >> 1;
		long rh = random(h2 >> 1) + (h2>>1);
		long rw = random(w2 >> 1) + (w2>>1);
		uView.rectFill(w2-rw, h2-rh, rw*2, rh*2);
		uView.display();
	}
	uView.setDrawMode(NORM);
	uView.setFontType(0); // normal
}

struct sWord gWordToDisplay;
void loop() {
	
	if ( gotWakeInterrrupt ) {
		gotWakeInterrrupt = 0;
		gSystemState  = updateStateMachine(gSystemState);
		delay(250);
		attachInterrupt (0, wakeInterrupt , LOW);
	}

	if (gSystemState == SHOW_WORD) {
		gWordToDisplay= getRandomWord();
		gTimeOfLastDisplay = displayMessage(gWordToDisplay.word, 0, 20);
		gSystemState = WAIT_FOR_DEFN_TAP;
 	} 

	if (gSystemState == SHOW_DEFN) {
		gTimeOfLastDisplay = displayMessage(gWordToDisplay.definition, 0, 0);
		gSystemState = BORED;
 	} 

	if (gSystemState == PLAY_PONG) {
		if (loopPong(getFilteredPos())) {
			gTimeOfLastDisplay = millis(); 
		} else { // done, turn screen off
			gSystemState == FORCE_SLEEP;
		}
 	} 
	if (gSystemState == MAGIC_QUESTION) {
		gTimeOfLastDisplay = displayMessage(gMagicQuestion, 0, 0);
		gSystemState = WAIT_FOR_ANSWER_SHAKE;
	}
	if (gSystemState == MAGIC_ANSWER) {
		char * answer = getRandomString((char**)gMagicAnswerList, gMagicAnswerListLength);
		gTimeOfLastDisplay = displayMessage(answer, 0, 0);
		gSystemState = BORED;
	}

	if (gSystemState == AIR_PUNCH) {
		drawAirPunch();
		gSystemState = BORED;
	}

 	if ((gSystemState == FORCE_SLEEP) || (millis()-gTimeOfLastDisplay > MOVED_DISPLAY_TIMEOUT)) {
 		if (gotWakeInterrrupt) Serial.println("Going to sleep with in");
 		gSystemState = updateStateMachine(GOING_TO_SLEEP);
 	}

}






















