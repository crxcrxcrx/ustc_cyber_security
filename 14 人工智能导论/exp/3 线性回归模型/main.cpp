//main.cpp
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"BMP.h"
#include"PROCESS.h"
//定义噪音
#define NOISER 0.9
#define NOISEG 0.9
#define NOISEB 0.9
//定义噪音文件和重做文件路径
#define NOISEFILE "C:\\Users\\ASUS\\Desktop\\noise.bmp"
#define REMAKEFILE "C:\\Users\\ASUS\\Desktop\\remake.bmp"
//定义二维高斯分部范围
#define RNGX 2 
#define RNGY 2 
main(){
	//调色板字节数，图片像素数，循环标签，像素数组 
	int n,pics,flag;
	//原颜色字节，颜色字节更改，三通道 
	char *array0,*array,*arrayr0,*arrayr,*arrayg0,*arrayg,*arrayb0,*arrayb;
	double err;
	FILE *fin,*fnoise,*fremake;
	//BMP 
	BmpHeader bh;
	BmpInfo bi;
	BmpColor *bc;
	
	//初始化 
	srand(rand()*time(NULL));
	fin=fopen("graph.bmp","rb");
	if(fin==NULL){
		printf("原图读取失败\n");
		return(1);
	}
	fnoise=fopen(NOISEFILE,"wb");
	fremake=fopen(REMAKEFILE,"wb");
	array=NULL;
	bc=NULL;
	n=FileReadBmp(fin,bh,bi,bc);
	FileWriteBmp(fnoise,bh,bi,bc,n);
	FileWriteBmp(fremake,bh,bi,bc,n);
	PrintBmpInfo(bh,bi,bc,n);
	fseek(fin,n+14+40,SEEK_SET);
	fseek(fnoise,0,SEEK_END);
	fseek(fremake,0,SEEK_END);
	pics=bi.picsize;
	array0=(char *)malloc(sizeof(char)*pics);
	array=(char *)malloc(sizeof(char)*pics);
	arrayr0=(char *)malloc(sizeof(char)*bi.width*bi.height);
	arrayr=(char *)malloc(sizeof(char)*bi.width*bi.height);
	arrayg0=(char *)malloc(sizeof(char)*bi.width*bi.height);
	arrayg=(char *)malloc(sizeof(char)*bi.width*bi.height);
	arrayb0=(char *)malloc(sizeof(char)*bi.width*bi.height);
	arrayb=(char *)malloc(sizeof(char)*bi.width*bi.height);
	fread(array0,sizeof(char),pics,fin);
	fseek(fin,n+14+40,SEEK_SET);
	fread(array,sizeof(char),pics,fin);
	
	//操作 
	//生成噪音 
	process(array,pics,NOISER,NOISEG,NOISEB);
	fwrite(array,sizeof(char),pics,fnoise);
	//计算噪音误差 
	err=mistake(array,array0,pics);
	printf("噪声比较值：%lf\n",err);
	//图片降噪 
	for(flag=0;flag<pics;flag++){
		if(flag%3==RED){
			arrayr0[flag/3]=array[flag];
			arrayr[flag/3]=array[flag];
		}
		if(flag%3==GREEN){
			arrayg0[flag/3]=array[flag];
			arrayg[flag/3]=array[flag];
		}
		if(flag%3==BLUE){
			arrayb0[flag/3]=array[flag];
			arrayb[flag/3]=array[flag];
		}
	}
	remake(arrayr0,arrayr,arrayg0,arrayg,arrayb0,arrayb,RNGX,RNGY,bi.width,bi.height);
	for(flag=0;flag<pics;flag++){
		if(flag%3==RED){
			array[flag]=arrayr[flag/3];
		}
		if(flag%3==GREEN){
			array[flag]=arrayg[flag/3];
		}
		if(flag%3==BLUE){
			array[flag]=arrayb[flag/3];
		}
	}
	fwrite(array,sizeof(char),pics,fremake);
	//计算重塑误差 
	err=mistake(array,array0,pics);
	printf("恢复后比较值：%lf\n",err);
	free(array0);
	free(array);
	free(arrayr0);
	free(arrayr);
	free(arrayg0);
	free(arrayg);
	free(arrayb0);
	free(arrayb);
} 
