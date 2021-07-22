//MYTIME.h
#ifndef __MYTIME_H
#define __MYTIME_H
//这是用于求时间差的操作 
//由于赶工繁忙，可能有些许bug，对此本人深感抱歉。如有建设性建议，可通过QQ：1345578933联系（麻治昊，20210510于中国科学技术大学） 
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
//函数内容 
timeval TimeDistance(timeval timeBefore,timeval timeAfter){
	//计算时间差并以原格式返回 
	timeval timeDistance;
	int numBefore,numAfter,numDistance; 
	numBefore=timeBefore.tv_sec*1000000+timeBefore.tv_usec;
	numAfter=timeAfter.tv_sec*1000000+timeAfter.tv_usec;
	numDistance=numAfter-numBefore;
	timeDistance.tv_sec=numDistance/1000000;
	timeDistance.tv_usec=numDistance%1000000;
	return(timeDistance);
}
#endif
