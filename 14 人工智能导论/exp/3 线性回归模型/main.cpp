//main.cpp
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"BMP.h"
#include"PROCESS.h"
//��������
#define NOISER 0.9
#define NOISEG 0.9
#define NOISEB 0.9
//���������ļ��������ļ�·��
#define NOISEFILE "C:\\Users\\ASUS\\Desktop\\noise.bmp"
#define REMAKEFILE "C:\\Users\\ASUS\\Desktop\\remake.bmp"
//�����ά��˹�ֲ���Χ
#define RNGX 2 
#define RNGY 2 
main(){
	//��ɫ���ֽ�����ͼƬ��������ѭ����ǩ���������� 
	int n,pics,flag;
	//ԭ��ɫ�ֽڣ���ɫ�ֽڸ��ģ���ͨ�� 
	char *array0,*array,*arrayr0,*arrayr,*arrayg0,*arrayg,*arrayb0,*arrayb;
	double err;
	FILE *fin,*fnoise,*fremake;
	//BMP 
	BmpHeader bh;
	BmpInfo bi;
	BmpColor *bc;
	
	//��ʼ�� 
	srand(rand()*time(NULL));
	fin=fopen("graph.bmp","rb");
	if(fin==NULL){
		printf("ԭͼ��ȡʧ��\n");
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
	
	//���� 
	//�������� 
	process(array,pics,NOISER,NOISEG,NOISEB);
	fwrite(array,sizeof(char),pics,fnoise);
	//����������� 
	err=mistake(array,array0,pics);
	printf("�����Ƚ�ֵ��%lf\n",err);
	//ͼƬ���� 
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
	//����������� 
	err=mistake(array,array0,pics);
	printf("�ָ���Ƚ�ֵ��%lf\n",err);
	free(array0);
	free(array);
	free(arrayr0);
	free(arrayr);
	free(arrayg0);
	free(arrayg);
	free(arrayb0);
	free(arrayb);
} 
