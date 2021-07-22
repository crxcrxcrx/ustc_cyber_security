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
//这是用于回归分析处理图像的基本操作。 
//由于赶工繁忙，可能有些许bug，对此本人深感抱歉。如有建设性建议，可通过QQ：1345578933联系（麻治昊，20210610于中国科学技术大学）
int process(char *arr,int arrsize,double pr,double pg,double pb){
	//对24真彩图的颜色进行失真模拟 
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
	//重塑像素点 
	//两个sigma，输出像素值，分母 
	double sigmax,sigmay,out,deno,tmp; 
	int flagx,flagy;
	//初始化 
	tmp=0;
	deno=0;
	out=0;
	sigmax=rangex/3.0;
	sigmay=rangey/3.0;
	//操作 
	if(in0[x*width+y]!=0){
		//不变 
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
	//对图有效像素点加权平均，左右rangex上下rangey内生成gauss分布，遵从3sigma原则 
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
