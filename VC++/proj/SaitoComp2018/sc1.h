#include<stdio.h>
#include<time.h>

int scN,scM;
int scB[2][10];
clock_t scStartTime,scEndTime;
void scInput(){
	int i;
	scanf("%d%d",&scN,&scM);
	for(i=0;i<scM;++i){scanf("%d%d",&scB[0][i],&scB[1][i]);}
	scStartTime=clock();
}
void scOutput(int s){
	scEndTime=clock();
	printf("Ans= %d, time=%d\n",s,(int)(scEndTime-scStartTime));
}
