//RAND.h
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#ifndef __RAND_H
#define __RAND_H
//�������ڻع��������ͼ��Ļ��������� 
//���ڸϹ���æ��������Щ��bug���Դ˱�����б�Ǹ�����н����Խ��飬��ͨ��QQ��1345578933��ϵ������껣�20210609���й���ѧ������ѧ��
int rand0p(double p){
	//��p��������0��01�ֲ���������-1 
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
