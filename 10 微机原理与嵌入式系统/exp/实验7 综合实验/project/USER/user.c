#include "user.h"
#include "sys.h"
#include "dip.h"

extern int pswd;
extern int pswd_stat;

u8 CheckPswd(void){
	//check password, right return 1, or return 0
	u8 tmp=pswd;
	if(tmp%2==DIP7){
		tmp>>=1;
		if(tmp%2==DIP6){
			tmp>>=1;
			if(tmp%2==DIP5){
				tmp>>=1;
				if(tmp%2==DIP4){
					tmp>>=1;
					if(tmp%2==DIP3){
						tmp>>=1;
						if(tmp%2==DIP2){
							tmp>>=1;
							if(tmp%2==DIP1){
								tmp>>=1;
								if(tmp%2==DIP0){
									return(1);
								}
							}
						}
					}
				}
			}
		}
	}
	return(0);
}

u8 ScanPswd(void){
	return((DIP0<<7)+(DIP1<<6)+(DIP2<<5)+(DIP3<<4)+(DIP4<<3)+(DIP5<<2)+(DIP6<<1)+(DIP7<<0));
}
