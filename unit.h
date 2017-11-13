#ifndef _UNIT_H
#define _UNIT_H

#include "point.h"

// const int BaseMaxHPArcher = 70;
// const int BaseMaxHPWarrior = 90;
// const int BaseMaxHPMage = 120;
// const int BaseMaxHPKing = 200;

// const int BaseMaxMPArcher = 100;
// const int BaseMaxMPWarrior = 80;
// const int BaseMaxMPMage = 150;
// const int BaseMaxMPKing = 210;

typedef struct{
	char* Name;
	int Dmg;
	char* Type;
} Atk;

typedef struct{
	Atk TAttack[5];
	POINT Loc;
	int MaximumHP;
	int CurrHP;
	int MaximumMP;
	int CurrMP;
	int POwner;
	char* KarType;
} Unit;

#define Locate(U) (U).Loc
#define HP(U) (U).CurrHP
#define Tipe(U) (U).KarType
#define MP(U) (U).CurrMP
#define Owner(U) (U).POwner
#define MaxHP(U) (U).MaximumHP
#define MaxMP(U) (U).MaximumMP
#define TabAttack (U).TAttack
#define Attack(U,i) (U).TAttack[i-1]

//FUNGSI NULLITAS
Unit NullUnit ();

//FUNGSI FUNGSI UNIT
int Distance(POINT U1, POINT U2);
//Mengembalikan jarak antara karakter 1 dan 2.

boolean IsUnitAdjacent (Unit U1, Unit U2);
//Mengeluarkan True Jika U1 dan U2 Adjacent atau beda sepetak dengan U2.

boolean IsTopPresent(Unit U);
//Mengembalikan True jika terdapat unit di 

boolean IsUnitAdjacent (Unit U1, Unit U2);
//Mengeluarkan True Jika U1 dan U2 Adjacent atau beda sepetak dengan U2.

Unit MakeUnit (int Owner, char Type, POINT Loc);
//Membuat Unit Baru dengan Owner, Type, dan Location yang dispesifikkan

void AttackU (Unit U1, Unit U2, Atk A);
//Membuat Unit 1 Menyerang Unit 2 dengan tipe Attack 1

void PrintAtkType(Unit U);
//Memprint ke layar Tipe Attack yang dapat dilakukan oleh Unit U

#endif
