//算法测试工具，当实际需要时间大于1ms的时候，测试记录时间较真实，因此对于小量数据，不适宜统计时间 
#include<stdio.h>
#include<iostream>
#include<sys/time.h>
#include"SORT.h"
#include"RNDF.h"
//数组规模大小 
#define ARRSIZE 50000
//打印数组数量，注意要比ARRSIZE小 
#define PRINT 100
using namespace std;
main(){
	//变量声明，三个时间，初始数组和排序用数组，数组文件，时间文件，multi是数组长度加倍，round是循环轮数 
	timeval timeDistance;
	int *arrInit,*arr;
	FILE *fp,*ft;
	int flag,multi,round; 
	
	//初始化 
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
	
	//开始执行 
	for(multi=1;multi<=10;multi++){
		for(round=0;round<10;round++){
			//初始化文件 
			fseek(fp,0,SEEK_SET);
			RndFile(fp,sizeof(int),ARRSIZE*multi);
			fseek(fp,0,SEEK_SET);
			ReadFile(fp,(char *)arrInit,sizeof(int),ARRSIZE*multi);
		
			//排序 
			for(flag=0;flag<ARRSIZE*multi;flag++){
				arr[flag]=arrInit[flag];
			}
			timeDistance=ProcTime(InsertSort,arr,0,ARRSIZE*multi);
			fprintf(ft,"%d,%d\n",timeDistance.tv_sec,timeDistance.tv_usec);
		}
	}
	
	
	//善后工作 
	fseek(fp,0,SEEK_SET);
	WriteFile(fp,(char *)arr,sizeof(int),ARRSIZE);
	free(arrInit);
	free(arr);
	fclose(fp);
	fclose(ft);
}
