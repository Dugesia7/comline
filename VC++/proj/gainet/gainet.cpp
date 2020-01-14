//---------------------------------------------
// Before u start to edit this program,
// plz open gaidata.gnd
// with a textediter.
//---------------------------------------------
#include "gainet.h"
int main(){
	UserResp ur;
	MachResp mr;
	gaiready(&ur,"GaiNetNail.gnn");
	int Error;
	for(;;){
		if((Error=GaiW84UserResp(mr,&ur))!=0)break;
		if((Error=GaiW84MachResp(ur,&mr))!=0)break;
	}
	return Error;
}