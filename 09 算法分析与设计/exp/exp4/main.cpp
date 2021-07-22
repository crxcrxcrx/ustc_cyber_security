#include<stdio.h>
#include<stdlib.h>
#include"BAGGING.h" 
//文件名
#define FILENAME "testdata/20test.txt"
int ScanData(FILE *f,Bag &b){
	//把文件的数据读到b中
	int flag;
	fscanf(f,"%d",&b.number);
	fscanf(f,"%d",&b.capacity);
	b.weight=(int *)malloc(b.number*sizeof(int));
	b.value=(int *)malloc(b.number*sizeof(int));
	for(flag=0;flag<b.number;flag++){
		fscanf(f,"%d",&b.weight[flag]);
	}
	for(flag=0;flag<b.number;flag++){
		fscanf(f,"%d",&b.value[flag]);
	}
	return(0);
}
int TraverseData(Bag b){
	int flag;
	printf("number: %d\n",b.number);
	printf("capacity: %d\n",b.capacity);
	for(flag=0;flag<b.number;flag++){
		printf("%d ",b.weight[flag]);
	}
	printf("\n");
	for(flag=0;flag<b.number;flag++){
		printf("%d ",b.value[flag]);
	}
	printf("\n");
}
main(){
	//变量声明 
	FILE *fp;
	Bag bag;
	int err,sta,flag;
	
	//初始化数据 
	fp=fopen(FILENAME,"r");
	ScanData(fp,bag);
	TraverseData(bag);
	
	//开始处理
	//穷举 
	printf("\n\n穷举算法\n"); 
	err=Exhausting(bag,sta); 
	TraverseResult(bag.number,err,sta);
	//备忘录 
	printf("\n\n备忘录算法\n"); 
	err=Memorial(bag,sta); 
	TraverseResult(bag.number,err,sta);
	//动态规划 
	printf("\n\n动态规划算法\n"); 
	err=Dynamic(bag,sta); 
	TraverseResult(bag.number,err,sta);
	//回溯 
	printf("\n\n回溯算法\n"); 
	err=Backtrack(bag,sta); 
	TraverseResult(bag.number,err,sta);
	//分支限界 
	printf("\n\n分支限界算法\n"); 
	err=Broad(bag,sta); 
	TraverseResult(bag.number,err,sta);
	//蒙特卡洛 
	printf("\n\n蒙特卡洛算法\n"); 
	err=Broad(bag,sta); 
	TraverseResult(bag.number,err,sta);
	 
	//善后工作 
	free(bag.weight);
	free(bag.value);
}
