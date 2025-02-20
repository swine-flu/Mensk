#pragma once

#include "Object.h"
#include "Rtl.h"


struct Spawn
{
	byte xpos;
	byte ypos;
	bool flag;
	Spawn* pNext;
};

/*
	CODE Section
	ram:1000:0000-ram:1000:2d1f
	ram:12d2:0000-ram:12d2:402f
	ram:16d5:0000-ram:16d5:42ef
	ram:1b04:0000-ram:1b04:0e1f
*/

bool __pascal16near FUN_1000_004d(void);
void __pascal16far PROGRAM(void);
bool __pascal16near FUN_12d2_0000(byte xpos, byte ypos);
void __pascal16far FUN_12d2_27e7(sbyte dx, sbyte dy);
bool __pascal16far FUN_12d2_2bfd(void);
void __pascal16far FUN_12d2_32f9(void);
void __pascal16far FUN_12d2_3553(byte targetx, byte targety);
Enemy* __pascal16far FUN_12d2_3887(void);
void __pascal16near FUN_12d2_3a15(byte xpos, byte ypos, bool flag);
void __pascal16near FUN_12d2_3a6b(void);
void __pascal16far FUN_12d2_3c07(void);
void __pascal16far FUN_12d2_4019(void);
void __pascal16far FUN_16d5_0000(void);
void __pascal16far FUN_16d5_0019(const PascalString255& string);
void __pascal16far FUN_16d5_0158(byte item);
bool __pascal16far FUN_16d5_032d(void);
void __pascal16far FUN_16d5_0950(const PascalString255& name);
void __pascal16far FUN_16d5_0c6a(byte xpos, byte ypos);
void __pascal16far FUN_16d5_0f6c(void);
bool __pascal16far FUN_16d5_149e(void);
void __pascal16far FUN_16d5_16e0(void);
void __pascal16far FUN_16d5_1926(void);
void __pascal16far FUN_16d5_1e17(void);
void __pascal16far FUN_16d5_230b(void);
void __pascal16far FUN_16d5_24c7(void);
void __pascal16far FUN_16d5_25d9(byte levelid);
void __pascal16far FUN_16d5_29fd(void);
void __pascal16far FUN_16d5_2c2c(void);
void __pascal16far FUN_16d5_2e05(const PascalString255& string1, const PascalString255& string2);
byte __pascal16far FUN_16d5_32b4(void);
void __pascal16near FUN_16d5_3476(byte xpos, byte ypos);
void __pascal16far FUN_16d5_3548(void);
void __pascal16far FUN_16d5_42df(void);
void __pascal16far FUN_1b04_00e0(void);
byte __pascal16near FUN_1b04_016d(byte param_1);
void __pascal16far FUN_1b04_01b1(byte* day, byte* month, word* year);
void __pascal16far FUN_1b04_0234(void);
void __pascal16far FUN_1b04_03ed(void);
void __pascal16far FUN_1b04_0487(byte xpos, byte ypos, byte character, byte attribute);
void __pascal16far FUN_1b04_0500(byte xpos, byte ypos, const PascalString255& string, byte attribute);
void __pascal16far FUN_1b04_05b3(byte* scancode, byte* character);
void __pascal16far FUN_1b04_05e4(byte regno, byte index);
bool __pascal16near FUN_1b04_05fd(void);
void __pascal16far FUN_1b04_064b(void);
void __pascal16far FUN_1b04_0670(void);
void __pascal16near FUN_1b04_069d(void);
void __pascal16near FUN_1b04_06e8(void);
void __pascal16near FUN_1b04_0733(void);
void __pascal16near FUN_1b04_0788(void);
void __pascal16far FUN_1b04_0a48(void);
void __pascal16far FUN_1b04_0c7f(const PascalString255& name, word offset, word size);
void __pascal16far FUN_1b04_0d8a(void);
void __pascal16far FUN_1b04_0dc1(dword delay);
void __pascal16far FUN_1b04_0e08(void);
