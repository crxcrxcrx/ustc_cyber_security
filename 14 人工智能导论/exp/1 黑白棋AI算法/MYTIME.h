//MYTIME.h
#ifndef __MYTIME_H
#define __MYTIME_H
//����������ʱ���Ĳ��� 
//���ڸϹ���æ��������Щ��bug���Դ˱�����б�Ǹ�����н����Խ��飬��ͨ��QQ��1345578933��ϵ������껣�20210510���й���ѧ������ѧ�� 
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
//�������� 
timeval TimeDistance(timeval timeBefore,timeval timeAfter){
	//����ʱ����ԭ��ʽ���� 
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
