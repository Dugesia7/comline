//デバッグ用ヘッダー
//無くてもコンパイルはできます
#pragma once
#ifndef MYDEBUG
#define MYDEBUG

typedef unsigned long long int dkusef;
constexpr int dABnum = 26 * 2;
constexpr int dnmax = 2000;
constexpr int dmmax = 10000;
constexpr char dAB[dABnum + 1] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";//アルファベット配列
typedef struct {//main関数ではこれ一個でほぼ事足りる素晴らしき構造体「bigstruct」
	//inputで確定する変数
	int n;//入力の個数
	dkusef ablf = 0;//文字が使用可能かのフラグ 大文字、小文字の揃わない文字は利用不可
	int abln = 0;//入力された作物の中で利用可能なものの数
	bool abls[dnmax];//作物が利用可能であるかのフラグ
	//計算で用いる変数
	dkusef crops[dmmax];//作物リスト
	int m = 0;//現在の交配回数
	//出力用変数
	int yn;//YESかNOか
	struct { int x, y; dkusef S; } macount[dmmax];//xとyを交配しcが出来る過程を記録
}dbigstruct;

inline void showkaass(int n, dkusef *Sf) {//show kuse array as string
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < dABnum; j++) {
			if (Sf[i] & (((dkusef)1) << j))printf("%c", dAB[j]);
		}
		printf("\n");
	}
}
inline void showkasb(dkusef S, char f = '0', char t = '1') {//show kuse as binary
	for (int i = 0; i < dABnum; i++) {
		printf("%c", ((S >> i) & 1) ? t : f);
	}
	printf("\n");
}
inline void showbig(dbigstruct *b){
	printf("<showbig>\nn=%d\nablf=",b->n);
	showkasb(b->ablf);
	printf("abln=%d\nabls=",b->abln);
	for(int i=0;i<b->n;i++)printf(b->abls[i]?"1":"0");
	printf("\ncrops=\n");
	showkaass(b->n+b->m,b->crops);
	printf("m=%d\nyn=%s",b->m,b->yn?"YES":"NO");
	for(int i=0;i<b->m;i++){
		printf("\nmacount[%d]=%d,%d,",i,b->macount[i].x,b->macount[i].y);
		showkasb(b->macount[i].S);
	}
}
#endif