#ifndef __RNDF_H
#define __RNDF_H
//这是用于随机生成文件的基本操作。 
//由于赶工繁忙，可能有些许bug，对此本人深感抱歉。如有建设性建议，可通过QQ：1345578933联系（麻治昊，20210419于中国科学技术大学） 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//函数内容 
int RndFile(FILE *fp,int bar,int num){
	//生成num个bar字节的随机文件写入fp中，成功返回0，失败返回1 
	int flag1,flag2,ran;
	if(fp==NULL){
		return(1);
	}
	srand(rand()*time(NULL));
	for(flag1=0;flag1<num;flag1++){
		for(flag2=0;flag2<bar;flag2++){
			ran=(char)rand();
			fwrite(&ran,sizeof(char),1,fp);
		}
	}
	return(0);
}
int ReadFile(FILE *fp,char *arr,int bar,int num){
	//把fp内num个bar字节的数据存入arr 
	int flag;
	if(fp==NULL){
		return(1);
	}
	fread(arr,bar,num,fp);
	return(0);
}
int WriteFile(FILE *fp,char *arr,int bar,int num){
	//把arr内num个bar字节的数据写入fp 
	int flag;
	if(fp==NULL){
		return(1);
	}
	fwrite(arr,bar,num,fp);
	return(0);
}
#endif 
