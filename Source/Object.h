#pragma once

#include "Rtl.h"


/*
	CODE Section
	ram:12d2:0000-ram:12d2:402f
*/

/*
	Enemy
*/
class Enemy
{
public:
	// Enemy* __pascal16far FUN_12d2_0523(byte index, byte icon, byte color, word maxhp, word data, Enemy* this)
	Enemy(byte index, byte icon, byte color, word maxhp);

	// Enemy* __pascal16far FUN_12d2_05ce(byte xpos, byte ypos, byte index, byte icon, byte color, word maxhp, bool draw, word data, Enemy* this)
	Enemy(byte xpos, byte ypos, byte index, byte icon, byte color, word maxhp, bool draw);

	virtual ~Enemy() = default;

	virtual void AiThink() = 0;

	// void __pascal16far FUN_12d2_0679(Enemy* this)
	virtual void AiAttackPlayer();

	// void __pascal16far FUN_12d2_0850(byte xpos, byte ypos, Enemy* this)
	void AiAttackFoe(byte xpos, byte ypos);

	// void __pascal16far FUN_12d2_0bc0(Enemy* this)
	void NormalPathfinding();

	// void __pascal16far FUN_12d2_14a8(Enemy* this)
	void DrunkPathfinding();

	// void __pascal16far FUN_12d2_0acf(Enemy* this)
	void DrawSymbol();

	// void __pascal16far FUN_12d2_0b4b(Enemy* this)
	void ClearSymbol();

//protected:
	byte index;
	byte icon;
	byte color;
	sword hp;
	byte xpos;
	byte ypos;
	Enemy* pNext;
};

/*
	NOTE: Regular enemies don't share dtor with Bat'ka
*/
class RegularEnemy : public Enemy
{
public:
	using Enemy::Enemy;

	// void __pascal16far FUN_12d2_0e2a(bool free, Enemy* this)
	~RegularEnemy();
};

/*
	Gopnik
*/
class DAT_1d2e_0096 : public RegularEnemy
{
public:
	using RegularEnemy::RegularEnemy;

	// Enemy* __pascal16far FUN_12d2_1a90(word data, Enemy* this)
	DAT_1d2e_0096()
		: RegularEnemy{ 1, 0xa3, 9, 3 }
	{ }

	// Enemy* __pascal16far FUN_12d2_1ac6(byte xpos, byte ypos, bool draw, word data, Enemy* this)
	DAT_1d2e_0096(byte xpos, byte ypos, bool draw)
		: RegularEnemy{ xpos, ypos, 1, 0xa3, 9, 3, draw }
	{ }

	//void __pascal16far FUN_12d2_1b08(Enemy* this)
	void AiThink() override;
};

/*
	Small Gopnik
*/
class DAT_1d2e_0046 : public DAT_1d2e_0096
{
public:
	// Enemy* __pascal16far FUN_12d2_10d4(word data, Enemy* this)
	DAT_1d2e_0046()
		: DAT_1d2e_0096{ 0xb, 0xa3, 6, 1 }
		, aistate{ 0 }
	{ }

	// Enemy* __pascal16far FUN_12d2_110a(byte xpos, byte ypos, bool draw, word data, Enemy* this)
	DAT_1d2e_0046(byte xpos, byte ypos, bool draw)
		: DAT_1d2e_0096{ xpos, ypos, 0xb, 0xa3, 6, 1, draw }
		, aistate{ 0 }
	{ }

	// void __pascal16far FUN_12d2_1424(Enemy* this)
	void AiThink() override;

	// void __pascal16far FUN_12d2_11c6(Enemy* this)
	void AiAttackPlayer() override;

private:
	byte aistate;
};

/*
	Drunk Gopnik
*/
class DAT_1d2e_006e : public DAT_1d2e_0096
{
public:
	// Enemy* __pascal16far FUN_12d2_1ba9(word data, Enemy* this)
	DAT_1d2e_006e()
		: DAT_1d2e_0096{ 2, 0xa3, 10, 5 }
	{ }

	// Enemy* __pascal16far FUN_12d2_1bdf(byte xpos, byte ypos, bool draw, word data, Enemy* this)
	DAT_1d2e_006e(byte xpos, byte ypos, bool draw)
		: DAT_1d2e_0096{ xpos, ypos, 2, 0xa3, 10, 5, draw }
	{ }

	// void __pascal16far FUN_12d2_1c21(Enemy* this)
	void AiThink() override;
};

/*
	Large Angry Gopnik
*/
class DAT_1d2e_00aa : public DAT_1d2e_0096
{
public:
	// Enemy* __pascal16far FUN_12d2_1cd5(word data, Enemy* this)
	DAT_1d2e_00aa()
		: DAT_1d2e_0096{ 3, 0xa3, 3, 0xf }
	{ }

	// Enemy* __pascal16far FUN_12d2_1d0b(byte xpos, byte ypos, bool draw, word data, Enemy* this)
	DAT_1d2e_00aa(byte xpos, byte ypos, bool draw)
		: DAT_1d2e_0096{ xpos, ypos, 3, 0xa3, 3, 0xf, draw }
	{ }
};

/*
	Skinhead
*/
class DAT_1d2e_00e6 : public RegularEnemy
{
public:
	using RegularEnemy::RegularEnemy;

	// Enemy* __pascal16far FUN_12d2_24e0(word data, Enemy* this)
	DAT_1d2e_00e6()
		: RegularEnemy{ 7, 0xe4, 9, 0xf }
	{ }

	// Enemy* __pascal16far FUN_12d2_2516(byte xpos, byte ypos, bool draw, word data, Enemy* this)
	DAT_1d2e_00e6(byte xpos, byte ypos, bool draw)
		: RegularEnemy{ xpos, ypos, 7, 0xe4, 9, 0xf, draw }
	{ }

	// void __pascal16far FUN_12d2_2558(Enemy* this)
	void AiThink() override;
};

/*
	Commie
*/
class DAT_1d2e_00fa : public DAT_1d2e_00e6
{
public:
	// Enemy* __pascal16far FUN_12d2_25f9(word data, Enemy* this)
	DAT_1d2e_00fa()
		: DAT_1d2e_00e6{ 8, 0xe4, 0xc, 0x14 }
	{ }

	// Enemy* __pascal16far FUN_12d2_262f(byte xpos, byte ypos, bool draw, word data, Enemy* this)
	DAT_1d2e_00fa(byte xpos, byte ypos, bool draw)
		: DAT_1d2e_00e6{ xpos, ypos, 8, 0xe4, 0xc, 0x14, draw }
	{ }
};

/*
	Drunk Commie
*/
class DAT_1d2e_0082 : public DAT_1d2e_00e6
{
public:
	// Enemy* __pascal16far FUN_12d2_18ef(word data, Enemy* this)
	DAT_1d2e_0082()
		: DAT_1d2e_00e6{ 0xc, 0xe4, 6, 0x19 }
	{ }

	// Enemy* __pascal16far FUN_12d2_1925(byte xpos, byte ypos, bool draw, word data, Enemy* this)
	DAT_1d2e_0082(byte xpos, byte ypos, bool draw)
		: DAT_1d2e_00e6{ xpos, ypos, 0xc, 0xe4, 6, 0x19, draw }
	{ }

	// void __pascal16far FUN_12d2_1967(Enemy* this)
	void AiThink() override;

	// void __pascal16far FUN_12d2_1a1b(Enemy* this)
	void AiAttackPlayer() override;
};

/*
	Barkashovets
*/
class DAT_1d2e_010e : public DAT_1d2e_00e6
{
public:
	// Enemy* __pascal16far FUN_12d2_2671(word data, Enemy* this)
	DAT_1d2e_010e()
		: DAT_1d2e_00e6{ 9, 0xe4, 3, 0x23 }
	{ }

	// Enemy* __pascal16far FUN_12d2_26a7(byte xpos, byte ypos, bool draw, word data, Enemy* this)
	DAT_1d2e_010e(byte xpos, byte ypos, bool draw)
		: DAT_1d2e_00e6{ xpos, ypos, 9, 0xe4, 3, 0x23, draw }
	{ }
};

/*
	Cop
*/
class DAT_1d2e_005a : public RegularEnemy
{
public:
	using RegularEnemy::RegularEnemy;

	// Enemy* __pascal16far FUN_12d2_1d4d(word size, Enemy* this)
	DAT_1d2e_005a()
		: RegularEnemy{ 4, 0xac, 0xc, 0x1e }
	{ }

	// Enemy* __pascal16far FUN_12d2_1d83(byte xpos, byte ypos, bool draw, word data, Enemy* this)
	DAT_1d2e_005a(byte xpos, byte ypos, bool draw)
		: RegularEnemy{ xpos, ypos, 4, 0xac, 0xc, 0x1e, draw }
	{ }

	// void __pascal16far FUN_12d2_1dc5(Enemy* this)
	void AiThink() override;
};

/*
	Special Unit (OMON)
*/
class DAT_1d2e_0122 : public DAT_1d2e_005a
{
public:
	// Enemy* __pascal16far FUN_12d2_26e9(word data, Enemy* this)
	DAT_1d2e_0122()
		: DAT_1d2e_005a{ 10, 0xac, 10, 0x3c }
	{ }

	// Enemy* __pascal16far FUN_12d2_271f(byte xpos, byte ypos, bool draw, word data, Enemy* this)
	DAT_1d2e_0122(byte xpos, byte ypos, bool draw)
		: DAT_1d2e_005a{ xpos, ypos, 10, 0xac, 10, 0x3c, draw }
	{ }
};

/*
	Imp
*/
class Imp : public RegularEnemy
{
public:
	// Enemy* __pascal16far FUN_12d2_16bd(byte index, byte color, byte maxhp, word data, Enemy* this)
	Imp(byte index, byte color, byte maxhp);

	// Enemy* __pascal16far FUN_12d2_16fb(byte index, byte color, byte maxhp, byte xpos, byte ypos, bool draw, word data, Enemy* this)
	Imp(byte index, byte color, byte maxhp, byte xpos, byte ypos, bool draw);

	// void __pascal16far FUN_12d2_17b7(bool free, Enemy* this)
	~Imp();

	void AiThink() override {
		DrunkPathfinding();
	}

	// void __pascal16far FUN_12d2_1745(Enemy* this)
	void AiAttackPlayer() override;
};

/*
	Green Imp (Neutral)
*/
class DAT_1d2e_000a : public Imp
{
public:
	// Enemy* __pascal16far FUN_12d2_17dd(word data, Enemy* this)
	DAT_1d2e_000a()
		: Imp{ 0xd, 2, 1 }
	{ }

	// Enemy* __pascal16far FUN_12d2_180f(byte xpos, byte ypos, bool draw, word data, Enemy* this)
	DAT_1d2e_000a(byte xpos, byte ypos, bool draw)
		: Imp{ 0xd, 2, 1, xpos, ypos, draw }
	{ }

	// void __pascal16far FUN_12d2_184d(bool free, Enemy* this)
	~DAT_1d2e_000a();
};

/*
	Blue Imp (Neutral)
*/
class DAT_1d2e_001e : public Imp
{
public:
	// Enemy* __pascal16far FUN_12d2_1873(byte xpos, byte ypos, bool draw, word data, Enemy* this)
	DAT_1d2e_001e(byte xpos, byte ypos, bool draw)
		: Imp{ 0xe, 9, 1, xpos, ypos, draw }
	{ }
};

/*
	Huge Infernal Cop
*/
class DAT_1d2e_0032 : public Imp
{
public:
	// Enemy* __pascal16far FUN_12d2_18b1(byte xpos, byte ypos, bool draw, word data, Enemy* this)
	DAT_1d2e_0032(byte xpos, byte ypos, bool draw)
		: Imp{ 0xf, 10, 0x37, xpos, ypos, draw }
	{ }
};

/*
	Club DJ (Miniboss)
*/
class DAT_1d2e_00d2 : public DAT_1d2e_0096
{
public:
	// Enemy* __pascal16far FUN_12d2_2761(byte xpos, byte ypos, bool draw, word data, Enemy* this)
	DAT_1d2e_00d2(byte xpos, byte ypos, bool draw)
		: DAT_1d2e_0096{ xpos, ypos, 6, 0xa4, 0xc, 100, draw }
	{ }
};

/*
	Bat'ka (Boss)
*/
class DAT_1d2e_00be : public Enemy
{
public:
	// Enemy* __pascal16far FUN_12d2_1e82(word data, Enemy* this)
	DAT_1d2e_00be();

	// Enemy* __pascal16far FUN_12d2_1ec2(byte xpos, byte ypos, bool draw, word data, Enemy* this)
	DAT_1d2e_00be(byte xpos, byte ypos, bool draw);

	// void __pascal16far FUN_12d2_1ff2(bool free, Enemy* this)
	~DAT_1d2e_00be();

	// void __pascal16far FUN_12d2_1f1e(Enemy* this)
	void AiThink() override;
};

/*
	Hedgehog Ninja
*/
class Ally
{
public:
	// Hedgehog* __pascal16far FUN_12d2_005c(byte param_1, byte icon, byte color, word data, Hedgehog* this)
	Ally(byte param_1, byte icon, byte color);

	// void __pascal16far FUN_12d2_011a(Hedgehog* this)
	void AiThink();

	// void __pascal16far FUN_12d2_033f(sbyte dx, sbyte dy, Hedgehog* this)
	void AiMove(sbyte dx, sbyte dy);

	// void __pascal16far FUN_12d2_0431(Enemy* target, Hedgehog* this)
	void AiAttack(Enemy* target);

	// void __pascal16far FUN_12d2_04b8(bool free, Hedgehog* this)
	~Ally();

//private:
	byte _unk_00;
	byte icon;
	byte color;
	byte xpos;
	byte ypos;
	byte item;
	byte _unk_06[2];
	word _metadata;	// Object metadata near ptr (DS:0002)
};

static_assert(sizeof(Ally) == 0x0A, "");
static_assert(offsetof(Ally, _metadata) == 0x08, "");
