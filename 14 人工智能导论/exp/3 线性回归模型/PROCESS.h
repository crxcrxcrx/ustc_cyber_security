//PROCESS.h
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"BMP.h"
#include"RAND.h"
#ifndef __PROCESS_H
#define __PROCESS_H
#define PI 3.1415926535897
//�������ڻع��������ͼ��Ļ��������� 
//���ڸϹ���æ��������Щ��bug���Դ˱�����б�Ǹ�����н����Խ��飬��ͨ��QQ��1345578933��ϵ������껣�20210610���й���ѧ������ѧ��
int process(char *arr,int arrsize,double pr,double pg,double pb){
	//��24���ͼ����ɫ����ʧ��ģ�� 
	int flag,p;
	for(flag=0;flag<arrsize;flag++){
		if(flag%3==RED){
			p=rand0p(pr);
			if(p==0){
				arr[flag]=0;
			}
		}
		if(flag%3==GREEN){
			p=rand0p(pg);
			if(p==0){
				arr[flag]=0;
			}
		}
		if(flag%3==BLUE){
			p=rand0p(pb);
			if(p==0){
				arr[flag]=0;
			}
		}
	}
	return(0);
}
char repixel(char *in0,int x,int y,int rangex,int rangey,int width,int height){
	//�������ص� 
	//����sigma���������ֵ����ĸ 
	double sigmax,sigmay,out,deno,tmp; 
	int flagx,flagy;
	//��ʼ�� 
	tmp=0;
	deno=0;
	out=0;
	sigmax=rangex/3.0;
	sigmay=rangey/3.0;
	//���� 
	if(in0[x*width+y]!=0){
		//���� 
		return(in0[x*width+y]);
	}
	for(flagx=x-rangex;flagx<=x+rangex;flagx++){
		for(flagy=y-rangey;flagy<=y+rangey;flagy++){
			if(flagx>=0&&flagx<height&&flagy>=0&&flagy<width){
				if(in0[flagx*width+flagy]!=0){
					tmp=pow(2*PI*sigmax*sigmay,-1)*exp(-0.5*(pow(flagx-x,2)/pow(sigmax,2)+pow(flagy-y,2)/pow(sigmay,2)));
					deno+=tmp;
					out+=tmp*in0[flagx*width+flagy];
				}
			}
		}
	}
	return((char)(out/deno+0.5));
}
int remake(char *arrayr0,char *arrayr,char *arrayg0,char *arrayg,char *arrayb0,char *arrayb,int rangex,int rangey,int width,int height){
	//��ͼ��Ч���ص��Ȩƽ��������rangex����rangey������gauss�ֲ������3sigmaԭ�� 
	int flag1,flag2;
	for(flag1=0;flag1<height;flag1++){
		for(flag2=0;flag2<width;flag2++){
			arrayr[flag1*width+flag2]=repixel(arrayr0,flag1,flag2,rangex,rangey,width,height);
			arrayg[flag1*width+flag2]=repixel(arrayg0,flag1,flag2,rangex,rangey,width,height);
			arrayb[flag1*width+flag2]=repixel(arrayb0,flag1,flag2,rangex,rangey,width,height);
		}
	}
	return(0);
}
double mistake(char *arr0,char *arr1,int arrsize){
	int flag;
	double err;
	err=0;
	for(flag=0;flag<arrsize;flag++){
		err+=pow(((int)arr0[flag]-(int)arr1[flag]),2)/pow(256,2);
	}
	return err;
} 
#endif
