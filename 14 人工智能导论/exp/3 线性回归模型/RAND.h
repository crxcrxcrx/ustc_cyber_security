//RAND.h
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#ifndef __RAND_H
#define __RAND_H
//这是用于回归分析处理图像的基本操作。 
//由于赶工繁忙，可能有些许bug，对此本人深感抱歉。如有建设性建议，可通过QQ：1345578933联系（麻治昊，20210609于中国科学技术大学）
int rand0p(double p){
	//以p概率生成0的01分布，出错返回-1 
	int i;
	if(p>1||p<0){
		return(-1);
	}
	i=rand();
	if((double)i/RAND_MAX<p){
		return(0);
	} 
	else{
		return(1);
	}
}
#endif
