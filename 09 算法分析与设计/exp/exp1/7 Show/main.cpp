//算法测试工具，相同数组不同算法，当实际需要时间大于1ms的时候，测试记录时间较真实，因此对于小量数据，不适宜统计时间 
#include<stdio.h>
#include<iostream>
#include<sys/time.h>
#include"SORT.h"
#include"RNDF.h"
//数组规模大小 
#define ARRSIZE 500000
//打印数组数量，注意要比ARRSIZE小 
#define PRINT 100
using namespace std;
main(){
	//变量声明，三个时间，初始数组和排序用数组，数组文件，时间文件，multi是数组长度加倍，round是循环轮数 
	timeval timeDistance;
	int *arrInit,*arr;
	FILE *fp;
	int flag; 
	
	//初始化 
	arrInit=(int *)malloc(ARRSIZE*sizeof(int));
	arr=(int *)malloc(ARRSIZE*sizeof(int));
	fp=fopen("array.dat","wb+");
	if(fp==NULL){
		return(1);
	}
	
	//开始执行 
	printf("Array Size %d\n\n",ARRSIZE);
	fseek(fp,0,SEEK_SET);
	RndFile(fp,sizeof(int),ARRSIZE);
	fseek(fp,0,SEEK_SET);
	ReadFile(fp,(char *)arrInit,sizeof(int),ARRSIZE);

	//选择排序算法 
	for(flag=0;flag<ARRSIZE;flag++){
		arr[flag]=arrInit[flag];
	}
	printf("Insert\n");
	ProcTime(InsertSort,arr,0,ARRSIZE);
	TraverseArray(arr,0,PRINT); 
	
	//善后工作 
	fseek(fp,0,SEEK_SET);
	WriteFile(fp,(char *)arr,sizeof(int),ARRSIZE);
	free(arrInit);
	free(arr);
	fclose(fp);
}
