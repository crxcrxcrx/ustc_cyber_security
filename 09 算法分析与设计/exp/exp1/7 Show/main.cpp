//�㷨���Թ��ߣ���ͬ���鲻ͬ�㷨����ʵ����Ҫʱ�����1ms��ʱ�򣬲��Լ�¼ʱ�����ʵ����˶���С�����ݣ�������ͳ��ʱ�� 
#include<stdio.h>
#include<iostream>
#include<sys/time.h>
#include"SORT.h"
#include"RNDF.h"
//�����ģ��С 
#define ARRSIZE 500000
//��ӡ����������ע��Ҫ��ARRSIZEС 
#define PRINT 100
using namespace std;
main(){
	//��������������ʱ�䣬��ʼ��������������飬�����ļ���ʱ���ļ���multi�����鳤�ȼӱ���round��ѭ������ 
	timeval timeDistance;
	int *arrInit,*arr;
	FILE *fp;
	int flag; 
	
	//��ʼ�� 
	arrInit=(int *)malloc(ARRSIZE*sizeof(int));
	arr=(int *)malloc(ARRSIZE*sizeof(int));
	fp=fopen("array.dat","wb+");
	if(fp==NULL){
		return(1);
	}
	
	//��ʼִ�� 
	printf("Array Size %d\n\n",ARRSIZE);
	fseek(fp,0,SEEK_SET);
	RndFile(fp,sizeof(int),ARRSIZE);
	fseek(fp,0,SEEK_SET);
	ReadFile(fp,(char *)arrInit,sizeof(int),ARRSIZE);

	//ѡ�������㷨 
	for(flag=0;flag<ARRSIZE;flag++){
		arr[flag]=arrInit[flag];
	}
	printf("Insert\n");
	ProcTime(InsertSort,arr,0,ARRSIZE);
	TraverseArray(arr,0,PRINT); 
	
	//�ƺ��� 
	fseek(fp,0,SEEK_SET);
	WriteFile(fp,(char *)arr,sizeof(int),ARRSIZE);
	free(arrInit);
	free(arr);
	fclose(fp);
}
