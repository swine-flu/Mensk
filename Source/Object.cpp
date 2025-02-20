#include "Console.h"
#include "Globals.h"
#include "Mensk.h"
#include "Object.h"


/*
	Enemy
*/
Enemy::Enemy(byte index, byte icon, byte color, word maxhp)
	: pNext{ NULL }
{
	Enemy* psVar1;
	word wVar2;
	Enemy* psVar3;
	undefined2 uVar4;
	undefined2 unaff_SS;
	undefined uVar5;

	__StackCheck(0);
	do {
		this->xpos = Random(0x40) + 0x10;
		this->ypos = Random(0x13) + 4;
	} while (BYTE_ARRAY_ARRAY_1d2e_152c[xpos - 0x0F][ypos - 0x02] != 0xFA); // 0xFA - Empty Tile
	this->hp = maxhp;
	this->index = index;
	this->color = color;
	this->icon = icon;
	this->pNext = PTR_1d2e_0156;
	PTR_1d2e_0156 = this;
	DrawSymbol();
	BYTE_1d2e_3348 = BYTE_1d2e_3348 + 1;
	FUN_1b04_064b();
}

Enemy::Enemy(byte xpos, byte ypos, byte index, byte icon, byte color, word maxhp, bool draw)
	: pNext{ NULL }
{
	Enemy* psVar1;
	Enemy* psVar2;
	undefined2 uVar3;
	undefined2 unaff_SS;
	undefined uVar4;

	__StackCheck(0);
	this->xpos = xpos;
	this->ypos = ypos;
	this->hp = maxhp;
	this->index = index;
	this->color = color;
	this->icon = icon;
	this->pNext = PTR_1d2e_0156;
	PTR_1d2e_0156 = this;
	if (draw) {
		DrawSymbol();
	}
	BYTE_1d2e_3348 = BYTE_1d2e_3348 + 1;
	FUN_1b04_064b();
}

void Enemy::AiAttackPlayer()
{
	word wVar1;
	undefined2 unaff_SS;
	PascalString255* pPVar2;
	PascalString255 local_102;

	__StackCheck(0x100);
	Randomize();
	if (BYTE_ARRAY_1d2e_07f0[this->index - 0x01] * 2 + 9 <
		BYTE_ARRAY_1d2e_07f0[this->index - 0x01] * 4 + Random(10)) {
		wVar1 = Random(BYTE_ARRAY_1d2e_07f0[this->index - 0x01]) + 1;
		SWORD_1d2e_3356 = SWORD_1d2e_3356 - BYTE_ARRAY_1d2e_07f0[this->index - 0x01] * wVar1;
		if (SWORD_1d2e_3356 < 0) {
			SWORD_1d2e_3356 = 0;
		}
		FUN_1b04_0500(1, 0xd, "CHP   :      ", 7);
		Str(SWORD_1d2e_3356, 0, (PascalString255*)BYTE_ARRAY_1d2e_3358, 3);
		FUN_1b04_0500(0xb, 0xd, (PascalString255&)BYTE_ARRAY_1d2e_3358, 7);
		local_102 = P_STRING__ARRAY_1d2e_0696[this->index - 0x01];
		Concat(local_102, " папаў па Лявону.");
		FUN_16d5_0019(local_102);
		if (SWORD_1d2e_3356 <= 0) {
			local_102 = "Забiты ";
			Concat(local_102, P_STRING__ARRAY_1d2e_0b5c[this->index - 0x01][0]);
			FUN_16d5_2e05(local_102, P_STRING__ARRAY_1d2e_0b5c[this->index - 0x01][1]);
		}
	}
	else {
		local_102 = P_STRING__ARRAY_1d2e_0696[this->index - 0x01];
		Concat(local_102, " прамазаў.");
		FUN_16d5_0019(local_102);
	}
	FUN_1b04_064b();
	return;
}

void Enemy::AiAttackFoe(byte xpos, byte ypos)
{
	byte bVar2;
	word wVar3;
	int iVar4;
	undefined uVar5;
	Enemy* psVar6;
	undefined2 uVar7;
	undefined2 unaff_SS;
	PascalString255* pPVar8;
	PascalString255 local_308;
	PascalString255 local_208;
	PascalString255 local_108;
	byte local_7;
	Enemy* local_6;

	__StackCheck(0x306);
	Randomize();
	if (BYTE_ARRAY_1d2e_07f0[this->index - 0x01] * 2 + 9 <
		BYTE_ARRAY_1d2e_07f0[this->index - 0x01] * 4 + Random(10)) {
		local_6 = PTR_1d2e_0156;
		while (true) {
			if ((local_6->xpos == xpos) && (local_6->ypos == ypos)) break;
			local_6 = local_6->pNext;
		}
		wVar3 = Random(BYTE_ARRAY_1d2e_07f0[this->index - 0x01]) + 1;
		local_7 = BYTE_ARRAY_1d2e_07f0[this->index - 0x01] * wVar3;
		local_6->hp = local_6->hp - local_7;
		if (local_6->hp <= 0) {
			local_6->hp = 0;
		}
		bVar2 = local_6->hp % 10;
		if ((bVar2 == 0) || ((5 <= bVar2) && (bVar2 <= 9)) ||
			(bVar2 = local_6->hp % 100, (11 <= bVar2) && (bVar2 <= 14))) {
			local_108 = " хiтоў.";
		}
		else if (local_6->hp % 10 == 1) {
			local_108 = " хiт.";
		}
		else {
			local_108 = " хiты.";
		}
		Str(local_6->hp, 0, (PascalString255*)BYTE_ARRAY_1d2e_3358, 3);
		if (local_6->hp == 0) {
			local_208 = " ды вырубiў яго.";
		}
		else {
			local_308 = " ды пакiнуў яму ";
			Concat(local_308, (PascalString255&)BYTE_ARRAY_1d2e_3358);
			Concat(local_308, local_108);
			local_208 = local_308;
		}
		local_308 = P_STRING__ARRAY_1d2e_0696[this->index - 0x01];
		Concat(local_308, " пабiў ");
		Concat(local_308, P_STRING__ARRAY_1d2e_0832[local_6->index - 0x01]);
		Concat(local_308, local_208);
		FUN_16d5_0019(local_308);
		if (local_6->hp == 0) {
			delete local_6;
		}
	}
	else {
		local_308 = P_STRING__ARRAY_1d2e_0696[this->index - 0x01];
		Concat(local_308, " прамазаў.");
		FUN_16d5_0019(local_308);
	}
	FUN_1b04_064b();
	return;
}

void Enemy::NormalPathfinding()
{
	uint uVar3;
	uint uVar4;
	Enemy* psVar5;
	undefined2 uVar6;
	std::pair<byte, word> dVar7;

	__StackCheck(0);
	if (this->hp <= 0) {
		// NOTE: Dubious use of dtor from a member function, supposedly dead branch
		__debugbreak();
		this->~Enemy();
	}
	else {
		if ((std::abs(BYTE_1d2e_1529 - this->xpos) < 2) &&
			(std::abs(BYTE_1d2e_152a - this->ypos) < 2)) {
			AiAttackPlayer();
		}
		else {
			if ((std::abs(BYTE_1d2e_1529 - this->xpos) < 10) &&
				(std::abs(BYTE_1d2e_152a - this->ypos) < 10)) {
				ClearSymbol();
				// FIXME: Diagonal movement should be performed in a single step!
				if ((this->xpos < BYTE_1d2e_1529) &&
					(dVar7 = GetElemOffset(BYTE_ARRAY_ARRAY_1d2e_152c[this->xpos - 0x0F + 1][this->ypos - 0x02], 1, 0x20, 0),
						(BYTE_ARRAY_1d2e_017e[dVar7.second] & dVar7.first) != 0)) {
					BYTE_ARRAY_ARRAY_1d2e_152c[this->xpos - 0x0F + 1][this->ypos - 0x02] = 0xfa;
					this->xpos = this->xpos + 1;
				}
				if ((BYTE_1d2e_1529 < this->xpos) &&
					(dVar7 = GetElemOffset(BYTE_ARRAY_ARRAY_1d2e_152c[this->xpos - 0x0F - 1][this->ypos - 0x02], 1, 0x20, 0),
						(BYTE_ARRAY_1d2e_017e[dVar7.second] & dVar7.first) != 0)) {
					BYTE_ARRAY_ARRAY_1d2e_152c[this->xpos - 0x0F - 1][this->ypos - 0x02] = 0xfa;
					this->xpos = this->xpos - 1;
				}
				if ((this->ypos < BYTE_1d2e_152a) &&
					(dVar7 = GetElemOffset(BYTE_ARRAY_ARRAY_1d2e_152c[this->xpos - 0x0F][this->ypos - 0x02 + 1], 1, 0x20, 0),
						(BYTE_ARRAY_1d2e_017e[dVar7.second] & dVar7.first) != 0)) {
					BYTE_ARRAY_ARRAY_1d2e_152c[this->xpos - 0x0F][this->ypos - 0x02 + 1] = 0xfa;
					this->ypos = this->ypos + 1;
				}
				if ((BYTE_1d2e_152a < this->ypos) &&
					(dVar7 = GetElemOffset(BYTE_ARRAY_ARRAY_1d2e_152c[this->xpos - 0x0F][this->ypos - 0x02 - 1], 1, 0x20, 0),
						(BYTE_ARRAY_1d2e_017e[dVar7.second] & dVar7.first) != 0)) {
					BYTE_ARRAY_ARRAY_1d2e_152c[this->xpos - 0x0F][this->ypos - 0x02 - 1] = 0xfa;
					this->ypos = this->ypos - 1;
				}
				DrawSymbol();
			}
		}
	}
	FUN_1b04_064b();
	return;
}

void Enemy::DrunkPathfinding()
{
	char cVar3;
	word wVar4;
	Enemy* psVar5;
	undefined2 uVar6;
	byte local_3;

	__StackCheck(2);
	if ((Random(100) & 1) == 0) {
		NormalPathfinding();
	}
	else if (this->hp <= 0) {
		// NOTE: Dubious use of dtor from a member function, supposedly dead branch
		__debugbreak();
		this->~Enemy();
	}
	else {
		local_3 = Random(4);
		if (local_3 == 0) {
			if (BYTE_ARRAY_ARRAY_1d2e_152c[this->xpos - 0x0F + 1][this->ypos - 0x02] == 0xFA) {
				if ((this->xpos + 1 == BYTE_1d2e_1529) &&
					(this->ypos == BYTE_1d2e_152a)) {
					AiAttackPlayer();
				}
				else {
					ClearSymbol();
					this->xpos = this->xpos + 1;
					DrawSymbol();
				}
			}
		}
		else if (local_3 == 1) {
			if (BYTE_ARRAY_ARRAY_1d2e_152c[this->xpos - 0x0F - 1][this->ypos - 0x02] == 0xFA) {
				if ((this->xpos - 1 == BYTE_1d2e_1529) &&
					(this->ypos == BYTE_1d2e_152a)) {
					AiAttackPlayer();
				}
				else {
					ClearSymbol();
					this->xpos = this->xpos - 1;
					DrawSymbol();
				}
			}
		}
		else if (local_3 == 2) {
			if (BYTE_ARRAY_ARRAY_1d2e_152c[this->xpos - 0x0F][this->ypos - 0x02 + 1] == 0xFA) {
				if ((this->xpos == BYTE_1d2e_1529) &&
					(this->ypos + 1 == BYTE_1d2e_152a)) {
					AiAttackPlayer();
				}
				else {
					ClearSymbol();
					this->ypos = this->ypos + 1;
					DrawSymbol();
				}
			}
		}
		else if (local_3 == 3) {
			if (BYTE_ARRAY_ARRAY_1d2e_152c[this->xpos - 0x0F][this->ypos - 0x02 - 1] == 0xFA) {
				if ((this->xpos == BYTE_1d2e_1529) &&
					(this->ypos - 1 == BYTE_1d2e_152a)) {
					AiAttackPlayer();
				}
				else {
					ClearSymbol();
					this->ypos = this->ypos - 1;
					DrawSymbol();
				}
			}
		}
		DrawSymbol();
	}
	return;
}

void Enemy::DrawSymbol() {
	Enemy* psVar1;
	undefined2 uVar2;

	__StackCheck(0);
	BYTE_ARRAY_ARRAY_1d2e_152c[xpos - 0x0F][ypos - 0x02] = this->icon;
	if ((BYTE_1d2e_334b != 2) || (BYTE_1d2e_1528 == 0) ||
		((BYTE_1d2e_1528 == 1) && (this->ypos < 0x12)) ||
		((BYTE_1d2e_1528 == 2) && (0x12 < this->ypos))) {
		FUN_1b04_0487(this->xpos, this->ypos, this->icon, this->color);
	}
	return;
}

void Enemy::ClearSymbol()
{
	Enemy* psVar1;
	undefined2 uVar2;

	__StackCheck(0);
	BYTE_ARRAY_ARRAY_1d2e_152c[xpos - 0x0F][ypos - 0x02] = 0xFA; // 0xFA - Empty Tile
	if ((BYTE_1d2e_334b != 2) || (BYTE_1d2e_1528 == 0) ||
		((BYTE_1d2e_1528 == 1) && (this->ypos < 0x12)) ||
		((BYTE_1d2e_1528 == 2) && (0x12 < this->ypos))) {
		FUN_1b04_0487(this->xpos, this->ypos, 0xFA, 7);
	}
	return;
}

/*
	Regular Enemy
*/
RegularEnemy::~RegularEnemy()
{
	undefined2 uVar1;
	word wVar2;
	Enemy* psVar3;
	Enemy* psVar4;
	int iVar5;
	undefined2 uVar6;
	undefined2 unaff_SS;
	byte local_9;
	byte local_8;
	byte local_7;
	Enemy* local_6;

	__StackCheck(8);
	wVar2 = Random(0x83);
	if ((0 <= wVar2) && (wVar2 <= 0x31)) {
		// 0x24 - Money
		local_7 = 0x24;
		local_8 = 0xe;
	}
	else if ((0x32 <= wVar2) && (wVar2 <= 0x40)) {
		// 0x21 - Bottle of Beer
		local_7 = 0x21;
		local_8 = 10;
	}
	else if ((0x41 <= wVar2) && (wVar2 <= 0x4f)) {
		// 0x2F - Stick or Club
		local_7 = 0x2f;
		local_8 = 6;
	}
	else if ((0x50 <= wVar2) && (wVar2 <= 0x54)) {
		if ((400 < WORD_1d2e_3352) && (BYTE_1d2e_0362 == 0)) {
			// 0x23 - BPSM Card
			local_7 = 0x23;
			local_8 = 4;
			BYTE_1d2e_0362 = 1;
		}
		else {
			// 0xFA - Empty Tile
			local_7 = 0xfa;
			local_8 = 7;
		}
	}
	else if ((0x55 <= wVar2) && (wVar2 <= 0x59)) {
		if ((460 < WORD_1d2e_3352) && (BYTE_1d2e_0363 == 0)) {
			// 0x5C - DOOMGUY Chainsaw
			local_7 = 0x5c;
			local_8 = 0xe;
			BYTE_1d2e_0363 = 1;
		}
		else {
			// 0xFA - Empty Tile
			local_7 = 0xfa;
			local_8 = 7;
		}
	}
	else if ((0x5a <= wVar2) && (wVar2 <= 0x5e)) {
		if ((650 < WORD_1d2e_3352) && (BYTE_1d2e_0364 == 0)) {
			// 0x3F - Lyavon's Bottle of Beer
			local_7 = 0x3f;
			local_8 = 0xc;
			BYTE_1d2e_0364 = 1;
		}
		else {
			// 0xFA - Empty Tile
			local_7 = 0xfa;
			local_8 = 7;
		}
	}
	else if ((0x5f <= wVar2) && (wVar2 <= 0x63)) {
		if ((700 < WORD_1d2e_3352) && (BYTE_1d2e_0365 == 0)) {
			// 0x5B - N.R.M. Cassette
			local_7 = 0x5b;
			local_8 = 0xf;
			BYTE_1d2e_0365 = 1;
		}
		else {
			// 0xFA - Empty Tile
			local_7 = 0xfa;
			local_8 = 7;
		}
	}
	else if ((0x64 <= wVar2) && (wVar2 <= 0x65)) {
		// 0x25 - Potion of Heroism
		local_7 = 0x25;
		local_8 = 6;
	}
	else if (wVar2 == 0x66) {
		// 0x26 - Green Magic Charm
		local_7 = 0x26;
		local_8 = 2;
	}
	else if ((0x67 <= wVar2) && (wVar2 <= 0x68)) {
		// 0x1F - Yellow Magic Charm
		local_7 = 0x1f;
		local_8 = 0xe;
	}
	else if ((0x69 <= wVar2) && (wVar2 <= 0x81)) {
		// 0xFA - Empty Tile
		local_7 = 0xfa;
		local_8 = 7;
	}
	else if (wVar2 == 0x82) {
		// 0x1E - White-Red-White Magic Charm
		local_7 = 0x1e;
		local_8 = 0xc;
	}
	BYTE_ARRAY_ARRAY_1d2e_152c[this->xpos - 0x0F][this->ypos - 0x02] = local_7;
	FUN_1b04_0487(this->xpos, this->ypos, local_7, local_8);
	if (this->hp <= 0) {
		WORD_1d2e_3352 = WORD_1d2e_3352 + WORD_ARRAY_1d2e_0800[this->index - 0x01];
	}
	if (this == PTR_1d2e_0156) {
		PTR_1d2e_0156 = this->pNext;
	}
	else {
		local_6 = PTR_1d2e_0156;
		local_9 = 1;
		while (true) {
			if ((BYTE_1d2e_3348 < local_9) ||
				(this == local_6->pNext)) break;
			local_6 = local_6->pNext;
			local_9 = local_9 + 1;
		}
		if (local_9 <= BYTE_1d2e_3348) {
			local_6->pNext = this->pNext;
		}
	}
	BYTE_1d2e_3348 = BYTE_1d2e_3348 - 1;
	if ((BYTE_1d2e_3348 == 0) && (BYTE_1d2e_334b == 3) &&
		(BYTE_1d2e_1104 != 0) && (this->hp == 0)) {
		BYTE_1d2e_1104 = 0;
		FUN_16d5_0019("Гэты быў апошнi!!!!!!!");
	}
	FUN_1b04_064b();
	return;
}

/*
	Gopnik
*/
void DAT_1d2e_0096::AiThink()
{
	char cVar1;
	bool bVar2;
	Enemy* psVar3;
	undefined2 uVar4;
	bool local_5;
	sbyte local_4;
	sbyte local_3;

	__StackCheck(4);
	local_5 = false;
	local_3 = -1;
	while (true) {
		local_4 = -1;
		while (true) {
			if (BYTE_ARRAY_ARRAY_1d2e_152c[this->xpos + local_3 - 0x0F][this->ypos + local_4 - 0x02] == 0xE4) { // 0xE4 - Nazi Symbol
				local_5 = true;
				AiAttackFoe(this->xpos + local_3, this->ypos + local_4);
			}
			if (local_4 == 1) break;
			local_4 = local_4 + 1;
		}
		if (local_3 == 1) break;
		local_3 = local_3 + 1;
	}
	if (!local_5) {
		NormalPathfinding();
	}
	return;
}

/*
	Small Gopnik
*/
void DAT_1d2e_0046::AiThink()
{
	bool bVar2;
	Enemy* psVar3;
	undefined2 uVar4;
	bool local_7;
	Enemy* local_6;

	__StackCheck(6);
	NormalPathfinding();
	local_6 = PTR_1d2e_0156;
	local_7 = false;
	while (true) {
		if (local_6 == NULL) break;
		if (this == local_6) {
			local_7 = true;
		}
		local_6 = local_6->pNext;
	}
	if ((local_7) && (this->aistate == 0)) {
		this->aistate = 1;
		AiThink();
	}
	this->aistate = 0;
	return;
}

void DAT_1d2e_0046::AiAttackPlayer()
{
	byte bVar1;
	char cVar2;
	char cVar3;
	byte bVar4;
	word wVar5;
	uint uVar6;
	Enemy* psVar7;
	undefined2 uVar8;
	std::pair<byte, word> dVar9;
	byte local_7;
	sbyte local_6;
	sbyte local_5;
	byte local_4;
	byte local_3;

	__StackCheck(6);
	if ((SWORD_1d2e_3354 != 0) || (BYTE_1d2e_3346 != 0)) {
		FUN_16d5_0019("Малы гопнiк падбягае да цябе...");
		if ((BYTE_1d2e_3346 == 0) || ((Random(100) & 1) == 0)) {
			wVar5 = Random(0x32) + 10;
			SWORD_1d2e_3354 = SWORD_1d2e_3354 - wVar5;
			if (SWORD_1d2e_3354 < 0) {
				SWORD_1d2e_3354 = 0;
			}
			FUN_16d5_0019("Нешта ў кiшэнi стала лягчэй...");
		}
		else {
			local_3 = Random(BYTE_1d2e_3346) + 1;
			// BPSM Card
			if (BYTE_ARRAY_1d2e_332a[local_3 - 0x01] == 10) {
				BYTE_1d2e_0362 = 0;
			}
			// DOOMGUY Chainsaw
			else if (BYTE_ARRAY_1d2e_332a[local_3 - 0x01] == 9) {
				BYTE_1d2e_0363 = 0;
			}
			// Lyavon's Bottle of Beer
			else if (BYTE_ARRAY_1d2e_332a[local_3 - 0x01] == 6) {
				BYTE_1d2e_0364 = 0;
			}
			// N.R.M. Cassette
			else if (BYTE_ARRAY_1d2e_332a[local_3 - 0x01] == 0xb) {
				BYTE_1d2e_0365 = 0;
			}
			local_7 = BYTE_1d2e_3346;
			if (local_3 <= local_7) {
				for (local_4 = local_3; BYTE_ARRAY_1d2e_332a[local_4 - 0x01] = BYTE_ARRAY_1d2e_332a[local_4],
					local_4 != local_7; local_4 = local_4 + 1) {
				}
			}
			BYTE_1d2e_3346 = BYTE_1d2e_3346 - 1;
			FUN_16d5_0019("Нешта торба стала надта лёгкая...");
		}
		ClearSymbol();
		FUN_16d5_0019("Малы гопнiк драпае прэч!");
		do {
			local_5 = (Random(3) - 1) * 6;
			local_6 = (Random(3) - 1) * 6;
			if ((local_5 == 0) && (local_6 == 0)) {
				continue;
			}
		} while (((this->xpos + local_5) <= 0x0F) || (0x50 <= (this->xpos + local_5)) ||
			((this->ypos + local_6) <= 2) || (0x18 <= (this->ypos + local_6)) ||
			(bVar1 = BYTE_ARRAY_ARRAY_1d2e_152c[this->xpos + local_5 - 0x0F][this->ypos + local_6 - 0x02],
				(bVar1 == 0x40) || // 0x40 - Player Character
				(bVar1 == 0xB1) || // 0xB1 - Impassable Tile
				(bVar1 == 0xC4) || // 0xC4 - Subway Turnstile
				(dVar9 = GetElemOffset(BYTE_ARRAY_ARRAY_1d2e_152c[this->xpos + local_5 - 0x0F][this->ypos + local_6 - 0x02], 1, 0x20, 0),
					((BYTE_ARRAY_1d2e_015a[dVar9.second] & dVar9.first) != 0))));
		this->xpos = this->xpos + local_5;
		this->ypos = this->ypos + local_6;
		DrawSymbol();
	}
	return;
}

/*
	Drunk Gopnik
*/
void DAT_1d2e_006e::AiThink()
{
	char cVar1;
	bool bVar2;
	word wVar3;
	Enemy* psVar4;
	undefined2 uVar5;
	bool local_5;
	sbyte local_4;
	sbyte local_3;

	__StackCheck(4);
	local_5 = false;
	local_3 = -1;
	while (true) {
		local_4 = -1;
		while (true) {
			if (BYTE_ARRAY_ARRAY_1d2e_152c[this->xpos + local_3 - 0x0F][this->ypos + local_4 - 0x02] == 0xE4) { // 0xE4 - Nazi Symbol
				if ((Random(100) & 1) == 0) {
					local_5 = true;
					AiAttackFoe(this->xpos + local_3, this->ypos + local_4);
				}
			}
			if (local_4 == 1) break;
			local_4 = local_4 + 1;
		}
		if (local_3 == '\x01') break;
		local_3 = local_3 + '\x01';
	}
	if (!local_5) {
		DrunkPathfinding();
	}
	return;
}

/*
	Skinhead
*/
void DAT_1d2e_00e6::AiThink()
{
	char cVar1;
	bool bVar2;
	Enemy* psVar3;
	undefined2 uVar4;
	bool local_5;
	sbyte local_4;
	sbyte local_3;

	__StackCheck(4);
	local_5 = false;
	local_3 = -1;
	while (true) {
		local_4 = -1;
		while (true) {
			if (BYTE_ARRAY_ARRAY_1d2e_152c[this->xpos + local_3 - 0x0F][this->ypos + local_4 - 0x02] == 0xA3) { // 0xA3 - Gopnik Symbol
				local_5 = true;
				AiAttackFoe(this->xpos + local_3, this->ypos + local_4);
			}
			if (local_4 == 1) break;
			local_4 = local_4 + 1;
		}
		if (local_3 == 1) break;
		local_3 = local_3 + 1;
	}
	if (!local_5) {
		NormalPathfinding();
	}
	return;
}

/*
	Drunk Commie
*/
void DAT_1d2e_0082::AiThink()
{
	char cVar1;
	bool bVar2;
	word wVar3;
	Enemy* psVar4;
	undefined2 uVar5;
	bool local_5;
	sbyte local_4;
	sbyte local_3;

	__StackCheck(4);
	local_5 = false;
	local_3 = -1;
	while (true) {
		local_4 = -1;
		while (true) {
			if (BYTE_ARRAY_ARRAY_1d2e_152c[this->xpos + local_3 - 0x0F][this->ypos + local_4 - 0x02] == 0xA3) { // 0xA3 - Gopnik Symbol
				if ((Random(100) & 1) == 0) {
					local_5 = true;
					AiAttackFoe(this->xpos + local_3, this->ypos + local_4);
				}
			}
			if (local_4 == 1) break;
			local_4 = local_4 + 1;
		}
		if (local_3 == 1) break;
		local_3 = local_3 + 1;
	}
	if (!local_5) {
		DrunkPathfinding();
	}
	return;
}

void DAT_1d2e_0082::AiAttackPlayer()
{
	word wVar1;
	undefined2 unaff_SS;
	PascalString255* dest;
	PascalString255 local_104;
	byte local_4;
	byte local_3;

	__StackCheck(0x102);
	local_3 = 1;
	for (local_4 = 0; ((local_3 != 0) && (local_4 < 2)); local_4 = local_4 + 1) {
		local_3 = Random(4);
		if (local_3 != 0) {
			local_104 = "П\'яны камуняга";
			Concat(local_104, P_STRING_ARRAY_1d2e_0222[local_3 - 0x01]);
			FUN_16d5_0019(local_104);
		}
	}
	Enemy::AiAttackPlayer();
	return;
}

/*
	Cop
*/
void DAT_1d2e_005a::AiThink()
{
	char cVar1;
	byte bVar2;
	bool bVar3;
	Enemy* psVar4;
	undefined2 uVar5;
	bool local_5;
	sbyte local_4;
	sbyte local_3;

	__StackCheck(4);
	local_5 = false;
	local_3 = -1;
	while (true) {
		local_4 = -1;
		while (true) {
			bVar2 = BYTE_ARRAY_ARRAY_1d2e_152c[this->xpos + local_3 - 0x0F][this->ypos + local_4 - 0x02];
			if ((bVar2 == 0xA3) || // 0xA3 - Gopnik Symbol
				(bVar2 == 0xE4)) { // 0xE4 - Nazi Symbol
				local_5 = true;
				AiAttackFoe(this->xpos + local_3, this->ypos + local_4);
			}
			if (local_4 == 1) break;
			local_4 = local_4 + 1;
		}
		if (local_3 == 1) break;
		local_3 = local_3 + 1;
	}
	if (!local_5) {
		NormalPathfinding();
	}
	return;
}

/*
	Imp
*/
Imp::Imp(byte index, byte color, byte maxhp)
	: RegularEnemy{ index, 0xe7, color, maxhp }
{
	undefined2 unaff_SS;
	undefined uVar1;

	__StackCheck(0);
	WORD_1d2e_019e = WORD_1d2e_019e + 1;
}

Imp::Imp(byte index, byte color, byte maxhp, byte xpos, byte ypos, bool draw)
	: RegularEnemy{ xpos, ypos, index, 0xe7, color, maxhp, draw }
{
	undefined2 unaff_SS;
	undefined uVar1;

	__StackCheck(0);
	WORD_1d2e_019e = WORD_1d2e_019e + 1;
}

Imp::~Imp()
{
	undefined2 unaff_SS;

	__StackCheck(0);
	WORD_1d2e_019e = WORD_1d2e_019e - 1;
}

void Imp::AiAttackPlayer()
{
	word wVar1;
	undefined2 unaff_SS;
	PascalString255* dest;
	PascalString255 local_104;
	byte local_3;

	__StackCheck(0x102);
	local_3 = Random(3);
	// FIXME: First message from the Imp Action string table is never used!
	if (local_3 != 0) {
		local_104 = P_STRING__ARRAY_1d2e_0696[this->index - 0x01];
		Concat(local_104, P_STRING_ARRAY_1d2e_01a0[local_3]);
		FUN_16d5_0019(local_104);
		if (this->index == 0xf) {
			Enemy::AiAttackPlayer();
		}
	}
	return;
}

/*
	Green Imp
*/
DAT_1d2e_000a::~DAT_1d2e_000a()
{
	undefined2 unaff_SS;

	__StackCheck(0);
	BYTE_1d2e_3349 = BYTE_1d2e_3349 - 1;
}

/*
	Bat'ka
*/
DAT_1d2e_00be::DAT_1d2e_00be()
	: Enemy{ 5, 0x81, 5, SWORD_1d2e_017a }
{
	undefined2 unaff_SS;
	undefined uVar1;

	__StackCheck(0);
	FUN_16d5_0019("А вось i БАЦЬКА!!!!!!!");
}

DAT_1d2e_00be::DAT_1d2e_00be(byte xpos, byte ypos, bool draw)
	: Enemy{ xpos, ypos, 5, 0x81, 5, SWORD_1d2e_017a, draw }
{
	undefined2 unaff_SS;
	undefined uVar1;

	__StackCheck(0);
}

DAT_1d2e_00be::~DAT_1d2e_00be()
{
	undefined2 uVar1;
	void* pcVar2;
	byte bVar3;
	char cVar4;
	Enemy* psVar5;
	Enemy* psVar6;
	int iVar7;
	undefined2 uVar8;
	undefined2 unaff_SS;
	byte ypos;
	byte xpos;
	UFileStream local_142;
	byte local_c1;
	byte local_c0;
	byte local_bf;
	byte local_be;
	byte local_bd;
	byte local_bc;
	byte local_bb;
	byte local_ba[16]; // blue
	byte local_aa[16]; // green
	byte local_9a[16]; // red
	byte local_8a;
	byte local_89;
	byte local_88;
	byte local_87;
	Enemy* local_86;
	UFileStream local_82;

	__StackCheck(0x140);
	FUN_1b04_0c7f("mnskbnd5.dat", 0xbe, 0xdf);
	FUN_1b04_0d8a();
	if (this->hp <= 0) {
		FUN_16d5_0019("");
		WORD_1d2e_3352 = WORD_1d2e_3352 + 1000;
		local_87 = 0;
		while (true) {
			Console.GetPaletteColor(local_87, &local_9a[local_87], &local_aa[local_87], &local_ba[local_87]);
			if (local_87 == 0xf) break;
			local_87 = local_87 + 1;
		}
		local_be = 0;
		while (true) {
			local_87 = 0;
			while (true) {
				Console.GetPaletteColor(local_87, &local_bb, &local_bc, &local_bd);
				if (local_bb < 0x3f) {
					local_bb = local_bb + 1;
				}
				if (local_bc < 0x3f) {
					local_bc = local_bc + 1;
				}
				if (local_bd < 0x3f) {
					local_bd = local_bd + 1;
				}
				Console.SetPaletteColor(local_87, local_bb, local_bc, local_bd);
				if (local_87 == 0xf) break;
				local_87 = local_87 + 1;
			}
			Console.UpdatePalette();
			FUN_1b04_0dc1(0xf);
			if (local_be == 0x3f) break;
			local_be = local_be + 1;
		}
		local_88 = 1;
		while (true) {
			local_87 = 1;
			while (FUN_1b04_0487(local_87, local_88, 0x20, 0xf0), local_87 != 0x50) {
				local_87 = local_87 + 1;
			}
			if (local_88 == 0x19) break;
			local_88 = local_88 + 1;
		}
		local_88 = 10;
		while (true) {
			local_87 = 1;
			while (FUN_1b04_0487(local_87, local_88, 0x20, 0xc0), local_87 != 0x50) {
				local_87 = local_87 + 1;
			}
			if (local_88 == 0x10) break;
			local_88 = local_88 + 1;
		}
		Assign(local_142, "mnskbnd6.dat");
		Reset(local_142, 1);
		__IOCheck();
		while (true) {
			cVar4 = Eof(local_142);
			__IOCheck();
			if (cVar4 != 0) break;
			Read(local_142, &local_bf);
			__IOCheck();
			Read(local_142, &local_c0);
			__IOCheck();
			Read(local_142, &local_c1);
			__IOCheck();
			local_bf = local_bf ^ 0xdf;
			local_c0 = local_c0 ^ 0xdf;
			local_c1 = local_c1 ^ 0xdf;
			FUN_1b04_0487(local_bf, local_c0, local_c1, 0xfc);
		}
		Close(local_142);
		__IOCheck();
		local_88 = 1;
		while (true) {
			local_87 = 1;
			while (FUN_1b04_0487(local_87, local_88, 0x20, 0), local_87 != 0x50) {
				local_87 = local_87 + 1;
			}
			if (local_88 == 2) break;
			local_88 = local_88 + 1;
		}
		local_88 = 0x18;
		while (true) {
			local_87 = 1;
			while (FUN_1b04_0487(local_87, local_88, 0x20, 0), local_87 != 0x50) {
				local_87 = local_87 + 1;
			}
			if (local_88 == 0x19) break;
			local_88 = local_88 + 1;
		}
		do {
			Console.GetPaletteColor(0x0C, &local_bb, &local_bc, &local_bd);
			if (local_9a[0xc] < local_bb) {
				local_bb = local_bb - 1;
			}
			if (local_aa[0xc] < local_bc) {
				local_bc = local_bc - 1;
			}
			if (local_ba[0xc] < local_bd) {
				local_bd = local_bd - 1;
			}
			Console.SetPaletteColor(0x0C, local_bb, local_bc, local_bd);
			Console.UpdatePalette();
			FUN_1b04_0dc1(0xf);
		} while (((local_bb != local_9a[0xc]) || (local_bc != local_aa[0xc])) || (local_bd != local_ba[0xc]));
		local_be = 0x3f;
		while (true) {
			Console.SetPaletteColor(0x00, local_be, local_be, local_be);
			Console.UpdatePalette();
			FUN_1b04_0dc1(0xf);
			if (local_be == 0) break;
			local_be = local_be - 1;
		}
		Console.SetPaletteColor(0x0A, local_9a[10], local_aa[10], local_ba[10]);
		Console.UpdatePalette();
		FUN_1b04_0500(0x1b, 1, "Вiншаваньнi! Лявон перамог!", 10);
		FUN_1b04_0500(0x1a, 0x19, "Нацiсьнiце адвольную клявiшу.", 10);
		FUN_1b04_05b3(&local_89, &local_8a);
		FUN_1b04_0234();
		FUN_1b04_0c7f("mnskbnd1.dat", 0, 0xff);
		Assign(local_82, "menskbnd.sav");
		Rewrite(local_82, 1);
		__IOCheck();
		Close(local_82);
		__IOCheck();
		FUN_16d5_3548();
		Console.ResetBuffer();
		Halt(0);
	}
	else {
		SWORD_1d2e_017a = this->hp;
		if (this == PTR_1d2e_0156) {
			PTR_1d2e_0156 = this->pNext;
		}
		else {
			local_86 = PTR_1d2e_0156;
			while (true) {
				if (this == local_86->pNext) break;
				local_86 = local_86->pNext;
			}
			local_86->pNext = this->pNext;
		}
		BYTE_1d2e_3348 = BYTE_1d2e_3348 - 1;
		FUN_1b04_064b();
	}
	return;
}

void DAT_1d2e_00be::AiThink()
{
	word wVar1;
	Enemy* local_8;
	byte local_3;

	__StackCheck(6);
	if ((Random(0x46) == 0) && (BYTE_1d2e_3348 <= 0xf)) {
		FUN_16d5_0019("БАЦЬКА выклiкае мянтоў!!!");
		local_3 = 1;
		while (true) {
			if (BYTE_1d2e_3348 <= 0xf) {
				local_8 = new DAT_1d2e_005a();
			}
			if (local_3 == 10) break;
			local_3 = local_3 + 1;
		}
	}
	else {
		NormalPathfinding();
	}
	return;
}

/*
	Hedgehog Ninja
*/
Ally::Ally(byte param_1, byte icon, byte color)
	: _metadata{ 0x0002 }
{
	word wVar1;
	Ally* psVar2;
	undefined2 uVar3;
	undefined2 unaff_SS;
	undefined uVar4;

	__StackCheck(0);
	do {
		this->xpos = Random(0x40) + 0x10;
		this->ypos = Random(0x13) + 4;
	} while (BYTE_ARRAY_ARRAY_1d2e_152c[xpos - 0x0F][ypos - 0x02] != 0xFA);
	this->_unk_00 = param_1;
	this->color = color;
	this->icon = icon;
	BYTE_ARRAY_ARRAY_1d2e_152c[xpos - 0x0F][ypos - 0x02] = this->icon;
	FUN_1b04_0487(this->xpos, this->ypos, this->icon, this->color);
	this->item = 0xfa;
}

void Ally::AiThink()
{
	byte bVar1;
	bool bVar2;
	uint uVar3;
	uint uVar4;
	int iVar5;
	uint uVar6;
	uint uVar7;
	Ally* psVar8;
	Enemy* psVar9;
	undefined2 uVar10;
	undefined2 uVar11;
	byte local_d;
	sbyte local_c;
	sbyte local_b;
	byte local_a;
	byte local_9;
	byte local_8;
	byte local_7;
	Enemy* local_6;

	__StackCheck(0xc);
	local_6 = PTR_1d2e_0156;
	local_8 = 0xff;
	local_a = 1;
	do {
		if (std::abs(local_6->ypos - this->ypos) < std::abs(local_6->xpos - this->xpos)) {
			local_9 = std::abs(local_6->xpos - this->xpos);
		}
		else {
			local_9 = std::abs(local_6->ypos - this->ypos);
		}
		if (local_9 < local_8) {
			local_8 = local_9;
			local_7 = local_a;
		}
		local_6 = local_6->pNext;
		local_a = local_a + 1;
	} while (local_6->pNext != NULL);
	local_6 = PTR_1d2e_0156;
	local_d = local_7 - 1;
	if (local_d != 0) {
		for (local_a = 1; local_6 = local_6->pNext, local_a != local_d;
			local_a = local_a + 1) {
		}
	}
	if (local_8 == 1) {
		AiAttack(local_6);
	}
	else {
		if (local_6->xpos < this->xpos) {
			local_b = -1;
		}
		else if (this->xpos < local_6->xpos) {
			local_b = 1;
		}
		else {
			local_b = 0;
		}
		if (local_6->ypos < this->ypos) {
			local_c = -1;
		}
		else if (this->ypos < local_6->ypos) {
			local_c = 1;
		}
		else {
			local_c = 0;
		}
		if (FUN_12d2_0000(this->xpos + local_b, this->ypos + local_c)) {
			AiMove(local_b, local_c);
		}
		else {
			if (FUN_12d2_0000(this->xpos + local_b, this->ypos)) {
				AiMove(local_b, 0);
			}
			else {
				if (FUN_12d2_0000(this->xpos, this->ypos + local_c)) {
					AiMove(0, local_c);
				}
			}
		}
	}
	return;
}

void Ally::AiMove(sbyte dx, sbyte dy)
{
	Ally* psVar1;
	undefined2 uVar2;

	__StackCheck(0);
	BYTE_ARRAY_ARRAY_1d2e_152c[xpos - 0x0F][ypos - 0x02] = this->item;
	FUN_1b04_0487(this->xpos, this->ypos, this->item, 7);
	FUN_16d5_0c6a(this->xpos, this->ypos);
	this->xpos = this->xpos + dx;
	this->ypos = this->ypos + dy;
	this->item = BYTE_ARRAY_ARRAY_1d2e_152c[xpos - 0x0F][ypos - 0x02];
	BYTE_ARRAY_ARRAY_1d2e_152c[xpos - 0x0F][ypos - 0x02] = this->icon;
	FUN_1b04_0487(this->xpos, this->ypos, this->icon, this->color);
	return;
}

void Ally::AiAttack(Enemy* target)
{
	undefined2 uVar2;
	undefined2 unaff_SS;
	Enemy* psVar3;
	PascalString255* dest;
	PascalString255 local_106;
	Enemy* local_6;

	__StackCheck(0x104);
	local_106 = "Вожык - нiньдзя размазаў па асфальце ";
	Concat(local_106, P_STRING__ARRAY_1d2e_0832[target->index - 0x01]);
	Concat(local_106, ".");
	FUN_16d5_0019(local_106);
	target->hp = 0;
	delete target;
	local_6 = NULL;
	if (BYTE_1d2e_3348 < 7) {
		do {
			local_6 = FUN_12d2_3887();
		} while (local_6 == NULL);
	}
	return;
}

Ally::~Ally()
{
	Ally* psVar1;
	undefined2 uVar2;
	undefined2 unaff_SS;

	__StackCheck(0);
	BYTE_ARRAY_ARRAY_1d2e_152c[xpos - 0x0F][ypos - 0x02] = this->item;
	FUN_1b04_0487(this->xpos, this->ypos, this->item, 7);
	FUN_16d5_0c6a(this->xpos, this->ypos);
	this->_unk_00 = 0;
	return;
}
