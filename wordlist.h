// WORDY word list
//
// I took definitions from a GRE vocabulary list:
// https://www.msu.edu/~defores1/gre/vocab/gre_vocab.htm
// and fiddled with them, making them shorter and taking out 
// words I don't care for or had definitions that were too long
// to fit on the screen.
//
// I also found many wonderfully strange words on Wordnik but
// had to do a lot more shaping of those definitions to fit the 
// ~60 characters available.
//
// The wordlist takes up as much space as you let it. The easiest
// way to have space to modify code is to comment out a few words. 
// To do that, you have to comment out two pieces:
//    on the top: word_n[] PROGMEM = "..."; char defn_n[] PROGMEM  ="...";
//    on the bottom:   { word_n, defn_n},
// Do this until your binary sketch size is less than 30k (30,720)

#include <avr/pgmspace.h> // for PROGMEM, the words go in flash
#include <stdio.h>

struct sWord {
  char * word;
  char * definition;
}; 
/*
char word_1[]  PROGMEM = "ingenious"; char defn_1[]  PROGMEM  ="clever";
char word_2[]  PROGMEM = "verbose"; char defn_2[]  PROGMEM  ="wordy: ";
char word_3[]  PROGMEM = "infer"; char defn_3[]  PROGMEM  ="to deduce";
char word_4[]  PROGMEM = "loquacious"; char defn_4[]  PROGMEM  ="talkative";
char word_5[]  PROGMEM = "aver"; char defn_5[]  PROGMEM  ="to declare";
char word_6[]  PROGMEM = "imperious"; char defn_6[]  PROGMEM  ="commanding";
char word_7[]  PROGMEM = "tacit"; char defn_7[]  PROGMEM  ="unspoken: ";
char word_8[]  PROGMEM = "hapless"; char defn_8[]  PROGMEM  ="unfortunate";
char word_9[]  PROGMEM = "conflagration"; char defn_9[]  PROGMEM  ="a great fire";
char word_10[]  PROGMEM = "nefarious"; char defn_10[]  PROGMEM  ="wicked, evil";
char word_11[]  PROGMEM = "dearth"; char defn_11[]  PROGMEM  ="lack, scarcity";
char word_12[]  PROGMEM = "guile"; char defn_12[]  PROGMEM  ="skillful deceit";
char word_13[]  PROGMEM = "impecunious"; char defn_13[]  PROGMEM  ="penniless; poor";
char word_14[]  PROGMEM = "enigma"; char defn_14[]  PROGMEM  ="puzzle; mystery: ";
char word_15[]  PROGMEM = "insensible"; char defn_15[]  PROGMEM  ="numb; unconscious";
char word_16[]  PROGMEM = "prodigal"; char defn_16[]  PROGMEM  ="rashly wasteful: ";
char word_17[]  PROGMEM = "craven"; char defn_17[]  PROGMEM  ="cowardly; a coward";
char word_18[]  PROGMEM = "lucid"; char defn_18[]  PROGMEM  ="clear; translucent";
char word_19[]  PROGMEM = "rescind"; char defn_19[]  PROGMEM  ="to repeal or annul";
char word_20[]  PROGMEM = "peccadillo"; char defn_20[]  PROGMEM  ="a small sin or fault";
char word_21[]  PROGMEM = "buttress"; char defn_21[]  PROGMEM  ="to support. a support";
char word_22[]  PROGMEM = "chicanery"; char defn_22[]  PROGMEM  ="deception by trickery";
char word_23[]  PROGMEM = "descry"; char defn_23[]  PROGMEM  ="to make clear, to say";
char word_24[]  PROGMEM = "sanguine"; char defn_24[]  PROGMEM  ="cheerful; confident: ";
char word_25[]  PROGMEM = "turpitude"; char defn_25[]  PROGMEM  ="depravity; baseness: ";
char word_26[]  PROGMEM = "laconic"; char defn_26[]  PROGMEM  ="using few words; terse";
char word_27[]  PROGMEM = "attenuate"; char defn_27[]  PROGMEM  ="weaken (adj: attenuated";
char word_28[]  PROGMEM = "corroborate"; char defn_28[]  PROGMEM  ="to strengthen or support";
*/char word_29[]  PROGMEM = "dogged"; char defn_29[]  PROGMEM  ="stubborn or determined: ";
char word_30[]  PROGMEM = "caprice"; char defn_30[]  PROGMEM  ="impulse (adj: capricious";
char word_31[]  PROGMEM = "propitiate"; char defn_31[]  PROGMEM  ="to conciliate; to appease: ";
char word_32[]  PROGMEM = "superficial"; char defn_32[]  PROGMEM  ="only covering the surface: ";
char word_33[]  PROGMEM = "deprecation"; char defn_33[]  PROGMEM  ="belittlement. (v. deprecate";
char word_34[]  PROGMEM = "extant"; char defn_34[]  PROGMEM  ="in existence, still existing";
char word_35[]  PROGMEM = "garrulous"; char defn_35[]  PROGMEM  ="verbose; talkative; rambling";
char word_36[]  PROGMEM = "venerate"; char defn_36[]  PROGMEM  ="great respect or reverence: ";
char word_37[]  PROGMEM = "depict"; char defn_37[]  PROGMEM  ="to show, create a picture of.";
char word_38[]  PROGMEM = "indelible"; char defn_38[]  PROGMEM  ="permanent; unerasable; strong";
char word_39[]  PROGMEM = "ponderous"; char defn_39[]  PROGMEM  ="heavy; massive; awkward; dull";
char word_40[]  PROGMEM = "incorrigible"; char defn_40[]  PROGMEM  ="not capable of being corrected";
char word_41[]  PROGMEM = "bombast"; char defn_41[]  PROGMEM  ="pompous speech (adj: bombastic";
char word_42[]  PROGMEM = "noisome"; char defn_42[]  PROGMEM  ="harmful, offensive, destructive";
char word_43[]  PROGMEM = "deference"; char defn_43[]  PROGMEM  ="submission or courteous yielding";
char word_44[]  PROGMEM = "insipid"; char defn_44[]  PROGMEM  ="lacking zest or excitement; dull";
char word_45[]  PROGMEM = "aberrant"; char defn_45[]  PROGMEM  ="deviating from normal or correct.";
char word_46[]  PROGMEM = "castigate"; char defn_46[]  PROGMEM  ="to chastise or criticize severely";
char word_47[]  PROGMEM = "emollient"; char defn_47[]  PROGMEM  ="softening; something that softens";
char word_48[]  PROGMEM = "homogenous"; char defn_48[]  PROGMEM  ="similar in nature or kind; uniform";
char word_49[]  PROGMEM = "phlegmatic"; char defn_49[]  PROGMEM  ="not easily excited; cool; sluggish";
char word_50[]  PROGMEM = "tortuous"; char defn_50[]  PROGMEM  ="twisted; excessively complicated: ";
char word_51[]  PROGMEM = "volatile"; char defn_51[]  PROGMEM  ="explosive; fickle (n: volatility.";
char word_52[]  PROGMEM = "culpable"; char defn_52[]  PROGMEM  ="deserving of blame (n: culpability";
char word_53[]  PROGMEM = "encomium"; char defn_53[]  PROGMEM  ="a formal eulogy or speech of praise";
char word_54[]  PROGMEM = "laudable"; char defn_54[]  PROGMEM  ="praiseworthy; commendable (v. laud";
char word_55[]  PROGMEM = "sedulous"; char defn_55[]  PROGMEM  ="diligent; persevering; persistent: ";
char word_56[]  PROGMEM = "misnomer"; char defn_56[]  PROGMEM  ="incorrect name or word for something";
char word_57[]  PROGMEM = "amalgamate"; char defn_57[]  PROGMEM  ="to unite or mix. (n -- amalgamation.";
char word_58[]  PROGMEM = "depredation"; char defn_58[]  PROGMEM  ="the act of preying upon or plundering";
char word_59[]  PROGMEM = "saturnine"; char defn_59[]  PROGMEM  ="having a gloomy or morose temperament";
char word_60[]  PROGMEM = "savant"; char defn_60[]  PROGMEM  ="a very knowledgable person; a genious";
char word_61[]  PROGMEM = "viscous"; char defn_61[]  PROGMEM  ="slow moving; highly resistant to flow";
char word_62[]  PROGMEM = "dissemble"; char defn_62[]  PROGMEM  ="to conceal one's real motive, to feign";
char word_63[]  PROGMEM = "desiccate"; char defn_63[]  PROGMEM  ="to dry out thoroughly (adj: desiccated";
char word_64[]  PROGMEM = "exculpate"; char defn_64[]  PROGMEM  ="to demonstrate or prove to be blameless";
char word_65[]  PROGMEM = "prevaricate"; char defn_65[]  PROGMEM  ="to stray away from or evade the truth: ";
char word_66[]  PROGMEM = "pusillanimous"; char defn_66[]  PROGMEM  ="cowardly, timid, or irreselute; petty: ";
char word_67[]  PROGMEM = "disabuse"; char defn_67[]  PROGMEM  ="to free a person from falsehood or error";
char word_68[]  PROGMEM = "esoteric"; char defn_68[]  PROGMEM  ="intended for or understood by only a few";
char word_69[]  PROGMEM = "intransigent"; char defn_69[]  PROGMEM  ="stubborn; immovable; unwilling to change";
char word_70[]  PROGMEM = "engender"; char defn_70[]  PROGMEM  ="to give rise to, to propagate, to cause: ";
char word_71[]  PROGMEM = "plethora"; char defn_71[]  PROGMEM  ="excessively large quantity; overabundance";
char word_72[]  PROGMEM = "assuage"; char defn_72[]  PROGMEM  ="to make less severe; to appease or satisfy";
char word_73[]  PROGMEM = "emulate"; char defn_73[]  PROGMEM  ="to strive to equal or excel (n: emulation";
char word_74[]  PROGMEM = "antipathy"; char defn_74[]  PROGMEM  ="hostility toward, objection, or aversion to";
char word_75[]  PROGMEM = "disparaging"; char defn_75[]  PROGMEM  ="belittling (n: disparagement. v. disparage";
char word_76[]  PROGMEM = "magnanimity"; char defn_76[]  PROGMEM  ="generosity and nobility. (adj: magnanimous";
char word_77[]  PROGMEM = "malevolent"; char defn_77[]  PROGMEM  ="malicious; evil; having or showing ill will";
char word_78[]  PROGMEM = "irascible"; char defn_78[]  PROGMEM  ="prone to outbursts of temper, easily angered";
char word_79[]  PROGMEM = "leviathan"; char defn_79[]  PROGMEM  ="giant whale, therefore, something very large";
char word_80[]  PROGMEM = "precursor"; char defn_80[]  PROGMEM  ="something (or someone that precedes another";
char word_81[]  PROGMEM = "tractable"; char defn_81[]  PROGMEM  ="ability to be easily managed or controlled: ";
char word_82[]  PROGMEM = "wretched"; char defn_82[]  PROGMEM  ="extremely pitiful or unfortunate (n: wretch";
char word_83[]  PROGMEM = "placate"; char defn_83[]  PROGMEM  ="to calm or reduce anger by making concessions";
char word_84[]  PROGMEM = "ambiguous"; char defn_84[]  PROGMEM  ="vague; subject to more than one interpretation";
char word_85[]  PROGMEM = "ossified"; char defn_85[]  PROGMEM  ="turned to bone; hardened like bone; Inflexible";
char word_86[]  PROGMEM = "antediluvian"; char defn_86[]  PROGMEM  ="ancient; outmoded; (literally,before the flood";
char word_87[]  PROGMEM = "arbitrate"; char defn_87[]  PROGMEM  ="to settle a dispute by impulse (n: arbitration";
char word_88[]  PROGMEM = "cadge"; char defn_88[]  PROGMEM  ="to get something by taking advantage of someone";
char word_89[]  PROGMEM = "diffident"; char defn_89[]  PROGMEM  ="lacking self-confidence, modest (n: diffidence";
char word_90[]  PROGMEM = "catalyst"; char defn_90[]  PROGMEM  ="an agent of change (adj: catalytic; v. catalyze";
char word_91[]  PROGMEM = "occlude"; char defn_91[]  PROGMEM  ="to close or shut off; to obstruct (n: occlusion";
char word_92[]  PROGMEM = "perfidious"; char defn_92[]  PROGMEM  ="deliberately treacherous; dishonest (n: perfidy";
char word_93[]  PROGMEM = "quiescence"; char defn_93[]  PROGMEM  ="inactivity; stillness; dormancy (adj: quiescent";
char word_94[]  PROGMEM = "ingenuous"; char defn_94[]  PROGMEM  ="unsophisticated; artless; straightforward; candid";
char word_95[]  PROGMEM = "taciturn"; char defn_95[]  PROGMEM  ="habitually untalkative or silent (n: taciturnity";
char word_96[]  PROGMEM = "aggrandize"; char defn_96[]  PROGMEM  ="to make greater, to increase, thus, to exaggerate.";
char word_97[]  PROGMEM = "enervate"; char defn_97[]  PROGMEM  ="to weaken or destroy the strength or vitality of: ";
char word_98[]  PROGMEM = "ineffable"; char defn_98[]  PROGMEM  ="undescribable; inexpressible in words; unspeakable";
char word_99[]  PROGMEM = "panegyric"; char defn_99[]  PROGMEM  ="a writing or speech in praise of a person or thing";
char word_100[]  PROGMEM = "abscond"; char defn_100[]  PROGMEM  ="to leave secretly and hide, often to avoid the law.";
char word_101[]  PROGMEM = "anomalous"; char defn_101[]  PROGMEM  ="peculiar; unique, contrary to the norm (n: anomaly";
char word_102[]  PROGMEM = "obdurate"; char defn_102[]  PROGMEM  ="hardened against influence or feeling; intractable.";
char word_103[]  PROGMEM = "fledgling"; char defn_103[]  PROGMEM  ="a baby bird; an inexperienced person; inexperienced.";
char word_104[]  PROGMEM = "gossamer"; char defn_104[]  PROGMEM  ="fine cobweb on foliage; fine gauzy fabric; very fine";
char word_105[]  PROGMEM = "efficacy"; char defn_105[]  PROGMEM  ="effectiveness; capability to produce a desired effect";
char word_106[]  PROGMEM = "ephemeral"; char defn_106[]  PROGMEM  ="lasting for only a brief time, fleeting (n: ephemera";
char word_107[]  PROGMEM = "dogmatic"; char defn_107[]  PROGMEM  ="relying upon doctrine or dogma, as opposed to evidence";
char word_108[]  PROGMEM = "inchoate"; char defn_108[]  PROGMEM  ="in an initial or early stage; incomplete; disorganized";
char word_109[]  PROGMEM = "exacerbate"; char defn_109[]  PROGMEM  ="to increase the bitterness or violence of; to aggravate";
char word_110[]  PROGMEM = "caustic"; char defn_110[]  PROGMEM  ="capable of dissolving by chemical action; highly critical";
char word_111[]  PROGMEM = "eulogy"; char defn_111[]  PROGMEM  ="a spoken or written tribute to the deceased (v. eulogize";
char word_112[]  PROGMEM = "obviate"; char defn_112[]  PROGMEM  ="to prevent by anticipatory measures; to make unnecessary:";
char word_113[]  PROGMEM = "vacuous"; char defn_113[]  PROGMEM  ="empty; without contents; without ideas or intelligence:: ";
char word_114[]  PROGMEM = "insular"; char defn_114[]  PROGMEM  ="of or pertaining to an island, thus, excessively exclusive";
char word_115[]  PROGMEM = "reproof"; char defn_115[]  PROGMEM  ="the act of censuring, scolding, or rebuking. (v. reprove.";
char word_116[]  PROGMEM = "burgeon"; char defn_116[]  PROGMEM  ="to grow or flourish; a bud or new growth (adj: burgeoning ";
char word_117[]  PROGMEM = "latent"; char defn_117[]  PROGMEM  ="present or potential but not evident or active (n: latency";
char word_118[]  PROGMEM = "tyro"; char defn_118[]  PROGMEM  ="beginner; lacking experience in a specific endeavor";
char word_119[]  PROGMEM = "antiphrasis"; char defn_119[]  PROGMEM  ="misuse of word's meaning for humor: mere babe of 40"; // I heart wordnik
char word_120[]  PROGMEM = "ruelle"; char defn_120[]  PROGMEM  ="Space between bed and wall"; // I heart wordnik
char word_121[]  PROGMEM = "expiscate"; char defn_121[]  PROGMEM  ="To fish out; find out by skill or investigation"; // I heart wordnik
char word_122[]  PROGMEM = "cerograph"; char defn_122[]  PROGMEM  ="A writing on wax"; // I heart wordnik
char word_123[]  PROGMEM = "dunch"; char defn_123[]  PROGMEM  ="To crash into, to bump into; to jog, esp with the elbow"; // I heart wordnik
char word_124[]  PROGMEM = "canorous"; char defn_124[]  PROGMEM  ="melodius, resonant"; // I heart wordnik
char word_125[]  PROGMEM = "pannose"; char defn_125[]  PROGMEM  ="Similar in texture or appearance to felt or woollen cloth"; // I heart wordnik
char word_126[]  PROGMEM = "tachydidaxy"; char defn_126[]  PROGMEM  ="A short or rapid method of instructing"; // I heart wordnik
char word_127[]  PROGMEM = "anosognosia"; char defn_127[]  PROGMEM  ="inability of a person to recognize his own illness/handicap"; // I heart wordnik
char word_128[]  PROGMEM = "acyrology"; char defn_128[]  PROGMEM  ="incorrect use of language; faulty diction"; // I heart wordnik
char word_129[]  PROGMEM = "prevenient"; char defn_129[]  PROGMEM  ="Coming before; preceding. Expectant; anticipatory."; // I heart wordnik
char word_130[]  PROGMEM = "furcatorium"; char defn_130[]  PROGMEM  ="The furciform bone, wishbone, or merrythought of a fowl"; // I heart wordnik
char word_131[]  PROGMEM = "parvanimity"; char defn_131[]  PROGMEM  ="the state or quality of having an ignoble mind; pettiness"; // I heart wordnik
char word_132[]  PROGMEM = "sciolism"; char defn_132[]  PROGMEM  ="pretentious attitude of scholarship"; // I heart wordnik
char word_133[]  PROGMEM = "protyle"; char defn_133[]  PROGMEM  ="hypothetical base from which all chemical elements derive"; // I heart wordnik
char word_134[]  PROGMEM = "chantepleure"; char defn_134[]  PROGMEM  ="to sing and cry at the same time"; // I heart wordnik
char word_135[]  PROGMEM = "versorium"; char defn_135[]  PROGMEM  ="magnetic needle mounted to move freely in horizontal plane"; // I heart wordnik
char word_136[]  PROGMEM = "footle"; char defn_136[]  PROGMEM  ="to talk nonsense; foolishnes"; // I heart wordnik
char word_137[]  PROGMEM = "noegenesis"; char defn_137[]  PROGMEM  ="the acquisition of new knowledge from observation"; // I heart wordnik
char word_138[]  PROGMEM = "subtrahend"; char defn_138[]  PROGMEM  ="quantity or number to be subtracted from another."; // I heart wordnik
char word_139[]  PROGMEM = "plerophory"; char defn_139[]  PROGMEM  ="full persuasion or confidence; perfect conviction, certitude"; // I heart wordnik
char word_140[]  PROGMEM = "inselberg"; char defn_140[]  PROGMEM  ="See monadnock."; // I heart wordnik
char word_141[]  PROGMEM = "collocutor"; char defn_141[]  PROGMEM  ="any of the people engaged in a conversation"; // I heart wordnik
char word_142[]  PROGMEM = "brool"; char defn_142[]  PROGMEM  ="murmuring sound as of wind blowing through a forest"; // I heart wordnik
char word_143[]  PROGMEM = "blirt"; char defn_143[]  PROGMEM  ="an outburst of wind, rain, or tears"; // I heart wordnik
char word_144[]  PROGMEM = "subdolous"; char defn_144[]  PROGMEM  ="sly; crafty; cunning; artful."; // I heart wordnik
char word_145[]  PROGMEM = "anient"; char defn_145[]  PROGMEM  ="to reduce to nothingness. In law, to abrogate; make null"; // I heart wordnik
char word_146[]  PROGMEM = "stigmergy"; char defn_146[]  PROGMEM  ="mechanism of spontaneous, indirect coordination"; // I heart wordnik
char word_147[]  PROGMEM = "nisus"; char defn_147[]  PROGMEM  ="effort or endeavor to realize an aim"; // I heart wordnik
char word_148[]  PROGMEM = "petrichor"; char defn_148[]  PROGMEM  =" distinctive scent of the first rain after a long dry spell"; // I heart wordnik
char word_149[]  PROGMEM = "boanthropy"; char defn_149[]  PROGMEM  ="form of madness:  the victim imagines himself to be an ox"; // I heart wordnik
char word_150[]  PROGMEM = "oblectation"; char defn_150[]  PROGMEM  ="the act of pleasing highly; delight."; // I heart wordnik
char word_151[]  PROGMEM = "vermiculate"; char defn_151[]  PROGMEM  ="to decorate with wavy or winding lines; bearing wavy lines"; // I heart wordnik
char word_152[]  PROGMEM = "cynopic"; char defn_152[]  PROGMEM  ="dog-eyed; shameless"; // I heart wordnik
char word_153[]  PROGMEM = "paronym"; char defn_153[]  PROGMEM  ="a word derived from the same root as another word"; // I heart wordnik
char word_154[]  PROGMEM = "fulguration"; char defn_154[]  PROGMEM  ="act of lightening, or flashing with light"; // I heart wordnik
char word_155[]  PROGMEM = "selcouth"; char defn_155[]  PROGMEM  ="strange, unusual, rare; unfamiliar; marvellous, wondrous"; // I heart wordnik
char word_156[]  PROGMEM = "adynaton"; char defn_156[]  PROGMEM  ="hyperbole modified to show impossibility: when pigs fly"; // I heart wordnik
char word_157[]  PROGMEM = "noology"; char defn_157[]  PROGMEM  ="the systematic study of everything dealing with knowledge"; // I heart wordnik
char word_158[]  PROGMEM = "zenzizenzizenzic"; char defn_158[]  PROGMEM  ="the eighth power of a number"; // I heart wordnik
char word_159[]  PROGMEM = "yex"; char defn_159[]  PROGMEM  ="hiccup"; // I heart wordnik
char word_160[]  PROGMEM = "vesuviate"; char defn_160[]  PROGMEM  ="to burst forth as a volcanic eruption"; // I heart wordnik
char word_161[]  PROGMEM = "versipellous "; char defn_161[]  PROGMEM  ="changeable; having a nature or appearance that changes often"; // I heart wordnik
char word_162[]  PROGMEM = "protean"; char defn_162[]  PROGMEM  ="readily taking on varied shapes, forms, or meanings."; // I heart wordnik
char word_163[]  PROGMEM = "venefice"; char defn_163[]  PROGMEM  ="the act or practice of poisoning."; // I heart wordnik
char word_164[]  PROGMEM = "veisalgia"; char defn_164[]  PROGMEM  ="unpleasant after-effects of consumption of alcohol; hangover"; // I heart wordnik
char word_165[]  PROGMEM = "vaccimulgence"; char defn_165[]  PROGMEM  ="The milking of cows"; // I heart wordnik
char word_166[]  PROGMEM = "turbillion"; char defn_166[]  PROGMEM  ="whirl or vortex"; // I heart wordnik
char word_167[]  PROGMEM = "tentacular"; char defn_167[]  PROGMEM  ="Of, or pertaining to, tentacles; resembling a tentacle"; // I heart wordnik
char word_168[]  PROGMEM = "temerarious"; char defn_168[]  PROGMEM  ="presumptuously or recklessly daring"; // I heart wordnik
char word_169[]  PROGMEM = "sweven"; char defn_169[]  PROGMEM  ="vision seen in sleep; a dream"; // I heart wordnik
char word_170[]  PROGMEM = "swarf"; char defn_170[]  PROGMEM  ="fine metallic filings or shavings removed by a cutting tool"; // I heart wordnik
char word_171[]  PROGMEM = "sprezzatura"; char defn_171[]  PROGMEM  ="art of performing a task so gracefully, it looks effortless"; // I heart wordnik
char word_172[]  PROGMEM = "sprack"; char defn_172[]  PROGMEM  ="lively, full of energy"; // I heart wordnik
char word_173[]  PROGMEM = "sortilege"; char defn_173[]  PROGMEM  ="act or practice of foretelling the future by drawing lots"; // I heart wordnik
char word_174[]  PROGMEM = "quadragenarian"; char defn_174[]  PROGMEM  ="between the ages of 40 and 49; in one's fifth decade"; // I heart wordnik
char word_175[]  PROGMEM = "purpureal"; char defn_175[]  PROGMEM  ="of a purple colour"; // I heart wordnik
char word_176[]  PROGMEM = "orismology"; char defn_176[]  PROGMEM  ="the explanation of technical terms"; // I heart wordnik
char word_177[]  PROGMEM = "outrecuidance"; char defn_177[]  PROGMEM  ="presumption, arrogance, self-conceit"; // I heart wordnik
char word_178[]  PROGMEM = "otaku"; char defn_178[]  PROGMEM  ="one w/ obsessive interest in something (anime/manga)."; // I heart wordnik
char word_179[]  PROGMEM = "obmutescence"; char defn_179[]  PROGMEM  ="silence; inability or refusal to speak."; // I heart wordnik
char word_180[]  PROGMEM = "obduracy"; char defn_180[]  PROGMEM  ="state or quality of being intractable or hardened"; // I heart wordnik
char word_181[]  PROGMEM = "gregarious"; char defn_181[]  PROGMEM  ="seeking and enjoying the company of others; sociable"; // I heart wordnik
char word_182[]  PROGMEM = "serendipity"; char defn_182[]  PROGMEM  ="faculty of making fortunate discoveries by accident"; // I heart wordnik


PROGMEM const struct sWord gWordList[] = {
/*  { word_1, defn_1},
  { word_2, defn_2},
  { word_3, defn_3},
  { word_4, defn_4},
  { word_5, defn_5},
  { word_6, defn_6},
  { word_7, defn_7},
  { word_8, defn_8},
  { word_9, defn_9},
  { word_10, defn_10},
  { word_11, defn_11},
  { word_12, defn_12},
  { word_13, defn_13},
  { word_14, defn_14},
  { word_15, defn_15},
  { word_16, defn_16},
  { word_17, defn_17},
  { word_18, defn_18},
  { word_19, defn_19},
  { word_20, defn_20},
  { word_21, defn_21},
  { word_22, defn_22},
  { word_23, defn_23},
  { word_24, defn_24},
  { word_25, defn_25},
  { word_26, defn_26},
  { word_27, defn_27},
  { word_28, defn_28},
 */ { word_29, defn_29},
  { word_30, defn_30},
  { word_31, defn_31},
  { word_32, defn_32},
  { word_33, defn_33},
  { word_34, defn_34},
  { word_35, defn_35},
  { word_36, defn_36},
  { word_37, defn_37},
  { word_38, defn_38},
  { word_39, defn_39},
  { word_40, defn_40},
  { word_41, defn_41},
  { word_42, defn_42},
  { word_43, defn_43},
  { word_44, defn_44},
  { word_45, defn_45},
  { word_46, defn_46},
  { word_47, defn_47},
  { word_48, defn_48},
  { word_49, defn_49},
  { word_50, defn_50},
  { word_51, defn_51},
  { word_52, defn_52},
  { word_53, defn_53},
  { word_54, defn_54},
  { word_55, defn_55},
  { word_56, defn_56},
  { word_57, defn_57},
  { word_58, defn_58},
  { word_59, defn_59},
  { word_60, defn_60},
  { word_61, defn_61},
  { word_62, defn_62},
  { word_63, defn_63},
  { word_64, defn_64},
  { word_65, defn_65},
  { word_66, defn_66},
  { word_67, defn_67},
  { word_68, defn_68},
  { word_69, defn_69},
  { word_70, defn_70},
  { word_71, defn_71},
  { word_72, defn_72},
  { word_73, defn_73},
  { word_74, defn_74},
  { word_75, defn_75},
  { word_76, defn_76},
  { word_77, defn_77},
  { word_78, defn_78},
  { word_79, defn_79},
  { word_80, defn_80},
  { word_81, defn_81},
  { word_82, defn_82},
  { word_83, defn_83},
  { word_84, defn_84},
  { word_85, defn_85},
  { word_86, defn_86},
  { word_87, defn_87},
  { word_88, defn_88},
  { word_89, defn_89},
  { word_90, defn_90},
  { word_91, defn_91},
  { word_92, defn_92},
  { word_93, defn_93},
  { word_94, defn_94},
  { word_95, defn_95},
  { word_96, defn_96},
  { word_97, defn_97},
  { word_98, defn_98},
  { word_99, defn_99},
  { word_100, defn_100},
  { word_101, defn_101},
  { word_102, defn_102},
  { word_103, defn_103},
  { word_104, defn_104},
  { word_105, defn_105},
  { word_106, defn_106},
  { word_107, defn_107},
  { word_108, defn_108},
  { word_109, defn_109},
  { word_110, defn_110},
  { word_111, defn_111},
  { word_112, defn_112},
  { word_113, defn_113},
  { word_114, defn_114},
  { word_115, defn_115},
  { word_116, defn_116},
  { word_117, defn_117},
  { word_118, defn_118},
  { word_119, defn_119},
  { word_120, defn_120},
  { word_121, defn_121},
  { word_122, defn_122},
  { word_123, defn_123},
  { word_124, defn_124},
  { word_125, defn_125},
  { word_126, defn_126},
  { word_127, defn_127},
  { word_128, defn_128},
  { word_129, defn_129},
  { word_130, defn_130},
  { word_131, defn_131},
  { word_132, defn_132},
  { word_133, defn_133},
  { word_134, defn_134},
  { word_135, defn_135},
  { word_136, defn_136},
  { word_137, defn_137},
  { word_138, defn_138},
  { word_139, defn_139},
  { word_140, defn_140},
  { word_141, defn_141},
  { word_142, defn_142},
  { word_143, defn_143},
  { word_144, defn_144},
  { word_145, defn_145},
  { word_146, defn_146},
  { word_147, defn_147},
  { word_148, defn_148},
  { word_149, defn_149},
  { word_150, defn_150},
  { word_151, defn_151},
  { word_152, defn_152},
  { word_153, defn_153},
  { word_154, defn_154},
  { word_155, defn_155},
  { word_156, defn_156},
  { word_157, defn_157},
  { word_158, defn_158},
  { word_159, defn_159},
  { word_160, defn_160},
  { word_161, defn_161},
  { word_162, defn_162},
  { word_163, defn_163},
  { word_164, defn_164},
  { word_165, defn_165},
  { word_166, defn_166},
  { word_167, defn_167},
  { word_168, defn_168},
  { word_169, defn_169},
  { word_170, defn_170},
  { word_171, defn_171},
  { word_172, defn_172},
  { word_173, defn_173},
  { word_174, defn_174},
  { word_175, defn_175},
  { word_176, defn_176},
  { word_177, defn_177},
  { word_178, defn_178},
  { word_179, defn_179},
  { word_180, defn_180},
  { word_181, defn_181},
  { word_182, defn_182},

};

const int gWordListLength = sizeof(gWordList)/sizeof(const struct sWord);
