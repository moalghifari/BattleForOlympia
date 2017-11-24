#include <stdio.h>
#include "stringt.h"
#include "command.h"
#include "point.h"
#include "MatriksMap.h"
#include "unit.h"
#include "stackt.h"
#include "player.h"
#include "queuelist.h"

int main()	{
	int n, NB, NK;
	char* cmd;
	POINT P;
	MatriksMap M;
	Player CurrPlayer, P1, P2;
	Stack SUndo;
	QueueU Q;
	Queue QP;
	Unit CurrUnit;
	printf("=====================================\n");
	printf("=== WELCOME TO BATTLE FOR OLYMPIA ===\n");
	printf("=====================================\n");
	printf("\n");
	printf("by : \n");
	printf("1. Mochamad Alghifari\n");
	printf("2. Rifqi Rifaldi Utomo\n");
	printf("3. M. Rafli Al Khadafi\n");
	printf("4. M. Alfian Rasyidin\n");
	printf("5. M. Aufa Helfiandri\n");
	printf("\n");
	printf("\n");
	printf("MENU : \n");
	printf("1. START\n");
	printf("2. LOAD\n");
	printf("3. EXIT\n");
	printf("Choose Menu : \n");	scanf("%d", &n);
	if (n==1)	{
		printf("Create Map : \n");	
		printf("Row : "); scanf("%d", &NB);
		printf("Column : "); scanf("%d", &NK);
		M = MatGen(NB,NK);
		CreateTurn(&QP, P1, P2);
		InitPlayer(&P1, &P2, NB,NK);
		cmd=" ";
		CurrPlayer = P1;
		while (strcmp(cmd,"EXIT")!=0)	{
			PrintMap(M);
			CurrUnit = getUnit(CurrentUnitPos(CurrPlayer),M);
			Q = MakeUnitQueue(UnitList(CurrPlayer));
			printf("Player %d's Turn\n", PlayNumber(CurrPlayer));
			// PrintInfoPlayer(CurrPlayer);
			PrintInfoUnit(CurrUnit);
			MainMove(&SUndo, &CurrUnit, &M);
			PrintMap(M);
			printf("Your Input : "); scanf("%s", cmd);
			PrintMap(M);
			if (!strcmp(cmd,"MOVE"))	{
				MainMove(&SUndo, &CurrUnit, &M);
			}
			if (!strcmp(cmd,"UNDO"))	{
				Undo(&SUndo,&CurrUnit);
			}
			if (!strcmp(cmd,"CHANGE_UNIT"))	{
				ChangeCurrUnit(&Q,M,&CurrPlayer);
			}
			if (!strcmp(cmd,"RECRUIT"))	{
				RecruitUnit (CurrPlayer, &UnitList(CurrPlayer), &Q, M);
			}
			if (!strcmp(cmd,"ATTACK"))	{
				//Attack
			}
			if (!strcmp(cmd,"MAP"))	{
				PrintMap(M);
			}
			if (!strcmp(cmd,"INFO"))	{
				MainInfo(M);
			}
			if (!strcmp(cmd,"END_TURN"))	{
				NextTurn(&QP,&CurrPlayer);
			}
			if (!strcmp(cmd,"SAVE"))	{

			}
			if (!strcmp(cmd,"EXIT"))	{

			}
		}

	} else if (n==2)	{

	}
	printf("======================================\n");
	printf("=========== GOOD BYE COOPS ===========\n");
	printf("======================================\n");
}
