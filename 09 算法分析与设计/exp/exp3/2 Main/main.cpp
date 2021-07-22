#include<stdio.h>
#include<stdlib.h>
#include"STOCK.h"
//数据文件来源
#define FILENAME "data6.bin" 
//手续费
#define FEE 6806 
main(){
	//变量声明 
	FILE *fp;
	int size,tmp,flag1,flag2,*a,profit,fee;
	fee=FEE;
	
	//初始化数据 
	fp=fopen(FILENAME,"rb");
	fseek(fp,0,SEEK_END);
	size=ftell(fp)/sizeof(int);
	printf("array size: %d\n",size);
	fseek(fp,0,SEEK_SET);
	a=(int *)malloc(sizeof(int)*size);
	fread(a,size,sizeof(int),fp);
	
	//开始执行 
//	profit=Profit1(a,size,fee);
//	printf("Dynamic Programming o(n^2) %d\n",profit);
	profit=Profit2(a,size,fee);
	printf("Dynamic Programming o(n) %d\n",profit);
	profit=Profit3(a,size,fee);
	printf("Greedy o(n) %d\n",profit);
	
	//善后工作
	free(a);
	fclose(fp); 
}
