//gaicui
//defines CUI behavior
#pragma once
#ifndef GAICUI
#define GAICUI

#include "gaigen.h"

typedef struct{//User Responce
	
} UserResp;
typedef struct{//Machine Responce
	
} MachResp;

int GaiMachInit(UserResp* outp){//Machine Initialization
	return 0;
}

int GaiW84UserResp(const MachResp& inp, UserResp* outp){//Wait For User Responce
	return 0;
}

int GaiW84MachResp(const UserResp& inp, MachResp* outp){//Wait For Machine Responce
	return 0;
}

#endif