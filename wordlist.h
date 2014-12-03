#include <avr/pgmspace.h> // for PROGMEM
#include <stdio.h>

struct sWord {
  char * word;
  char * definition;
}; 

char word_100[] PROGMEM = "placate"; char defn_100[] PROGMEM = "to calm or reduce anger by making concessions";
char word_101[] PROGMEM = "ambiguous"; char defn_101[] PROGMEM = "vague; subject to more than one interpretation";
char word_102[] PROGMEM = "ossified"; char defn_102[] PROGMEM = "turned to bone; hardened like bone; Inflexible";
char word_103[] PROGMEM = "antediluvian"; char defn_103[] PROGMEM = "ancient; outmoded; (literally,before the flood";
char word_104[] PROGMEM = "arbitrate"; char defn_104[] PROGMEM = "to settle a dispute by impulse (n: arbitration";
char word_105[] PROGMEM = "cadge"; char defn_105[] PROGMEM = "to get something by taking advantage of someone";
char word_106[] PROGMEM = "diffident"; char defn_106[] PROGMEM = "lacking self-confidence, modest (n: diffidence";
char word_107[] PROGMEM = "catalyst"; char defn_107[] PROGMEM = "an agent of change (adj: catalytic; v. catalyze";
char word_108[] PROGMEM = "occlude"; char defn_108[] PROGMEM = "to close or shut off; to obstruct (n: occlusion";
char word_109[] PROGMEM = "perfidious"; char defn_109[] PROGMEM = "deliberately treacherous; dishonest (n: perfidy";
char word_110[] PROGMEM = "quiescence"; char defn_110[] PROGMEM = "inactivity; stillness; dormancy (adj: quiescent";
char word_111[] PROGMEM = "ingenuous"; char defn_111[] PROGMEM = "unsophisticated; artless; straightforward; candid";
char word_112[] PROGMEM = "taciturn"; char defn_112[] PROGMEM = "habitually untalkative or silent (n: taciturnity";
char word_113[] PROGMEM = "aggrandize"; char defn_113[] PROGMEM = "to make greater, to increase, thus, to exaggerate.";
char word_114[] PROGMEM = "enervate"; char defn_114[] PROGMEM = "to weaken or destroy the strength or vitality of: ";
char word_115[] PROGMEM = "ineffable"; char defn_115[] PROGMEM = "undescribable; inexpressible in words; unspeakable";
char word_116[] PROGMEM = "panegyric"; char defn_116[] PROGMEM = "a writing or speech in praise of a person or thing";
char word_117[] PROGMEM = "abscond"; char defn_117[] PROGMEM = "to leave secretly and hide, often to avoid the law.";
char word_118[] PROGMEM = "anomalous"; char defn_118[] PROGMEM = "peculiar; unique, contrary to the norm (n: anomaly";
char word_119[] PROGMEM = "obdurate"; char defn_119[] PROGMEM = "hardened against influence or feeling; intractable.";
char word_120[] PROGMEM = "fledgling"; char defn_120[] PROGMEM = "a baby bird; an inexperienced person; inexperienced.";
char word_121[] PROGMEM = "gossamer"; char defn_121[] PROGMEM = "fine cobweb on foliage; fine gauzy fabric; very fine";
char word_122[] PROGMEM = "efficacy"; char defn_122[] PROGMEM = "effectiveness; capability to produce a desired effect";
char word_123[] PROGMEM = "ephemeral"; char defn_123[] PROGMEM = "lasting for only a brief time, fleeting (n: ephemera";
char word_124[] PROGMEM = "dogmatic"; char defn_124[] PROGMEM = "relying upon doctrine or dogma, as opposed to evidence";
char word_125[] PROGMEM = "inchoate"; char defn_125[] PROGMEM = "in an initial or early stage; incomplete; disorganized";
char word_126[] PROGMEM = "exacerbate"; char defn_126[] PROGMEM = "to increase the bitterness or violence of; to aggravate";
char word_127[] PROGMEM = "caustic"; char defn_127[] PROGMEM = "capable of dissolving by chemical action; highly critical";
char word_128[] PROGMEM = "eulogy"; char defn_128[] PROGMEM = "a spoken or written tribute to the deceased (v. eulogize";
char word_129[] PROGMEM = "obviate"; char defn_129[] PROGMEM = "to prevent by anticipatory measures; to make unnecessary:";
char word_130[] PROGMEM = "vacuous"; char defn_130[] PROGMEM = "empty; without contents; without ideas or intelligence:: ";
char word_131[] PROGMEM = "insular"; char defn_131[] PROGMEM = "of or pertaining to an island, thus, excessively exclusive";
char word_132[] PROGMEM = "reproof"; char defn_132[] PROGMEM = "the act of censuring, scolding, or rebuking. (v. reprove.";
char word_133[] PROGMEM = "burgeon"; char defn_133[] PROGMEM = "to grow or flourish; a bud or new growth (adj: burgeoning ";
char word_134[] PROGMEM = "latent"; char defn_134[] PROGMEM = "present or potential but not evident or active (n: latency";
char word_135[] PROGMEM = "tyro"; char defn_135[] PROGMEM = "beginner; person lacking experience in a specific endeavor: ";
char word_136[] PROGMEM = "antiphrasis"; char defn_136[] PROGMEM = "The use of a word contrary to its normal meaning for humorous effect"; // I heart wordnik
char word_137[] PROGMEM = "ruelle"; char defn_137[] PROGMEM = "n. The space between the bed and the wall."; // I heart wordnik
char word_138[] PROGMEM = "expiscate"; char defn_138[] PROGMEM = "To fish out; find out by skill or investigation; to search out."; // I heart wordnik
char word_139[] PROGMEM = "cerograph"; char defn_139[] PROGMEM = "n.A writing on wax"; // I heart wordnik
char word_140[] PROGMEM = "dunch"; char defn_140[] PROGMEM = "v. To crash into, to bump into. v. To jog, esp with the elbow."; // I heart wordnik
char word_141[] PROGMEM = "canorous"; char defn_141[] PROGMEM = "melodius, resonant"; // I heart wordnik
char word_142[] PROGMEM = "pannose"; char defn_142[] PROGMEM = "adj.Similar in texture or appearance to felt or woollen cloth."; // I heart wordnik
char word_143[] PROGMEM = "tachydidaxy"; char defn_143[] PROGMEM = "n.A short or rapid method of instructing."; // I heart wordnik
char word_144[] PROGMEM = "anosognosia"; char defn_144[] PROGMEM = "The inability of a person to recognize his own illness/handicap."; // I heart wordnik
char word_145[] PROGMEM = "acyrology"; char defn_145[] PROGMEM = "n.The incorrect use of language.  Faulty diction."; // I heart wordnik
char word_146[] PROGMEM = "prevenient"; char defn_146[] PROGMEM = "adj. Coming before; preceding. adj. Expectant; anticipatory."; // I heart wordnik
char word_147[] PROGMEM = "furcatorium"; char defn_147[] PROGMEM = "The furciform bone, wishbone, or merrythought of a fowl"; // I heart wordnik
char word_148[] PROGMEM = "parvanimity"; char defn_148[] PROGMEM = "n.The state or quality of having an ignoble mind; pettiness."; // I heart wordnik
char word_149[] PROGMEM = "sciolism"; char defn_149[] PROGMEM = "A pretentious attitude of scholarship; superficial knowledgeability."; // I heart wordnik
char word_150[] PROGMEM = "protyle"; char defn_150[] PROGMEM = "Hypothetical base from which all chemical elements are derived"; // I heart wordnik
char word_151[] PROGMEM = "chantepleure"; char defn_151[] PROGMEM = "v.To sing and cry at the same time."; // I heart wordnik
char word_152[] PROGMEM = "versorium"; char defn_152[] PROGMEM = "Magnetic needle mounted so as to move freely in horizontal plane"; // I heart wordnik
char word_153[] PROGMEM = "footle"; char defn_153[] PROGMEM = " v. To talk nonsense. n. Nonsense; foolishnes"; // I heart wordnik
char word_154[] PROGMEM = "noegenesis"; char defn_154[] PROGMEM = "n.The acquisition of new knowledge from observation"; // I heart wordnik
char word_155[] PROGMEM = "subtrahend"; char defn_155[] PROGMEM = "n.A quantity or number to be subtracted from another."; // I heart wordnik
char word_156[] PROGMEM = "plerophory"; char defn_156[] PROGMEM = "Full persuasion or confidence; perfect conviction or certitude."; // I heart wordnik
char word_157[] PROGMEM = "inselberg"; char defn_157[] PROGMEM = "n.See monadnock."; // I heart wordnik
char word_158[] PROGMEM = "collocutor"; char defn_158[] PROGMEM = ".Any of the people engaged in a conversation"; // I heart wordnik
char word_159[] PROGMEM = "brool"; char defn_159[] PROGMEM = "n.A murmuring sound as of wind blowing through a forest."; // I heart wordnik
char word_160[] PROGMEM = "blirt"; char defn_160[] PROGMEM = "An outburst of wind, rain, or tears"; // I heart wordnik
char word_161[] PROGMEM = "subdolous"; char defn_161[] PROGMEM = "adj.Sly; crafty; cunning; artful."; // I heart wordnik
char word_162[] PROGMEM = "anient"; char defn_162[] PROGMEM = "To reduce to nothingness. In law, to abrogate; make null."; // I heart wordnik
char word_163[] PROGMEM = "stigmergy"; char defn_163[] PROGMEM = "Mechanism of spontaneous, indirect coordination between agents"; // I heart wordnik
char word_164[] PROGMEM = "nisus"; char defn_164[] PROGMEM = "n.An effort or endeavor to realize an aim"; // I heart wordnik
char word_165[] PROGMEM = "petrichor"; char defn_165[] PROGMEM = "The distinctive scent of the first rain after a long dry spell."; // I heart wordnik
char word_166[] PROGMEM = "boanthropy"; char defn_166[] PROGMEM = "Form of madness in which the victim imagines himself to be an ox."; // I heart wordnik
char word_167[] PROGMEM = "oblectation"; char defn_167[] PROGMEM = "n.The act of pleasing highly; delight."; // I heart wordnik
char word_168[] PROGMEM = "vermiculate"; char defn_168[] PROGMEM = "To decorate with wavy or winding lines. adj. Bearing wavy lines"; // I heart wordnik
char word_169[] PROGMEM = "cynopic"; char defn_169[] PROGMEM = "Dog-eyed; shameless"; // I heart wordnik
char word_170[] PROGMEM = "paronym"; char defn_170[] PROGMEM = "A word derived from the same root as another word."; // I heart wordnik
char word_171[] PROGMEM = "misocapnist"; char defn_171[] PROGMEM = "n.One who hates tobacco smoke."; // I heart wordnik
char word_172[] PROGMEM = "fulguration"; char defn_172[] PROGMEM = "n. The act of lightening, or flashing with light"; // I heart wordnik
char word_173[] PROGMEM = "selcouth"; char defn_173[] PROGMEM = "adj.Strange, unusual, rare; unfamiliar; marvellous, wondrous."; // I heart wordnik
char word_174[] PROGMEM = "adynaton"; char defn_174[] PROGMEM = "Hyperbole that uses magnified exaggeration to express impossibility"; // I heart wordnik
char word_175[] PROGMEM = "noology"; char defn_175[] PROGMEM = "n.The systematic study of everything dealing with knowledge."; // I heart wordnik
char word_176[] PROGMEM = "zenzizenzizenzic"; char defn_176[] PROGMEM = "n.the eighth power of a number"; // I heart wordnik
char word_177[] PROGMEM = "yex"; char defn_177[] PROGMEM = "Hiccup"; // I heart wordnik
char word_178[] PROGMEM = "vesuviate"; char defn_178[] PROGMEM = "To burst forth as a volcanic eruption."; // I heart wordnik
char word_179[] PROGMEM = "versipellous"; char defn_179[] PROGMEM = "dj.Changeable; having a nature or appearance that changes often"; // I heart wordnik
char word_180[] PROGMEM = "protean"; char defn_180[] PROGMEM = "adj.Readily taking on varied shapes, forms, or meanings."; // I heart wordnik
char word_181[] PROGMEM = "venefice"; char defn_181[] PROGMEM = "n.The act or practice of poisoning."; // I heart wordnik
char word_182[] PROGMEM = "veisalgia"; char defn_182[] PROGMEM = "Unpleasant after-effects of the consumption of alcohol; hangover."; // I heart wordnik
char word_183[] PROGMEM = "vaccimulgence"; char defn_183[] PROGMEM = "n.The milking of cows."; // I heart wordnik
char word_184[] PROGMEM = "turbillion"; char defn_184[] PROGMEM = "n.A whirl or vortex."; // I heart wordnik
char word_185[] PROGMEM = "tentacular"; char defn_185[] PROGMEM = "adj. Of, or pertaining to, tentacles. Resembling a tentacle."; // I heart wordnik
char word_186[] PROGMEM = "temerarious"; char defn_186[] PROGMEM = "dj.Presumptuously or recklessly daring"; // I heart wordnik
char word_187[] PROGMEM = "sweven"; char defn_187[] PROGMEM = "A vision seen in sleep; a dream."; // I heart wordnik
char word_188[] PROGMEM = "swarf"; char defn_188[] PROGMEM = "n.Fine metallic filings or shavings removed by a cutting tool."; // I heart wordnik
char word_189[] PROGMEM = "sprezzatura"; char defn_189[] PROGMEM = "The art of performing a task so gracefully, it looks effortless."; // I heart wordnik
char word_190[] PROGMEM = "sprack"; char defn_190[] PROGMEM = "adj.lively, full of energy"; // I heart wordnik
char word_191[] PROGMEM = "sortilege"; char defn_191[] PROGMEM = "The act or practice of foretelling the future by drawing lots. "; // I heart wordnik
char word_192[] PROGMEM = "quadragenarian"; char defn_192[] PROGMEM = "adj.between the ages of 40 and 49; in one's fifth decade"; // I heart wordnik
char word_193[] PROGMEM = "purpureal"; char defn_193[] PROGMEM = "adj.Of a purple colour."; // I heart wordnik
char word_194[] PROGMEM = "orismology"; char defn_194[] PROGMEM = "n.The explanation of technical terms."; // I heart wordnik
char word_195[] PROGMEM = "outrecuidance"; char defn_195[] PROGMEM = "n.Presumption, arrogance, self-conceit."; // I heart wordnik
char word_196[] PROGMEM = "otaku"; char defn_196[] PROGMEM = "One with an obsessive interest in something (anime/manga)."; // I heart wordnik
char word_197[] PROGMEM = "obmutescence"; char defn_197[] PROGMEM = "n.Silence; inability or refusal to speak."; // I heart wordnik
char word_198[] PROGMEM = "obduracy"; char defn_198[] PROGMEM = "n.The state or quality of being intractable or hardened."; // I heart wordnik
char word_199[] PROGMEM = "gregarious"; char defn_199[] PROGMEM = "Seeking and enjoying the company of others; sociable."; // I heart wordnik
char word_200[] PROGMEM = "serendipity"; char defn_200[] PROGMEM = "n.The faculty of making fortunate discoveries by accident."; // I heart wordnik


PROGMEM const struct sWord gWordList[] = {
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
{ word_183, defn_183},
{ word_184, defn_184},
{ word_185, defn_185},
{ word_186, defn_186},
{ word_187, defn_187},
{ word_188, defn_188},
{ word_189, defn_189},
{ word_190, defn_190},
{ word_191, defn_191},
{ word_192, defn_192},
{ word_193, defn_193},
{ word_194, defn_194},
{ word_195, defn_195},
{ word_196, defn_196},
{ word_197, defn_197},
{ word_198, defn_198},
{ word_199, defn_199},
{ word_200, defn_200},

};

const int gWordListLength = sizeof(gWordList)/sizeof(const struct sWord);
