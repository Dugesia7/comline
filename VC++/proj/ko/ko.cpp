#include<stdio.h>

struct A{
	size_t c;
	int a;
	char b[4];
	struct{char *e;char f[3];} d;
};

int main(){
	FILE* fp=fopen("test.txt","wb");
	struct A* aa=new struct A;
	//*aa={sizeof(A),0xFF,{'A','B','C','\0'},{"strinds",{'E','F,','\0'}}};
	aa->c=sizeof(A);
	aa->a=0xFF;
	for(int i=0;i<4;i++)aa->b[i]="ABC\0"[i];
	//aa->d={"strinds",{'E','F,','\0'}};
	aa->d.e=new char[8];
	for(int i=0;i<10;aa->d.e[i++]="strinds"[i]);
	for(int i=0;i<3;aa->d.f[i++]="DE\0"[i]);
	//char a[10]={};
	//fread(a,9,1,fp);
	//int i;
	//for(i=0;fprintf(fp,"%d",i)>=0;i++);
	//printf("%s",a);
	fwrite(aa,sizeof(struct A),1,fp);
	return 0;
}