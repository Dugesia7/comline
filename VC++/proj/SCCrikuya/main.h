#pragma once
#ifndef MAINCLUDE
#define MAINCLUDE
#include "mydebug.h"

//プログラマ向け各種定義
typedef unsigned long long int kusef;//クセフラグ　一つでクセ文字列一つ分
constexpr int nmax = 2000;//n(入力の個数)の最大値
constexpr int mmax = 10000;//m（交配回数）の最大値
constexpr int ABnum = 26 * 2;//アルファベットの数＊文字の大小
constexpr char AB[ABnum + 1] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";//アルファベット配列
constexpr kusef Lall = 0b0101010101010101010101010101010101010101010101010101;//全大文字
constexpr kusef sall = 0b1010101010101010101010101010101010101010101010101010;//全小文字
typedef struct {//main関数ではこれ一個でほぼ事足りる素晴らしき構造体「bigstruct」
	//inputで確定する変数
	int n;//入力の個数
	kusef ablf = 0;//文字が使用可能かのフラグ 大文字、小文字の揃わない文字は利用不可
	int abln = 0;//入力された作物の中で利用可能なものの数
	bool abls[nmax];//作物が利用可能であるかのフラグ
	//計算で用いる変数
	kusef crops[mmax];//作物リスト
	int m = 0;//現在の交配回数
	//出力用変数
	int yn;//YESかNOか
	struct { int x, y; kusef S; } macount[mmax];//xとyを交配しcが出来る過程を記録
}bigstruct;
//プログラマ向け関数宣言
inline bigstruct* input(bigstruct*);//入力用関数
inline bigstruct* output(bigstruct*);//出力用関数
inline bigstruct* marry(bigstruct*,int x, int y,bool ifrem);//交配用関数 x番目とy番目を交配、ifremは消せるクセを残すか否か
inline kusef krev(kusef);//大文字小文字を反転させる

//プログラマは使わない内部宣言
typedef struct { int x, y; char S[52]; }cross;//datatype for outputting
inline void opd(int yn, int m, cross *c);//direct output function
time_t get_elapsed_time(void(*func()));//not used


//--------------------------------------------------------------------
//　以下関数定義
//--------------------------------------------------------------------
inline bigstruct* input(bigstruct* b)
{
	char S[ABnum + 1];//文字列格納用一時変数
	scanf("%d", &(b->n));
	b->abln = b->n;
	for (int i = 0; i < b->n; i++) {//入力取得ループ
		scanf("%s", S);
		b->crops[i] = 0;
		for (int j = 0, k = 0; S[k] != '\0'; j++) {//文字列からkusefへの変換
			if (S[k] == AB[j]) {
				b->crops[i] |= ((kusef)1) << j;
				k++;
			}
		}
		b->abls[i] = true;//ループついでの初期化
		b->ablf |= b->crops[i];//ablfに現在使用されている文字を全て格納
	}
	
	//printf("/First");
	//showkasb(b->ablf);
	for (int i=1; i!=0;) {//i、即ち使用不可文字の検出がゼロなら終了
		i = 0;
		b->ablf &= krev(b->ablf);//大小文字の揃っていないクセを除去
		//printf("/Start");
		//showkasb(b->ablf);
		for (int j = 0; j < b->n; j++) {//使用不可文字の検出
			if (b->abls[j]) {
				if ((b->crops[j])&(~b->ablf)) {
					b->abls[j] = false;
					b->abln--;
					i++;
					//printf("/count %d\n",i);
				}
			}
		}
		b->ablf = 0;
		for (int j = 0; j < b->n; j++) {//ablfを更新
			if (b->abls[j])b->ablf |= b->crops[j];
		}
		//printf("/Finis");
		//showkasb(b->ablf);
	}
	return b;
}

inline bigstruct * output(bigstruct *b)
{
	cross c[mmax];
	for (int i = 0; i < b->m; i++) {
		c[i].x = b->macount[i].x;
		c[i].y = b->macount[i].y;
		int j = 0;
		if (b->macount[i].S == 0)c[i].S[j++] = '!';
		else {
			for (int k = 0; k < ABnum; k++) {
				c[i].S[j] = AB[k];
				j += (b->macount[i].S >> k) & 1;
			}
		}
		c[i].S[j] = '\0';
	}
	opd(b->yn,b->m,c);
	return b;
}

inline bigstruct * marry(bigstruct *b, int x, int y, bool ifrem)
{
	const kusef xf = b->crops[x];
	const kusef rxf = krev(xf);//大小逆転
	const kusef yf = b->crops[y];
	const kusef ryf = krev(yf);
	b->macount[b->m].x = x;
	b->macount[b->m].y = y;
	kusef &oup = b->macount[b->m].S;
	if (ifrem) {
		oup = xf | yf;
	}
	else {
		oup = (xf&~ryf) | (yf&~rxf);
	}
	b->crops[b->n + b->m] = oup;
	b->m++;
	return b;
}

inline kusef krev(kusef x)
{
	return (x << 1 & sall) | (x >> 1 & Lall);
}

inline void opd(int yn, int m, cross *c) {
	if (!yn) {
		printf("NO\n");
	}
	else {
		printf("YES\n%d\n", m);
		int i;
		for (i = 0; i < m; i++)
			printf("%d %d %s\n", c[i].x, c[i].y, c[i].S);
	}
	fflush(stdout);
}
time_t get_elapsed_time(void(*func())) {
	return (time_t)0;
}
#endif