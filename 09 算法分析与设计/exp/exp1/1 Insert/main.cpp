//�㷨���Թ��ߣ���ʵ����Ҫʱ�����1ms��ʱ�򣬲��Լ�¼ʱ�����ʵ����˶���С�����ݣ�������ͳ��ʱ�� 
#include<stdio.h>
#include<iostream>
#include<sys/time.h>
#include"SORT.h"
#include"RNDF.h"
//�����ģ��С 
#define ARRSIZE 50000
//��ӡ����������ע��Ҫ��ARRSIZEС 
#define PRINT 100
using namespace std;
main(){
	//��������������ʱ�䣬��ʼ��������������飬�����ļ���ʱ���ļ���multi�����鳤�ȼӱ���round��ѭ������ 
	timeval timeDistance;
	int *arrInit,*arr;
	FILE *fp,*ft;
	int flag,multi,round; 
	
	//��ʼ�� 
	arrInit=(int *)malloc(ARRSIZE*10*sizeof(int));
	arr=(int *)malloc(ARRSIZE*10*sizeof(int));
	fp=fopen("array.dat","wb+");
	if(fp==NULL){
		return(1);
	}
	ft=fopen("InsertTime.csv","w");
	if(ft==NULL){
		return(1);
	}
	
	//��ʼִ�� 
	for(multi=1;multi<=10;multi++){
		for(round=0;round<10;round++){
			//��ʼ���ļ� 
			fseek(fp,0,SEEK_SET);
			RndFile(fp,sizeof(int),ARRSIZE*multi);
			fseek(fp,0,SEEK_SET);
			ReadFile(fp,(char *)arrInit,sizeof(int),ARRSIZE*multi);
		
			//���� 
			for(flag=0;flag<ARRSIZE*multi;flag++){
				arr[flag]=arrInit[flag];
			}
			timeDistance=ProcTime(InsertSort,arr,0,ARRSIZE*multi);
			fprintf(ft,"%d,%d\n",timeDistance.tv_sec,timeDistance.tv_usec);
		}
	}
	
	
	//�ƺ��� 
	fseek(fp,0,SEEK_SET);
	WriteFile(fp,(char *)arr,sizeof(int),ARRSIZE);
	free(arrInit);
	free(arr);
	fclose(fp);
	fclose(ft);
}
