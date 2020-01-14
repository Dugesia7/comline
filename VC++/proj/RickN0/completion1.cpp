#include<stdio.h>
#include"sc1.h"
#define BLOCK -1
#define abs(a) (a<0?-1*a:a)

//local macro for the function "function"
#define ROOT(a,b) (coordinate_record[a+10][b+10])//enable to access the local valuable "coordinate_record" by raw position
inline int function() {
	//declarations&definitions
	int used_direction_amount[4] = {};
	int coordinate_record[20][20] = {};	//	coordinate_record[10][10] is the origin
	int counter = 0;
	//initialization
	ROOT(0, 0) = true;
	for (int i = 0; i < scM; i++)ROOT(scB[0][i], scB[1][i]) = BLOCK;

	//body
	const int alldownf = (1 << (2 * scN)) - 1;
	const int end = scN - 1;
	for (__int64 flags = 0; flags<alldownf; flags++) {//each 2bit-flags mean a direction
		int loc[2] = {};//location_now
		int dam[4] = {};//used_direction_amount
		for (int stage = 0; stage<end; stage++) {
			int d = (flags >> (2 * (end - stage))) & 3;//direction
			int db = stage == 0 ? -1 : (flags >> (2 * (end - stage - 1))) & 3;//direction before
			loc[d & 1] = 2 * (d & 2) - 1;
			ROOT(loc[0], loc[1])++;
			if ((abs(loc[0]) + abs(loc[1]) > end - stage + 1)//cautioni
				|| (abs(dam[d] - dam[(d + 2) % 4] > end - stage))//caoutionii
				|| (d != db && d % 2 == db % 2)//cautioniii
											   //||(dam[d]>((end-1)/2))//cautioniv
				) {
				flags >>= 2 * (end - stage - 1);
				flags++;
				flags <<= 2 * (end - stage - 1);
				break;
			}
			if ((ROOT(loc[0], loc[1])>1 && stage != end)//cautionv
				) {
			}
		}
	}

	return counter;
}
#undef ROOT//keep the macro in local

int main()
{
	//scInput();

	//scOutput(function(0));
	return 0;
}