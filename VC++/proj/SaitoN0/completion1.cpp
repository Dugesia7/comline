/*
	for SuperCon 2018 by Saito Takuma, EINSTEIN HEAD
*/

/*
	*************************
			OUTLINE
	*************************
	STEP1.	input
	STEP2.	block's coordinates conversion
	STEP3.	recursive function behaviour
		for 4 directions: RIGHT, UP, LEFT, & DOWN, (these are represented as 0, 1, 2, 3),
		3-1.	cut off impossible options checking each CAUTIONs hung below
		3-2.	parameters update
		3-3.	check whether you reached the goal: the origin
		3-4.	pass to the next stage as 
					function(stage + 1);
		3-5.	revision of parameters
		returning
	STEP4.	output
*/

/*
	************************
			CAUTION
	************************
	CAUTION I.		you have to return the origin in options left
	CAUTION II.		the No. of the direction & that of the opposite is same
	CAUTION III.	NOT put the opposite direction aside
	CAUTION IV.		each direction has a capacity of number (scN - 2) / 2
	CAUTION V.		NOT reach the coordinate you have reached previously
	CAUTION VI.		NOT reach the coordinate with a block
*/

#include<stdio.h>
#include<stdlib.h>
#include"sc1.h"

//#define debugA
#define debugB

#ifdef debugA
#define debugB
#endif

#define true 1
#define false 0
#define BLOCK -1
#define NO_DIRECTION -1

int direction_order[20] = {};	//	default is NO_DIRECTION (-1)
int used_direction_amount[4] = {};
int coordinate_record[20][20] = {};	//	coordinate_record[10][10] is the origin
int location_now[2] = {};
int counter = 0;

void function(int stage)
{
	int d;
	for (d = 0; d < 4; d++)
	{
		used_direction_amount[d]++;
		
		//	CAUTION i. you have to return to the origin in options left
		/*
		if (abs(location_now[0]) + abs(location_now[1]) > scN - stage )
		{
#ifdef debugA
			printf("%d\tCAUTION I.\n", stage);
#endif
			used_direction_amount[d]--;
			continue;
		}
		*/
		//	CAUTION ii. the number of the direction & that of the opposite is same
		
		if (abs(used_direction_amount[d] - used_direction_amount[(d + 2) % 4]) > scN - stage - 1)	//	when you cannot recover the difference
		{
#ifdef debugA
			printf("%d\tCAUTION II.\n", stage);
#endif
			used_direction_amount[d]--;
			continue;
		}
		

		//	CAUTION iii. NOT put the opposite direction aside
		if (stage != 0 && d != direction_order[stage - 1] && d % 2 == direction_order[stage - 1] % 2)
		{
#ifdef debugA
			printf("%d\tCAUTION III.\n", stage);
#endif
			used_direction_amount[d]--;
			continue;
		}

		//	CAUTION iv. each direction has the capacity (n-2)/2
		/*
		if (used_direction_amount[d] > (scN - 2) / 2)
		{
#ifdef debugA
			printf("%d\tCAUTION IV.\n", stage);
#endif
			used_direction_amount[d]--;
			continue;
		}
		*/
		//	locatrion recording
		location_now[d%2] += 2 * (d < 2) - 1;

		//	CAUTION v. NOT reach the coordinate you have reached previously
		if ((coordinate_record[location_now[0] + 10][location_now[1] + 10] != 0 )&& (stage != scN - 1))
		{
#ifdef debugA
			printf("%d\tCAUTION V.\n", stage);
#endif
			used_direction_amount[d]--;
			//	location back
			location_now[d%2] -= 2 * (d < 2) - 1;
			continue;
		}
/*
		//	CAUTION vi. NOT reach the coordinate with a block
		if (coordinate_record[location_now[0] + 10][location_now[1] + 10] == BLOCK)
		{
#ifdef debugA
			printf("%d\tCAUTION VI.\n", stage);
#endif
			used_direction_amount[d]--;
			//	location back
			location_now[d%2] -= 2 * (d < 2) - 1;
			continue;
		}
*/
		//	parameters update
		coordinate_record[location_now[0] + 10][location_now[1] + 10] = true;
#ifdef debugA
		printf("%d\t\t%d\t%d\n", stage, location_now[0], location_now[1]);
#endif
		direction_order[stage] = d;

		//	completion check
		if (stage == scN - 1 && location_now[0] == 0 && location_now[1] == 0)
		{
#ifdef debugB
			for (int i = 0; i < scN; i++)
				printf("%d", direction_order[i]);
			printf("\b\n");
#endif
			counter++;
			
			//	parameters revision
			coordinate_record[location_now[0] + 10][location_now[1] + 10] = false;
			coordinate_record[10][10] = true;
			location_now[d%2] -= 2 * (d < 2) - 1;
			used_direction_amount[d]--;
			return;
		}
		
		function(stage + 1);
		if (location_now[0] || location_now[1])
			coordinate_record[location_now[0] + 10][location_now[1] + 10] = false;
		direction_order[stage + 1] = NO_DIRECTION;
		//	location back
		location_now[d%2] -= 2 * (d < 2) - 1;
		used_direction_amount[d]--;
	}
	return;
}

int main()
{
	scInput();
	coordinate_record[10][10] = true;

	for (int i = 0; i < 20; i++)
		direction_order[i] = NO_DIRECTION;
	for (int i = 0; i < scM; i++)
	{
		coordinate_record[scB[0][i]+10][scB[1][i]+10] = BLOCK;
	}

	function(0);
	
	scOutput(counter);

	
	return 0;
}