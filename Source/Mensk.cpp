#include <Windows.h>

#include "Console.h"
#include "Globals.h"
#include "Mensk.h"
#include "Object.h"


/*
	Load Save File
*/
bool __pascal16near FUN_1000_004d(void)
{
	byte bVar1;
	word wVar2;
	uint uVar3;
	undefined2 unaff_SS;
	bool bVar4;
	PascalString255* dest;
	PascalString255 local_106;
	byte local_9;
	word local_8;
	byte local_6;
	byte local_5;
	byte local_4;
	bool local_3;

	__StackCheck(0x104);
	Assign(FILE_1d2e_149e, "menskbnd.sav");
	Reset(FILE_1d2e_149e, 1);
	if (IOResult() == 0) {
		P_STRING_1d2e_1288.resize(4);
		BlockRead(FILE_1d2e_149e, (byte*)P_STRING_1d2e_1288.data(), 4, NULL);
		if (IOResult() == 0) {
			if (!StrComp(P_STRING_1d2e_1288, "MBSF")) {
				BYTE_1d2e_335c = 0;
				BlockRead(FILE_1d2e_149e, &BYTE_1d2e_1529, 1, NULL);
				BlockRead(FILE_1d2e_149e, &BYTE_1d2e_152a, 1, NULL);
				BlockRead(FILE_1d2e_149e, (byte*)&WORD_1d2e_3352, 2, NULL);
				SWORD_1d2e_3350 = 25;
				if (60 < WORD_1d2e_3352) {
					SWORD_1d2e_3350 = 30;
				}
				if (160 < WORD_1d2e_3352) {
					SWORD_1d2e_3350 = 100;
				}
				if (380 < WORD_1d2e_3352) {
					SWORD_1d2e_3350 = 150;
				}
				if (600 < WORD_1d2e_3352) {
					SWORD_1d2e_3350 = 200;
				}
				if (1200 < WORD_1d2e_3352) {
					SWORD_1d2e_3350 = 300;
				}
				BlockRead(FILE_1d2e_149e, (byte*)&SWORD_1d2e_3356, 2, NULL);
				BlockRead(FILE_1d2e_149e, (byte*)&SWORD_1d2e_3354, 2, NULL);
				BlockRead(FILE_1d2e_149e, (byte*)&SWORD_1d2e_334e, 2, NULL);
				BlockRead(FILE_1d2e_149e, (byte*)&SBYTE_1d2e_3327, 1, NULL);
				BlockRead(FILE_1d2e_149e, &BYTE_1d2e_334b, 1, NULL);
				BlockRead(FILE_1d2e_149e, &BYTE_1d2e_1104, 1, NULL);
				BlockRead(FILE_1d2e_149e, &BYTE_1d2e_1528, 1, NULL);
				BlockRead(FILE_1d2e_149e, (byte*)&WORD_1d2e_1526, 2, NULL);
				BlockRead(FILE_1d2e_149e, &BYTE_1d2e_3328, 1, NULL);
				BlockRead(FILE_1d2e_149e, &BYTE_1d2e_017c, 1, NULL);
				BlockRead(FILE_1d2e_149e, &BYTE_1d2e_3329, 1, NULL);
				BlockRead(FILE_1d2e_149e, &BYTE_1d2e_331e, 1, NULL);
				BlockRead(FILE_1d2e_149e, &BYTE_1d2e_335e, 1, NULL);
				BlockRead(FILE_1d2e_149e, (byte*)&DAT_ARRAY_1d2e_126a[0], 0x1e, NULL);
				BlockRead(FILE_1d2e_149e, (byte*)BYTE_ARRAY_ARRAY_1d2e_152c, 0x5ee, NULL);
				WORD_1d2e_1496 = 0xf;
				while (true) {
					BYTE_1d2e_331b = 2;
					while (BYTE_ARRAY_ARRAY_1d2e_152c[WORD_1d2e_1496 - 0x0F][BYTE_1d2e_331b - 0x02] =
						BYTE_ARRAY_ARRAY_1d2e_152c[WORD_1d2e_1496 - 0x0F][BYTE_1d2e_331b - 0x02] ^ 0xce ^
						BYTE_1d2e_331b & (byte)WORD_1d2e_1496, BYTE_1d2e_331b != 0x18) {
						BYTE_1d2e_331b = BYTE_1d2e_331b + 1;
					}
					if (WORD_1d2e_1496 == 0x50) break;
					WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
				}
				BlockRead(FILE_1d2e_149e, &BYTE_1d2e_3346, 1, NULL);
				local_8 = BYTE_1d2e_3346;
				if (local_8 != 0) {
					WORD_1d2e_1496 = 1;
					while (BlockRead(FILE_1d2e_149e,
						&BYTE_ARRAY_1d2e_332a[WORD_1d2e_1496 - 0x01], 1, NULL),
						WORD_1d2e_1496 != local_8) {
						WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
					}
				}
				BlockRead(FILE_1d2e_149e, &BYTE_1d2e_3347, 1, NULL);
				BlockRead(FILE_1d2e_149e, (byte*)BYTE_ARRAY_ARRAY_1d2e_3336, 0x10, NULL);
				WORD_1d2e_1496 = 1;
				while (BlockRead(FILE_1d2e_149e,
					&BYTE_ARRAY_1d2e_0362[WORD_1d2e_1496 - 0x01], 1, NULL),
					WORD_1d2e_1496 != 4) {
					WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
				}
				BlockRead(FILE_1d2e_149e, &BYTE_1d2e_334c, 1, NULL);
				BlockRead(FILE_1d2e_149e, &BYTE_1d2e_3348, 1, NULL);
				BYTE_1d2e_3349 = 0;
				local_8 = BYTE_1d2e_3348;
				if (local_8 != 0) {
					WORD_1d2e_1496 = 1;
					while (true) {
						BlockRead(FILE_1d2e_149e, &local_4, 1, NULL);
						if (local_4 == 0xd) {
							BYTE_1d2e_3349 = BYTE_1d2e_3349 + 1;
						}
						BlockRead(FILE_1d2e_149e, &local_5, 1, NULL);
						BlockRead(FILE_1d2e_149e, &local_6, 1, NULL);
						if (local_4 == 1) {
							PTR_1d2e_148a = new DAT_1d2e_0096(local_5, local_6, false);
						}
						else if (local_4 == 2) {
							PTR_1d2e_148a = new DAT_1d2e_006e(local_5, local_6, false);
						}
						else if (local_4 == 3) {
							PTR_1d2e_148a = new DAT_1d2e_00aa(local_5, local_6, false);
						}
						else if (local_4 == 4) {
							PTR_1d2e_148a = new DAT_1d2e_005a(local_5, local_6, false);
						}
						else if (local_4 == 5) {
							PTR_1d2e_148a = new DAT_1d2e_00be(local_5, local_6, false);
							BYTE_1d2e_335c = 1;
						}
						else if (local_4 == 6) {
							PTR_1d2e_148a = new DAT_1d2e_00d2(local_5, local_6, false);
						}
						else if (local_4 == 7) {
							PTR_1d2e_148a = new DAT_1d2e_00e6(local_5, local_6, false);
						}
						else if (local_4 == 8) {
							PTR_1d2e_148a = new DAT_1d2e_00fa(local_5, local_6, false);
						}
						else if (local_4 == 9) {
							PTR_1d2e_148a = new DAT_1d2e_010e(local_5, local_6, false);
						}
						else if (local_4 == 10) {
							PTR_1d2e_148a = new DAT_1d2e_0122(local_5, local_6, false);
						}
						else if (local_4 == 0xb) {
							PTR_1d2e_148a = new DAT_1d2e_0046(local_5, local_6, false);
						}
						else if (local_4 == 0xc) {
							PTR_1d2e_148a = new DAT_1d2e_0082(local_5, local_6, false);
						}
						else if (local_4 == 0xd) {
							PTR_1d2e_148a = new DAT_1d2e_000a(local_5, local_6, false);
						}
						else if (local_4 == 0xe) {
							PTR_1d2e_148a = new DAT_1d2e_001e(local_5, local_6, false);
						}
						else if (local_4 == 0xf) {
							PTR_1d2e_148a = new DAT_1d2e_0032(local_5, local_6, false);
						}
						BlockRead(FILE_1d2e_149e, (byte*)&PTR_1d2e_148a->hp, 2, NULL);
						BYTE_1d2e_3348 = BYTE_1d2e_3348 - 1;
						if (WORD_1d2e_1496 == local_8) break;
						WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
					}
				}
				BlockRead(FILE_1d2e_149e, &BYTE_1d2e_334a, 1, NULL);
				local_8 = BYTE_1d2e_334a;
				if (local_8 != 0) {
					WORD_1d2e_1496 = 1;
					while (true) {
						BlockRead(FILE_1d2e_149e, &local_9, 1, NULL);
						DAT_1d2E_1b1a[WORD_1d2e_1496 - 0x01].resize(local_9);
						BlockRead(FILE_1d2e_149e, (byte*)DAT_1d2E_1b1a[WORD_1d2e_1496 - 0x01].data(), local_9, NULL);
						if (local_9 != 0) {
							BYTE_1d2e_331b = 1;
							while (DAT_1d2E_1b1a[WORD_1d2e_1496 - 0x01][BYTE_1d2e_331b - 0x01] =
								DAT_1d2E_1b1a[WORD_1d2e_1496 - 0x01][BYTE_1d2e_331b - 0x01] ^ 0xce,
								BYTE_1d2e_331b != local_9) {
								BYTE_1d2e_331b = BYTE_1d2e_331b + 1;
							}
						}
						if (WORD_1d2e_1496 == local_8) break;
						WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
					}
				}
				BlockRead(FILE_1d2e_149e, (byte*)P_STRING_1d2e_1288.data(), 1, NULL);
				BYTE_1d2e_335d = P_STRING_1d2e_1288[0] == '!';
				Close(FILE_1d2e_149e);
				local_3 = true;
				if (BYTE_1d2e_334b == 1) {
					P_STRING_1d2e_1288 = " у горадзе...";
				}
				else if (BYTE_1d2e_334b == 2) {
					P_STRING_1d2e_1288 = " у метро...";
				}
				else if (BYTE_1d2e_334b == 3) {
					P_STRING_1d2e_1288 = " у клюбе...";
				}
				local_106 = "Ну вось Лявон iзноў";
				Concat(local_106, P_STRING_1d2e_1288);
				FUN_16d5_0019(local_106);
				FUN_16d5_0019("");
			}
			else {
				local_3 = false;
			}
		}
		else {
			local_3 = false;
		}
	}
	else {
		local_3 = false;
	}
	return local_3;
}

/*
	Main
*/
void __pascal16far PROGRAM(void)
{
	void* pcVar3;
	int iVar4;
	word wVar5;
	bool bVar6;
	byte bVar7;
	byte bVar8;
	byte bVar9;
	word wVar10;
	uint uVar11;
	undefined2 uVar12;
	undefined2 unaff_SS;
	Enemy* psVar13;
	Enemy* psVar14;
	std::pair<byte, word> dVar15;
	PascalString255* psVar16;
	undefined uVar17;
	undefined uVar18;
	char cVar19;
	undefined uVar20;
	undefined uVar21;
	PascalString255 local_102;
	byte local_5;
	byte local_4;
	byte local_3;

	__SystemInit();
	FUN_1b04_0e08();
	FUN_16d5_42df();
	FUN_12d2_4019();
	__StackCheck(0x100);
	FUN_1b04_00e0();
	Randomize();
	Console.ResetBuffer();
	Console.HideCursor();
	FUN_1b04_0c7f("mnskbnd1.dat", 0, 0xff);
	FUN_1b04_0d8a();
	FUN_1b04_03ed();
#ifndef SKIPINTRO
	FUN_1b04_0a48();
#endif
	FUN_1b04_0d8a();
	FUN_1b04_03ed();
	Console.ClearInputBuffer();
	if (!FUN_1000_004d()) {
		if (ParamCount() == 1) {
			ParamStr(local_102, 1);
			if (!StrComp(local_102, "/god")) {
				BYTE_1d2e_335d = 1;
			}
		}
		// Start New Game
		FUN_16d5_25d9(1);
		WORD_1d2e_1526 = 0;
		SWORD_1d2e_334e = 1;
		SBYTE_1d2e_3327 = 0;
		BYTE_1d2e_335c = 0;
		BYTE_1d2e_3328 = 0;
		BYTE_1d2e_3329 = 0;
		BYTE_1d2e_149c = 0;
		BYTE_1d2e_1529 = 16;
		BYTE_1d2e_152a = 3;
		SWORD_1d2e_3354 = 100;
		SWORD_1d2e_3356 = 25;
		WORD_1d2e_3352 = 0;
		BYTE_1d2e_1104 = 1;
		SWORD_1d2e_3350 = 25;
		BYTE_1d2e_3347 = 5;
		BYTE_1d2e_334a = 0;
		BYTE_1d2e_3348 = 0;
		BYTE_1d2e_334b = 1;
		BYTE_1d2e_335e = 0;
		BYTE_1d2e_3349 = 0;
		FUN_16d5_0019("Хлабысь! Лявон выпiў бутэльку пiва \"Крынiца\".");
		FUN_16d5_0019("Як адразу добра стала!..");
		FUN_16d5_0019("Вось толькi гопнiкi ды скiны дасталi!");
		BYTE_1d2e_334c = 1;
		BYTE_ARRAY_1d2e_332a[0] = 3;
		BYTE_1d2e_3346 = 1;
		BYTE_1d2e_0362 = 0;
		BYTE_1d2e_0363 = 0;
		BYTE_1d2e_0364 = 0;
		BYTE_1d2e_0365 = 0;
		FUN_16d5_24c7();
	}
	FUN_1b04_0d8a();
	FUN_1b04_03ed();
	FUN_16d5_0f6c();
	// Draw Hedgehog Ninjas
	if (BYTE_1d2e_335e != 0) {
		WORD_1d2e_1496 = 1;
		while (true) {
			FUN_1b04_0487(DAT_ARRAY_1d2e_126a[WORD_1d2e_1496 - 0x01].xpos,
				DAT_ARRAY_1d2e_126a[WORD_1d2e_1496 - 0x01].ypos,
				DAT_ARRAY_1d2e_126a[WORD_1d2e_1496 - 0x01].icon,
				DAT_ARRAY_1d2e_126a[WORD_1d2e_1496 - 0x01].color);
			if (WORD_1d2e_1496 == 3) break;
			WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
		}
	}
	// Draw Enemies
	PTR_1d2e_148e = PTR_1d2e_0156;
	while (true) {
		if (PTR_1d2e_148e == NULL) break;
		PTR_1d2e_148e->DrawSymbol();
		PTR_1d2e_148e = PTR_1d2e_148e->pNext;
	}
	// Draw UI
	FUN_1b04_0500(1, 0xc, "ВОПЫТУ:      ", 7);
	Str(WORD_1d2e_3352, 0, &P_STRING_1d2e_1288, 0xff);
	FUN_1b04_0500(0xb, 0xc, P_STRING_1d2e_1288, 7);
	FUN_1b04_0500(1, 0xd, "CHP   :      ", 7);
	Str(SWORD_1d2e_3356, 0, &P_STRING_1d2e_1288, 0xff);
	FUN_1b04_0500(0xb, 0xd, P_STRING_1d2e_1288, 7);
	FUN_1b04_0500(1, 0x14, "ГРОШЫ:", 7);
	Str(SWORD_1d2e_3354, 0, &P_STRING_1d2e_1288, 0xff);
	P_STRING_1d2e_1288.resize(4, ' ');
	FUN_1b04_0500(8, 0x14, P_STRING_1d2e_1288, 7);
	FUN_1b04_0500(0x46, 0x19, "Менск", 7);
	FUN_16d5_2c2c();
LAB_1000_0f7f:
	// Enter Location
	if ((BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_1529 - 0x0F][BYTE_1d2e_152a - 0x02] == '1') || // 1 - Pub "Honest Izya"
		(BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_1529 - 0x0F][BYTE_1d2e_152a - 0x02] == '2') || // 2 - The Government House
		(BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_1529 - 0x0F][BYTE_1d2e_152a - 0x02] == '3')) { // 3 - Club "Reactor"
		FUN_1b04_0500(0xf, 1, "Зайсьцi? [Enter], калi згодзен", 7);
		FUN_1b04_0670();
		FUN_1b04_05b3(&BYTE_1d2e_331c, &BYTE_1d2e_331d);
		// Enter the Pub
		if ((BYTE_1d2e_331c == 0x1c) &&
			(BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_1529 - 0x0F][BYTE_1d2e_152a - 0x02] == '1')) {
			FUN_16d5_230b();
			PTR_1d2e_148e = PTR_1d2e_0156;
			while (true) {
				if (PTR_1d2e_148e == NULL) break;
				PTR_1d2e_148e->DrawSymbol();
				PTR_1d2e_148e = PTR_1d2e_148e->pNext;
			}
		}
		// Enter the Government House
		if ((BYTE_1d2e_331c == 0x1c) &&
			(BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_1529 - 0x0F][BYTE_1d2e_152a - 0x02] == '2')) {
			FUN_16d5_29fd();
			if (BYTE_1d2e_335e != 0) {
				WORD_1d2e_1496 = 1;
				while (true) {
					FUN_1b04_0487(DAT_ARRAY_1d2e_126a[WORD_1d2e_1496 - 0x01].xpos,
						DAT_ARRAY_1d2e_126a[WORD_1d2e_1496 - 0x01].ypos,
						DAT_ARRAY_1d2e_126a[WORD_1d2e_1496 - 0x01].icon,
						DAT_ARRAY_1d2e_126a[WORD_1d2e_1496 - 0x01].color);
					if (WORD_1d2e_1496 == 3) break;
					WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
				}
			}
			PTR_1d2e_148e = PTR_1d2e_0156;
			while (true) {
				if (PTR_1d2e_148e == NULL) break;
				PTR_1d2e_148e->DrawSymbol();
				PTR_1d2e_148e = PTR_1d2e_148e->pNext;
			}
			FUN_16d5_0019("Дарэмна ты туды пайшоў, дарэмна...");
			WORD_1d2e_1496 = 1;
			while (true) {
				PTR_1d2e_148a = new DAT_1d2e_005a();
				if (WORD_1d2e_1496 == 0xf) break;
				WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
			}
		}
		// Enter the Club
		if ((BYTE_1d2e_331c == 0x1c) &&
			(BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_1529 - 0x0F][BYTE_1d2e_152a - 0x02] == '3')) {
			BYTE_1d2e_334b = 3;
			FUN_16d5_0019("Лявон пайшоў у клюб \"РЕАКТОР\".");
			FUN_16d5_0019("ГАПАТА Б\'Е ЛЯВОНА ПА МАЗГОХ!!!");
			BYTE_1d2e_335e = 0;
			SWORD_1d2e_3356 = SWORD_1d2e_3356 - 25;
			if (SWORD_1d2e_3356 <= 0) {
				FUN_16d5_0019(" ");
				FUN_16d5_2e05("ад гапаты", "");
			}
			FUN_16d5_0019("");
			local_4 = BYTE_1d2e_3348;
			if (local_4 != 0) {
				WORD_1d2e_1496 = 1;
				while (delete PTR_1d2e_0156, WORD_1d2e_1496 != local_4) {
					WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
				}
			}
			BYTE_1d2e_3348 = 0;
			BYTE_1d2e_335c = 0;
			FUN_16d5_25d9(3);
			FUN_16d5_0f6c();
			// Draw Club Level Layout
			WORD_1d2e_1496 = 0xf;
			while (true) {
				FUN_1b04_0487(WORD_1d2e_1496, 2, 0xb1, 1);
				if (WORD_1d2e_1496 == 0x50) break;
				WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
			}
			WORD_1d2e_1496 = 3;
			while (true) {
				FUN_1b04_0487(0xf, WORD_1d2e_1496, 0xb1, 1);
				if (WORD_1d2e_1496 == 0x18) break;
				WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
			}
			WORD_1d2e_1496 = 0xf;
			while (true) {
				FUN_1b04_0487(WORD_1d2e_1496, 0x18, 0xb1, 1);
				if (WORD_1d2e_1496 == 0x50) break;
				WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
			}
			WORD_1d2e_1496 = 3;
			while (true) {
				FUN_1b04_0487(0x50, WORD_1d2e_1496, 0xb1, 1);
				if (WORD_1d2e_1496 == 0x18) break;
				WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
			}
			WORD_1d2e_1496 = 2;
			while (true) {
				FUN_1b04_0487(0x2c, WORD_1d2e_1496, 0xb1, 1);
				if (WORD_1d2e_1496 == 5) break;
				WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
			}
			WORD_1d2e_1496 = 2;
			while (true) {
				FUN_1b04_0487(0x34, WORD_1d2e_1496, 0xb1, 1);
				if (WORD_1d2e_1496 == 5) break;
				WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
			}
			WORD_1d2e_1496 = 0x2c;
			while (true) {
				FUN_1b04_0487(WORD_1d2e_1496, 7, 0xb1, 1);
				if (WORD_1d2e_1496 == 0x34) break;
				WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
			}
			// Populate Club Level with Enemies
			WORD_1d2e_1496 = 1;
			while (true) {
				wVar10 = Random(100) % 0xb;
				if (((wVar10 == 1) || (wVar10 == 2)) || (wVar10 == 3)) {
					PTR_1d2e_148a = new DAT_1d2e_0096();
				}
				else if (((wVar10 == 5) || (wVar10 == 6)) || (wVar10 == 7)) {
					PTR_1d2e_148a = new DAT_1d2e_006e();
				}
				else if (wVar10 == 4) {
					PTR_1d2e_148a = new DAT_1d2e_0046();
				}
				else if (((wVar10 == 9) || (wVar10 == 10)) || (wVar10 == 0)) {
					PTR_1d2e_148a = new DAT_1d2e_00aa();
				}
				if (WORD_1d2e_1496 == 100) break;
				WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
			}
			PTR_1d2e_148a = new DAT_1d2e_00d2(0x30, 5, true);
			BYTE_1d2e_017c = 0;
			FUN_1b04_0500(0x46, 0x19, "Клюб ", 7);
		}
		// Draw City Level Objects
		if (BYTE_1d2e_334b == 1) {
			FUN_1b04_0487(0x1f, 8, 0x31, 0xe);
			FUN_1b04_0487(0x37, 0x11, 0x32, 0xc);
			FUN_1b04_0487(0x45, 8, 0x33, 1);
			if (BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_1529 - 0x0F][BYTE_1d2e_152a - 0x02] == '3') {
				BYTE_1d2e_1529 = BYTE_1d2e_1529 + 1;
			}
			else {
				BYTE_1d2e_1529 = BYTE_1d2e_1529 - 1;
			}
			BYTE_1d2e_152a = BYTE_1d2e_152a - 1;
			FUN_1b04_0487(BYTE_1d2e_1529, BYTE_1d2e_152a, 0x40, 7);
		}
	}
	// Pickup Items
	cVar19 = BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_1529 - 0x0F][BYTE_1d2e_152a - 0x02];
	// 0x21 - Random Bottle
	if (cVar19 == '!') {
		// FIXME: Impossible to spawn a Bottle of Ukrainian Beer!
		BYTE_1d2e_151e = Random(6) + 1;
		if (5 <= BYTE_1d2e_151e) {
			BYTE_1d2e_151e = BYTE_1d2e_151e + 10;
		}
		FUN_16d5_0158(BYTE_1d2e_151e);
	}
	// 0x2F - Stick or Club
	else if (cVar19 == '/') {
		FUN_16d5_0158(Random(2) + 7);
	}
	// 0x23 - BPSM Card
	else if (cVar19 == '#') {
		FUN_16d5_0158(10);
	}
	// 0x3F - Lyavon's Bottle of Beer
	else if (cVar19 == '?') {
		FUN_16d5_0158(6);
	}
	// 0x5C - DOOMGUY Chainsaw
	else if (cVar19 == '\\') {
		FUN_16d5_0158(9);
	}
	// 0x5B - N.R.M. Cassette
	else if (cVar19 == '[') {
		FUN_16d5_0158(0xb);
	}
	// 0x25 - Potion of Heroism
	else if (cVar19 == '%') {
		FUN_16d5_0158(0xc);
	}
	// 0x26 - Green Magic Charm
	else if (cVar19 == '&') {
		FUN_16d5_0158(0xd);
	}
	// 0x1F - Yellow Magic Charm
	else if (cVar19 == '\x1f') {
		FUN_16d5_0158(0xe);
	}
	// 0x1E - White-Red-White Magic Charm
	else if (cVar19 == '\x1e') {
		FUN_16d5_0158(0x11);
	}
	// Pickup Money
	if (BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_1529 - 0x0F][BYTE_1d2e_152a - 0x02] == '$') {
		BYTE_1d2e_331d = Random(0x14) + 5;
		SWORD_1d2e_3354 = BYTE_1d2e_331d + SWORD_1d2e_3354;
		Str(BYTE_1d2e_331d, 0, &P_STRING_1d2e_1288, 0xff);
		bVar7 = BYTE_1d2e_331d % 10;
		if ((bVar7 == 0) || ((5 <= bVar7) && (bVar7 <= 9)) ||
			(bVar7 = BYTE_1d2e_331d % 100, (11 <= bVar7) && (bVar7 <= 14))) {
			P_STRING_1d2e_1388 = " грошаў.";
		}
		else if (BYTE_1d2e_331d % 10 == 1) {
			P_STRING_1d2e_1388 = " грош.";
		}
		else {
			P_STRING_1d2e_1388 = " грошы.";
		}
		local_102 = "Лявон знайшоў ";
		Concat(local_102, P_STRING_1d2e_1288);
		Concat(local_102, P_STRING_1d2e_1388);
		FUN_16d5_0019(local_102);
		BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_1529 - 0x0F][BYTE_1d2e_152a - 0x02] = 0xfa;
	}
	// Update XP, HP & Money
	FUN_16d5_0000();
	FUN_1b04_0500(1, 0xc, "ВОПЫТУ:      ", 7);
	Str(WORD_1d2e_3352, 0, &P_STRING_1d2e_1288, 0xff);
	FUN_1b04_0500(0xb, 0xc, P_STRING_1d2e_1288, 7);
	FUN_1b04_0500(1, 0xd, "CHP   :      ", 7);
	Str(SWORD_1d2e_3356, 0, &P_STRING_1d2e_1288, 0xff);
	FUN_1b04_0500(0xb, 0xd, P_STRING_1d2e_1288, 7);
	FUN_1b04_0500(1, 0x14, "ГРОШЫ:", 7);
	Str(SWORD_1d2e_3354, 0, &P_STRING_1d2e_1288, 0xff);
	P_STRING_1d2e_1288.resize(4, ' ');
	FUN_1b04_0500(8, 0x14, P_STRING_1d2e_1288, 7);
	FUN_1b04_064b();
	// Spawn Bat'ka
	if ((1200 <= WORD_1d2e_3352) && (BYTE_1d2e_335c == 0) && (BYTE_1d2e_334b != 3) &&
		(BYTE_1d2e_1104 == 0)) {
		PTR_1d2e_148a = new DAT_1d2e_00be();
		BYTE_1d2e_335c = 1;
	}
	// Spawn Random Enemies
	if ((BYTE_1d2e_3348 < 7) && (BYTE_1d2e_334b != 3)) {
		do {
			PTR_1d2e_148a = FUN_12d2_3887();
		} while (PTR_1d2e_148a == NULL);
	}
	if ((BYTE_1d2e_334b == 3) && (3 <= BYTE_1d2e_017c)) {
		BYTE_1d2e_017c = 0;
		wVar10 = Random(100) % 0xc;
		if ((wVar10 == 1) || (wVar10 == 2) || (wVar10 == 3) || (wVar10 == 9)) {
			PTR_1d2e_148a = new DAT_1d2e_0096();
		}
		else if ((wVar10 == 4) || (wVar10 == 5) || (wVar10 == 6)) {
			PTR_1d2e_148a = new DAT_1d2e_006e();
		}
		else if (wVar10 == 7) {
			PTR_1d2e_148a = new DAT_1d2e_0046();
		}
		else if ((wVar10 == 10) || (wVar10 == 11) || (wVar10 == 0) || (wVar10 == 8)) {
			PTR_1d2e_148a = new DAT_1d2e_00aa();
		}
	}
LAB_1000_1805:
	// Player Input Handler
	FUN_1b04_0670();
	FUN_1b04_05b3(&BYTE_1d2e_331c, &BYTE_1d2e_331d);
	if ((BYTE_1d2e_331c != 1) && (BYTE_1d2e_331c != 0x11) &&
		(BYTE_1d2e_331c != 0x17) && (BYTE_1d2e_331c != 0x19) &&
		(BYTE_1d2e_331c != 0x22) && (BYTE_1d2e_331c != 0x25) &&
		(BYTE_1d2e_331c != 0x26) && (BYTE_1d2e_3328 != 0)) {
		if (Random(2) != 0) {
			do {
				// 0x47..0x51 - Movement Key Scancodes
				BYTE_1d2e_331c = Random(0xb) + 0x47;
			} while ((BYTE_1d2e_331c == 0x4a) || (BYTE_1d2e_331c == 0x4c) || (BYTE_1d2e_331c == 0x4e));
		}
	}
	// Player Movement Handler
	FUN_12d2_32f9();
	if ((BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_1529 - 0x0F][BYTE_1d2e_152a - 0x02] == 0xC4) && // 0xC4 - Turnstile
		(0x4f <= BYTE_1d2e_331c) && (BYTE_1d2e_331c <= 0x51)) { // 0x4F..0x51 - Move Down
		dVar15 = GetElemOffset(BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_1529 - 0x0F][BYTE_1d2e_152a - 0x02 + 1], 1, 0x20, 0);
		if ((BYTE_ARRAY_1d2e_015a[dVar15.second] & dVar15.first) == 0) {
			FUN_16d5_0019("Лявон прайшоў празь турнiкэт.");
			FUN_16d5_0019("А жэтону няма!");
			FUN_16d5_0019("ХЛАБЫСЬ! Лявона прышыбае турнiкэтам!");
			SWORD_1d2e_3356 = SWORD_1d2e_3356 - 15;
			if (SWORD_1d2e_3356 <= 0) {
				FUN_16d5_2e05("Прышлёпнуты", "турнiкэтам");
			}
			FUN_16d5_0019("Лявон здолеў-такi пралезьцi!");
			FUN_1b04_0487(BYTE_1d2e_1529, BYTE_1d2e_152a, BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_1529 - 0x0F][BYTE_1d2e_152a - 0x02], 7);
			FUN_16d5_0c6a(BYTE_1d2e_1529, BYTE_1d2e_152a);
			BYTE_1d2e_152a = BYTE_1d2e_152a + 1;
			FUN_1b04_0487(BYTE_1d2e_1529, BYTE_1d2e_152a, 0x40, 7);
		}
		else {
			FUN_1b04_0487(BYTE_1d2e_1529, BYTE_1d2e_152a, 0xc4, 7);
			BYTE_1d2e_152a = BYTE_1d2e_152a - 1;
			FUN_1b04_0487(BYTE_1d2e_1529, BYTE_1d2e_152a, 0x40, 7);
		}
	}
	// Use Artifact
	if ((BYTE_1d2e_331c == 0x19) && (BYTE_1d2e_331d == 0x70)) {
		if (BYTE_1d2e_334c == 6) {
			FUN_16d5_0019("Па тэксьце на бутэльцы Лявон засьпяваў \"Одзiрыдзiдзiну\"!");
			FUN_16d5_0019("Лявон адчуў прылiў моцы! Каму даць у дыню?");
			FUN_1b04_0670();
			FUN_1b04_05b3(&BYTE_1d2e_331c, &BYTE_1d2e_331d);
			WORD_1d2e_1496 = 1;
			while (true) {
				FUN_1b04_0487(WORD_1d2e_1496, 1, 0x20, 7);
				if (WORD_1d2e_1496 == 0x50) break;
				WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
			}
			FUN_16d5_0000();
			if (BYTE_1d2e_331c == 0x47) {
				FUN_12d2_27e7(-1, -1);
			}
			else if (BYTE_1d2e_331c == 0x48) {
				FUN_12d2_27e7(0, -1);
			}
			else if (BYTE_1d2e_331c == 0x49) {
				FUN_12d2_27e7(1, -1);
			}
			else if (BYTE_1d2e_331c == 0x4b) {
				FUN_12d2_27e7(-1, 0);
			}
			else if (BYTE_1d2e_331c == 0x4d) {
				FUN_12d2_27e7(1, 0);
			}
			else if (BYTE_1d2e_331c == 0x4f) {
				FUN_12d2_27e7(-1, 1);
			}
			else if (BYTE_1d2e_331c == 0x50) {
				FUN_12d2_27e7(0, 1);
			}
			else if (BYTE_1d2e_331c == 0x51) {
				FUN_12d2_27e7(1, 1);
			}
		} else if (BYTE_1d2e_334c == 0xb) {
			if (BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_1529 - 0x0F][BYTE_1d2e_152a - 0x02] == ']') { // 0x5D - Cassette Player
				FUN_16d5_0019("Лявон паставiў касэту...");
				if (BYTE_1d2e_1104 != 0) {
					FUN_16d5_0019("Усе гопнiкi дохнуць ад драйву!!!");
					FUN_16d5_0000();
					WORD_1d2e_1496 = 0xf;
					while (true) {
						FUN_1b04_0487(WORD_1d2e_1496, 2, 0xb1, 7);
						if (WORD_1d2e_1496 == 0x50) break;
						WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
					}
					WORD_1d2e_1496 = 3;
					while (true) {
						FUN_1b04_0487(0xf, WORD_1d2e_1496, 0xb1, 7);
						if (WORD_1d2e_1496 == 0x18) break;
						WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
					}
					WORD_1d2e_1496 = 0xf;
					while (true) {
						FUN_1b04_0487(WORD_1d2e_1496, 0x18, 0xb1, 7);
						if (WORD_1d2e_1496 == 0x50) break;
						WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
					}
					WORD_1d2e_1496 = 3;
					while (true) {
						FUN_1b04_0487(0x50, WORD_1d2e_1496, 0xb1, 7);
						if (WORD_1d2e_1496 == 0x18) break;
						WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
					}
					WORD_1d2e_1496 = 2;
					while (true) {
						FUN_1b04_0487(0x2c, WORD_1d2e_1496, 0xb1, 7);
						if (WORD_1d2e_1496 == 5) break;
						WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
					}
					WORD_1d2e_1496 = 2;
					while (true) {
						FUN_1b04_0487(0x34, WORD_1d2e_1496, 0xb1, 7);
						if (WORD_1d2e_1496 == 5) break;
						WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
					}
					WORD_1d2e_1496 = 0x2c;
					while (true) {
						FUN_1b04_0487(WORD_1d2e_1496, 7, 0xb1, 7);
						if (WORD_1d2e_1496 == 0x34) break;
						WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
					}
					local_4 = BYTE_1d2e_3348;
					if (local_4 != 0) {
						WORD_1d2e_1496 = 1;
						while (true) {
							delete PTR_1d2e_0156;
							FUN_1b04_0dc1(0x1e);
							if (WORD_1d2e_1496 == local_4) break;
							WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
						}
					}
					WORD_1d2e_3352 = WORD_1d2e_3352 + 200;
					BYTE_1d2e_1104 = 0;
				}
				else {
					FUN_16d5_0019("А гопнiкаў больш няма!");
				}
			}
			else {
				FUN_16d5_0019("Тут жа няма мафону!");
			}
		}
		else {
			FUN_16d5_0019("I што ты хочаш з гэтым рабiць?");
		}
	}
	// Show Inventory
	if ((BYTE_1d2e_331c == 0x17) || (BYTE_1d2e_331c == 0x37)) {
		FUN_16d5_32b4();
		goto LAB_1000_1805;
	}
	// Drink Potion or Beer
	if ((BYTE_1d2e_331c == 0x22) && (BYTE_1d2e_331d != 0)) {
		bVar6 = FUN_16d5_032d();
		if (!bVar6) goto LAB_1000_1805;
	}
	// Use Magic Charm
	if ((BYTE_1d2e_331c == 0x26) && (BYTE_1d2e_331d != 0)) {
		FUN_12d2_3c07();
		if ((BYTE_1d2e_334b != 1) || (BYTE_1d2e_335c != 0) || (WORD_1d2e_019e != 0)) {
			if (BYTE_1d2e_335e == 0x32) {
				FUN_16d5_0019("Вожыкi-нiньдзя спалохалiся!");
			}
			BYTE_1d2e_335e = 0;
		}
		if (BYTE_1d2e_335e == 0x32) {
			new (&DAT_ARRAY_1d2e_126a[0]) Ally(10, 0xa2, 0xf);
			new (&DAT_ARRAY_1d2e_126a[1]) Ally(10, 0xa2, 0xc);
			new (&DAT_ARRAY_1d2e_126a[2]) Ally(10, 0xa2, 0xf);
			FUN_16d5_0019("З каналiзацыйных люкаў зьяўляюцца вожыкi - нiньдзя!");
		}
	}
	// Show Message Log
	if ((BYTE_1d2e_331c == 0x3b) && (BYTE_1d2e_331d == 0)) {
		FUN_16d5_0950("mnskbnd2.dat");
		goto LAB_1000_1805;
	}
	// Show Help Screen
	if ((BYTE_1d2e_331c == 0x32) || (BYTE_1d2e_331d == 0x6d) ||
		(BYTE_1d2e_331c == 0) || (BYTE_1d2e_331d == 0xec)) {
		FUN_16d5_0950("");
		goto LAB_1000_1805;
	}
	// Equip Item
	if (BYTE_1d2e_331c == 0x11) {
		bVar6 = FUN_16d5_149e();
		if (!bVar6) goto LAB_1000_1805;
	}
	// Throw Item
	if ((BYTE_1d2e_331d == 0x6b) || (BYTE_1d2e_331d == 0x4b)) {
		bVar6 = FUN_12d2_2bfd();
		if (!bVar6) goto LAB_1000_1805;
	}
	// Exit Game
	if (BYTE_1d2e_331c == 1) {
		FUN_1b04_0500(1, 1, "Захаваць гульню ды выйсьцi? [y / n]", 7);
		FUN_1b04_05b3(&BYTE_1d2e_331c, &BYTE_1d2e_331d);
		if (BYTE_1d2e_331c == 0x15) goto LAB_1000_2844;
		FUN_1b04_0500(1, 1, "                                    ", 7);
		goto LAB_1000_1805;
	}
	// Enter Subway
	if ((BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_1529 - 0x0F][BYTE_1d2e_152a - 0x02] == '>') && // > - Key Scancode
		(BYTE_1d2e_331c == 0x34) && (BYTE_1d2e_331d == 0x3e)) {
		FUN_16d5_0019("Лявон пайшоў у метро.");
		FUN_16d5_0019("");
		BYTE_1d2e_335e = 0;
		local_4 = BYTE_1d2e_3348;
		if (local_4 != 0) {
			WORD_1d2e_1496 = 1;
			while (true) {
				delete PTR_1d2e_0156;
				if (WORD_1d2e_1496 == local_4) break;
				WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
			}
		}
		BYTE_1d2e_3348 = 0;
		if ((sbyte)WORD_1d2e_1526 >= 0) {
			BYTE_1d2e_1528 = 0;
		}
		else {
			BYTE_1d2e_1528 = 1;
		}
		FUN_16d5_25d9(2);
		PTR_1d2e_148a = new DAT_1d2e_005a(0x29, 8, true);
		PTR_1d2e_148a = new DAT_1d2e_005a(0x2a, 8, true);
		PTR_1d2e_148a = new DAT_1d2e_005a(0x29, 9, true);
		PTR_1d2e_148a = new DAT_1d2e_005a(0x2a, 9, true);
		if (BYTE_1d2e_1528 == 0) {
			BYTE_ARRAY_ARRAY_1d2e_152c[0x11][0x10] = 0xfa;
			BYTE_ARRAY_ARRAY_1d2e_152c[0x21][0x10] = 0xfa;
			BYTE_ARRAY_ARRAY_1d2e_152c[0x30][0x10] = 0xfa;
		}
		BYTE_1d2e_334b = 2;
		FUN_16d5_0f6c();
		PTR_1d2e_148e = PTR_1d2e_0156;
		while (true) {
			if (PTR_1d2e_148e == NULL) break;
			PTR_1d2e_148e->DrawSymbol();
			PTR_1d2e_148e = PTR_1d2e_148e->pNext;
		}
		FUN_1b04_0500(0x46, 0x19, "Метро", 7);
	}
	// Enter the City
	if ((BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_1529 - 0x0F][BYTE_1d2e_152a - 0x02] == '<') && // < - Key Scancode
		(BYTE_1d2e_331c == 0x33) && (BYTE_1d2e_331d == 0x3c)) {
		if (BYTE_1d2e_334b == 3) {
			FUN_16d5_0019("Лявон выйшаў з клюбу.");
		}
		else {
			FUN_16d5_0019("Лявон выйшаў зь метро.");
		}
		local_4 = BYTE_1d2e_3348;
		if (local_4 != 0) {
			WORD_1d2e_1496 = 1;
			while (true) {
				delete PTR_1d2e_0156;
				if (WORD_1d2e_1496 == local_4) break;
				WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
			}
		}
		BYTE_1d2e_3348 = 0;
		BYTE_1d2e_335c = 0;
		FUN_16d5_25d9(1);
		if (BYTE_1d2e_334b == 3) {
			BYTE_1d2e_1529 = 0x46;
			BYTE_1d2e_152a = 7;
		}
		else {
			BYTE_1d2e_1529 = 0x4e;
			BYTE_1d2e_152a = 0x16;
		}
		BYTE_1d2e_334b = 1;
		FUN_16d5_0f6c();
		PTR_1d2e_148e = PTR_1d2e_0156;
		while (true) {
			if (PTR_1d2e_148e == NULL) break;
			PTR_1d2e_148e->DrawSymbol();
			PTR_1d2e_148e = PTR_1d2e_148e->pNext;
		}
		FUN_1b04_0500(0x46, 0x19, "Менск", 7);
	}
	// Update Drunkenness Status
	SWORD_1d2e_334e = SWORD_1d2e_334e + 1;
	FUN_16d5_2c2c();
	// Spawn Green Imps
	if (BYTE_1d2e_3349 == 0xff) {
		BYTE_1d2e_3349 = 3;
		WORD_1d2e_1496 = 1;
		while (true) {
			PTR_1d2e_148a = new DAT_1d2e_000a();
			if (WORD_1d2e_1496 == 3) break;
			WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
		}
	}
	// Enemy AI Handler
	PTR_1d2e_148e = PTR_1d2e_0156;
	while (true) {
		if (PTR_1d2e_148e == NULL) break;
		PTR_1d2e_148e->AiThink();
		PTR_1d2e_148e = PTR_1d2e_148e->pNext;
	}
	// Hedgehog Ninjas AI Handler
	if (BYTE_1d2e_335e != 0) {
		if ((BYTE_1d2e_3349 == 0) && (BYTE_1d2e_335c == 0)) {
			WORD_1d2e_1496 = 1;
			while (true) {
				DAT_ARRAY_1d2e_126a[WORD_1d2e_1496 - 0x01].AiThink();
				if (WORD_1d2e_1496 == 3) break;
				WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
			}
		}
		BYTE_1d2e_335e = BYTE_1d2e_335e - 1;
		if (BYTE_1d2e_3349 != 0) {
			BYTE_1d2e_335e = 0;
		}
		if (BYTE_1d2e_335c != 0) {
			BYTE_1d2e_335e = 0;
		}
		if (BYTE_1d2e_335e == 0) {
			FUN_16d5_0019("Вожыкi - нiньдзя хаваюцца ў люкi");
			WORD_1d2e_1496 = 1;
			while (true) {
				DAT_ARRAY_1d2e_126a[WORD_1d2e_1496 - 0x01].~Ally();
				if (WORD_1d2e_1496 == 3) break;
				WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
			}
		}
	}
	// Update HP & Max HP
	if (BYTE_1d2e_335d == 1) {
		SWORD_1d2e_3356 = SWORD_1d2e_3350;
	}
	if ((SWORD_1d2e_3356 < 0) || (SWORD_1d2e_3356 < SWORD_1d2e_3350)) {
		SWORD_1d2e_3356 = SWORD_1d2e_3356 + 1;
	}
	if (60 < WORD_1d2e_3352) {
		SWORD_1d2e_3350 = 30;
	}
	if (160 < WORD_1d2e_3352) {
		SWORD_1d2e_3350 = 100;
	}
	if (380 < WORD_1d2e_3352) {
		SWORD_1d2e_3350 = 150;
	}
	if (600 < WORD_1d2e_3352) {
		SWORD_1d2e_3350 = 200;
	}
	if (1200 < WORD_1d2e_3352) {
		SWORD_1d2e_3350 = 300;
	}
	FUN_1b04_0500(1, 0xe, "MHP   :     ", 7);
	Str(SWORD_1d2e_3350, 0, &P_STRING_1d2e_1288, 0xff);
	FUN_1b04_0500(0xb, 0xe, P_STRING_1d2e_1288, 7);
	FUN_1b04_064b();
	WORD_1d2e_1526 = WORD_1d2e_1526 + 1;
	// Visual Glitches Handler
	if (BYTE_1d2e_3329 != 0) {
		// Glitches Cleanup
		WORD_1d2e_1496 = 1;
		while (true) {
			local_3 = BYTE_ARRAY_1d2e_3324[WORD_1d2e_1496 - 0x01] + 2;
			if (BYTE_ARRAY_1d2e_3324[WORD_1d2e_1496 - 0x01] <= local_3) {
				BYTE_1d2e_1499 = BYTE_ARRAY_1d2e_3324[WORD_1d2e_1496 - 0x01];
				while (true) {
					local_4 = BYTE_ARRAY_1d2e_3320[WORD_1d2e_1496 - 0x01] + 2;
					if (BYTE_ARRAY_1d2e_3320[WORD_1d2e_1496 - 0x01] <= local_4) {
						BYTE_1d2e_1498 = BYTE_ARRAY_1d2e_3320[WORD_1d2e_1496 - 0x01];
						while (true) {
							if ((BYTE_1d2e_334b != 2) || (BYTE_1d2e_1528 == 0) ||
								((BYTE_1d2e_1528 == 1) && (BYTE_1d2e_1499 <= 0x12)) ||
								((BYTE_1d2e_1528 == 2) && (0x12 <= BYTE_1d2e_1499))) {
								FUN_1b04_0487(BYTE_1d2e_1498, BYTE_1d2e_1499,
									BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_1498 - 0x0F][BYTE_1d2e_1499 - 0x02], 7);
								FUN_16d5_0c6a(BYTE_1d2e_1498, BYTE_1d2e_1499);
							}
							if ((BYTE_1d2e_1498 == BYTE_1d2e_1529) &&
								(BYTE_1d2e_1499 == BYTE_1d2e_152a)) {
								FUN_1b04_0487(BYTE_1d2e_1498, BYTE_1d2e_1499, 0x40, 7);
							}
							if (BYTE_1d2e_1498 == local_4) break;
							BYTE_1d2e_1498 = BYTE_1d2e_1498 + 1;
						}
					}
					if (BYTE_1d2e_1499 == local_3) break;
					BYTE_1d2e_1499 = BYTE_1d2e_1499 + 1;
				}
			}
			if (WORD_1d2e_1496 == 3) break;
			WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
		}
		PTR_1d2e_148e = PTR_1d2e_0156;
		while (true) {
			if (PTR_1d2e_148e == NULL) break;
			PTR_1d2e_148e->DrawSymbol();
			PTR_1d2e_148e = PTR_1d2e_148e->pNext;
		}
		FUN_1b04_0500(1, 2, "Лявон - ", 7);
		if (BYTE_1d2e_334b == 1) {
			if (BYTE_1d2e_1104 == 0) {
				FUN_1b04_0500(0x3a, 5, "           ", 0xf0);
				FUN_1b04_0500(0x3a, 6, "           ", 0xc0);
				FUN_1b04_0500(0x3a, 7, "           ", 0xf0);
			}
			else {
				FUN_1b04_0487(0x39, 5, 0x8a, 7);
				FUN_1b04_0487(0x39, 6, 0x8b, 7);
				FUN_1b04_0487(0x39, 7, 0x93, 7);
				FUN_1b04_0487(0x39, 8, 0x81, 7);
				FUN_1b04_0500(0x3c, 6, "РЕАКТОР", 1);
			}
		}
		// Draw Glitches
		if (BYTE_1d2e_334b != 2) {
			BYTE_1d2e_1528 = 0;
		}
		WORD_1d2e_1496 = 1;
		while (true) {
			BYTE_ARRAY_1d2e_3320[WORD_1d2e_1496 - 0x01] = Random(0x3f) + 0x10;
			if (BYTE_1d2e_1528 == 0) {
				BYTE_ARRAY_1d2e_3324[WORD_1d2e_1496 - 0x01] = Random(0x15) + 0x02;
			}
			else if (BYTE_1d2e_1528 == 1) {
				BYTE_ARRAY_1d2e_3324[WORD_1d2e_1496 - 0x01] = Random(0xf) + 0x02;
			}
			else if (BYTE_1d2e_1528 == 2) {
				BYTE_ARRAY_1d2e_3324[WORD_1d2e_1496 - 0x01] = Random(5) + 0x12;
			}
			BYTE_1d2e_149b = Random(0xf) + 1;
			BYTE_1d2e_149a = 0xc5;
			local_3 = BYTE_ARRAY_1d2e_3324[WORD_1d2e_1496 - 0x01] + 2;
			if (BYTE_ARRAY_1d2e_3324[WORD_1d2e_1496 - 0x01] <= local_3) {
				BYTE_1d2e_1499 = BYTE_ARRAY_1d2e_3324[WORD_1d2e_1496 - 0x01];
				while (true) {
					local_4 = BYTE_ARRAY_1d2e_3320[WORD_1d2e_1496 - 0x01] + 2;
					if (BYTE_ARRAY_1d2e_3320[WORD_1d2e_1496 - 0x01] <= local_4) {
						BYTE_1d2e_1498 = BYTE_ARRAY_1d2e_3320[WORD_1d2e_1496 - 0x01];
						while (true) {
							FUN_1b04_0487(BYTE_1d2e_1498, BYTE_1d2e_1499, BYTE_1d2e_149a, BYTE_1d2e_149b);
							BYTE_1d2e_149a = BYTE_1d2e_149a + 1;
							if (BYTE_1d2e_1498 == local_4) break;
							BYTE_1d2e_1498 = BYTE_1d2e_1498 + 1;
						}
					}
					if (BYTE_1d2e_1499 == local_3) break;
					BYTE_1d2e_1499 = BYTE_1d2e_1499 + 1;
				}
			}
			BYTE_1d2e_331e = BYTE_1d2e_331e - 1;
			if (WORD_1d2e_1496 == 3) break;
			WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
		}
		// Glitches Cleanup
		if (BYTE_1d2e_331e == 0) {
			BYTE_1d2e_3329 = 0;
			FUN_16d5_0019("Ху-у-у! Скончылiся глюкi!");
			WORD_1d2e_1496 = 1;
			while (true) {
				local_3 = BYTE_ARRAY_1d2e_3324[WORD_1d2e_1496 - 0x01] + 2;
				if (BYTE_ARRAY_1d2e_3324[WORD_1d2e_1496 - 0x01] <= local_3) {
					BYTE_1d2e_1499 = BYTE_ARRAY_1d2e_3324[WORD_1d2e_1496 - 0x01];
					while (true) {
						local_4 = BYTE_ARRAY_1d2e_3320[WORD_1d2e_1496 - 0x01] + 2;
						if (BYTE_ARRAY_1d2e_3320[WORD_1d2e_1496 - 0x01] <= local_4) {
							BYTE_1d2e_1498 = BYTE_ARRAY_1d2e_3320[WORD_1d2e_1496 - 0x01];
							while (true) {
								if ((BYTE_1d2e_334b != 2) || (BYTE_1d2e_1528 == 0) ||
									((BYTE_1d2e_1528 == 1) && (BYTE_1d2e_1499 <= 0x12)) ||
									((BYTE_1d2e_1528 == 2) && (0x12 <= BYTE_1d2e_1499))) {
									FUN_1b04_0487(BYTE_1d2e_1498, BYTE_1d2e_1499,
										BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_1498 - 0x0F][BYTE_1d2e_1499 - 0x02], 7);
									FUN_16d5_0c6a(BYTE_1d2e_1498, BYTE_1d2e_1499);
								}
								if ((BYTE_1d2e_1498 == BYTE_1d2e_1529) &&
									(BYTE_1d2e_1499 == BYTE_1d2e_152a)) {
									FUN_1b04_0487(BYTE_1d2e_1498, BYTE_1d2e_1499, 0x40, 7);
								}
								if (BYTE_1d2e_1498 == local_4) break;
								BYTE_1d2e_1498 = BYTE_1d2e_1498 + 1;
							}
						}
						if (BYTE_1d2e_1499 == local_3) break;
						BYTE_1d2e_1499 = BYTE_1d2e_1499 + 1;
					}
				}
				if (WORD_1d2e_1496 == 3) break;
				WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
			}
			if (BYTE_1d2e_334b == 1) {
				if (BYTE_1d2e_1104 == 0) {
					FUN_1b04_0500(0x3a, 5, "           ", 0xf0);
					FUN_1b04_0500(0x3a, 6, "           ", 0xc0);
					FUN_1b04_0500(0x3a, 7, "           ", 0xf0);
				}
				else {
					FUN_1b04_0487(0x39, 5, 0x8a, 7);
					FUN_1b04_0487(0x39, 6, 0x8b, 7);
					FUN_1b04_0487(0x39, 7, 0x93, 7);
					FUN_1b04_0487(0x39, 8, 0x81, 7);
					FUN_1b04_0500(0x3c, 6, "РЕАКТОР", 1);
				}
			}
			while (true) {
				if (PTR_1d2e_148e == NULL) break;
				PTR_1d2e_148e->DrawSymbol();
				PTR_1d2e_148e = PTR_1d2e_148e->pNext;
			}
		}
	}
	// Refresh Pub Goods
	if ((WORD_1d2e_1526 & 0x1ff) == 0) {
		FUN_16d5_24c7();
	}
	// Update Subway Station
	if (BYTE_1d2e_334b == 2) {
		if (BYTE_1d2e_1528 != 0) {
			if ((WORD_1d2e_1526 & 0x7f) == 0) {
				BYTE_1d2e_1528 = 0;
				BYTE_ARRAY_ARRAY_1d2e_152c[0x11][0x10] = 0xfa;
				BYTE_ARRAY_ARRAY_1d2e_152c[0x21][0x10] = 0xfa;
				BYTE_ARRAY_ARRAY_1d2e_152c[0x30][0x10] = 0xfa;
				FUN_16d5_0f6c();
				PTR_1d2e_148e = PTR_1d2e_0156;
				while (true) {
					if (PTR_1d2e_148e == NULL) break;
					if (PTR_1d2e_148e->ypos == 0x12) {
						PTR_1d2e_148e->ypos = 0x11;
					}
					PTR_1d2e_148e->DrawSymbol();
					PTR_1d2e_148e = PTR_1d2e_148e->pNext;
				}
			}
		}
		else {
			if ((WORD_1d2e_1526 & 0x1f) == 0) {
				BYTE_ARRAY_ARRAY_1d2e_152c[0x11][0x10] = 0xb1;
				BYTE_ARRAY_ARRAY_1d2e_152c[0x21][0x10] = 0xb1;
				BYTE_ARRAY_ARRAY_1d2e_152c[0x30][0x10] = 0xb1;
				if (BYTE_1d2e_152a == 0x12) {
					BYTE_1d2e_152a = 0x11;
				}
				if (BYTE_1d2e_152a < 0x12) {
					BYTE_1d2e_1528 = 1;
				}
				else {
					BYTE_1d2e_1528 = 2;
				}
				FUN_16d5_0f6c();
				PTR_1d2e_148e = PTR_1d2e_0156;
				while (true) {
					if (PTR_1d2e_148e == NULL) break;
					if (PTR_1d2e_148e->ypos == 0x12) {
						PTR_1d2e_148e->ypos = 0x11;
					}
					PTR_1d2e_148e->DrawSymbol();
					PTR_1d2e_148e = PTR_1d2e_148e->pNext;
				}
			}
		}
	}
	if (BYTE_1d2e_149c == 0) {
		goto LAB_1000_0f7f;
	}
LAB_1000_2844:
	// Save Game
	Assign(FILE_1d2e_149e, "menskbnd.sav");
	Rewrite(FILE_1d2e_149e, 1);
	P_STRING_1d2e_1288 = "MBSF";
	BlockWrite(FILE_1d2e_149e, (byte*)P_STRING_1d2e_1288.c_str(), 4, NULL);
	BlockWrite(FILE_1d2e_149e, &BYTE_1d2e_1529, 1, NULL);
	BlockWrite(FILE_1d2e_149e, &BYTE_1d2e_152a, 1, NULL);
	BlockWrite(FILE_1d2e_149e, (byte*)&WORD_1d2e_3352, 2, NULL);
	BlockWrite(FILE_1d2e_149e, (byte*)&SWORD_1d2e_3356, 2, NULL);
	BlockWrite(FILE_1d2e_149e, (byte*)&SWORD_1d2e_3354, 2, NULL);
	BlockWrite(FILE_1d2e_149e, (byte*)&SWORD_1d2e_334e, 2, NULL);
	BlockWrite(FILE_1d2e_149e, (byte*)&SBYTE_1d2e_3327, 1, NULL);
	BlockWrite(FILE_1d2e_149e, &BYTE_1d2e_334b, 1, NULL);
	BlockWrite(FILE_1d2e_149e, &BYTE_1d2e_1104, 1, NULL);
	BlockWrite(FILE_1d2e_149e, &BYTE_1d2e_1528, 1, NULL);
	BlockWrite(FILE_1d2e_149e, (byte*)&WORD_1d2e_1526, 2, NULL);
	BlockWrite(FILE_1d2e_149e, &BYTE_1d2e_3328, 1, NULL);
	BlockWrite(FILE_1d2e_149e, &BYTE_1d2e_017c, 1, NULL);
	BlockWrite(FILE_1d2e_149e, &BYTE_1d2e_3329, 1, NULL);
	BlockWrite(FILE_1d2e_149e, &BYTE_1d2e_331e, 1, NULL);
	BlockWrite(FILE_1d2e_149e, &BYTE_1d2e_335e, 1, NULL);
	BlockWrite(FILE_1d2e_149e, (byte*)&DAT_ARRAY_1d2e_126a, 0x1e, NULL);
	WORD_1d2e_1496 = 0xf;
	while (true) {
		BYTE_1d2e_331b = 2;
		while (BYTE_ARRAY_ARRAY_1d2e_152c[WORD_1d2e_1496 - 0x0F][BYTE_1d2e_331b - 0x02] =
			BYTE_ARRAY_ARRAY_1d2e_152c[WORD_1d2e_1496 - 0x0F][BYTE_1d2e_331b - 0x02] ^ 0xce ^
			BYTE_1d2e_331b & WORD_1d2e_1496, BYTE_1d2e_331b != 0x18) {
			BYTE_1d2e_331b = BYTE_1d2e_331b + 1;
		}
		if (WORD_1d2e_1496 == 0x50) break;
		WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
	}
	BlockWrite(FILE_1d2e_149e, (byte*)BYTE_ARRAY_ARRAY_1d2e_152c, 0x5ee, NULL);
	BlockWrite(FILE_1d2e_149e, &BYTE_1d2e_3346, 1, NULL);
	local_4 = BYTE_1d2e_3346;
	if (local_4 != 0) {
		WORD_1d2e_1496 = 1;
		while (true) {
			BlockWrite(FILE_1d2e_149e, &BYTE_ARRAY_1d2e_332a[WORD_1d2e_1496 - 0x01], 1, NULL);
			if (WORD_1d2e_1496 == local_4) break;
			WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
		}
	}
	BlockWrite(FILE_1d2e_149e, &BYTE_1d2e_3347, 1, NULL);
	BlockWrite(FILE_1d2e_149e, (byte*)BYTE_ARRAY_ARRAY_1d2e_3336, 0x10, NULL);
	WORD_1d2e_1496 = 1;
	while (true) {
		BlockWrite(FILE_1d2e_149e, &BYTE_ARRAY_1d2e_0362[WORD_1d2e_1496 - 0x01], 1, NULL);
		if (WORD_1d2e_1496 == 4) break;
		WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
	}
	BlockWrite(FILE_1d2e_149e, &BYTE_1d2e_334c, 1, NULL);
	BlockWrite(FILE_1d2e_149e, &BYTE_1d2e_3348, 1, NULL);
	PTR_1d2e_148e = PTR_1d2e_0156;
	while (true) {
		if (PTR_1d2e_148e == NULL) break;
		BlockWrite(FILE_1d2e_149e, &PTR_1d2e_148e->index, 1, NULL);
		BlockWrite(FILE_1d2e_149e, &PTR_1d2e_148e->xpos, 1, NULL);
		BlockWrite(FILE_1d2e_149e, &PTR_1d2e_148e->ypos, 1, NULL);
		BlockWrite(FILE_1d2e_149e, (byte*)&PTR_1d2e_148e->hp, 2, NULL);
		PTR_1d2e_148e = PTR_1d2e_148e->pNext;
	}
	BlockWrite(FILE_1d2e_149e, &BYTE_1d2e_334a, 1, NULL);
	local_4 = BYTE_1d2e_334a;
	if (local_4 != 0) {
		WORD_1d2e_1496 = 1;
		while (true) {
			P_STRING_1d2e_1288 = DAT_1d2E_1b1a[WORD_1d2e_1496 - 0x01];
			local_5 = P_STRING_1d2e_1288.size();
			BlockWrite(FILE_1d2e_149e, &local_5, 1, NULL);
			if (local_5 != 0) {
				BYTE_1d2e_331b = 1;
				while (true) {
					P_STRING_1d2e_1288[BYTE_1d2e_331b - 1] =
						P_STRING_1d2e_1288[BYTE_1d2e_331b - 1] ^ 0xce;
					BlockWrite(FILE_1d2e_149e,
						(byte*)&P_STRING_1d2e_1288[BYTE_1d2e_331b - 1], 1, NULL);
					if (BYTE_1d2e_331b == local_5) break;
					BYTE_1d2e_331b = BYTE_1d2e_331b + 1;
				}
			}
			if (WORD_1d2e_1496 == local_4) break;
			WORD_1d2e_1496 = WORD_1d2e_1496 + 1;
		}
	}
	if (BYTE_1d2e_335d == 1) {
		P_STRING_1d2e_1288[0] = '!';
	}
	else {
		P_STRING_1d2e_1288[0] = '0';
	}
	BlockWrite(FILE_1d2e_149e, (byte*)&P_STRING_1d2e_1288[0], 1, NULL);
	Close(FILE_1d2e_149e);
	FUN_1b04_0234();
	Console.ResetBuffer();
	Halt(0);
	return;
}

/*
	Collision Check
*/
bool __pascal16near FUN_12d2_0000(byte xpos, byte ypos)
{
	std::pair<byte, word> dVar1;
	bool local_3;

	__StackCheck(2);
	dVar1 = GetElemOffset(BYTE_ARRAY_ARRAY_1d2e_152c[xpos - 0x0F][ypos - 0x02], 1, 0x20, 0);
	if (((BYTE_ARRAY_1d2e_017e[dVar1.second] & dVar1.first) == 0) ||
		((xpos == BYTE_1d2e_1529) && (ypos == BYTE_1d2e_152a))) {
		local_3 = false;
	}
	else {
		local_3 = true;
	}
	return local_3;
}

/*
	Use Lyavon's Bottle of Beer
*/
void __pascal16far FUN_12d2_27e7(sbyte dx, sbyte dy)
{
	bool bVar2;
	byte bVar3;
	uint uVar4;
	uint uVar5;
	undefined2 unaff_SS;
	std::pair<byte, word> dVar6;
	undefined uVar7;
	undefined uVar8;
	PascalString255* pPVar9;
	PascalString255 local_30c;
	PascalString255 local_20c;
	PascalString255 local_10c;
	Enemy* local_c;
	bool local_7;
	byte local_6;
	byte local_4;
	byte local_3;

	__StackCheck(0x30a);
	local_3 = BYTE_1d2e_1529 + dx;
	local_4 = BYTE_1d2e_152a + dy;
	local_6 = 7;
	local_7 = false;
	do {
		local_c = PTR_1d2e_0156;
		while (true) {
			if ((local_c == NULL) ||
				((local_c->xpos == local_3) && (local_c->ypos == local_4))) {
				break;
			}
			local_c = local_c->pNext;
		}
		if (local_c != NULL) {
			local_c->hp = local_c->hp - 10;
			if (local_c->hp < 0) {
				local_c->hp = 0;
			}
			local_7 = true;
			bVar3 = local_c->hp % 10;
			if ((bVar3 == 0) || ((5 <= bVar3) && (bVar3 <= 9)) ||
				(bVar3 = local_c->hp % 100, (11 <= bVar3) && (bVar3 <= 14))) {
				local_20c = " хiтоў.";
			}
			else if (local_c->hp % 10 == 1) {
				local_20c = " хiт.";
			}
			else {
				local_20c = " хiты.";
			}
			Str(local_c->hp, 0, (PascalString255*)BYTE_ARRAY_1d2e_3358, 3);
			if (local_c->hp == 0) {
				local_10c = "вырубiў яго.";
			}
			else {
				local_30c = "пакiнуў яму ";
				Concat(local_30c, (PascalString255&)BYTE_ARRAY_1d2e_3358);
				Concat(local_30c, local_20c);
				local_10c = local_30c;
			}
			local_30c = "Лявон трапiў у ";
			Concat(local_30c, P_STRING__ARRAY_1d2e_0832[local_c->index - 0x01]);
			Concat(local_30c, " ды ");
			Concat(local_30c, local_10c);
			FUN_16d5_0019(local_30c);
			if (local_c->hp == 0) {
				BYTE_1d2e_017c = BYTE_1d2e_017c + 1;
				delete local_c;
			}
		}
		else {
			local_6 = Console.ReadAttribute(local_3, local_4);
			FUN_1b04_0487(local_3, local_4, 0x2a, 0xb);
			FUN_1b04_0dc1(0x14);
			FUN_1b04_0487(BYTE_1d2e_1529, BYTE_1d2e_152a, 0x40, 7);
			if ((8 < std::abs(local_3 - BYTE_1d2e_1529)) ||
				(8 < std::abs(local_4 - BYTE_1d2e_152a))) {
				local_7 = true;
			}
			FUN_1b04_0487(local_3, local_4,
				BYTE_ARRAY_ARRAY_1d2e_152c[local_3 - 0x0F][local_4 - 0x02], local_6);
			local_3 = local_3 + dx;
			local_4 = local_4 + dy;
		}
		dVar6 = GetElemOffset(BYTE_ARRAY_ARRAY_1d2e_152c[local_3 + dx - 0x0F][local_4 + dy - 0x02], 1, 0x20, 0);
	} while ((((BYTE_ARRAY_1d2e_017e[dVar6.second] & dVar6.first) != 0) ||
		(dVar6 = GetElemOffset(BYTE_ARRAY_ARRAY_1d2e_152c[local_3 + dx - 0x0F][local_4 + dy - 0x02], 1, 0x20, 0),
			(BYTE_ARRAY_1d2e_015a[dVar6.second] & dVar6.first) != 0)) && (!local_7));
	FUN_1b04_064b();
	return;
}

/*
	Throw Item
*/
bool __pascal16far FUN_12d2_2bfd(void)
{
	byte abVar1[2];
	int iVar3;
	bool bVar4;
	byte bVar5;
	byte bVar6;
	byte bVar7;
	word wVar8;
	uint uVar9;
	uint uVar10;
	undefined2 unaff_SS;
	std::pair<byte, word> dVar11;
	byte* pbVar12;
	undefined uVar13;
	undefined uVar14;
	undefined uVar15;
	undefined uVar16;
	undefined4 uVar17;
	PascalString255* pPVar18;
	PascalString255 local_d7e;
	PascalString255 local_d7c;
	byte local_c7d;
	byte local_c7c;
	byte local_c7b;
	word local_c7a;
	byte local_c79;
	byte local_c78;
	byte local_c76;
	byte local_c75;
	PascalString255 local_c74;
	PascalString255 local_b74;
	PascalString255 local_a74;
	Enemy* local_974;
	bool local_96f;
	byte local_96e[2400];
	sword local_e;
	sword local_c;
	byte local_9;
	byte local_8;
	byte local_7;
	byte local_5;
	byte local_4;
	bool local_3;

	__StackCheck(0xd7c);
	Console.SaveBuffer(0, 0, 80, 15);
	if (BYTE_1d2e_3346 == 0) {
		FUN_16d5_0019("Няма ж чым кiдацца!");
		local_3 = false;
	}
	else {
		FUN_1b04_0500(1, 1, " Чым кiдацца будзем?", 7);
		local_c7d = BYTE_1d2e_3346;
		if (local_c7d != 0) {
			local_4 = 1;
			while (true) {
				local_8 = 0x1e;
				while (FUN_1b04_0487(local_8, local_4 + 1, 0x20, 0), local_8 != 0x50) {
					local_8 = local_8 + 1;
				}
				local_d7e = P_STRING_ARRAY_1d2e_0340[local_4];
				Concat(local_d7e, ") ");
				Concat(local_d7e, P_STRING__ARRAY_1d2e_0366[BYTE_ARRAY_1d2e_332a[local_4 - 0x01] - 0x01]);
				FUN_1b04_0500(0x1e, local_4 + 1, local_d7e, 7);
				if (local_4 == local_c7d) break;
				local_4 = local_4 + 1;
			}
		}
		do {
			FUN_1b04_0670();
			FUN_1b04_05b3(&local_8, &local_9);
			if (local_8 == 1) {
				Console.RestoreBuffer(0, 0, 80, 15);
				local_3 = false;
				goto LAB_12d2_32f1;
			}
		} while ((local_9 <= 0x30) || ((BYTE_1d2e_3346 + 0x31) <= local_9));
		local_c7b = BYTE_ARRAY_1d2e_332a[local_9 - 0x30 - 0x01];
		local_c78 = BYTE_ARRAY_ARRAY_1d2e_10e2[local_c7b - 0x01][0];
		local_c79 = BYTE_ARRAY_ARRAY_1d2e_10e2[local_c7b - 0x01][1];
		local_c7a = local_c79 * (Random(local_c78) + 1);
		Console.RestoreBuffer(0, 0, 80, 15);
		FUN_16d5_0019("Каму ўмазаць?");
		FUN_1b04_0670();
		FUN_1b04_05b3(&local_c75, &local_c76);
		local_4 = 1;
		while (FUN_1b04_0487(local_4, 1, 0x20, 7), local_4 != 0x50) {
			local_4 = local_4 + 1;
		}
		FUN_16d5_0000();
		if (local_c75 == 0x47) {
			local_c = -1;
			local_e = -1;
			local_c7c = '\\';
		}
		else if (local_c75 == 0x48) {
			local_c = 0;
			local_e = -1;
			local_c7c = '|';
		}
		else if (local_c75 == 0x49) {
			local_c = 1;
			local_e = -1;
			local_c7c = '/';
		}
		else if (local_c75 == 0x4b) {
			local_c = -1;
			local_e = 0;
			local_c7c = '-';
		}
		else if (local_c75 == 0x4d) {
			local_c = 1;
			local_e = 0;
			local_c7c = '-';
		}
		else if (local_c75 == 0x4f) {
			local_c = -1;
			local_e = 1;
			local_c7c = '/';
		}
		else if (local_c75 == 0x50) {
			local_c = 0;
			local_e = 1;
			local_c7c = '|';
		}
		else if (local_c75 == 0x51) {
			local_c = 1;
			local_e = 1;
			local_c7c = '\\';
		}
		else {
			local_3 = false;
			goto LAB_12d2_32f1;
		}
		local_c7d = BYTE_1d2e_3346;
		if (local_9 - 0x30 <= local_c7d) {
			for (local_4 = local_9 - 0x30; BYTE_ARRAY_1d2e_332a[local_4 - 0x01] = BYTE_ARRAY_1d2e_332a[local_4],
				local_4 != local_c7d; local_4 = local_4 + 1) {
			}
		}
		BYTE_1d2e_3346 = BYTE_1d2e_3346 - 1;
		// FIXME: Consider Item Name (Accusative Case) string table usage!
		if (local_c7b == 7) {
			local_b74 = "дубiну [2ды4]";
		}
		else {
			local_b74 = P_STRING_ARRAY_1d2e_0d3c[local_c7b - 0x01];
		}
		local_d7c = "Лявон кiнуў ";
		Concat(local_d7c, local_b74);
		Concat(local_d7c, ".");
		FUN_16d5_0019(local_d7c);
		if (local_c7b == 10) {
			BYTE_1d2e_0362 = 0;
		}
		else if (local_c7b == 9) {
			BYTE_1d2e_0363 = 0;
		}
		else if (local_c7b == 6) {
			BYTE_1d2e_0364 = 0;
		}
		else if (local_c7b == 0xb) {
			BYTE_1d2e_0365 = 0;
		}
		local_4 = BYTE_1d2e_1529 + local_c;
		local_5 = BYTE_1d2e_152a + local_e;
		local_7 = 7;
		local_96f = false;
		do {
			local_974 = PTR_1d2e_0156;
			while (true) {
				if ((local_974 == NULL) ||
					((local_974->xpos == local_4) && (local_974->ypos == local_5)))
					break;
				local_974 = local_974->pNext;
			}
			if (local_974 != NULL) {
				local_974->hp = local_974->hp - local_c7a;
				if (local_974->hp < 0) {
					local_974->hp = 0;
				}
				local_96f = true;
				Str(local_974->hp, 0, &local_b74, 0xff);
				bVar7 = local_974->hp % 10;
				if ((bVar7 == 0) || ((5 <= bVar7) && (bVar7 <= 9)) ||
					(bVar7 = local_974->hp % 100, (11 <= bVar7) && (bVar7 <= 14))) {
					local_c74 = " хiтоў.";
				}
				else if (local_974->hp % 10 == 1) {
					local_c74 = " хiт.";
				}
				else {
					local_c74 = " хiты.";
				}
				Str(local_974->hp, 0, &local_b74, 0xff);
				if (local_c7a == 0) {
					local_a74 = ", ды той не заўважыў.";
				}
				else if (local_974->hp == 0) {
					local_a74 = " ды вырубiў яго.";
				}
				else {
					local_d7c = " ды пакiнуў яму ";
					Concat(local_d7c, local_b74);
					Concat(local_d7c, local_c74);
					local_a74 = local_d7c;
				}
				local_d7c = "Лявон трапiў у ";
				Concat(local_d7c, P_STRING__ARRAY_1d2e_0832[local_974->index - 0x01]);
				Concat(local_d7c, local_a74);
				FUN_16d5_0019(local_d7c);
				if (local_974->hp == 0) {
					BYTE_1d2e_017c = BYTE_1d2e_017c + 1;
					delete local_974;
				}
			}
			else {
				local_7 = Console.ReadAttribute(local_4, local_5);
				FUN_1b04_0487(local_4, local_5, local_c7c, 0xe);
				FUN_1b04_0dc1(0x14);
				FUN_1b04_0487(BYTE_1d2e_1529, BYTE_1d2e_152a, 0x40, 7);
				if ((8 < std::abs(local_4 - BYTE_1d2e_1529)) ||
					(8 < std::abs(local_5 - BYTE_1d2e_152a))) {
					local_96f = true;
				}
				FUN_1b04_0487(local_4, local_5, BYTE_ARRAY_ARRAY_1d2e_152c[local_4 - 0x0F][local_5 - 0x02], local_7);
				local_4 = local_4 + local_c;
				local_5 = local_5 + local_e;
			}
			dVar11 = GetElemOffset(BYTE_ARRAY_ARRAY_1d2e_152c[local_4 + local_c - 0x0F][local_5 + local_e - 0x02], 1, 0x20, 0);
		} while ((((BYTE_ARRAY_1d2e_017e[dVar11.second] & dVar11.first) != 0) ||
			(dVar11 = GetElemOffset(BYTE_ARRAY_ARRAY_1d2e_152c[local_4 + local_c - 0x0F][local_5 + local_e - 0x02], 1, 0x20, 0),
				(BYTE_ARRAY_1d2e_015a[dVar11.second] & dVar11.first) != 0)) && (!local_96f));
		local_3 = true;
		FUN_1b04_064b();
	}
LAB_12d2_32f1:
	return local_3;
}

/*
	Move to Adjacent Tile / Attack Nearby Enemy
*/
void __pascal16far FUN_12d2_32f9(void)
{
	std::pair<byte, word> dVar1;
	sbyte local_4;
	sbyte local_3;

	__StackCheck(2);
	FUN_16d5_0000();
	FUN_16d5_0019("");
	FUN_16d5_0000();
	if (BYTE_1d2e_331c == 0x47) {
		local_3 = -1;
		local_4 = -1;
	}
	else if (BYTE_1d2e_331c == 0x48) {
		local_3 = 0;
		local_4 = -1;
	}
	else if (BYTE_1d2e_331c == 0x49) {
		local_3 = 1;
		local_4 = -1;
	}
	else if (BYTE_1d2e_331c == 0x4b) {
		local_3 = -1;
		local_4 = 0;
	}
	else if (BYTE_1d2e_331c == 0x4d) {
		local_3 = 1;
		local_4 = 0;
	}
	else if (BYTE_1d2e_331c == 0x4f) {
		local_3 = -1;
		local_4 = 1;
	}
	else if (BYTE_1d2e_331c == 0x50) {
		local_3 = 0;
		local_4 = 1;
	}
	else if (BYTE_1d2e_331c == 0x51) {
		local_3 = 1;
		local_4 = 1;
	}
	else {
		local_3 = 0;
		local_4 = 0;
	}
	dVar1 = GetElemOffset(BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_1529 + local_3 - 0x0F][BYTE_1d2e_152a + local_4 - 0x02], 1, 0x20, 0);
	if ((BYTE_ARRAY_1d2e_0136[dVar1.second] & dVar1.first) == 0) {
		dVar1 = GetElemOffset(BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_1529 + local_3 - 0x0F][BYTE_1d2e_152a + local_4 - 0x02], 1, 0x20, 0);
		if ((BYTE_ARRAY_1d2e_015a[dVar1.second] & dVar1.first) == 0) {
			FUN_1b04_0487(BYTE_1d2e_1529, BYTE_1d2e_152a, BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_1529 - 0x0F][BYTE_1d2e_152a - 0x02], 7);
			FUN_16d5_0c6a(BYTE_1d2e_1529, BYTE_1d2e_152a);
			BYTE_1d2e_152a = BYTE_1d2e_152a + local_4;
			BYTE_1d2e_1529 = BYTE_1d2e_1529 + local_3;
			FUN_1b04_0487(BYTE_1d2e_1529, BYTE_1d2e_152a, 0x40, 7);
		}
		else {
			FUN_12d2_3553(BYTE_1d2e_1529 + local_3, BYTE_1d2e_152a + local_4);
		}
	}
	FUN_1b04_064b();
	return;
}

/*
	Attack Enemy in Melee
*/
void __pascal16far FUN_12d2_3553(byte targetx, byte targety)
{
	byte bVar2;
	byte bVar3;
	word wVar4;
	int iVar5;
	undefined uVar6;
	Enemy* psVar7;
	undefined2 uVar8;
	undefined2 unaff_SS;
	PascalString255* pPVar9;
	PascalString255 local_408;
	PascalString255 local_308;
	PascalString255 local_208;
	PascalString255 local_108;
	Enemy* local_8;
	byte local_3;

	__StackCheck(0x406);
	if (Random(10) == 0) {
		FUN_16d5_0019("Лявон прамазаў.");
	}
	else {
		local_8 = PTR_1d2e_0156;
		while (true) {
			if ((local_8->xpos == targetx) && (local_8->ypos == targety)) break;
			local_8 = local_8->pNext;
		}
		wVar4 = Random(BYTE_ARRAY_ARRAY_1d2e_10c0[BYTE_1d2e_334c - 0x01][1]);
		local_3 = BYTE_ARRAY_ARRAY_1d2e_10c0[BYTE_1d2e_334c - 0x01][0] * (wVar4 + 1);
		if (BYTE_1d2e_334c == 10) {
			local_408 = "Лявон паказаў ";
			Concat(local_408, P_STRING__ARRAY_1d2e_09d6[local_8->index - 0x01]);
			Concat(local_408, " бiлет БПСМ.");
			FUN_16d5_0019(local_408);
			bVar3 = local_8->index;
			if ((bVar3 == 5) || ((7 <= bVar3) && (bVar3 <= 9))) {
				local_308 = P_STRING__ARRAY_1d2e_0696[local_8->index - 0x01];
				if ((local_8->index != 5) && (local_8->index != 10)) {
					local_308[0] = DAT_1d2e_10a0[(byte)local_308[0] - 0x80];
				}
				local_408 = "Так ";
				Concat(local_408, local_308);
				Concat(local_408, " i спужаўся БПСМаўскага бiлета!");
				Concat(local_408, " Ты ж ня ў казцы!");
				FUN_16d5_0019(local_408);
				return;
			}
			local_408 = P_STRING__ARRAY_1d2e_0696[local_8->index - 0x01];
			Concat(local_408, " паверыў...");
			FUN_16d5_0019(local_408);
		}
		local_8->hp = local_8->hp - local_3;
		if (local_8->hp <= 0) {
			local_8->hp = 0;
		}
		bVar3 = local_8->hp % 10;
		if ((bVar3 == 0) || ((5 <= bVar3) && (bVar3 <= 9)) ||
			(bVar3 = local_8->hp % 100, (11 <= bVar3) && (bVar3 <= 14))) {
			local_208 = " хiтоў.";
		}
		else if (local_8->hp % 10 == 1) {
			local_208 = " хiт.";
		}
		else {
			local_208 = " хiты.";
		}
		Str(local_8->hp, 0, (PascalString255*)BYTE_ARRAY_1d2e_3358, 3);
		if (local_3 == 0) {
			local_108 = ", ды той не заўважыў.";
		}
		else if (local_8->hp == 0) {
			local_108 = " ды вырубiў яго.";
		}
		else {
			local_408 = " ды пакiнуў яму ";
			Concat(local_408, (PascalString255&)BYTE_ARRAY_1d2e_3358);
			Concat(local_408, local_208);
			local_108 = local_408;
		}
		local_408 = "Лявон пабiў ";
		Concat(local_408, P_STRING__ARRAY_1d2e_0832[local_8->index - 0x01]);
		Concat(local_408, local_108);
		FUN_16d5_0019(local_408);
		if (local_8->hp == 0) {
			BYTE_1d2e_017c = BYTE_1d2e_017c + 1;
			delete local_8;
		}
		FUN_1b04_064b();
	}
	return;
}

/*
	Spawn Random Enemy
*/
Enemy* __pascal16far FUN_12d2_3887(void)
{
	word wVar1;
	uint uVar2;
	Enemy* psVar3;
	Enemy* local_a;
	Enemy* local_6;

	__StackCheck(8);
	local_a = NULL;
	wVar1 = Random(100) % 10;
	if (wVar1 == 1) {
		if (BYTE_1d2e_1104 != 0) {
			local_a = new DAT_1d2e_0096();
		}
	}
	else if (wVar1 == 2) {
		if (BYTE_1d2e_1104 != 0) {
			local_a = new DAT_1d2e_006e();
		}
	}
	else if (wVar1 == 3) {
		if ((60 < WORD_1d2e_3352) && (BYTE_1d2e_1104 != 0)) {
			local_a = new DAT_1d2e_00aa();
		}
	}
	else if (wVar1 == 4) {
		if (160 < WORD_1d2e_3352) {
			local_a = new DAT_1d2e_005a();
		}
	}
	else if (wVar1 == 5) {
		if (160 < WORD_1d2e_3352) {
			local_a = new DAT_1d2e_00e6();
		}
	}
	else if (wVar1 == 6) {
		if (380 < WORD_1d2e_3352) {
			local_a = new DAT_1d2e_00fa();
		}
	}
	else if (wVar1 == 7) {
		if (380 < WORD_1d2e_3352) {
			local_a = new DAT_1d2e_010e();
		}
	}
	else if (wVar1 == 8) {
		if (600 < WORD_1d2e_3352) {
			local_a = new DAT_1d2e_0122();
		}
	}
	else if (wVar1 == 9) {
		if (BYTE_1d2e_1104 != 0) {
			local_a = new DAT_1d2e_0046();
		}
	}
	else if (wVar1 == 0) {
		if (380 < WORD_1d2e_3352) {
			local_a = new DAT_1d2e_0082();
		}
	}
	local_6 = local_a;
	return local_6;
}

/*
	Store Enemy Coordinates
*/
void __pascal16near FUN_12d2_3a15(byte xpos, byte ypos, bool flag)
{
	Spawn* psVar1;
	undefined2 uVar2;
	Spawn* psVar3;
	Spawn* local_6;

	__StackCheck(8);
	local_6 = new Spawn; // (Spawn*)GetMem(sizeof(Spawn));
	local_6->pNext = PTR_1d2e_1520;
	local_6->xpos = xpos;
	local_6->ypos = ypos;
	local_6->flag = flag;
	PTR_1d2e_1520 = local_6;
	return;
}

/*
	Spawn Imp at Stored Coordinates
*/
void __pascal16near FUN_12d2_3a6b(void)
{
	Spawn* pointer;
	Spawn* local_a;
	Enemy* local_6;

	__StackCheck(8);
	if (PTR_1d2e_1520 != NULL) {
		if (PTR_1d2e_1520->flag) {
			BYTE_1d2e_1524 = 1;
			local_6 = new DAT_1d2e_0032(PTR_1d2e_1520->xpos, PTR_1d2e_1520->ypos, true);
		}
		else {
			local_6 = new DAT_1d2e_001e(PTR_1d2e_1520->xpos, PTR_1d2e_1520->ypos, true);
		}
		local_a = PTR_1d2e_1520;
		PTR_1d2e_1520 = local_a->pNext;
		delete local_a; // FreeMem(local_a, sizeof(Spawn));
	}
	return;
}

/*
	Use Magic Charm
*/
void __pascal16far FUN_12d2_3c07(void)
{
	byte bVar1;
	bool bVar3;
	byte bVar4;
	Enemy* psVar5;
	undefined2 uVar6;
	undefined2 unaff_SS;
	std::pair<byte, word> dVar7;
	PascalString255* dest;
	undefined4 uVar8;
	PascalString255 local_a70;
	byte local_96f;
	Enemy* local_96e;
	bool local_969;
	byte local_968;
	byte local_967;
	byte local_966[2400];
	bool local_6;
	byte local_5;
	byte local_4;
	byte local_3;

	__StackCheck(0xa6e);
	if (BYTE_1d2e_3346 == 0) {
		FUN_16d5_0019("А ў тваёй торбачцы - анiводнай фенечкi!");
	}
	else {
		Console.SaveBuffer(0, 0, 80, 15);
		local_3 = 0;
		local_96f = BYTE_1d2e_3346;
		if (local_96f != 0) {
			BYTE_1d2e_331a = 1;
			while (true) {
				dVar7 = GetElemOffset(BYTE_ARRAY_1d2e_332a[BYTE_1d2e_331a - 0x01], 1, 0x20, 0);
				if ((BYTE_ARRAY_1d2e_0320[dVar7.second] & dVar7.first) != 0) {
					local_3 = local_3 + 1;
				}
				if (BYTE_1d2e_331a == local_96f) break;
				BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
			}
		}
		if (local_3 == 0) {
			FUN_16d5_0019("А ў тваёй торбачцы - анiводнай фенечкi!");
		}
		else {
			local_3 = 1;
			BYTE_1d2e_331a = 1;
			while (FUN_1b04_0487(BYTE_1d2e_331a, 1, 0x20, 7), BYTE_1d2e_331a != 0x50) {
				BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
			}
			FUN_1b04_0500(1, 1, " Што юзануць?", 7);
			local_96f = BYTE_1d2e_3346;
			if (local_96f != 0) {
				BYTE_1d2e_331a = 1;
				while (true) {
					dVar7 = GetElemOffset(BYTE_ARRAY_1d2e_332a[BYTE_1d2e_331a - 0x01], 1, 0x20, 0);
					if ((BYTE_ARRAY_1d2e_0320[dVar7.second] & dVar7.first) != 0) {
						local_4 = 0x1e;
						while (FUN_1b04_0487(local_4, local_3 + 1, 0x20, 0), local_4 != 0x50) {
							local_4 = local_4 + 1;
						}
						local_a70 = PascalString255(P_STRING_ARRAY_1d2e_0340[local_3]);
						Concat(local_a70, ") ");
						Concat(local_a70, P_STRING__ARRAY_1d2e_0366[BYTE_ARRAY_1d2e_332a[BYTE_1d2e_331a - 0x01] - 0x01]);
						FUN_1b04_0500(0x1e, local_3 + 1, local_a70, 7);
						local_3 = local_3 + 1;
					}
					if (BYTE_1d2e_331a == local_96f) break;
					BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
				}
			}
			local_3 = local_3 - 1;
			do {
				FUN_1b04_0670();
				FUN_1b04_05b3(&local_4, &local_5);
				if (local_4 == 1) {
					Console.RestoreBuffer(0, 0, 80, 15);
					BYTE_1d2e_331a = 1;
					while (FUN_1b04_0487(BYTE_1d2e_331a, 1, 0x20, 7), BYTE_1d2e_331a != 0x50) {
						BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
					}
					return;
				}
			} while ((local_5 <= 0x30) || (local_3 + 0x31 <= local_5));
			local_3 = 0;
			local_96f = local_5 - 0x30;
			if (local_96f != 0) {
				BYTE_1d2e_331a = 1;
				while (true) {
					do {
						local_3 = local_3 + 1;
						dVar7 = GetElemOffset(BYTE_ARRAY_1d2e_332a[local_3 - 0x01], 1, 0x20, 0);
					} while ((BYTE_ARRAY_1d2e_0320[dVar7.second] & dVar7.first) == 0);
					if (BYTE_1d2e_331a == local_96f) break;
					BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
				}
			}
			Console.RestoreBuffer(0, 0, 80, 15);
			FUN_16d5_0019("Фенька ўспыхвае ды й робiцца бутэлькаю \"Крынiцы\"!");
			bVar1 = BYTE_ARRAY_1d2e_332a[local_3 - 0x01];
			if (bVar1 == 0xd) {
				if (BYTE_1d2e_335e == 0) {
					BYTE_1d2e_335e = 0x32;
				}
			}
			else if (bVar1 == 0xe) {
				local_6 = false;
				local_96f = BYTE_1d2e_3346;
				if (local_96f != 0) {
					BYTE_1d2e_331a = 1;
					while (true) {
						if (BYTE_ARRAY_1d2e_332a[BYTE_1d2e_331a - 0x01] == 3) {
							BYTE_ARRAY_1d2e_332a[BYTE_1d2e_331a - 0x01] = 2;
							local_6 = true;
						}
						if (BYTE_1d2e_331a == local_96f) break;
						BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
					}
				}
				if (local_6) {
					FUN_16d5_0019("Нешта зьмянiлася ў торбе");
				}
			}
			else if (bVar1 == 0x11) {
				BYTE_1d2e_1524 = 0;
				FUN_16d5_0019("Усе наўкол ператвараюцца ў чорцiкаў!");
				if (BYTE_1d2e_334b == 3) {
					FUN_16d5_0019("ЯНЫ ЎСЕ ВАР\'ЯЦЕЮЦЬ АД ГАПАТЫ!!!");
				}
				PTR_1d2e_1520 = NULL;
				local_969 = false;
				local_96f = BYTE_1d2e_3348;
				if (local_96f != 0) {
					BYTE_1d2e_331a = 1;
					while (true) {
						if (PTR_1d2e_0156->index != 5) {
							if ((PTR_1d2e_0156->index < 0xd) && (BYTE_1d2e_334b != 3)) {
								bVar4 = 0;
							}
							else {
								bVar4 = 1;
							}
							FUN_12d2_3a15(PTR_1d2e_0156->xpos, PTR_1d2e_0156->ypos, bVar4);
						}
						else {
							local_969 = true;
							local_967 = PTR_1d2e_0156->xpos;
							local_968 = PTR_1d2e_0156->ypos;
						}
						delete PTR_1d2e_0156;
						if (BYTE_1d2e_331a == local_96f) break;
						BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
					}
				}
				while (PTR_1d2e_1520 != NULL) {
					FUN_12d2_3a6b();
				}
				if (local_969) {
					local_96e = new DAT_1d2e_00be(local_967, local_968, true);
				}
				if (BYTE_1d2e_1524 != 0) {
					FUN_16d5_0019("Аёй! Старыя чорцiкi растуць на вачох!");
					if (SBYTE_1d2e_3327 < 0) {
						FUN_16d5_0019("Лявон так афiгеў, што стаў амаль цьвярозы!");
					}
				}
			}
			BYTE_ARRAY_1d2e_332a[local_3 - 0x01] = 2;
		}
	}
	return;
}

/*
	NOP
*/
void __pascal16far FUN_12d2_4019(void)
{
	__StackCheck(0);
	return;
}

/*
	Proceed to the Next Message
*/
void __pascal16far FUN_16d5_0000(void)
{
	__StackCheck(0);
	BYTE_1d2e_1106 = 0;
	return;
}

/*
	Show Status Message
*/
void __pascal16far FUN_16d5_0019(const PascalString255& string)
{
	byte* pbVar1;
	char* pcVar2;
	uint uVar3;
	PascalString255* pPVar4;
	undefined2 unaff_SS;
	byte local_104;
	byte local_103;
	PascalString255 local_102;

	__StackCheck(0x104);
	local_102 = string;
	if (BYTE_1d2e_1106 != 0) {
		FUN_1b04_0500(0x48, 1, "-далей-", 7);
		do {
			FUN_1b04_0670();
			FUN_1b04_05b3(&local_103, &local_104);
		} while (local_103 == 0);
	}
	local_103 = 1;
	while (true) {
		FUN_1b04_0487(local_103, 1, 0x20, 7);
		if (local_103 == 0x4f) break;
		local_103 = local_103 + 1;
	}
	FUN_1b04_0500(1, 1, local_102, 7);
	if (local_102.size() != 0) {
		BYTE_1d2e_334a = BYTE_1d2e_334a + 1;
		if (0x18 < BYTE_1d2e_334a) {
			local_103 = 1;
			while (true) {
				DAT_1d2E_1b1a[local_103 - 0x01] = DAT_1d2E_1b1a[local_103];
				if (local_103 == 0x17) break;
				local_103 = local_103 + 1;
			}
			BYTE_1d2e_334a = 0x18;
		}
		DAT_1d2E_1b1a[BYTE_1d2e_334a - 0x01] = local_102;
	}
	BYTE_1d2e_1106 = 1;
	return;
}

/*
	Pickup Item
*/
void __pascal16far FUN_16d5_0158(byte item)
{
	undefined2 unaff_SS;
	PascalString255* dest;
	PascalString255 local_202;
	PascalString255 local_102;

	__StackCheck(0x200);
	if (BYTE_1d2e_3346 < 9) {
		BYTE_1d2e_3346 = BYTE_1d2e_3346 + 1;
		BYTE_ARRAY_1d2e_332a[BYTE_1d2e_3346 - 0x01] = item;
		local_102 = P_STRING_ARRAY_1d2e_0d3c[item - 0x01];
		if (item == 10) {
			BYTE_1d2e_0362 = 1;
		}
		else if (item == 9) {
			BYTE_1d2e_0363 = 1;
		}
		else if (item == 6) {
			BYTE_1d2e_0364 = 1;
		}
		else if (item == 0xb) {
			BYTE_1d2e_0365 = 1;
		}
		local_202 = "Лявон знайшоў ";
		Concat(local_202, local_102);
		Concat(local_202, ".");
		FUN_16d5_0019(local_202);
		BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_1529 - 0x0F][BYTE_1d2e_152a - 0x02] = 0xfa;
	}
	else {
		FUN_16d5_0019("А месца ў торбе няма!");
	}
	return;
}

/*
	Drink Potion or Beer
*/
bool __pascal16far FUN_16d5_032d(void)
{
	byte bVar1;
	word wVar2;
	undefined2 unaff_SS;
	bool bVar3;
	std::pair<byte, word> dVar4;
	PascalString255* pPVar5;
	undefined4 uVar6;
	PascalString255 local_b6e;
	PascalString255 local_b6c;
	byte local_a6d;
	byte local_a6c[2400];
	PascalString255 local_10c;
	byte local_c[3 + 1]; // +1 for '\0'
	byte local_8;
	byte local_7;
	byte local_6;
	byte local_5;
	byte local_4;
	bool local_3;

	__StackCheck(0xb6c);
	if (BYTE_1d2e_3346 == 0) {
		FUN_16d5_0019("А пiва няма...");
		local_3 = false;
	}
	else {
		Console.SaveBuffer(0, 0, 80, 15);
		local_7 = 0;
		local_a6d = BYTE_1d2e_3346;
		if (local_a6d != 0) {
			local_6 = 1;
			while (true) {
				dVar4 = GetElemOffset(BYTE_ARRAY_1d2e_332a[local_6 - 0x01], 1, 0x20, 0);
				if ((BYTE_ARRAY_1d2e_0300[dVar4.second] & dVar4.first) != 0) {
					local_7 = local_7 + 1;
				}
				if (local_6 == local_a6d) break;
				local_6 = local_6 + 1;
			}
		}
		if (local_7 == 0) {
			FUN_16d5_0019("А пiва няма...");
			local_3 = false;
		}
		else {
			while (true) {
				local_7 = 1;
				for (local_6 = 1; FUN_1b04_0487(local_6, 1, 0x20, 7), local_6 != 0x50; local_6 = local_6 + 1) {
				}
				FUN_1b04_0500(1, 1, " Чаго б тут гэткага...", 7);
				local_a6d = BYTE_1d2e_3346;
				if (local_a6d != 0) {
					local_6 = 1;
					while (true) {
						dVar4 = GetElemOffset(BYTE_ARRAY_1d2e_332a[local_6 - 0x01], 1, 0x20, 0);
						if ((BYTE_ARRAY_1d2e_0300[dVar4.second] & dVar4.first) != 0) {
							local_4 = 0x1e;
							while (FUN_1b04_0487(local_4, local_7 + 1, 0x20, 0), local_4 != 0x50) {
								local_4 = local_4 + 1;
							}
							local_b6e = P_STRING_ARRAY_1d2e_0340[local_7];
							Concat(local_b6e, ") ");
							Concat(local_b6e, P_STRING__ARRAY_1d2e_0366[BYTE_ARRAY_1d2e_332a[local_6 - 0x01] - 0x01]);
							FUN_1b04_0500(0x1e, local_7 + 1, local_b6e, 7);
							local_7 = local_7 + 1;
						}
						if (local_6 == local_a6d) break;
						local_6 = local_6 + 1;
					}
				}
				local_7 = local_7 - 1;
				do {
					FUN_1b04_0670();
					FUN_1b04_05b3(&local_4, &local_5);
					if (local_4 == 1) {
						Console.RestoreBuffer(0, 0, 80, 15);
						local_3 = false;
						for (local_6 = 1; FUN_1b04_0487(local_6, 1, 0x20, 7), local_6 != 0x50;
							local_6 = local_6 + 1) {
						}
						goto LAB_16d5_08fa;
					}
				} while ((local_5 <= 0x30) || (local_7 + 0x31 <= local_5));
				local_7 = 0;
				local_a6d = local_5 - 0x30;
				if (local_a6d != 0) {
					local_6 = 1;
					while (true) {
						do {
							local_7 = local_7 + 1;
							dVar4 = GetElemOffset(BYTE_ARRAY_1d2e_332a[local_7 - 0x01], 1, 0x20, 0);
						} while ((BYTE_ARRAY_1d2e_0300[dVar4.second] & dVar4.first) == 0);
						if (local_6 == local_a6d) break;
						local_6 = local_6 + 1;
					}
				}
				if (BYTE_ARRAY_1d2e_332a[local_7 - 0x01] != 6) break;
				FUN_16d5_0019("Пачакай, мо спатрэбiцца яшчэ...");
				FUN_16d5_0019("");
			}
			local_10c = P_STRING__ARRAY_1d2e_0366[BYTE_ARRAY_1d2e_332a[local_7 - 0x01] - 0x01];
			// FIXME: Consider Item Name (Accusative Case) string table usage!
			// [Б]утэльк[а] -> [б]утэльк[у]
			local_10c[0] = '\xa1';
			local_10c[7] = '\xe3';
			Console.RestoreBuffer(0, 0, 80, 15);
			if (BYTE_ARRAY_1d2e_332a[local_7 - 0x01] != 0xc) {
				local_b6c = "Хлабысь! Лявон выпiў ";
				Concat(local_b6c, local_10c);
				Concat(local_b6c, ".");
				FUN_16d5_0019(local_b6c);
			}
			if (BYTE_ARRAY_1d2e_332a[local_7 - 0x01] == 0xf) {
				FUN_16d5_0019("АУОУЁООФТХГХТ!!!...");
				SWORD_1d2e_334e = SWORD_1d2e_334e + 0x15e;
				if (500 < SWORD_1d2e_334e) {
					FUN_16d5_0019("");
					FUN_16d5_2e05("ад гопнiцкага", "пiва");
				}
				if (20 < SWORD_1d2e_3356) {
					SWORD_1d2e_3356 = SWORD_1d2e_3356 - 20;
				}
				else {
					FUN_16d5_0019("");
					FUN_16d5_2e05("ад гопнiцкага", "пiва");
				}
			}
			else if (BYTE_ARRAY_1d2e_332a[local_7 - 0x01] == 0xc) {
				FUN_16d5_0019("Хлабысь... Авой...");
				FUN_16d5_0019("Лявон адчуў сябе крутым ХЕРАМ!");
				if (50 < SWORD_1d2e_334e) {
					SWORD_1d2e_334e = SWORD_1d2e_334e - 50;
				}
				else {
					SWORD_1d2e_334e = 0;
				}
				SWORD_1d2e_3356 = SWORD_1d2e_3350 + 5;
			}
			else {
				if (BYTE_ARRAY_1d2e_332a[local_7 - 0x01] == 3) {
					if (BYTE_1d2e_3329 != 0) {
						BYTE_1d2e_331e = BYTE_1d2e_331e + 0x1e;
					}
					else {
						FUN_16d5_0019("Хаця б паглядзеў, што п\'еш...");
						BYTE_1d2e_3329 = 1;
						BYTE_1d2e_331e = 0x3c;
						local_6 = 1;
						while (true) {
							if (BYTE_1d2e_334b != 2) {
								BYTE_1d2e_1528 = 0;
							}
							BYTE_ARRAY_1d2e_3320[local_6 - 0x01] = Random(0x3f) + 0x10;
							if (BYTE_1d2e_1528 == 0) {
								BYTE_ARRAY_1d2e_3324[local_6 - 0x01] = Random(0x15) + 0x02;
							}
							else if (BYTE_1d2e_1528 == 1) {
								BYTE_ARRAY_1d2e_3324[local_6 - 0x01] = Random(0xf) + 0x02;
							}
							else if (BYTE_1d2e_1528 == 2) {
								BYTE_ARRAY_1d2e_3324[local_6 - 0x01] = Random(5) + 0x12;
							}
							if (local_6 == 3) break;
							local_6 = local_6 + 1;
						}
					}
				}
				else if ((BYTE_1d2e_334c == 10) && (BYTE_1d2e_3329 == 0)) {
					FUN_16d5_0019("Нiчога не разумею: такiя глюкi ад добрага пiва!..");
					BYTE_1d2e_3329 = 1;
					BYTE_1d2e_331e = 0x3c;
					local_6 = 1;
					while (true) {
						if (BYTE_1d2e_334b != 2) {
							BYTE_1d2e_1528 = 0;
						}
						BYTE_ARRAY_1d2e_3320[local_6 - 0x01] = Random(0x3f) + 0x10;
						if (BYTE_1d2e_1528 == 0) {
							BYTE_ARRAY_1d2e_3324[local_6 - 0x01] = Random(0x15) + 0x02;
						}
						else if (BYTE_1d2e_1528 == 1) {
							BYTE_ARRAY_1d2e_3324[local_6 - 0x01] = Random(0xf) + 0x02;
						}
						else if (BYTE_1d2e_1528 == 2) {
							BYTE_ARRAY_1d2e_3324[local_6 - 0x01] = Random(5) + 0x12;
						}
						if (local_6 == 3) break;
						local_6 = local_6 + 1;
					}
				}
				local_8 = BYTE_ARRAY_1d2e_332a[local_7 - 0x01];
				if (local_8 == 0x10) {
					local_8 = 6;
				}
				SWORD_1d2e_334e = SWORD_1d2e_334e - WORD_ARRAY_1d2e_081e[local_8 - 0x02];
				SWORD_1d2e_3356 = SWORD_1d2e_3356 + WORD_ARRAY_1d2e_0828[local_8 - 0x02];
				if ((0 <= SWORD_1d2e_3356) && (SWORD_1d2e_3350 < SWORD_1d2e_3356)) {
					SWORD_1d2e_3356 = SWORD_1d2e_3350;
				}
			}
			FUN_1b04_0500(1, 0xd, "CHP   :      ", 7);
			// FIXME: Maximum size is 2 digits for the current hit points value!
			Str(SWORD_1d2e_3356, 0, (PascalString255*)local_c, 2);
			FUN_1b04_0500(0xb, 0xd, (PascalString255&)local_c, 7);
			BYTE_ARRAY_1d2e_332a[local_7 - 0x01] = 1;
			FUN_16d5_2c2c();
			local_3 = true;
		}
	}
LAB_16d5_08fa:
	return local_3;
}

/*
	Show Message Log / Help Screen
*/
void __pascal16far FUN_16d5_0950(const PascalString255& name)
{
	byte* pbVar1;
	char* pcVar2;
	byte bVar3;
	bool bVar4;
	byte bVar5;
	char cVar6;
	word wVar7;
	uint uVar8;
	PascalString255* pPVar9;
	undefined2 unaff_SS;
	bool bVar10;
	PascalString255* pPVar11;
	undefined4 uVar12;
	FFileStream* stream;
	PascalString255* dest;
	PascalString255 local_1450;
	PascalString255 local_1350;
	byte local_1250;
	byte local_124f;
	bool local_124e;
	byte local_124c;
	byte local_124b;
	PascalString255 local_124a;
	PascalString255 local_11f8;
	FFileStream local_11a6;
	byte local_10a6;
	byte local_10a5;
	byte local_10a4;
	byte local_10a3;
	byte local_10a2[4000];
	PascalString255 local_102;

	__StackCheck(0x144e);
	local_102 = name;
	Console.SaveBuffer(0, 0, 80, 25);
	Console.ClearBuffer(0, 0, 80*25);
	local_124e = true;
	if (local_102.size() == 0) {
		if (BYTE_1d2e_334a == 0) {
			FUN_1b04_0500(1, 1, " Месагаў няма", 7);
		}
		local_124f = BYTE_1d2e_334a;
		if (local_124f != 0) {
			local_10a3 = 1;
			while (true) {
				local_1350 = " ";
				Concat(local_1350, DAT_1d2E_1b1a[local_10a3 - 0x01]);
				FUN_1b04_0500(1, local_10a3, local_1350, 7);
				if (local_10a3 == local_124f) break;
				local_10a3 = local_10a3 + 1;
			}
		}
	}
	else {
		Assign(local_11a6, local_102);
		Reset(local_11a6);
		__IOCheck();
		local_10a3 = IOResult();
		local_10a4 = 0;
		while (true) {
			cVar6 = Eof(local_11a6);
			__IOCheck();
			if (cVar6 != 0) break;
			Read(local_11a6, &local_124a, 0x50);
			ReadLn(local_11a6);
			__IOCheck();
			local_11f8.clear();
			local_124f = local_124a.size();
			if (local_124f != 0) {
				local_10a5 = 1;
				while (true) {
					local_124a[local_10a5 - 1] = local_124a[local_10a5 - 1] ^ 0xcd;
					if (25 < (byte)local_124a[local_10a5 - 1]) {
						local_1450 = local_11f8;
						local_1350 = local_124a[local_10a5 - 1];
						Concat(local_1450, local_1350);
						local_11f8 = PascalString255(local_1450.c_str(), 0x50);
					}
					else {
						local_1250 = local_124a[local_10a5 - 1];
						if (local_1250 != 0) {
							local_10a6 = 1;
							while (true) {
								local_1350 = local_11f8;
								Concat(local_1350, " ");
								local_11f8 = PascalString255(local_1350.c_str(), 0x50);
								if (local_10a6 == local_1250) break;
								local_10a6 = local_10a6 + 1;
							}
						}
					}
					if (local_10a5 == local_124f) break;
					local_10a5 = local_10a5 + 1;
				}
			}
			if (!StrComp(local_11f8, "==")) {
				FUN_1b04_0500(0x16, 0x19, "[Enter] - далей, [Esc] - выхад", 7);
				do {
					FUN_1b04_0670();
					FUN_1b04_05b3(&local_124b, &local_124c);
					if (local_124b == 1) break;
				} while (local_124c != 0xd);
				if (local_124b == 1) {
					local_124e = false;
					goto LAB_16d5_0c1f;
				}
				Console.ClearBuffer(0, 0, 80*25);
				local_10a4 = 0;
			}
			else {
				local_10a4 = local_10a4 + 1;
				FUN_1b04_0500(1, local_10a4, local_11f8, 7);
			}
		}
		FUN_1b04_0500(0x1a, 0x19, "Нацiсьнiце адвольную клявiшу", 7);
	LAB_16d5_0c1f:
		Close(local_11a6);
		__IOCheck();
	}
	if (local_124e) {
		FUN_1b04_0670();
		FUN_1b04_05b3(&local_10a3, &local_10a4);
	}
	Console.RestoreBuffer(0, 0, 80, 25);
	return;
}

/*
	Draw Items, Objects and Disco Visuals
*/
void __pascal16far FUN_16d5_0c6a(byte xpos, byte ypos)
{
	char cVar1;

	__StackCheck(0);
	cVar1 = BYTE_ARRAY_ARRAY_1d2e_152c[xpos - 0x0F][ypos - 0x02];
	if (cVar1 == '!') {
		// ! - Bottle of Beer
		FUN_1b04_0487(xpos, ypos, 0x21, 10);
	}
	else if (cVar1 == '/') {
		// / - Stick or Club
		FUN_1b04_0487(xpos, ypos, 0x2f, 6);
	}
	else if (cVar1 == '1') {
		// 1 - Pub "Honest Izya"
		FUN_1b04_0487(xpos, ypos, 0x31, 0xe);
	}
	else if (cVar1 == '2') {
		// 2 - The Government House
		FUN_1b04_0487(xpos, ypos, 0x32, 0xc);
	}
	else if (cVar1 == '3') {
		// 3 - Club "Reactor"
		FUN_1b04_0487(xpos, ypos, 0x33, 1);
	}
	else if (cVar1 == '$') {
		// $ - Money
		FUN_1b04_0487(xpos, ypos, 0x24, 0xe);
	}
	else if (cVar1 == ']') {
		// ] - Cassette Player
		FUN_1b04_0487(xpos, ypos, 0x5d, 0xb);
	}
	else if (cVar1 == '[') {
		// [ - Audio Cassette (Artifact)
		FUN_1b04_0487(xpos, ypos, 0x5b, 0xf);
	}
	else if (cVar1 == '#') {
		// # - BPSM Membership Card
		FUN_1b04_0487(xpos, ypos, 0x23, 4);
	}
	else if (cVar1 == '\\') {
		// \ - DOOMGUY Chainsaw
		FUN_1b04_0487(xpos, ypos, 0x5c, 0xe);
	}
	else if (cVar1 == '?') {
		// ? - Lyavon's Bottle of Beer (Artifact)
		FUN_1b04_0487(xpos, ypos, 0x3f, 0xc);
	}
	else if (cVar1 == '%') {
		// % - Potion of Heroism
		FUN_1b04_0487(xpos, ypos, 0x25, 6);
	}
	else if (cVar1 == '&') {
		// & - Green Charm
		FUN_1b04_0487(xpos, ypos, 0x26, 2);
	}
	else if (cVar1 == '\x1f') {
		// & - Yellow Charm
		FUN_1b04_0487(xpos, ypos, 0x1f, 0xe);
	}
	else if (cVar1 == '\x1e') {
		// & - White-Red-White Charm
		FUN_1b04_0487(xpos, ypos, 0x1e, 0xc);
	}
	// Disco Visuals
	if ((BYTE_1d2e_1104 != 0) && (BYTE_1d2e_334b == 3) &&
		(BYTE_ARRAY_ARRAY_1d2e_152c[xpos - 0x0F][ypos - 0x02] == 0xB1)) {
		FUN_1b04_0487(xpos, ypos, 0xb1, 1);
	}
	return;
}

/*
	Draw Level Tiles, Items, Objects & UI
*/
void __pascal16far FUN_16d5_0f6c(void)
{
	void* pcVar1;
	byte bVar2;
	byte local_5;
	byte local_4;
	byte local_3;

	__StackCheck(4);
	FUN_1b04_0c7f("mnskbnd1.dat", 0, 0xff);
	FUN_1b04_0d8a();
	FUN_1b04_03ed();
	FUN_1b04_064b();
	if (BYTE_1d2e_334b == 2) {
		if (BYTE_1d2e_1528 == 0) {
			local_3 = 0x02;
			local_4 = 0x18;
		}
		else if (BYTE_1d2e_1528 == 1) {
			local_3 = 0x02;
			local_4 = 0x12;
		}
		else if (BYTE_1d2e_1528 == 2) {
			local_3 = 0x12;
			local_4 = 0x18;
		}
	}
	else {
		local_3 = 0x02;
		local_4 = 0x18;
	}
	BYTE_1d2e_331a = 0xf;
	while (true) {
		if (local_3 != 2) {
			local_5 = local_3 - 1;
			if (2 <= local_5) {
				BYTE_1d2e_331b = 2;
				while (FUN_1b04_0487(BYTE_1d2e_331a, BYTE_1d2e_331b, 0x20, 0),
					BYTE_1d2e_331b != local_5) {
					BYTE_1d2e_331b = BYTE_1d2e_331b + 1;
				}
			}
		}
		else {
			bVar2 = local_4 + 1;
			if (bVar2 <= 0x18) {
				BYTE_1d2e_331b = bVar2;
				while (FUN_1b04_0487(BYTE_1d2e_331a, BYTE_1d2e_331b, 0x20, 0),
					BYTE_1d2e_331b != 0x18) {
					BYTE_1d2e_331b = BYTE_1d2e_331b + 1;
				}
			}
		}
		if (BYTE_1d2e_331a == 0x50) break;
		BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
	}
	BYTE_1d2e_331a = 0xf;
	while (true) {
		local_5 = local_4;
		if (local_3 <= local_5) {
			BYTE_1d2e_331b = local_3;
			while (true) {
				FUN_1b04_0487(BYTE_1d2e_331a, BYTE_1d2e_331b,
					BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_331a - 0x0F][BYTE_1d2e_331b - 0x02], 7);
				FUN_16d5_0c6a(BYTE_1d2e_331a, BYTE_1d2e_331b);
				if (BYTE_1d2e_331b == local_5) break;
				BYTE_1d2e_331b = BYTE_1d2e_331b + 1;
			}
		}
		if (BYTE_1d2e_331a == 0x50) break;
		BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
	}
	if (BYTE_1d2e_334b == 1) {
		if (BYTE_1d2e_1104 != 0) {
			FUN_1b04_0500(0x3c, 6, "РЕАКТОР", 1);
			FUN_1b04_0487(0x39, 5, 0x8a, 7);
			FUN_1b04_0487(0x39, 6, 0x8b, 7);
			FUN_1b04_0487(0x39, 7, 0x93, 7);
			FUN_1b04_0487(0x39, 8, 0x81, 7);
		}
		else {
			FUN_1b04_0500(0x3a, 5, "           ", 0xf0);
			FUN_1b04_0500(0x3a, 6, "           ", 0xc0);
			FUN_1b04_0500(0x3a, 7, "           ", 0xf0);
		}
	}
	FUN_1b04_0500(0x46, 0x19, "Менск", 7);
	FUN_1b04_0500(1, 2, "Лявон - ", 7);
	FUN_1b04_0500(1, 3, "Усiм па мордзе", 7);
	FUN_1b04_0500(1, 4, "Круцей няма!", 7);
	FUN_1b04_0500(1, 7, "МАЗГОЎ :    0 ", 7);
	FUN_1b04_0500(1, 8, "СIЛЫ   :    0 ", 7);
	FUN_1b04_0500(1, 9, "СПРЫТНЫ: вой! ", 7);
	FUN_1b04_0500(1, 10, "ПРЫГОЖЫ: вай! ", 7);
	FUN_1b04_0500(1, 0xc, "ВОПЫТУ:    ", 7);
	Str(WORD_1d2e_3352, 0, (PascalString255*)BYTE_ARRAY_1d2e_3358, 3);
	FUN_1b04_0500(0xb, 0xc, (PascalString255&)BYTE_ARRAY_1d2e_3358, 7);
	FUN_1b04_0500(1, 0xe, "MHP   :    ", 7);
	Str(SWORD_1d2e_3350, 0, (PascalString255*)BYTE_ARRAY_1d2e_3358, 3);
	FUN_1b04_0500(0xb, 0xe, (PascalString255&)BYTE_ARRAY_1d2e_3358, 7);
	FUN_1b04_0500(1, 0xd, "CHP   :    ", 7);
	Str(SWORD_1d2e_3356, 0, (PascalString255*)BYTE_ARRAY_1d2e_3358, 3);
	FUN_1b04_0500(0xb, 0xd, (PascalString255&)BYTE_ARRAY_1d2e_3358, 7);
	FUN_1b04_0500(1, 0x14, "ГРОШЫ:", 7);
	Str(SWORD_1d2e_3354, 0, (PascalString255*)BYTE_ARRAY_1d2e_3358, 3);
	FUN_1b04_0500(8, 0x14, (PascalString255&)BYTE_ARRAY_1d2e_3358, 7);
	FUN_1b04_0500(1, 0xf, "МАНА: не было", 7);
	FUN_1b04_0500(1, 0x10, "  й ня будзе!", 7);
	FUN_1b04_0500(1, 0x16, "Не баiцца ён", 7);
	FUN_1b04_0500(1, 0x17, "нiкога!!!", 7);
	FUN_1b04_0500(1, 0x18, "Бо п\'яны...", 7);
	if (SBYTE_1d2e_3327 == -1) {
		FUN_1b04_0500(1, 0x19, "У дошку...", 7);
	}
	if (SBYTE_1d2e_3327 == 1) {
		FUN_1b04_0500(1, 0x19, "Цьвярозы!!!", 7);
	}
	if (SBYTE_1d2e_3327 == 2) {
		FUN_1b04_0500(1, 0x19, "Памiрае - пiва хоча!!!", 7);
	}
	FUN_1b04_0487(BYTE_1d2e_1529, BYTE_1d2e_152a, 0x40, 7);
	return;
}

/*
	Equip Item
*/
bool __pascal16far FUN_16d5_149e(void)
{
	bool bVar1;
	bool bVar2;
	byte bVar3;
	byte bVar4;
	undefined2 unaff_SS;
	PascalString255* psVar5;
	undefined uVar6;
	undefined uVar7;
	undefined4 uVar8;
	PascalString255* dest;
	PascalString255 local_108;
	byte local_8;
	byte local_7;
	byte local_6;
	bool local_5;
	bool local_4;
	bool local_3;

	__StackCheck(0x106);
	if (BYTE_1d2e_3346 == 0) {
		FUN_16d5_0019("Няма ж нiчога!");
		local_3 = false;
	}
	else {
	LAB_16d5_14c4:
		local_6 = 0;
		local_4 = false;
		local_5 = false;
		Str(BYTE_1d2e_3346, 0, (PascalString255*)BYTE_ARRAY_1d2e_3358, 3);
		BYTE_1d2e_331a = 1;
		while (FUN_1b04_0487(BYTE_1d2e_331a, 1, 0x20, 7), BYTE_1d2e_331a != 0x50) {
			BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
		}
		local_108 = "Чаго узяць (1..";
		Concat(local_108, (PascalString255&)BYTE_ARRAY_1d2e_3358);
		Concat(local_108, "), * - iнвентар ?");
		FUN_1b04_0500(1, 1, local_108, 7);
		do {
			FUN_1b04_0670();
			FUN_1b04_05b3(&BYTE_1d2e_331c, &BYTE_1d2e_331d);
			if ((BYTE_1d2e_331c == 0x17) || (BYTE_1d2e_331c == 0x37)) {
				BYTE_1d2e_331d = FUN_16d5_32b4();
			}
			if ((0x30 <= BYTE_1d2e_331d) && (BYTE_1d2e_331d <= 0x3b)) {
				if (((BYTE_1d2e_3346 + 1) <= (BYTE_1d2e_331d - 0x30)) ||
					((BYTE_1d2e_331d - 0x30) < 0)) {
					goto LAB_16d5_14c4;
				}
				local_6 = BYTE_1d2e_331d - 0x30;
				// FIXME: Trying to equip a nonexistent item from the inventory!
				if (local_6 == 0) {
					local_6 = 10;
				}
				if (BYTE_1d2e_334c == 10) {
					if (BYTE_ARRAY_1d2e_332a[local_6 - 0x01] == 6) {
						FUN_16d5_0019("Па тэксьце на бутэльцы Лявон засьпяваў \"Одзiрыдзiдзiну\".");
						FUN_16d5_0019("Пракляты бiлет выпаў з рук сам сабою!");
					}
					else {
						FUN_16d5_0019("Чорт! Гэты пракляты бiлет немагчыма выпусьцiць з рук!");
						FUN_16d5_0019("");
						FUN_16d5_0000();
						goto LAB_16d5_14c4;
					}
				}
				local_7 = BYTE_1d2e_334c;
				BYTE_1d2e_334c = BYTE_ARRAY_1d2e_332a[local_6 - 0x01];
				local_8 = BYTE_1d2e_3346;
				if (local_6 <= local_8) {
					BYTE_1d2e_331a = local_6;
					while (BYTE_ARRAY_1d2e_332a[BYTE_1d2e_331a - 0x01] = BYTE_ARRAY_1d2e_332a[BYTE_1d2e_331a],
						BYTE_1d2e_331a != local_8) {
						BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
					}
				}
				BYTE_ARRAY_1d2e_332a[BYTE_1d2e_3346 - 0x01] = local_7;
				local_108 = "Лявон узяў у рукi ";
				Concat(local_108, P_STRING_ARRAY_1d2e_0d3c[BYTE_1d2e_334c - 0x01]);
				Concat(local_108, ".              ");
				FUN_16d5_0019(local_108);
				local_4 = true;
			}
			if (BYTE_1d2e_331c == 1) {
				local_4 = true;
				BYTE_1d2e_331a = 1;
				while (FUN_1b04_0487(BYTE_1d2e_331a, 1, 0x20, 7), BYTE_1d2e_331a != 0x50) {
					BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
				}
				local_5 = true;
			}
			BYTE_1d2e_331c = 0xd;
			if (local_4) break;
		} while (true);
		local_3 = !local_5;
	}
	return local_3;
}

/*
	Show List of Goods
*/
void __pascal16far FUN_16d5_16e0(void)
{
	byte bVar1;
	undefined2 unaff_SS;
	PascalString255* psVar2;
	undefined uVar3;
	undefined uVar4;
	undefined4 uVar5;
	PascalString255 local_104;
	byte local_3;

	__StackCheck(0x102);
	local_3 = BYTE_1d2e_3347;
	if (local_3 != 0) {
		BYTE_1d2e_331a = 1;
		while (true) {
			BYTE_1d2e_331b = 8;
			while (FUN_1b04_0487(BYTE_1d2e_331b, BYTE_1d2e_331a + 5, 0x20, 7), BYTE_1d2e_331b != 0x3a) {
				BYTE_1d2e_331b = BYTE_1d2e_331b + 1;
			}
			if (BYTE_1d2e_331a == local_3) break;
			BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
		}
	}
	local_3 = BYTE_1d2e_3347;
	if (local_3 != 0) {
		BYTE_1d2e_331a = 1;
		while (FUN_1b04_0500(8, BYTE_1d2e_331a + 5, P_STRING__ARRAY_1d2e_0366[BYTE_ARRAY_1d2e_3336[BYTE_1d2e_331a - 0x01] - 0x01], 7),
			BYTE_1d2e_331a != local_3) {
			BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
		}
	}
	local_3 = BYTE_1d2e_3347;
	if (local_3 != 0) {
		BYTE_1d2e_331a = 1;
		while (true) {
			BYTE_ARRAY_1d2e_3358[0] = 0;
			Str(BYTE_ARRAY_1d2e_333e[BYTE_1d2e_331a - 0x01], 0, (PascalString255*)BYTE_ARRAY_1d2e_3358, 3);
			local_104 = (PascalString255&)BYTE_ARRAY_1d2e_3358;
			Concat(local_104, "  ");
			FUN_1b04_0500(0x41, BYTE_1d2e_331a + 5, local_104, 7);
			BYTE_ARRAY_1d2e_3358[0] = 0;
			Str(BYTE_1d2e_331a, 0, (PascalString255*)BYTE_ARRAY_1d2e_3358, 3);
			FUN_1b04_0500(5, BYTE_1d2e_331a + 5, (PascalString255&)BYTE_ARRAY_1d2e_3358, 7);
			FUN_1b04_0500(6, BYTE_1d2e_331a + 5, ".", 7);
			if (BYTE_1d2e_331a == local_3) break;
			BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
		}
	}
	bVar1 = BYTE_1d2e_3347 + 1;
	if (bVar1 <= 0xb) {
		BYTE_1d2e_331a = bVar1;
		while (true) {
			BYTE_1d2e_331b = 1;
			while (FUN_1b04_0487(BYTE_1d2e_331b, BYTE_1d2e_331a + 5, 0x20, 7), BYTE_1d2e_331b != 0x50) {
				BYTE_1d2e_331b = BYTE_1d2e_331b + 1;
			}
			if (BYTE_1d2e_331a == 0xb) break;
			BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
		}
	}
	return;
}

/*
	Buy Goods
*/
void __pascal16far FUN_16d5_1926(void)
{
	byte bVar1;
	byte bVar2;
	undefined2 unaff_SS;
	PascalString255* psVar3;
	undefined uVar4;
	undefined uVar5;
	undefined uVar6;
	undefined uVar7;
	undefined4 uVar8;
	PascalString255 local_206;
	byte local_107;
	PascalString255 local_106;
	byte local_5;
	byte local_4;
	byte local_3;

	__StackCheck(0x204);
	if (BYTE_1d2e_3347 == 0) {
		local_3 = 5;
		while (FUN_1b04_0487(local_3, 0x16, 0x20, 7), local_3 != 0x50) {
			local_3 = local_3 + 1;
		}
		FUN_1b04_0500(5, 0x16, "Усё! Скончылася пiва!", 7);
		FUN_1b04_05b3(&local_3, &local_4);
		local_3 = 5;
		while (FUN_1b04_0487(local_3, 0x16, 0x20, 7), local_3 != 0x50) {
			local_3 = local_3 + 1;
		}
	}
	else {
	LAB_16d5_19a3:
		do {
			local_3 = 5;
			while (true) {
				FUN_1b04_0487(local_3, 0x16, 0x20, 7);
				FUN_1b04_0487(local_3, 0x17, 0x20, 7);
				if (local_3 == 0x50) break;
				local_3 = local_3 + 1;
			}
			FUN_1b04_0500(5, 0x16, "Што будзем набываць ?", 7);
			Str(SWORD_1d2e_3354, 0, (PascalString255*)BYTE_ARRAY_1d2e_3358, 3);
			FUN_1b04_0500(0x3b, 0x18, "ГРОШЫ:       ", 7);
			FUN_1b04_0500(0x42, 0x18, (PascalString255&)BYTE_ARRAY_1d2e_3358, 7);
			FUN_1b04_05b3(&local_3, &local_4);
			if ((local_4 == 0x69) || (local_4 == 0x49)) {
				FUN_16d5_32b4();
			}
			if ((0x31 <= local_4) && (local_4 <= 0x38)) {
				if ((BYTE_1d2e_3347 < (local_4 - 0x30)) || (BYTE_1d2e_3347 == 0)) {
					goto LAB_16d5_19a3;
				}
				if ((SWORD_1d2e_3354 - BYTE_ARRAY_1d2e_333e[local_4 - 0x30 - 0x01]) < 0) {
					FUN_1b04_0500(5, 0x16, "А пянёндзаў-та нямашака !", 7);
					FUN_1b04_05b3(&local_3, &local_4);
					goto LAB_16d5_19a3;
				}
				if (9 < BYTE_1d2e_3346 + 1) {
					FUN_1b04_0500(5, 0x16, "А месца ў торбе няма!", 7);
					FUN_1b04_05b3(&local_3, &local_4);
					goto LAB_16d5_19a3;
				}
				SWORD_1d2e_3354 = SWORD_1d2e_3354 - BYTE_ARRAY_1d2e_333e[local_4 - 0x30 - 0x01];
				BYTE_ARRAY_1d2e_332a[BYTE_1d2e_3346] = BYTE_ARRAY_1d2e_3336[local_4 - 0x30 - 0x01];
				BYTE_1d2e_3346 = BYTE_1d2e_3346 + 1;
				FUN_1b04_0500(5, 0x17, "Набыў - ", 7);
				local_206 = P_STRING__ARRAY_1d2e_0366[BYTE_ARRAY_1d2e_3336[local_4 - 0x30 - 0x01] - 0x01];
				Concat(local_206, " ");
				FUN_1b04_0500(0x0d, 0x17, local_206, 7);
				FUN_1b04_0487(0xd, 0x17, 0xa1, 7);
				FUN_1b04_0487(0x14, 0x17, 0xe3, 7);
				local_5 = BYTE_ARRAY_1d2e_333e[local_4 - 0x30];
				Str(local_5, 0, (PascalString255*)BYTE_ARRAY_1d2e_3358, 3);
				bVar2 = local_5 % 10;
				if ((bVar2 == 0) || ((5 <= bVar2) && (bVar2 <= 9)) ||
					(bVar2 = local_5 % 100, (11 <= bVar2) && (bVar2 <= 14))) {
					local_106 = " грошаў.";
				}
				else if (local_5 % 10 == 1) {
					local_106 = " грош.";
				}
				else {
					local_106 = " грошы.";
				}
				local_206 = "за ";
				Concat(local_206, (PascalString255&)BYTE_ARRAY_1d2e_3358);
				Concat(local_206, local_106);
				FUN_1b04_0500(0x38, 0x17, local_206, 7);
				local_107 = BYTE_1d2e_3347 - 1;
				bVar1 = local_4 - 0x30;
				if (bVar1 <= local_107) {
					BYTE_1d2e_331a = bVar1;
					while (true) {
						BYTE_ARRAY_1d2e_3336[BYTE_1d2e_331a - 0x01] = BYTE_ARRAY_1d2e_3336[BYTE_1d2e_331a];
						BYTE_ARRAY_1d2e_333e[BYTE_1d2e_331a - 0x01] = BYTE_ARRAY_1d2e_333e[BYTE_1d2e_331a];
						if (BYTE_1d2e_331a == local_107) break;
						BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
					}
				}
				BYTE_1d2e_3347 = BYTE_1d2e_3347 - 1;
				FUN_1b04_05b3(&local_3, &local_4);
				FUN_16d5_16e0();
			}
			FUN_16d5_16e0();
			if ((local_3 == 1) || (BYTE_1d2e_3347 == 0)) break;
		} while (true);
	}
}

/*
	Sell Goods
*/
void __pascal16far FUN_16d5_1e17(void)
{
	char cVar1;
	void* pcVar2;
	byte bVar3;
	byte bVar4;
	word wVar5;
	undefined2 unaff_SS;
	PascalString255* psVar6;
	undefined uVar7;
	undefined uVar8;
	undefined uVar9;
	undefined uVar10;
	undefined4 uVar11;
	PascalString255 local_206;
	byte local_107;
	PascalString255 local_106;
	byte local_5;
	byte local_4;
	byte local_3;

	__StackCheck(0x204);
	if (BYTE_1d2e_3346 == 0) {
		local_3 = 5;
		while (FUN_1b04_0487(local_3, 0x16, 0x20, 7), local_3 != 0x50) {
			local_3 = local_3 + 1;
		}
		FUN_1b04_0500(5, 0x16, "I чаго гэта ты зьбiраесься прадаваць?", 7);
		FUN_1b04_05b3(&local_3, &local_4);
		local_3 = 5;
		while (FUN_1b04_0487(local_3, 0x16, 0x20, 7), local_3 != 0x50) {
			local_3 = local_3 + 1;
		}
	}
	else {
	LAB_16d5_1e94:
		do {
			local_3 = 5;
			while (true) {
				FUN_1b04_0487(local_3, 0x16, 0x20, 7);
				FUN_1b04_0487(local_3, 0x17, 0x20, 7);
				if (local_3 == 0x50) break;
				local_3 = local_3 + 1;
			}
			Str(BYTE_1d2e_3346, 0, (PascalString255*)BYTE_ARRAY_1d2e_3358, 3);
			local_206 = "Што будзем прадаваць (1..";
			Concat(local_206, (PascalString255&)BYTE_ARRAY_1d2e_3358);
			Concat(local_206, "), * - iнвентар ?");
			FUN_1b04_0500(0x05, 0x16, local_206, 7);
			Str(SWORD_1d2e_3354, 0, (PascalString255*)BYTE_ARRAY_1d2e_3358, 3);
			FUN_1b04_0500(0x3b, 0x18, "ГРОШЫ:       ", 7);
			FUN_1b04_0500(0x42, 0x18, (PascalString255&)BYTE_ARRAY_1d2e_3358, 7);
			FUN_1b04_05b3(&local_3, &local_4);
			if ((local_3 == 0x17) || (local_3 == 0x37)) {
				local_4 = FUN_16d5_32b4();
			}
			if ((0x31 <= local_4) && (local_4 <= 0x3b)) {
				if (BYTE_1d2e_3346 < (local_4 - 0x30)) {
					goto LAB_16d5_1e94;
				}
				if (8 < (BYTE_1d2e_3347 + 1)) {
					FUN_1b04_0500(5, 0x16, "А месца на складзе няма!                            ", 7);
					FUN_1b04_05b3(&local_3, &local_4);
					goto LAB_16d5_1e94;
				}
				cVar1 = BYTE_ARRAY_1d2e_332a[local_4 - 0x30 - 0x01];
				if (cVar1 == 1) {
					local_5 = 15;
				}
				else if (cVar1 == 2) {
					local_5 = 50;
				}
				else if ((cVar1 == 3) || (cVar1 == 4)) {
					local_5 = 25;
				}
				else if (cVar1 == 5) {
					local_5 = 60;
				}
				else if (cVar1 == 16) {
					local_5 = 120;
				}
				else if (cVar1 == 6) {
					FUN_1b04_0500(5, 0x16, "Пачакай, мо спатрэбiцца яшчэ...             ", 7);
					Console.WaitForInput();
					return;
				}
				else {
					FUN_1b04_0500(5, 0x16, "А гэта ж ня пiва!                                 ", 7);
					Console.WaitForInput();
					return;
				}
				SWORD_1d2e_3354 = SWORD_1d2e_3354 + local_5;
				FUN_1b04_0500(5, 0x17, "Прадаў - ", 7);
				local_206 = P_STRING__ARRAY_1d2e_0366[BYTE_ARRAY_1d2e_332a[local_4 - 0x30 - 0x01] - 0x01];
				Concat(local_206, " ");
				FUN_1b04_0500(0x0E, 0x17, local_206, 7);
				FUN_1b04_0487(0xe, 0x17, 0xa1, 7);
				FUN_1b04_0487(0x15, 0x17, 0xe3, 7);
				Str(local_5, 0, (PascalString255*)BYTE_ARRAY_1d2e_3358, 3);
				bVar4 = local_5 % 10;
				if ((bVar4 == 0) || ((5 <= bVar4) && (bVar4 <= 9)) ||
					(bVar4 = local_5 % 100, (11 <= bVar4) && (bVar4 <= 14))) {
					local_106 = " грошаў.";
				}
				else if (local_5 % 10 == 1) {
					local_106 = " грош.";
				}
				else {
					local_106 = " грошы.";
				}
				local_206 = "за ";
				Concat(local_206, (PascalString255&)BYTE_ARRAY_1d2e_3358);
				Concat(local_206, local_106);
				FUN_1b04_0500(0x38, 0x17, local_206, 7);
				BYTE_1d2e_3347 = BYTE_1d2e_3347 + 1;
				BYTE_ARRAY_1d2e_3336[BYTE_1d2e_3347 - 0x01] = BYTE_ARRAY_1d2e_332a[local_4 - 0x30 - 0x01];
				BYTE_ARRAY_1d2e_333e[BYTE_1d2e_3347 - 0x01] = local_5 * 2 + Random(5);
				local_107 = BYTE_1d2e_3346;
				bVar3 = local_4 - 0x30;
				if (bVar3 <= local_107) {
					BYTE_1d2e_331a = bVar3;
					while (BYTE_ARRAY_1d2e_332a[BYTE_1d2e_331a - 0x01] = BYTE_ARRAY_1d2e_332a[BYTE_1d2e_331a],
						BYTE_1d2e_331a != local_107) {
						BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
					}
				}
				BYTE_1d2e_3346 = BYTE_1d2e_3346 - 1;
				FUN_1b04_05b3(&local_3, &local_4);
			}
			FUN_16d5_16e0();
			if ((local_3 == 1) || (BYTE_1d2e_3346 == 0)) break;
		} while (true);
	}
}

/*
	Display Pub Screen
*/
void __pascal16far FUN_16d5_230b(void)
{
	void* pcVar1;
	undefined2 unaff_SS;
	PascalString255* psVar2;
	undefined uVar3;
	undefined uVar4;
	undefined uVar5;
	undefined uVar6;
	undefined4 uVar7;
	PascalString255 local_106;
	byte local_5;
	byte local_4;
	byte local_3;

	__StackCheck(0x104);
	Console.ResetBuffer();
	Console.HideCursor();
	FUN_1b04_0d8a();
	do {
		Console.ClearBuffer(0, 0, 80*25);
		Str(SWORD_1d2e_3354, 0, (PascalString255*)BYTE_ARRAY_1d2e_3358, 3);
		local_106 = "ГРОШЫ: ";
		Concat(local_106, (PascalString255&)BYTE_ARRAY_1d2e_3358);
		FUN_1b04_0500(0x3B, 0x18, local_106, 7);
		if (SWORD_1d2e_3354 < 10) {
			FUN_1b04_0500(6, 0x14, "Дарэчы, на свае грошы ты зможаш набыць цэлую (!) кроплю пiва !", 7);
		}
		FUN_1b04_0500(5, 2, "Пiўнуха - рай для Лявона,", 7);
		FUN_1b04_0500(0x1f, 2, "бо гопнiкi сюды ня соўваюцца - баяцца", 7);
		FUN_1b04_0500(5, 0x16, "[F1]  - прадаць пiва", 7);
		FUN_1b04_0500(5, 0x17, "[F2]  - набыць пiва ", 7);
		FUN_1b04_0500(5, 0x18, "[Esc] - Выхад", 7);
		FUN_1b04_0500(0x1d, 4, "Пiўнуха \"Чэсны Iзя\"", 0xe);
		for (local_5 = 5; FUN_1b04_0487(local_5, 0x15, 0xc4, 7), local_5 != 0x44; local_5 = local_5 + 1) {
		}
		FUN_16d5_16e0();
		while ((local_5 == 0) || (3 < local_5)) {
			FUN_1b04_05b3(&local_3, &local_4);
			if ((local_4 == 0x69) || (local_4 == 0x49)) {
				FUN_16d5_32b4();
			}
			if (local_3 == 1) {
				local_5 = 1;
			}
			if (local_3 == 0x3b) {
				local_5 = 2;
			}
			if (local_3 == 0x3c) {
				local_5 = 3;
			}
		}
		if (local_5 == 3) {
			FUN_16d5_1926();
		}
		if (local_5 == 2) {
			FUN_16d5_1e17();
		}
	} while (local_5 != 1);
	Console.ClearBuffer(0, 0, 80*25);
	FUN_16d5_0f6c();
	FUN_1b04_0487(BYTE_1d2e_1529, BYTE_1d2e_152a, 0x31, 0xe);
	return;
}

/*
	Refresh Beer Stock
*/
void __pascal16far FUN_16d5_24c7(void)
{
	byte bVar1;
	byte bVar2;
	word wVar3;
	byte local_4;
	byte local_3;

	__StackCheck(2);
	BYTE_1d2e_3347 = Random(5) + 4;
	local_4 = BYTE_1d2e_3347;
	if (local_4 != 0) {
		BYTE_1d2e_331a = 1;
		while (true) {
			local_3 = Random(6) + 1;
			if (5 < local_3) {
				local_3 = local_3 + 10;
			}
			BYTE_ARRAY_1d2e_3336[BYTE_1d2e_331a - 0x01] = local_3;
			bVar1 = BYTE_ARRAY_1d2e_3336[BYTE_1d2e_331a - 0x01];
			if (bVar1 == 1) {
				BYTE_ARRAY_1d2e_333e[BYTE_1d2e_331a - 0x01] = Random(10) + 30;
			}
			else if (bVar1 == 2) {
				BYTE_ARRAY_1d2e_333e[BYTE_1d2e_331a - 0x01] = Random(10) + 100;
			}
			else if ((bVar1 == 3) || (bVar1 == 4)) {
				BYTE_ARRAY_1d2e_333e[BYTE_1d2e_331a - 0x01] = Random(10) + 50;
			}
			else if (bVar1 == 5) {
				BYTE_ARRAY_1d2e_333e[BYTE_1d2e_331a - 0x01] = Random(10) + 120;
			}
			else if (bVar1 == 16) {
				BYTE_ARRAY_1d2e_333e[BYTE_1d2e_331a - 0x01] = Random(10) + 210;
			}
			if (BYTE_1d2e_331a == local_4) break;
			BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
		}
	}
	return;
}

/*
	Fill Level Tiles
*/
void __pascal16far FUN_16d5_25d9(byte levelid)
{
	__StackCheck(0);
	// Fill Edge Tiles
	BYTE_1d2e_331a = 0xf;
	while (BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_331a - 0x0F][0] = 0xb1,
		BYTE_1d2e_331a != 0x50) {
		BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
	}
	BYTE_1d2e_331a = 3;
	while (BYTE_ARRAY_ARRAY_1d2e_152c[0][BYTE_1d2e_331a - 0x02] = 0xb1,
		BYTE_1d2e_331a != 0x18) {
		BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
	}
	BYTE_1d2e_331a = 0xf;
	while (BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_331a - 0x0F][0x16] = 0xb1,
		BYTE_1d2e_331a != 0x50) {
		BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
	}
	BYTE_1d2e_331a = 3;
	while (BYTE_ARRAY_ARRAY_1d2e_152c[0x41][BYTE_1d2e_331a - 0x02] = 0xb1,
		BYTE_1d2e_331a != 0x18) {
		BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
	}
	// Fill Empty Tiles
	BYTE_1d2e_331a = 0x10;
	while (true) {
		BYTE_1d2e_331b = 3;
		while (BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_331a - 0x0F][BYTE_1d2e_331b - 0x02] = 0xfa,
			BYTE_1d2e_331b != 0x17) {
			BYTE_1d2e_331b = BYTE_1d2e_331b + 1;
		}
		if (BYTE_1d2e_331a == 0x4f) break;
		BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
	}
	// Fill City Level Tiles
	if (levelid == 1) {
		BYTE_1d2e_331a = 0x1a;
		while (true) {
			BYTE_1d2e_331b = 8;
			while (BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_331a - 0x0F][BYTE_1d2e_331b - 0x02] = 0xb1,
				BYTE_1d2e_331b != 0xe) {
				BYTE_1d2e_331b = BYTE_1d2e_331b + 1;
			}
			if (BYTE_1d2e_331a == 0x24) break;
			BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
		}
		BYTE_1d2e_331a = 0x37;
		while (true) {
			BYTE_1d2e_331b = 0xd;
			while (BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_331a - 0x0F][BYTE_1d2e_331b - 0x02] = 0xb1,
				BYTE_1d2e_331b != 0x15) {
				BYTE_1d2e_331b = BYTE_1d2e_331b + 1;
			}
			if (BYTE_1d2e_331a == 0x3a) break;
			BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
		}
		BYTE_1d2e_331a = 0x39;
		while (true) {
			BYTE_1d2e_331b = 4;
			while (BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_331a - 0x0F][BYTE_1d2e_331b - 0x02] = 0xb1,
				BYTE_1d2e_331b != 9) {
				BYTE_1d2e_331b = BYTE_1d2e_331b + 1;
			}
			if (BYTE_1d2e_331a == 0x45) break;
			BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
		}
		BYTE_ARRAY_ARRAY_1d2e_152c[0x10][6] = 0x31;
		BYTE_ARRAY_ARRAY_1d2e_152c[0x28][0xf] = 0x32;
		if (BYTE_1d2e_1104 != 0) {
			BYTE_ARRAY_ARRAY_1d2e_152c[0x36][6] = 0x33;
		}
		BYTE_ARRAY_ARRAY_1d2e_152c[0x3f][0x14] = 0x3e;
	}
	// Fill Subway Level Tiles
	if (levelid == 2) {
		BYTE_1d2e_331a = 0x10;
		while (true) {
			BYTE_1d2e_331b = 3;
			while (BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_331a - 0x0F][BYTE_1d2e_331b - 0x02] = 0xfa,
				BYTE_1d2e_331b != 0x17) {
				BYTE_1d2e_331b = BYTE_1d2e_331b + 1;
			}
			if (BYTE_1d2e_331a == 0x4f) break;
			BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
		}
		BYTE_1d2e_331a = 0x10;
		while (BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_331a - 0x0F][0x05] = 0xb1,
			BYTE_1d2e_331a != 0x4f) {
			BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
		}
		BYTE_ARRAY_ARRAY_1d2e_152c[0x1c][6] = 0xb1;
		BYTE_1d2e_331b = 8;
		while (BYTE_ARRAY_ARRAY_1d2e_152c[0x19][BYTE_1d2e_331b - 0x02] = 0xb1,
			BYTE_1d2e_331b != 10) {
			BYTE_1d2e_331b = BYTE_1d2e_331b + 1;
		}
		BYTE_1d2e_331b = 0x29;
		while (BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_331b - 0x0F][0x08] = 0xb1,
			BYTE_1d2e_331b != 0x2b) {
			BYTE_1d2e_331b = BYTE_1d2e_331b + 1;
		}
		BYTE_1d2e_331a = 1;
		while (BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_331a * 2 + 0x2B - 0x0F][0x05] = 0xc4, // 0xC4 - Turnstile
			BYTE_1d2e_331a != 6) {
			BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
		}
		BYTE_1d2e_331a = 0x10;
		while (true) {
			BYTE_1d2e_331b = 0x10;
			while (BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_331a - 0x0F][BYTE_1d2e_331b - 0x02] = 0xfa,
				BYTE_1d2e_331b != 0x11) {
				BYTE_1d2e_331b = BYTE_1d2e_331b + 1;
			}
			if (BYTE_1d2e_331a == 0x4f) break;
			BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
		}
		BYTE_1d2e_331a = 0x10;
		while (BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_331a - 0x0F][0x10] = 0xb1,
			BYTE_1d2e_331a != 0x4f) {
			BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
		}
		BYTE_1d2e_1529 = 0x10;
		BYTE_1d2e_152a = 4;
		BYTE_ARRAY_ARRAY_1d2e_152c[1][2] = 0x3c;
	}
	// Fill Club Level Tiles
	if (levelid == 3) {
		BYTE_1d2e_331a = 2;
		while (BYTE_ARRAY_ARRAY_1d2e_152c[0x1D][BYTE_1d2e_331a - 0x02] = 0xb1,
			BYTE_1d2e_331a != 5) {
			BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
		}
		BYTE_1d2e_331a = 2;
		while (BYTE_ARRAY_ARRAY_1d2e_152c[0x25][BYTE_1d2e_331a - 0x02] = 0xb1,
			BYTE_1d2e_331a != 5) {
			BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
		}
		BYTE_1d2e_331a = 0x2c;
		while (BYTE_ARRAY_ARRAY_1d2e_152c[BYTE_1d2e_331a - 0x0F][0x05] = 0xb1,
			BYTE_1d2e_331a != 0x34) {
			BYTE_1d2e_331a = BYTE_1d2e_331a + 1;
		}
		BYTE_ARRAY_ARRAY_1d2e_152c[0x21][0x15] = 0x3c;
		BYTE_ARRAY_ARRAY_1d2e_152c[0x21][4] = 0x5d;
		BYTE_1d2e_1529 = 0x30;
		BYTE_1d2e_152a = 0x17;
	}
	return;
}

/*
	Display Government House Sceen
*/
void __pascal16far FUN_16d5_29fd(void)
{
	undefined2 unaff_SS;
	byte local_4;
	byte local_3;

	__StackCheck(2);
	Console.ClearBuffer(0, 0, 80*25);
	FUN_1b04_0500(0x19, 1, "Ды ты ведаеш, куды трапiў?!!", 0xf);
	local_3 = 1;
	while (true) {
		FUN_1b04_0487(local_3, 2, 0, 0x40);
		if (local_3 == 0x50) break;
		local_3 = local_3 + 1;
	}
	local_3 = 1;
	while (true) {
		FUN_1b04_0487(local_3, 3, 0, 0x40);
		if (local_3 == 0x50) break;
		local_3 = local_3 + 1;
	}
	local_3 = 1;
	while (true) {
		FUN_1b04_0487(local_3, 4, 0, 0x20);
		if (local_3 == 0x50) break;
		local_3 = local_3 + 1;
	}
	FUN_1b04_0500(0x16, 6, "Зойдзеш ва Ўрад - выйдзеш наўрад!", 0xe);
	FUN_1b04_0500(0x16, 7, " Самога зьядуць, пiвам зап\'юць,", 0xe);
	FUN_1b04_0500(0x14, 8, "Бо нашыя ўладары - найпершыя гапары!", 0xe);
	FUN_1b04_0500(0x13, 9, "Бягi адсюль, браце, покуль можаш бяжацi!", 0xe);
	FUN_1b04_0500(0x21, 0xb, "- далей -", 0xe);
	do {
		FUN_1b04_05b3(&local_3, &local_4);
	} while (local_4 != 0xd);
	Console.ClearBuffer(0, 0, 80*25);
	FUN_16d5_0f6c();
	return;
}

/*
	Update Drunkenness Status
*/
void __pascal16far FUN_16d5_2c2c(void)
{
	__StackCheck(0);
	if (SBYTE_1d2e_3327 == -1) {
		SWORD_1d2e_334e = -1;
	}
	if ((0 < SWORD_1d2e_334e) && (SWORD_1d2e_334e <= 300) && (0 < SBYTE_1d2e_3327)) {
		if (BYTE_1d2e_3329 == 0) {
			FUN_16d5_0019("Вось так лепей будзе!");
		}
		Console.ClearBuffer(0, 24, 22);
		SBYTE_1d2e_3327 = 0;
	}
	if ((SWORD_1d2e_334e <= 0) && (SBYTE_1d2e_3327 != -1)) {
		FUN_16d5_0019("Авой! Зялёныя чорцiкi!");
		BYTE_1d2e_3349 = 0xff;
		FUN_1b04_0500(1, 0x19, "У дошку...            ", 7);
		BYTE_1d2e_3328 = 1;
		SBYTE_1d2e_3327 = -1;
	}
	if ((300 < SWORD_1d2e_334e) && (SWORD_1d2e_334e <= 400) && (SBYTE_1d2e_3327 != 1)) {
		FUN_16d5_0019("У Лявона сьвятлее ў вачах...");
		FUN_1b04_0500(1, 0x19, "Цьвярозы!!!           ", 7);
		SBYTE_1d2e_3327 = 1;
	}
	if ((400 < SWORD_1d2e_334e) && (SWORD_1d2e_334e <= 500) && (SBYTE_1d2e_3327 != 2)) {
		FUN_16d5_0019("Перад вачыма Лявона неадступна стаiць бутэлька пiва...");
		FUN_1b04_0500(1, 0x19, "Памiрае - пiва хоча!!! ", 7);
		SBYTE_1d2e_3327 = 2;
	}
	if ((BYTE_1d2e_3349 == 0) && (SBYTE_1d2e_3327 == -1)) {
		FUN_16d5_0019("Ну, вось ужо й гайдацца перастаў.");
		BYTE_1d2e_3328 = 0;
		Console.ClearBuffer(0, 24, 22);
		SBYTE_1d2e_3327 = 0;
		SWORD_1d2e_334e = 1;
	}
	if (500 < SWORD_1d2e_334e) {
		FUN_16d5_2e05("ад абясьпiўленьня", "арганiзму");
	}
	return;
}

/*
	Display Death Screen
*/
void __pascal16far FUN_16d5_2e05(const PascalString255& string1, const PascalString255& string2)
{
	byte* pbVar1;
	char* pcVar2;
	void* pcVar3;
	word wVar4;
	word wVar5;
	char cVar6;
	uint uVar7;
	PascalString255* pPVar8;
	undefined2 unaff_SS;
	undefined uVar9;
	undefined uVar10;
	PascalString255* pPVar11;
	PascalString255 local_60c;
	word local_50c;
	byte local_509;
	byte local_508;
	byte local_507;
	byte local_506;
	byte local_505;
	UFileStream local_504;
	UFileStream local_484;
	byte local_404;
	byte local_403;
	PascalString255 local_402;
	PascalString255 local_302;
	PascalString255 local_202;
	PascalString255 local_102;

	__StackCheck(0x60a);
	local_102 = string1;
	local_202 = string2;
	FUN_1b04_0234();
	Console.ResetBuffer();
	Console.HideCursor();
	FUN_1b04_0c7f("mnskbnd1.dat", 0, 0xff);
	FUN_1b04_0d8a();
	FUN_1b04_03ed();
	Console.ClearInputBuffer();
	Assign(local_504, "mnskbnd4.dat");
	Reset(local_504, 1);
	__IOCheck();
	while (true) {
		cVar6 = Eof(local_504);
		__IOCheck();
		if (cVar6 != 0) break;
		Read(local_504, &local_505);
		__IOCheck();
		Read(local_504, &local_506);
		__IOCheck();
		Read(local_504, &local_507);
		__IOCheck();
		local_505 = local_505 ^ 0xdf;
		local_506 = local_506 ^ 0xdf;
		local_507 = local_507 ^ 0xdf;
		FUN_1b04_0487(local_505, local_506, local_507, 7);
	}
	Close(local_504);
	__IOCheck();
	if (BYTE_1d2e_334b == 1) {
		local_402 = "Памёр у горадзе";
	}
	else if (BYTE_1d2e_334b == 2) {
		local_402 = "Памёр у метро";
	}
	else if (BYTE_1d2e_334b == 3) {
		local_402 = "Памёр у клюбе";
	}
	FUN_1b04_0500(0x18, 10, "Лявон", 7);
	FUN_1b04_0500((0x1b - local_402.size()) / 2 + 0xd, 0xc, local_402, 7);
	FUN_1b04_0500((0x1b - local_102.size()) / 2 + 0xd, 0xe, local_102, 7);
	FUN_1b04_0500((0x1b - local_202.size()) / 2 + 0xd, 0xf, local_202, 7);
	Str(WORD_1d2e_3352, 4, &local_402, 0xff);
	local_60c = "Меў вопыту : ";
	Concat(local_60c, local_402);
	local_402 = local_60c;
	FUN_1b04_0500((0x1b - local_402.size()) / 2 + 0xd, 0x11, local_402, 7);
	FUN_1b04_01b1(&local_508, &local_509, &local_50c);
	local_402.clear();
	Str(local_508, 0, &local_302, 0xff);
	if (local_302.size() < 2) {
		local_60c = "0";
		Concat(local_60c, local_302);
		local_302 = local_60c;
	}
	local_60c = local_402;
	Concat(local_60c, local_302);
	Concat(local_60c, ".");
	local_402 = local_60c;
	Str(local_509, 0, &local_302, 0xff);
	if (local_302.size() < 2) {
		local_60c = "0";
		Concat(local_60c, local_302);
		local_302 = local_60c;
	}
	local_60c = local_402;
	Concat(local_60c, local_302);
	Concat(local_60c, ".");
	local_402 = local_60c;
	Str(local_50c, 4, &local_302, 0xff);
	local_60c = local_402;
	Concat(local_60c, local_302);
	local_402 = local_60c;
	FUN_1b04_0500(0x16, 0xd, local_402, 7);
	FUN_1b04_0500(0x18, 0x18, "Нацiсьнiце [Enter]...", 7);
	do {
		FUN_1b04_05b3(&local_403, &local_404);
	} while (local_404 != 0xd);
	Assign(local_484, "menskbnd.sav");
	Rewrite(local_484, 0x80);
	__IOCheck();
	Close(local_484);
	__IOCheck();
	FUN_16d5_3548();
	Console.ResetBuffer();
	Halt(0);
	return;
}

/*
	Show Inventory Content
*/
byte __pascal16far FUN_16d5_32b4(void)
{
	byte bVar1;
	undefined2 unaff_SS;
	PascalString255* pPVar2;
	undefined4 uVar3;
	PascalString255 local_a68;
	PascalString255 local_a66;
	byte local_967;
	byte local_966;
	byte local_965;
	byte local_964[2400];
	byte local_3;

	__StackCheck(0xa66);
	Console.SaveBuffer(0, 0, 80, 15);
	local_965 = 1;
	while (FUN_1b04_0487(local_965, 1, 0x20, 7), local_965 != 0x50) {
		local_965 = local_965 + 1;
	}
	FUN_1b04_0500(1, 1, "                   А з сабою ў Лявона ...", 7);
	if (BYTE_1d2e_3346 > 0) {
		local_967 = BYTE_1d2e_3346;
		if (local_967 != 0) {
			local_965 = 1;
			while (true) {
				local_966 = 0x1e;
				while (FUN_1b04_0487(local_966, local_965 + 1, 0x20, 0), local_966 != 0x50) {
					local_966 = local_966 + 1;
				}
				local_a68 = " ";
				Concat(local_a68, P_STRING_ARRAY_1d2e_0340[local_965]);
				Concat(local_a68, ") ");
				Concat(local_a68, P_STRING__ARRAY_1d2e_0366[BYTE_ARRAY_1d2e_332a[local_965 - 0x01] - 0x01]);
				FUN_1b04_0500(0x1E, local_965 + 1, local_a68, 7);
				if (local_965 == local_967) break;
				local_965 = local_965 + 1;
			}
		}
	}
	local_965 = 0x1e;
	while (FUN_1b04_0487(local_965, BYTE_1d2e_3346 + 2, 0x20, 0), local_965 != 0x50) {
		local_965 = local_965 + 1;
	}
	local_a66 = " Зб: ";
	Concat(local_a66, P_STRING__ARRAY_1d2e_0366[BYTE_1d2e_334c - 0x01]);
	FUN_1b04_0500(0x1E, BYTE_1d2e_3346 + 2, local_a66, 7);
	FUN_1b04_0670();
	FUN_1b04_05b3(&local_965, &local_966);
	Console.RestoreBuffer(0, 0, 80, 15);
	local_3 = local_966;
	return local_3;
}

/*
	Set Cursor Position
*/
void __pascal16near FUN_16d5_3476(byte xpos, byte ypos)
{
	Console.SetCursorPositon(xpos, ypos);
	return;
}

/*
	Display Hall of Fame
*/
void __pascal16far FUN_16d5_3548(void)
{
	char* pcVar1;
	int iVar2;
	void* pcVar3;
	char cVar4;
	byte bVar5;
	word wVar6;
	undefined2 unaff_SS;
	bool bVar7;
	PascalString255* psVar8;
	undefined uVar9;
	undefined uVar10;
	undefined uVar11;
	undefined uVar12;
	PascalString255* pPVar13;
	undefined4 uVar14;
	PascalString255 local_5c4;
	byte local_4c5;
	PascalString255 local_4c4;
	PascalString255 local_3c4;
	PascalString255 local_2c4;
	byte local_1c3;
	byte local_1c2;
	byte local_1c1;
	byte local_1c0;
	byte local_1bf;
	byte local_1be;
	byte local_1bd;
	word local_1bc[7];
	word local_1ae;
	byte local_1ac;
	byte local_1ab;
	PascalString255 local_1aa[7]; // byte local_1aa[7][11];
	PascalString255 local_15c[7]; // byte local_15c[7][31];
	UFileStream local_82;

	__StackCheck(0x5c2);
	Console.ResetBuffer();
	FUN_1b04_0d8a();
	FUN_1b04_03ed();
	FUN_1b04_0487(1, 1, 0xd0, 7);
	FUN_1b04_0487(0x50, 1, 0xd1, 7);
	FUN_1b04_0487(1, 0x17, 0xd3, 7);
	FUN_1b04_0487(0x50, 0x17, 0xd2, 7);
	for (local_1c0 = 2; FUN_1b04_0487(local_1c0, 1, 0xd5, 7), local_1c0 != 0x4f;
		local_1c0 = local_1c0 + 1) {
	}
	for (local_1c0 = 2; FUN_1b04_0487(local_1c0, 0x17, 0xd4, 7), local_1c0 != 0x4f;
		local_1c0 = local_1c0 + 1) {
	}
	for (local_1c0 = 2; FUN_1b04_0487(1, local_1c0, 0xd7, 7), local_1c0 != 0x16;
		local_1c0 = local_1c0 + 1) {
	}
	for (local_1c0 = 2; FUN_1b04_0487(0x50, local_1c0, 0xd6, 7), local_1c0 != 0x16;
		local_1c0 = local_1c0 + 1) {
	}
	FUN_1b04_0500(0x20, 2, "ЛЕПШЫЯ ЗЬ ЛЕПШЫХ", 0xb);
	FUN_1b04_0500(0x1b, 3, "\"Прыйшоў, Убачыў, Замачыў\"", 0xb);
	IOResult();
	FUN_1b04_01b1(&local_1ab, &local_1ac, &local_1ae);
	local_3c4.clear();
	Str(local_1ab, 0, &local_4c4, 0xff);
	if (local_4c4.size() < 2) {
		local_5c4 = "0";
		Concat(local_5c4, local_4c4);
		local_4c4 = local_5c4;
	}
	local_5c4 = local_3c4;
	Concat(local_5c4, local_4c4);
	Concat(local_5c4, ".");
	local_3c4 = local_5c4;
	Str(local_1ac, 0, &local_4c4, 0xff);
	if (local_4c4.size() < 2) {
		local_5c4 = "0";
		Concat(local_5c4, local_4c4);
		local_4c4 = local_5c4;
	}
	local_5c4 = local_3c4;
	Concat(local_5c4, local_4c4);
	Concat(local_5c4, ".");
	local_3c4 = local_5c4;
	Str(local_1ae, 4, &local_4c4, 0xff);
	local_5c4 = local_3c4;
	Concat(local_5c4, local_4c4);
	local_3c4 = local_5c4;
	Assign(local_82, "menskbnd.hof");
	Reset(local_82, 1);
	__IOCheck();
	local_1bf = 1;
	if (IOResult() == 0) {
		for (; local_1bf <= 7; local_1bf = local_1bf + 1) {
			cVar4 = Eof(local_82);
			__IOCheck();
			if (cVar4 != 0) break;
			local_15c[local_1bf - 0x01].resize(0x1e);
			BlockRead(local_82, (byte*)local_15c[local_1bf - 0x01].data(), 0x1e, NULL);
			__IOCheck();
			for (local_1c0 = 1;
				local_15c[local_1bf - 0x01][local_1c0 - 0x01] =
				local_15c[local_1bf - 0x01][local_1c0 - 0x01] ^ 0xad,
				local_1c0 != 0x1e; local_1c0 = local_1c0 + 1) {
			}
			local_1aa[local_1bf - 0x01].resize(10);
			BlockRead(local_82, (byte*)local_1aa[local_1bf - 0x01].data(), 10, NULL);
			__IOCheck();
			BlockRead(local_82, (byte*)&local_1bc[local_1bf - 0x01], 2, NULL);
			__IOCheck();
			for (local_1c0 = 1;
				local_1aa[local_1bf - 0x01][local_1c0 - 0x01] =
				local_1aa[local_1bf - 0x01][local_1c0 - 0x01] ^ 0xad,
				local_1c0 != 10; local_1c0 = local_1c0 + 1) {
			}
		}
	}
	local_1bf = local_1bf - 1;
	local_1be = 0;
	for (local_1c0 = 1; local_1c0 <= local_1bf; local_1c0 = local_1c0 + 1) {
		if (local_1c0 == 1) {
			local_1c3 = 0xe;
		}
		else {
			local_1c3 = 9;
		}
		FUN_1b04_0487(9, local_1c0 * 2 + 3, local_1c0 + 0x30, local_1c3);
		iVar2 = local_1bc[local_1c0 - 0x01];
		if (((0 <= iVar2) && (WORD_1d2e_3352 <= iVar2)) || (local_1be != 0))
		{
			FUN_1b04_0500(0xe, local_1c0 * 2 + 3, local_15c[local_1c0 - 0x01], local_1c3);
			local_5c4 = "(";
			Concat(local_5c4, local_1aa[local_1c0 - 0x01]);
			Concat(local_5c4, ")");
			FUN_1b04_0500(0x2D, local_1c0 * 2 + 3, local_5c4, local_1c3);
			Str(local_1bc[local_1c0 - 0x01], 4, &local_2c4, 0xff);
			local_5c4 = "ВОПЫТУ: ";
			Concat(local_5c4, local_2c4);
			FUN_1b04_0500(0x3E, local_1c0 * 2 + 3, local_5c4, local_1c3);
		}
		else if (local_1be == 0) {
			local_5c4 = "(";
			Concat(local_5c4, local_3c4);
			Concat(local_5c4, ")");
			FUN_1b04_0500(0x2D, local_1c0 * 2 + 3, local_5c4, local_1c3);
			Str(WORD_1d2e_3352, 4, &local_2c4, 0xff);
			local_5c4 = "ВОПЫТУ: ";
			Concat(local_5c4, local_2c4);
			FUN_1b04_0500(0x3E, local_1c0 * 2 + 3, local_5c4, local_1c3);
			local_1be = local_1c0;
			if (local_1c0 < 7) {
				FUN_1b04_0487(9, local_1c0 * 2 + 5, local_1c0 + 0x31, 9);
				FUN_1b04_0500(0xe, local_1c0 * 2 + 5, local_15c[local_1c0 - 0x01], 9);
				local_5c4 = "(";
				Concat(local_5c4, local_1aa[local_1c0 - 0x01]);
				Concat(local_5c4, ")");
				FUN_1b04_0500(0x2D, local_1c0 * 2 + 5, local_5c4, 9);
				Str(local_1bc[local_1c0 - 0x01], 4, &local_2c4, 0xff);
				local_5c4 = "ВОПЫТУ: ";
				Concat(local_5c4, local_2c4);
				FUN_1b04_0500(0x3E, local_1c0 * 2 + 5, local_5c4, 9);
				local_1c0 = local_1c0 + 1;
			}
			if (local_1bf < 7) {
				local_1bf = local_1bf + 1;
			}
			local_4c5 = local_1be + 1;
			if (local_4c5 <= local_1bf) {
				local_1c1 = local_1bf;
				while (true) {
					local_15c[local_1c1 - 0x01] = PascalString255(local_15c[local_1c1 - 0x01 - 0x01].c_str(), 0x1E);
					local_1aa[local_1c1 - 0x01] = PascalString255(local_1aa[local_1c1 - 0x01 - 0x01].c_str(), 0x0A);
					local_1bc[local_1c1 - 0x01] = local_1bc[local_1c1 - 0x01 - 0x01];
					if (local_1c1 == local_4c5) break;
					local_1c1 = local_1c1 - 1;
				}
			}
			local_1bc[local_1be - 0x01] = WORD_1d2e_3352;
			local_1aa[local_1be - 0x01] = PascalString255(local_3c4.c_str(), 0x0A);
		}
	}
	if ((local_1bf < 7) && (local_1c0 = local_1bf + 1, local_1c0 <= 7)) {
		while (true) {
			if (local_1c0 == 1) {
				local_1c3 = 0xe;
			}
			else {
				local_1c3 = 9;
			}
			FUN_1b04_0487(9, local_1c0 * 2 + 3, local_1c0 + 0x30, local_1c3);
			if ((local_1c0 == local_1bf + 1) && (local_1be == 0)) {
				Str(WORD_1d2e_3352, 4, &local_2c4, 0xff);
				local_5c4 = "(";
				Concat(local_5c4, local_3c4);
				Concat(local_5c4, ")");
				FUN_1b04_0500(0x2D, local_1c0 * 2 + 3, local_5c4, local_1c3);
				local_5c4 = "ВОПЫТУ: ";
				Concat(local_5c4, local_2c4);
				FUN_1b04_0500(0x3E, local_1c0 * 2 + 3, local_5c4, local_1c3);
				local_1be = local_1c0;
				local_1bf = local_1bf + 1;
				local_1bc[local_1bf - 0x01] = WORD_1d2e_3352;
				local_1aa[local_1bf - 0x01] = PascalString255(local_3c4.c_str(), 0x0A);
			}
			if (local_1c0 == 7) break;
			local_1c0 = local_1c0 + 1;
		}
	}
	if (BYTE_1d2e_335d == 1) {
		FUN_1b04_0500(0x1a, 0x14, "А ты ХАЛЯВIЎ ! ", 2);
		Close(local_82);
		__IOCheck();
	}
	else if (local_1be == 0) {
		Str(WORD_1d2e_3352, 0, &local_2c4, 0xff);
		local_5c4 = "А ў цябе вопыту толькi ";
		Concat(local_5c4, local_2c4);
		Concat(local_5c4, "...");
		FUN_1b04_0500(0x1A, 0x14, local_5c4, 2);
		Close(local_82);
		__IOCheck();
	}
	else {
		Console.ShowCursor();
		FUN_1b04_0500(0x20, 0x14, "Увядзiце сваё iмя!", 10);
		local_1c2 = 0xe;
		FUN_16d5_3476(local_1c2, local_1be * 2 + 3);
		local_15c[local_1be - 0x01].clear();
		if (local_1be == 1) {
			local_1c3 = 0xe;
		}
		else {
			local_1c3 = 9;
		}
		do {
			FUN_1b04_05b3(&BYTE_1d2e_331c, &BYTE_1d2e_331d);
			// FIXME: Backspace escape character '\b' could be placed at the beginning of a string!
			if ((BYTE_1d2e_331c == 0xe) && (local_15c[local_1be - 0x01].size() != 0)) {
				local_15c[local_1be - 0x01].pop_back();
				local_1c2 = local_1c2 - 1;
				FUN_1b04_0487(local_1c2, local_1be * 2 + 3, 0x20, local_1c3);
				FUN_16d5_3476(local_1c2, local_1be * 2 + 3);
			}
			else if ((BYTE_1d2e_331d != 0xd) && (local_15c[local_1be - 0x01].size() < 0x1e)) {
				local_15c[local_1be - 0x01].push_back(BYTE_1d2e_331d);
				FUN_1b04_0487(local_1c2, local_1be * 2 + 3, BYTE_1d2e_331d, local_1c3);
				local_1c2 = local_1c2 + 1;
				FUN_16d5_3476(local_1c2, local_1be * 2 + 3);
			}
		} while (BYTE_1d2e_331d != 0xd);
		local_15c[local_1be - 0x01].resize(0x1e, ' ');
		for (local_1c0 = 2; FUN_1b04_0487(local_1c0, 0x14, 0x20, 7), local_1c0 != 0x4f;
			local_1c0 = local_1c0 + 1) {
		}
		FUN_1b04_0500(0x23, 0x14, "Вiншаваньнi!", 10);
		Close(local_82);
		__IOCheck();
		Rewrite(local_82, 1);
		__IOCheck();
		local_4c5 = local_1bf;
		if (local_4c5 != 0) {
			local_1c0 = 1;
			while (true) {
				for (local_1c1 = 1;
					local_15c[local_1c0 - 0x01][local_1c1 - 0x01] =
					local_15c[local_1c0 - 0x01][local_1c1 - 0x01] ^ 0xad,
					local_1c1 != 0x1e; local_1c1 = local_1c1 + 1) {
				}
				BlockWrite(local_82, (byte*)local_15c[local_1c0 - 0x01].c_str(), 0x1e, NULL);
				__IOCheck();
				for (local_1c1 = 1;
					local_1aa[local_1c0 - 0x01][local_1c1 - 0x01] =
					local_1aa[local_1c0 - 0x01][local_1c1 - 0x01] ^ 0xad,
					local_1c1 != 10; local_1c1 = local_1c1 + 1) {
				}
				BlockWrite(local_82, (byte*)local_1aa[local_1c0 - 0x01].c_str(), 10, NULL);
				__IOCheck();
				BlockWrite(local_82, (byte*)&local_1bc[local_1c0 - 0x01], 2, NULL);
				__IOCheck();
				if (local_1c0 == local_4c5) break;
				local_1c0 = local_1c0 + 1;
			}
		}
		Close(local_82);
		__IOCheck();
	}
	Console.HideCursor();
	FUN_1b04_0500(0x1a, 0x19, "Нацiсьнiце адвольную клявiшу!", 7);
	FUN_1b04_05b3(&BYTE_1d2e_331c, &BYTE_1d2e_331d);
	FUN_1b04_0234();
	return;
}

/*
	NOP
*/
void __pascal16far FUN_16d5_42df(void)
{
	__StackCheck(0);
	return;
}

/*
	Test Graphics Card for VGA Compatibility
*/
void __pascal16far FUN_1b04_00e0(void)
{
	void* pcVar1;
	char cVar2;

	__StackCheck(0);
	if (![] { PascalString255 str;
			for (int i = 1, N = ParamCount(); i <= N; i++) {
				ParamStr(str, i);
				if (!StrComp(str, "/novga")) {
					return false;
				}
			}
			return true;
		}() ) {
		Console.ResetBuffer();
		Console.HideCursor();
		FUN_1b04_0c7f("mnskbnd1.dat", 0, 0xff);
		FUN_1b04_0d8a();
		FUN_1b04_0500(7, 1, "Дарэчы, твая вiдэакарта зьяўляецца музэйнаю рэдкасьцю!", 9);
		FUN_1b04_0500(5, 2, "Яна будзе выдатна выглядаць сярод прыладаў працы каменнага веку,", 9);
		FUN_1b04_0500(5, 3, "але МЕНСК на ёй ня пойдзе нiколi!", 9);
		FUN_1b04_0500(7, 5, "Нацiсьнiце што-небудзь! (калi ў вас ёсьць клявiятура...)", 9);
		Console.WaitForInput();
		Console.ResetBuffer();
		Halt(0);
	}
	return;
}

/*
	Convert Packed BCD to Byte
*/
byte __pascal16near FUN_1b04_016d(byte param_1)
{
	byte local_3;

	__StackCheck(2);
	local_3 = (param_1 & 0xf) + (param_1 >> 4) * 10;
	return local_3;
}

/*
	Get Real-Time Clock Date (Day/Month/Year)
*/
void __pascal16far FUN_1b04_01b1(byte* day, byte* month, word* year)
{
	SYSTEMTIME lt;
	GetLocalTime(&lt);
	*day = lt.wDay;
	*month = lt.wMonth;
	*year = lt.wYear;
	return;
}

/*
	Fade Screen to Black
*/
void __pascal16far FUN_1b04_0234(void)
{
	byte bVar1;
	void* pcVar2;
	byte bVar3;
	byte local_7; // blue
	byte local_6; // green
	byte local_5; // red
	byte local_4;
	byte local_3;

	__StackCheck(6);
	FUN_1b04_03ed();
	local_3 = 0;
	while (true) {
		Console.SetPaletteColor(local_3 << 4, 0, 0, 0);
		local_4 = 1;
		while (true) {
			if (local_3 < 10) {
				if ((local_4 & 4) == 0) {
					local_5 = 0;
				}
				else {
					local_5 = (9 - local_3) * 4;
				}
				if ((local_4 & 2) == 0) {
					local_6 = 0;
				}
				else {
					local_6 = (9 - local_3) * 4;
				}
				if ((local_4 & 1) == 0) {
					local_7 = 0;
				}
				else {
					local_7 = (9 - local_3) * 4;
				}
			}
			else {
				local_5 = 0;
				local_6 = 0;
				local_7 = 0;
			}
			Console.SetPaletteColor((local_3 << 4) + local_4, local_5, local_6, local_7);
			if (local_4 == 7) break;
			local_4 = local_4 + 1;
		}
		local_4 = 8;
		while (true) {
			if ((local_4 & 4) == 0) {
				local_5 = 0;
			}
			else {
				local_5 = (15 - local_3) * 4;
			}
			if ((local_4 & 2) == 0) {
				local_6 = 0;
			}
			else {
				local_6 = (15 - local_3) * 4;
			}
			if ((local_4 & 1) == 0) {
				local_7 = 0;
			}
			else {
				local_7 = (15 - local_3) * 4;
			}
			Console.SetPaletteColor((local_3 << 4) + local_4, local_5, local_6, local_7);
			if (local_4 == 0xf) break;
			local_4 = local_4 + 1;
		}
		if (local_3 == 0xf) break;
		local_3 = local_3 + 1;
	}
	local_3 = 0;
	while (true) {
		Console.SelectColorPage(local_3);
		FUN_1b04_0dc1(0x32);
		if (local_3 == 0xf) break;
		local_3 = local_3 + 1;
	}
	FUN_1b04_0dc1(200);
	Console.ResetBuffer();
	return;
}

/*
	Reset Palette Registers
*/
void __pascal16far FUN_1b04_03ed(void)
{
	Console.ResetPalette();
	return;
}

/*
	Print Single Character
*/
void __pascal16far FUN_1b04_0487(byte xpos, byte ypos, byte character, byte attribute)
{
	Console.WriteCharacter(xpos, ypos, character, attribute);
	return;
}

/*
	Print Character String
*/
void __pascal16far FUN_1b04_0500(byte xpos, byte ypos, const PascalString255& string, byte attribute)
{
	byte* pbVar1;
	char* pcVar2;
	uint uVar3;
	PascalString255* pPVar4;
	undefined2 unaff_SS;
	byte local_105;
	byte local_104;
	byte local_103;
	PascalString255 local_102;

	__StackCheck(0x104);
	local_102 = string;
	local_105 = 1;
	for (local_103 = 1; local_103 <= local_102.size(); local_103 = local_103 + 1) {
		if (local_102[local_103 - 1] == '=') {
			local_104 = (byte)local_102[local_103] - 0x40 + (attribute & 0xf0);
			local_103 = local_103 + 2;
		}
		else {
			local_104 = attribute;
		}
		FUN_1b04_0487((xpos + local_105) - 1, ypos, local_102[local_103 - 1], local_104);
		local_105 = local_105 + 1;
	}
	return;
}

/*
	Get Keyboard Input
*/
void __pascal16far FUN_1b04_05b3(byte* scancode, byte* character)
{
	Console.GetKeyboardInput(scancode, character);
	return;
}

/*
	Set Palette Register Color
*/
void __pascal16far FUN_1b04_05e4(byte regno, byte index)
{
	Console.SetPaletteRegister(regno, index);
	return;
}

/*
	Check Delta Time
*/
bool __pascal16near FUN_1b04_05fd(void)
{
	static dword LastTickCount; // WORD_1d2e_1208
	dword tickCount = GetTickCount();
	if ((tickCount - LastTickCount) >= 55 * 4) {
		LastTickCount = tickCount;
		return true;
	}
	return false;
}

/*
	Set Random Color to a Palette Register
*/
void __pascal16far FUN_1b04_064b(void)
{
	bool bVar1;
	byte bVar2;
	word wVar3;

	__StackCheck(0);
	bVar1 = FUN_1b04_05fd();
	if (bVar1) {
		bVar2 = 1;
		wVar3 = Random(99);
		FUN_1b04_05e4(bVar2, wVar3 + 1);
	}
	return;
}

/*
	Set Random Color to a Palette Register
*/
void __pascal16far FUN_1b04_0670(void)
{
	bool bVar1;
	bool bVar2;
	byte bVar3;
	word wVar4;

	while (true) {
		bVar1 = Console.CheckKeyboardInput();
		if (bVar1) break;
		bVar2 = FUN_1b04_05fd();
		if (bVar2) {
			bVar3 = 1;
			wVar4 = Random(99);
			FUN_1b04_05e4(bVar3, wVar4 + 1);
		}
	}
	return;
}

/*
	Load Fading Gray Palette (60 -> 0)
*/
void __pascal16near FUN_1b04_069d(void)
{
	char cVar1;
	byte local_4;
	byte local_3;

	__StackCheck(2);
	local_3 = 0;
	while (true) {
		Console.SetPaletteColor(local_3 + 0x10, (15 - local_3) * 4, (15 - local_3) * 4, (15 - local_3) * 4);
		if (local_3 == 15) break;
		local_3 = local_3 + 1;
	}
	return;
}

/*
	Load Fading Gray Palette (40 -> 4)
*/
void __pascal16near FUN_1b04_06e8(void)
{
	char cVar1;
	byte local_4;
	byte local_3;

	__StackCheck(2);
	local_3 = 0;
	while (true) {
		Console.SetPaletteColor(local_3 + 0x10, (10 - local_3) * 4, (10 - local_3) * 4, (10 - local_3) * 4);
		if (local_3 == 9) break;
		local_3 = local_3 + 1;
	}
	return;
}

/*
	Load Fading Red Palette (40 -> 4)
*/
void __pascal16near FUN_1b04_0733(void)
{
	char cVar1;
	byte local_3;

	__StackCheck(2);
	local_3 = 0;
	while (true) {
		Console.SetPaletteColor(local_3 + 0x10, (10 - local_3) * 4, 0, 0);
		if (local_3 == 9) break;
		local_3 = local_3 + 1;
	}
	return;
}

/*
	Display Intro Graphics
*/
void __pascal16near FUN_1b04_0788(void)
{
	void* pcVar1;
	undefined2 unaff_SS;
	word local_386;
	word local_384;
	UFileStream local_382;
	byte local_302[256][3]; // palette
	void* pvBits;

	__StackCheck(0x388);
	Console.ResetBuffer();
	Assign(local_382, "mnskbnd3.dat");
	Reset(local_382, 1);
	__IOCheck();
	BlockRead(local_382, local_302[0], 0x300, NULL);
	__IOCheck();
	for (local_384 = 0; Console.SetPaletteColor(local_384, 0x00, 0x00, 0x00),
		local_384 != 255; local_384 = local_384 + 1) {
	}
	Console.InitBitmap(&pvBits, 320, 200);
	BlockRead(local_382, (byte*)pvBits, 64000, NULL);
	__IOCheck();
	Close(local_382);
	__IOCheck();
	for (local_384 = 0; Console.SetPaletteColor(local_384,
		local_302[local_384][0],
		local_302[local_384][1],
		local_302[local_384][2]),
		local_384 != 255; local_384 = local_384 + 1) {
	}
	Console.DrawBitmap();
	FUN_1b04_0dc1(0x9c4);
	local_384 = 0x3f;
	while (true) {
		for (local_386 = 0; Console.SetPaletteColor(local_386,
			local_302[local_386][0] * local_384 >> 6,
			local_302[local_386][1] * local_384 >> 6,
			local_302[local_386][2] * local_384 >> 6),
			local_386 != 255; local_386 = local_386 + 1) {
		}
		Console.DrawBitmap();
		FUN_1b04_0dc1(0xf);
		if (local_384 == 0) break;
		local_384 = local_384 - 1;
	}
	return;
}

/*
	Display Intro Screen
*/
void __pascal16far FUN_1b04_0a48(void)
{
	void* pcVar1;
	word wVar2;
	undefined2 unaff_SS;
	bool bVar3;
	PascalString255* string;
	PascalString255 local_104;
	byte local_3;

	__StackCheck(0x102);
	FUN_1b04_0500(0xc, 0x15, "Забiваць за гэта трэба (c) Gildur\'а, Morfin\'а ды Forion\'а.", 4);
	FUN_1b04_0500(0x18, 8, "▓   ▓ ░░░░░ ▒   ▒  ░░░░   ▓   ▓▓", 0xf);
	FUN_1b04_0500(0x18, 9, "▓▓ ▓▓ ░     ▒   ▒ ░░  ░░  ▓  ▓▓", 0xf);
	FUN_1b04_0500(0x18, 10, "▓ ▓ ▓ ░░░   ▒▒▒▒▒ ░░      ▓▓▓▓", 0xf);
	FUN_1b04_0500(0x18, 0xb, "▓   ▓ ░     ▒   ▒ ░░  ░░  ▓  ▓▓", 0xf);
	FUN_1b04_0500(0x18, 0xc, "▓   ▓ ░░░░░ ▒   ▒  ░░░░   ▓   ▓▓", 0xf);
	FUN_1b04_0500(0x1c, 0xf, "Version 2.718281828459045...", 0xf);
	FUN_1b04_0500(0x20, 0x11, "!BEER AND MAGIC!", 0xb);
	FUN_1b04_0dc1(0x4b0);
	FUN_1b04_069d();
	local_3 = 0x10;
	while (true) {
		FUN_1b04_05e4(0xf, local_3);
		FUN_1b04_0dc1(0x32);
		if (local_3 == 0x1f) break;
		local_3 = local_3 + 1;
	}
	FUN_1b04_05e4(0xf, 0);
	FUN_1b04_0dc1(600);
	FUN_1b04_0500(0x13, 0x19, "[Нацicьнiце адвольную клявiшу дзеля працягу.]", 4);
	Console.WaitForInput();
	FUN_1b04_0733();
	local_3 = 0x10;
	while (true) {
		FUN_1b04_05e4(4, local_3);
		FUN_1b04_0dc1(0x32);
		if (local_3 == 0x19) break;
		local_3 = local_3 + 1;
	}
	FUN_1b04_05e4(4, 0);
	FUN_1b04_0788();
	Console.ResetBuffer();
	Console.HideCursor();
	FUN_1b04_0500(1, 1, "3dfx card initialization failed.", 7);
	FUN_1b04_0dc1(100);
	FUN_1b04_0500(1, 2, "Processor initialized.", 7);
	FUN_1b04_0dc1(100);
	FUN_1b04_0500(1, 3, "Accessing main databank...", 7);
	FUN_1b04_0dc1(100);
	wVar2 = ParamCount();
	if (wVar2 == 1) {
		ParamStr(local_104, 1);
		bVar3 = StrComp(local_104, "/god");
		if (!bVar3) {
			FUN_1b04_0500(1, 7, "Халява...    Enabled!", 4);
		}
	}
	FUN_1b04_0500(1, 5, "GET PREPARED...", 7);
	FUN_1b04_0dc1(0x4b0);
	FUN_1b04_06e8();
	local_3 = 0x10;
	while (true) {
		FUN_1b04_05e4(7, local_3);
		FUN_1b04_0dc1(0x32);
		if (local_3 == 0x19) break;
		local_3 = local_3 + 1;
	}
	FUN_1b04_05e4(7, 0);
	FUN_1b04_0dc1(0x14);
	Console.ResetBuffer();
	Console.HideCursor();
	return;
}

/*
	Load User-Specified Character Set (File -> RAM)
*/
void __pascal16far FUN_1b04_0c7f(const PascalString255& name, word offset, word size)
{
	byte* pbVar1;
	char* pcVar2;
	word wVar3;
	uint uVar4;
	PascalString255* pPVar5;
	undefined2 unaff_SS;
	word local_186;
	word local_184;
	UFileStream local_182;
	PascalString255 local_102;

	__StackCheck(0x184);
	local_102 = name;
	Assign(local_182, local_102);
	Reset(local_182, 1);
	__IOCheck();
	BlockRead(local_182, &BYTE_ARRAY_ARRAY_1d2e_3360[offset][0], ((size - offset) + 1) * 0x10, NULL);
	__IOCheck();
	Close(local_182);
	__IOCheck();
	local_186 = size * 0x10 + 0xf;
	local_184 = offset * 0x10;
	if (local_184 <= local_186) {
		for (; BYTE_ARRAY_ARRAY_1d2e_3360[local_184 >> 4][local_184 & 0x0F] =
			BYTE_ARRAY_1d2e_120a[local_184 & 0x0F] ^
			BYTE_ARRAY_ARRAY_1d2e_3360[local_184 >> 4][local_184 & 0x0F] ^ local_184 ^
			(local_184 >> 4), local_184 != local_186; local_184 = local_184 + 1) {
		}
	}
	FillChar(BYTE_ARRAY_ARRAY_1d2e_3360, 0x10, 0);
	return;
}

/*
	Load User-Specified Character Set (RAM -> VGA RAM)
*/
void __pascal16far FUN_1b04_0d8a(void)
{
	void* pcVar1;
	byte* local_6;

	__StackCheck(4);
	return;
}

/*
	Wait a Certain Number of Milliseconds
*/
void __pascal16far FUN_1b04_0dc1(dword delay)
{
	Sleep(delay);
	return;
}

/*
	NOP
*/
void __pascal16far FUN_1b04_0e08(void)
{
	__StackCheck(0);
	return;
}
