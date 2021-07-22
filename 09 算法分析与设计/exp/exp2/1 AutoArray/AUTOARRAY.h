#ifndef __AUTOARRAY_H
#define __AUTOARRAY_H
//�������ڶ�̬�������Ա�Ļ�������
//���ڸϹ���æ��������Щ��bug���Դ˱�����б�Ǹ�����н����Խ��飬��ͨ��QQ��1345578933��ϵ������껣�20210508���й���ѧ������ѧ�� 
#include<stdio.h>
#include<stdlib.h>
#include"STRINGHEAP.h"
//��̬������С���ȣ�ȱʡ50 
#define LISTSIZE 100100
//��̬����ÿ��������Ԫ��������ȱʡ10 
#define LISTADDON 10 
//��̬�������Ա��������ͣ�ȱʡint 
struct Host{
	int index;
	String *s;
};
typedef Host ListElemType; 
struct List{
	ListElemType *data;
	int length;
	int size;
};
//�������� 
int InitList(List *&l){
	//��ʼ����̬����l��l��Ĭ�ϳ�����LISTSIZE��������ɾ���ɹ�����0��l�շ���1��data�շ���2 
	l=(List *)malloc(sizeof(List));
	if(l==NULL){
		return(1);
	}
	l->data=(ListElemType *)calloc(LISTSIZE,sizeof(ListElemType));
	if(l->data==NULL){
		return(2);
	}
	l->length=0;
	l->size=LISTSIZE;
	return(0);
}
void DestroyList(List *&l){
	//���ٶ�̬����l 
	free(l->data); 
	free(l);
	l=NULL;
	return;
}
int ListInsert(List *&l,ListElemType e){
	//��l�а������e���ɹ�����0��i���Ϸ�����1���ڴ治�㷵��2 
	int flag,left,right,mid;
	left=0;
	right=l->length;
	if(l->length==l->size){
		l->data=(ListElemType *)realloc(l->data,(l->size+LISTADDON)*sizeof(ListElemType));
		if(l->data==NULL){
			return(2);
		}
		l->size=l->size+LISTADDON;
	}
	while(left<right){
		mid=(left+right)/2;
		if(e.index>=l->data[mid].index){
			left=mid+1;
		}
		else{
			right=mid;
		}
	}
	for(flag=l->length-1;flag>=left;flag--){
		l->data[flag+1]=l->data[flag];
	}
	l->data[flag+1]=e;
	l->length++;
	return(0);
}
int ListDelete(List *&l,int index,ListElemType &e){
	//ɾ��l��indexλ�õ�Ԫ�ز��������򡣳ɹ�����0��������Ԫ�ط���1���ڴ治�㷵��2 
	int flag,have;
	ListElemType tmp;
	have=0;
	for(flag=0;flag<l->length;flag++){
		if(l->data[flag].index==index){
			have=1;
			break;
		}
	}
	if(have==0){
		return(1);
	}
	e=l->data[flag];
	for(;flag<l->length;flag++){
		l->data[flag]=l->data[flag+1];
	}
	l->length--;
	if(l->size-l->length>LISTADDON&&l->size>LISTSIZE){
		l->data=(ListElemType *)realloc(l->data,(l->size-LISTADDON)*sizeof(ListElemType));
		if(l->data==NULL){
			return(2);
		}
		l->size=l->size-LISTADDON;
	}
	return(0);
}
int ListFind(List *&l,int index,ListElemType &e){
	//����l��indexλ�õ�Ԫ�ز��������򡣳ɹ�����0��������Ԫ�ط���1
	int left,right,mid;
	left=0;
	right=l->length;
	while(left<=right){
		mid=(left+right)/2;
		if(index==l->data[mid].index){
			e=l->data[mid];
			return(0);
		}
		else if(index>l->data[mid].index){
			left=mid+1;
		}
		else if(index<l->data[mid].index){
			right=mid-1;
		}
	}
	return(1);
}
#endif
