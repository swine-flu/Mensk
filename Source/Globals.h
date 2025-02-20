#pragma once

#include "Console.h"
#include "Mensk.h"
#include "Object.h"
#include "Rtl.h"

#if defined(__clang__)
	#define SELECTANY __attribute__((weak))
#elif defined(__GNUC__)
	#define SELECTANY __attribute__((weak))
#elif defined(_MSC_VER)
	#define SELECTANY __declspec(selectany)
#else
	#define SELECTANY
#endif


SELECTANY ConsoleAPIProxy Console;


/*
	DATA Sectiom
	ram:1d2e:0000-ram:1d2e:126f
*/

// Player Movement Collision Bitset
const byte BYTE_ARRAY_1d2e_0136[32] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00
};

// Enemy Spawn List
SELECTANY Enemy* PTR_1d2e_0156 = NULL;

// Enemy Collision Bitset
const byte BYTE_ARRAY_1d2e_015a[32] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x02, 0x00, 0x00, 0x00, 0x18, 0x10, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00, 0x00
};

// Bat'ka Hit Points
SELECTANY sword SWORD_1d2e_017a = 300;

// Kill Counter
SELECTANY byte BYTE_1d2e_017c = 0;

// Empty Tile & Items Collision Bitset
const byte BYTE_ARRAY_1d2e_017e[32] = {
	0x00, 0x00, 0x00, 0xc0, 0x7a, 0x80, 0x00, 0x80,
	0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04
};

// Spawned Imp Count
SELECTANY word WORD_1d2e_019e = 0;

// Imp Action String Table
const PascalString255 P_STRING_ARRAY_1d2e_01a0[3] = {
	" паказвае Лявону язык.",
	" жартаўлiва лягае Лявона брудным капытцам.",
	" спрабуе зачапiць Лявона рожкамi."
};

// Drunk Commie Action String Table
const PascalString255 P_STRING_ARRAY_1d2e_0222[3] = {
	" крычыць: \"Парцiя - ум, чэсьць i совесьць нашэй эпохi!",
	" пасылае Лявона на тры лiтары.",
	" мочыцца Лявону пад ногi."
};

// Usable Items Bitset
const byte BYTE_ARRAY_1d2e_0300[32] = {
	0x7c, 0x90, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Charm Items Bitset
const byte BYTE_ARRAY_1d2e_0320[32] = {
	0x00, 0x60, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Numeric Character String Table
const PascalString255 P_STRING_ARRAY_1d2e_0340[11] = {
	"0",
	"1",
	"2",
	"3",
	"4",
	"5",
	"6",
	"7",
	"8",
	"9",
	"10"
};

// Unique Item Flags
SELECTANY byte BYTE_ARRAY_1d2e_0362[4] = { 0, 0, 0, 0 };
// BPSM Card Flag
SELECTANY byte& BYTE_1d2e_0362 = BYTE_ARRAY_1d2e_0362[0];
// DOOMGUY Chainsaw Flag
SELECTANY byte& BYTE_1d2e_0363 = BYTE_ARRAY_1d2e_0362[1];
// Lyavon's Bottle of Beer Flag
SELECTANY byte& BYTE_1d2e_0364 = BYTE_ARRAY_1d2e_0362[2];
// N.R.M. Cassette Flag
SELECTANY byte& BYTE_1d2e_0365 = BYTE_ARRAY_1d2e_0362[3];

// Item Name String Table (Nominative Case)
const PascalString255 P_STRING__ARRAY_1d2e_0366[17] = {
	"Бутэлька з-пад пiва [1ды1]",
	"Бутэлька зь пiвам \"Крынiца\" [2ды2]",
	"Бутэлька зь пiвам \"Жигулёвское\" [1ды2]",
	"Бутэлька зь пiвам родным, сялянскiм [1ды2]",
	"Бутэлька з украiнскiм пiвам [1ды3]",
	"Бутэлька пiва Лявона Вольскага [1ды2] [!]",
	"Дубiна [2ды4]",
	"Палка [2ды3]",
	"Бензапiла DOOM'ера [4ды5]",
	"Бiлет БПСМ [6ды5]",
	"Касэта \"Пашпарт грамадзянiна N.R.M.\" [0ды0] [!]",
	"Поўшн оф хераiзм [1ды1]",
	"Зялёная магiчная фенька [0ды0]",
	"Жоўтая магiчная фенька [0ды0]",
	"Бутэлька пiва згушчанага, зь мякацьцю [2ды3]",
	"Бутэлька зь пiвам \"Балтика-6\" [2ды2]",
	"Бела-чырвона-белая магiчная фенька [0ды0]",
};

// Enemy Name String Table (Nominative Case)
const PascalString255 P_STRING__ARRAY_1d2e_0696[15] = {
	"Гопнiк",
	"П'яны гопнiк",
	"Вялiзны злосны гапар",
	"Мент",
	"БАЦЬКА",
	"Ды-джэй",
	"Скiн",
	"Камунiст",
	"Баркашовец",
	"АМАПавец",
	"Малы гопнiк",
	"П'яны камуняга",
	"Зялёны чорцiк",
	"Блакiтны чорцiк",
	"Вялiзны мянтоўскi чорт"
};

// Enemy Strength & Hit Chance
const byte BYTE_ARRAY_1d2e_07f0[15] = {
	0x01, 0x02, 0x03, 0x04, 0x0a,
	0x07, 0x03, 0x04, 0x05, 0x06,
	0x00, 0x04, 0x00, 0x00, 0x0e
};

// Enemy Experience
const word WORD_ARRAY_1d2e_0800[15] = {
	0x0003, 0x0005, 0x0007, 0x000f, 0x03e8,
	0x0032, 0x0007, 0x000a, 0x000f, 0x0014,
	0x0003, 0x000a, 0x0000, 0x0000, 0x0000
};

// Alcohol Drunkenness Effect
const word WORD_ARRAY_1d2e_081e[5] = { 0x00c8, 0x0064, 0x0064, 0x00c8, 0x015e };

// Alcohol Healing Effect
const word WORD_ARRAY_1d2e_0828[5] = { 0x0014, 0x0000, 0x0014, 0x0000, 0x0000 };

// Enemy Name String Table (Accusative Case)
const PascalString255 P_STRING__ARRAY_1d2e_0832[15] = {
	"гопнiка",
	"п'янага гопнiка",
	"вялiзнага злоснага гапара",
	"мянта",
	"БАЦЬКУ",
	"ды-джэя",
	"скiна",
	"камунiста",
	"баркашоўца",
	"АМАПаўца",
	"малога гопнiка",
	"п'янага камунягу",
	"зялёнага чорцiка",
	"блакiтнага чорцiка",
	"вялiзнага мянтоўскага чорта"
};

// Enemy Name String Table (Dative Case)
const PascalString255 P_STRING__ARRAY_1d2e_09d6[15] = {
	"гопнiку",
	"п'янаму гопнiку",
	"вялiзнаму злоснаму гапару",
	"мянту",
	"БАЦЬКУ",
	"ды-джэю",
	"скiну",
	"камунiсту",
	"баркашоўцу",
	"АМАПаўцу",
	"малому гопнiку",
	"п'янаму камунягу",
	"зялёнаму чорцiку",
	"блакiтнаму чорцiку",
	// FIXME: Name string is truncated and missing a few letters at the end!
	"вялiзнаму мянтоўскаму чор"
};

// Enemy Name String Table (Instrumental Case)
const PascalString255 P_STRING__ARRAY_1d2e_0b5c[15][2] = {
	{ "гопнiкам", "" },
	{ "п'яным", "гопнiкам" },
	{ "вялiзным", "злосным гапаром" },
	{ "мянтом", "" },
	{ "БАЦЬКАМ", "" },
	{ "ды-джэем", "" },
	{ "скiном", "" },
	{ "камунiстам", "" },
	{ "баркашоўцам", "" },
	{ "АМАПаўцам", "" },
	{ "малым гопнiкам", "" },
	{ "п'яным", "камунягам" },
	{ "зялёным", "чорцiкам" },
	{ "блакiтным", "чорцiкам" },
	{ "вялiзным мян-", "тоўскiм чортам" }
};

// Item Name String Table (Accusative Case)
const PascalString255 P_STRING_ARRAY_1d2e_0d3c[17] = {
	"бутэльку з-пад пiва [1ды1]",
	"бутэльку зь пiвам \"Крынiца\" [2ды2]",
	"бутэльку зь пiвам \"Жигулёвское\" [1ды2]",
	"бутэльку зь пiвам родным, сялянскiм [1ды2]",
	"бутэльку з украiнскiм пiвам [1ды3]",
	"бутэльку пiва Лявона Вольскага [1ды2] [!]",
	"дубiну [2ды4]",
	"палку [2ды3]",
	"бензапiлу DOOM'ера [4ды5]",
	"бiлет БПСМ [6ды5]",
	"касэту \"Пашпарт грамадзянiна N.R.M.\" [0ды0] [!]",
	"поўшн оф хераiзм [1ды1]",
	"зялёную магiчную феньку [0ды0]",
	"жоўтую магiчную феньку [0ды0]",
	"бутэльку пiва згушчанага, зь мякацьцю [2ды3]",
	"бутэльку зь пiвам \"Балтика-6\" [2ды2]",
	"бела-чырвона-белую магiчную феньку [0ды0]"
};

// Upper Case -> Lower Case Conversion Table
const char DAT_1d2e_10a0[32] = {
	'а', 'б', 'в', 'г',
	'д', 'е', 'ж', 'з',
	'и', 'й', 'к', 'л',
	'м', 'н', 'о', 'п',
	'р', 'с', 'т', 'у',
	'ф', 'х', 'ц', 'ч',
	'ш', 'щ', 'ъ', 'ы',
	'ь', 'э', 'ю', 'я'
};

// Item Melee Damage
const byte BYTE_ARRAY_ARRAY_1d2e_10c0[17][2] = {
	{ 0x01, 0x01 },
	{ 0x02, 0x02 },
	{ 0x01, 0x02 },
	{ 0x01, 0x02 },
	{ 0x01, 0x03 },
	{ 0x01, 0x02 },
	{ 0x02, 0x04 },
	{ 0x02, 0x03 },
	{ 0x04, 0x05 },
	{ 0x06, 0x05 },
	{ 0x00, 0x00 },
	{ 0x01, 0x01 },
	{ 0x00, 0x00 },
	{ 0x00, 0x00 },
	{ 0x02, 0x03 },
	{ 0x02, 0x02 },
	{ 0x00, 0x00 }
};

// Item Throwing Damage
const byte BYTE_ARRAY_ARRAY_1d2e_10e2[17][2] = {
	{ 0x01, 0x01 },
	{ 0x02, 0x02 },
	{ 0x01, 0x02 },
	{ 0x01, 0x02 },
	{ 0x01, 0x03 },
	{ 0x01, 0x02 },
	{ 0x02, 0x04 },
	{ 0x02, 0x03 },
	{ 0x04, 0x05 },
	{ 0x00, 0x00 },
	{ 0x00, 0x00 },
	{ 0x01, 0x01 },
	{ 0x00, 0x00 },
	{ 0x00, 0x00 },
	{ 0x02, 0x03 },
	{ 0x02, 0x02 },
	{ 0x00, 0x00 }
};

// Gopnik Spawn Flag
SELECTANY byte BYTE_1d2e_1104 = 1;

// Wait User Input Flag
SELECTANY byte BYTE_1d2e_1106 = 0;

// System Clock Counter (Low Word)
SELECTANY word WORD_1d2e_1208 = 0;

// XOR Cipher Table
const char BYTE_ARRAY_1d2e_120a[16] = {
	'q', 's', 'c', 'w',
	'd', 'v', 'e', 'f',
	'b', 'r', 'g', 'n',
	't', 'h', 'm', 'y'
};

/*
	BSS Section
	ram:1d2e:1270-ram:1d2e:45af
*/

// Hedgehog Ninjas Array
SELECTANY alignas(alignof(Ally)) byte DAT_ARRAY_STORAGE_1d2e_126a[sizeof(Ally) * 3];
SELECTANY Ally (&DAT_ARRAY_1d2e_126a)[3] = *reinterpret_cast<Ally(*)[3]>(DAT_ARRAY_STORAGE_1d2e_126a);

// Temp String Buffers
SELECTANY PascalString255 P_STRING_1d2e_1288;
SELECTANY PascalString255 P_STRING_1d2e_1388;

// Input Scancode
SELECTANY byte DAT_1d2e_1488;
// Input Character
SELECTANY byte DAT_1d2e_1489;

// Last Enemy Pointer
SELECTANY Enemy* PTR_1d2e_148a;

// Current Enemy Pointer
SELECTANY Enemy* PTR_1d2e_148e;

// Next Enemy Pointer
SELECTANY Enemy* PTR_1d2e_1492;

// Loop Counter
SELECTANY word WORD_1d2e_1496;

// Char Position X
SELECTANY byte BYTE_1d2e_1498;
// Char Position Y
SELECTANY byte BYTE_1d2e_1499;
// Char Symbol
SELECTANY byte BYTE_1d2e_149a;
// Char Attribute
SELECTANY byte BYTE_1d2e_149b;

// Auto Save Flag?
SELECTANY byte BYTE_1d2e_149c;

// Save File Stream Object
SELECTANY UFileStream FILE_1d2e_149e;

// Random Bottle
SELECTANY byte BYTE_1d2e_151e;

// Imp Spawn Info List
SELECTANY Spawn* PTR_1d2e_1520;

// Imp Transformation Flag
SELECTANY byte BYTE_1d2e_1524;

// Game Tick Counter
SELECTANY word WORD_1d2e_1526;

// Subway Station State (Enum)
SELECTANY byte BYTE_1d2e_1528;

// Player Position X
SELECTANY byte BYTE_1d2e_1529;
// Player Position Y
SELECTANY byte BYTE_1d2e_152a;

// Tile Data
SELECTANY byte BYTE_ARRAY_ARRAY_1d2e_152c[66][23];

// Message Log
SELECTANY PascalString255 DAT_1d2E_1b1a[24];

// Loop Counter (i)
SELECTANY byte BYTE_1d2e_331a;
// Loop Counter (j)
SELECTANY byte BYTE_1d2e_331b;

// Input Scancode
SELECTANY byte BYTE_1d2e_331c;
// Input Character
SELECTANY byte BYTE_1d2e_331d;

// Glitch Duration (Ticks)
SELECTANY byte BYTE_1d2e_331e;

// Glitch Coordinate X
SELECTANY byte BYTE_ARRAY_1d2e_3320[3];
// Glitch Coordinate Y
SELECTANY byte BYTE_ARRAY_1d2e_3324[3];

// Intoxication level (Enum)
SELECTANY sbyte SBYTE_1d2e_3327;

// Impaired Coordination Flag
SELECTANY byte BYTE_1d2e_3328;

// Glitch Activation Flag
SELECTANY byte BYTE_1d2e_3329;

// Player Inventory
SELECTANY byte BYTE_ARRAY_1d2e_332a[12];

// Pub Goods
SELECTANY byte BYTE_ARRAY_ARRAY_1d2e_3336[2][8];
// Beer Type
SELECTANY byte (&BYTE_ARRAY_1d2e_3336)[8] = BYTE_ARRAY_ARRAY_1d2e_3336[0];
// Beer Cost
SELECTANY byte (&BYTE_ARRAY_1d2e_333e)[8] = BYTE_ARRAY_ARRAY_1d2e_3336[1];

// Inventory Items Count
SELECTANY byte BYTE_1d2e_3346;

// Stock Items Count
SELECTANY byte BYTE_1d2e_3347;

// Spawned Enemy Count
SELECTANY byte BYTE_1d2e_3348;

// Spawned Green Imp Count
SELECTANY byte BYTE_1d2e_3349;

// Message Log Entries Count
SELECTANY byte BYTE_1d2e_334a;

// Level Id (Enum)
SELECTANY byte BYTE_1d2e_334b;

// Equipped Item
SELECTANY byte BYTE_1d2e_334c;

// Soberness Level
SELECTANY sword SWORD_1d2e_334e;

// Max Hit Points
SELECTANY sword SWORD_1d2e_3350;

// Experience
SELECTANY word WORD_1d2e_3352;

// Cash Money
SELECTANY sword SWORD_1d2e_3354;

// Current Hit Points
SELECTANY sword SWORD_1d2e_3356;

// Longint -> String Conversion Buffer
SELECTANY byte BYTE_ARRAY_1d2e_3358[4 + 1]; // +1 for '\0'

// Bat'ka Spawn Flag
SELECTANY byte BYTE_1d2e_335c;

// God Mode Flag
SELECTANY byte BYTE_1d2e_335d;

// Hedgehog Summon Duration (Ticks)
SELECTANY byte BYTE_1d2e_335e;

// User-Specified Character Table
SELECTANY byte BYTE_ARRAY_ARRAY_1d2e_3360[256][16];
