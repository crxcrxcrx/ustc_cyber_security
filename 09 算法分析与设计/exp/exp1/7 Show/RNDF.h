#ifndef __RNDF_H
#define __RNDF_H
//����������������ļ��Ļ��������� 
//���ڸϹ���æ��������Щ��bug���Դ˱�����б�Ǹ�����н����Խ��飬��ͨ��QQ��1345578933��ϵ������껣�20210419���й���ѧ������ѧ�� 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//�������� 
int RndFile(FILE *fp,int bar,int num){
	//����num��bar�ֽڵ�����ļ�д��fp�У��ɹ�����0��ʧ�ܷ���1 
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
	//��fp��num��bar�ֽڵ����ݴ���arr 
	int flag;
	if(fp==NULL){
		return(1);
	}
	fread(arr,bar,num,fp);
	return(0);
}
int WriteFile(FILE *fp,char *arr,int bar,int num){
	//��arr��num��bar�ֽڵ�����д��fp 
	int flag;
	if(fp==NULL){
		return(1);
	}
	fwrite(arr,bar,num,fp);
	return(0);
}
#endif 
