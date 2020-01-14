#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define listnum 10

int main(){
	FILE* fp;
	char chosenOdai[100];
	char odai[]="odai.txt";
	char odaiR[]="odaiR.txt";
	char* odaibako[2]={odai,odaiR};
	fp=fopen(odaibako[time(NULL)%2],"r");
	srand(time(NULL));
	int r=rand()%listnum;
	for(int i=0;i<=r;i++){
		fgets(chosenOdai,100,fp);
		//printf("r=%d,%s",r,chosenOdai);
	}
	printf("%s",chosenOdai);
	
}