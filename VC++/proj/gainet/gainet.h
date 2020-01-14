//gainet.h
//all-in-one header for main source
#ifndef GAINET_DEFINED
#define GAINET_DEFINED
#include <malloc.h>
#include "gaiIO.h"
#include "gaicui.h"

typedef struct{
	char Sub[WORDMAX];
	char Rel[WORDMAX];
	char Ob[WORDMAX];
} gword;
#endif //GAINET_DEFINED