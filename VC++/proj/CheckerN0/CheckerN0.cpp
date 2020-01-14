#include <stdio.h>
#include <string>
#include <malloc.h>
int main(int argc,char*[] argv){
	int direction_order[20] = {};	//	default is NO_DIRECTION (-1)
	int used_direction_amount[4] = {};
	int coordinate_record[20][20] = {};	//	coordinate_record[10][10] is the origin
	int location_now[2] = {};
	int SAWnum=1;//How many SAWs
	bool cautf[6]={};
	for(int i=0;i<argc,i++){
		string com(argv[i]);
		if(com=="/n"){
			com=argv(++i);
			SAWnum=(int)com;
			continue;
		}
		if(com=="/c"){
			com=argv(++i);
			cautf((int)com)=true;
			continue;
		}
	}
		
	string** SAWs=(string*)malloc(sizeof(string*)*SAWnum);
	for(int i=0;i<SAWnum;i++){
		char str[21];
		scanf("%s",str);
		SAWs[i]=new string(str);
	}
	return 0;
}