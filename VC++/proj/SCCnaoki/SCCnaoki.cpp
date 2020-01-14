#pragma warning(disable:4996)
#include <stdio.h>

int judge(char);//引数のアルファベット判定
void add(char *, char *,char *);
int next(int,int, bool *);//次の採用されている種を見つける　エラーは-1

int main() {
	char s[53] = {};//add関数用

	int n;
	char a[2000][26 * 2 + 1];
	char b[2000][26 * 2 + 1];//新種
	bool a2[2001] = {};//採用しない=true
	int alp[26 * 2] = {};//alp[0]='a',alp[1]='A',…
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &a[i]);
	}
	
	while (1) {
		//選別(どのアルファベットがどのくらいあるかをみる)
		for (int i = 0; i < n; i++) {
			if (a2[i] == false) {//まだ採用されている
				for (int j = 0; j < 52; j++) {
					if (a[i][j] == '\0') break;
					alp[judge(a[i][j])]++;
				}
			}
		}

		bool update = true;//false=更新あり、true=無し
		//選別(足してはいけないものを除外する)
		for (int i = 0; i < n; i++) {
			bool tmp[2000] = {};
			if (a2[i] == false) {//まだ駄目でない時
				bool Judge = false;//true=だめ、false=いいだろう
				for (int j = 0; j < 52; j++) {
					if (a[i][j] == '\0') break;
					if (judge(a[i][j]) % 2) {//大文字の場合
						if (alp[judge(a[i][j] - 1)] == 0) {//対のものが0
							Judge = true;
						}
					}
					else {//小文字の場合
						if (alp[judge(a[i][j] + 1)] == 0) {//対のものが0
							Judge = true;
						}
					}
				}
				if (Judge) {//ダメでした
					a2[i] = true;
					update = false;
				}
			}
		}

		if (update) {//更新がないとき発動
			break;
		}
	}
	
	//答えの出力
	bool tmp = false;
	for (int i = 0; i < n; i++) {
		if (a2[i] == false) {
			tmp = true;
		}
	}
	if (tmp) printf("NO\n");
	else printf("YES\n");

	int counter = 0;
	for (int i = 0; i < n; i++) {
		if (a2[i] == false) {
			counter++;
		}
	}
	printf("%d\n", counter);


	//具体的な勾配方法
	counter = 0;//残っている種の数
	for (int i = 0; i < n; i++) {
		if (a2[i] == false) counter++;
	}

	int seed1;
	int seed2;
	switch (counter) {
	case 2://二種のみ残されている場合
		seed1 = next(0, n, a2);
		seed2 = next(seed1, n, a2);
		printf("%d ", seed1 + 1);
		printf("%d ", seed2 + 1);
		add(a[seed1], a[seed2], b[0]);//掛け合わせる
		printf("%s\n", b[0]);

		printf("%d ", n + 1);
		printf("%d ", n + 1);
		printf("!\n");
		break;

	default:
		seed1 = next(0, n, a2);
		seed2 = next(seed1, n, a2);
		printf("%d ", seed1 + 1);
		printf("%d ", seed2 + 1);
		add(a[seed1], a[seed2], b[0]);//掛け合わせる
		printf("%s\n", b[0]);

		int i = 1;//b[]を指すインデクス
		int seed = seed2;
		while (next(seed, n, a2) != -1) {
			printf("%d ", seed + 1);
			printf("%d ", n + i);
			add(a[seed], b[i - 1], b[i]);//掛け合わせる
			printf("%s\n", b[i]);
			i++;
		}
		printf("%d ", n + i);
		printf("%d ", n + i);
		printf("!\n");
		break;
	}
	while (1);
}


int judge(char c) {
	int n = 0;
	if (c < 'a') {//cは大文字
		n = c - 'A';//A=0,B=1…Z=25
		return n * 2 + 1;
	}
	else {//cは小文字
		n = c - 'a';//a=0,b=1…z=25
		return n * 2;
	}
}

void add(char *a, char *b,char *s) {//a,bを掛け合わせてsを作る
	int counter = 0;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 52; j++) {//小文字
			if ((a[i] == 97 + i)|| (b[i] == 97 + i)) {
				if (s[counter] == 0) {
					s[counter] = 97 + i;
					counter++;
				}
			}
		}
		for (int j = 0; j < 52; j++) {//大文字
			if ((a[i] == 65 + i)|| (b[i] == 65 + i)) {
				if (s[counter] == 0) {
					s[counter] = 65 + i;
					counter++;
				}
			}
		}
	}
	s[counter] = '\n';
}

int next(int i,int max ,bool* a) {//次がない場合 -1
	for (int j = i; j < max; j++) {
		if (a[j] == false) {
			return j;
		}
	}
	return -1;
}