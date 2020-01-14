#include<stdio.h>
#include<sys\stat.h>
#include<malloc.h>
const char add[]="test.txt"

int main(){
	FILE* fp=fopen(add,"w+");
	if(fp=NULL){printf("Failed to open file.");goto end;}
	struct stat stbuf;
	if(stat(add,&stbuf)){printf("Failed to get stat.");goto end;}
	char* str;
	
	fscanf(fp,""
	
	
	end:
	for(;;);
}