#include<stdio.h>
#include<stdlib.h>
#include"sc1.h"

int direction_order[20] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };//default is -1
int N = 0;
int used_direction_amount[4] = {};
int coordinate_record[20][20] = {};//coordinate_record[10][10] is the origin
int location_now[2] = {};
int counter = 0;

void function(int stage)
{
	int d;
	for (d = 0; d < 4; d++)
	{
		used_direction_amount[d]++;
		
		//CAUTION i. you have to return to the origin in options left
		if (abs(location_now[0])+abs(location_now[1])>N-stage)
		{
			//printf("%d\tCAUTION I.\n", stage);
			used_direction_amount[d]--;
			continue;
		}
		//CAUTION ii. the number of the direction & that of the opposite is same
		if (abs(used_direction_amount[d] - used_direction_amount[(d + 2) % 4]) > N - stage - 1)//opposite is represented as (d+2)%4
		{
			//printf("%d\tCAUTION II.\n", stage);
			used_direction_amount[d]--;
			continue;
		}
		//CAUTION iii. NOT put the opposite direction aside
		if (stage != 0 && d != direction_order[stage - 1] && d % 2 == direction_order[stage - 1] % 2)
		{
			//printf("%d\tCAUTION III.\n", stage);
			used_direction_amount[d]--;
			continue;
		}
		//CAUTION iv. each direction has the capacity (n-2)2
		if (used_direction_amount[d] > (N - 2) / 2)
		{
			//printf("%d\tCAUTION IV.\n", stage);
			used_direction_amount[d]--;
			continue;
		}
		//locatrion recording
		location_now[!(d % 2)] += 2 * (d < 2) - 1;
		
		//CAUTION v. NOT reach the coordinate you have reached previously
		if (coordinate_record[location_now[0] + 10][location_now[1] + 10] == 1)
		{
			//printf("%d\tCAUTION V.\n", stage);
used_direction_amount[d]--;
//location back
location_now[!(d % 2)] -= 2 * (d < 2) - 1;
continue;
}

//CAUTION vii. NOT reach the coordinate with a block
if (coordinate_record[location_now[0]+10][location_now[1]+10]==-2)
{
//printf("%d\tCAUTIONVII.\n", stage);
used_direction_amount[d]--;
//location back
location_now[!(d % 2)] -= 2 * (d < 2) - 1;
continue;
}

//completion check
if (stage == N - 2 &&
((abs(location_now[0]) == 1 && location_now[1] == 0) ||
(location_now[0] == 0 && abs(location_now[1]) == 1))
)
{
//printf("COMPLETE\n");
used_direction_amount[d]--;
counter++;
//location back
location_now[!(d % 2)] -= 2 * (d < 2) - 1;
return;
}

coordinate_record[location_now[0] + 10][location_now[1] + 10] = 1;
//printf("%d\t\t%d\t%d\n", stage, location_now[0], location_now[1]);
direction_order[stage] = d;

function(stage + 1);
coordinate_record[location_now[0] + 10][location_now[1] + 10] = 0;
direction_order[stage + 1] = -1;
//location back
location_now[!(d % 2)] -= 2 * (d < 2) - 1;
used_direction_amount[d]--;
}
return;
}

int main()
{
scInput();
N = scN;
coordinate_record[10][10] = 1;

for (int i = 0; i < scM; i++)
{
coordinate_record[scB[0][i]+10][scB[1][i]+10] = -2;
}

function(0);

scOutput(counter);
while (true)
{

}
return 0;
}
