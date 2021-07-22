#ifndef __AUTOARRAY_H
#define __AUTOARRAY_H
//这是用于动态数组线性表的基本操作
//由于赶工繁忙，可能有些许bug，对此本人深感抱歉。如有建设性建议，可通过QQ：1345578933联系（麻治昊，20210508于中国科学技术大学） 
#include<stdio.h>
#include<stdlib.h>
#include"STRINGHEAP.h"
//动态数组最小长度，缺省50 
#define LISTSIZE 100100
//动态数组每次申请新元素增量，缺省10 
#define LISTADDON 10 
//动态数组线性表数据类型，缺省int 
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
//函数内容 
int InitList(List *&l){
	//初始化动态数组l，l的默认长度是LISTSIZE，可以增删。成功返回0，l空返回1，data空返回2 
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
	//销毁动态数组l 
	free(l->data); 
	free(l);
	l=NULL;
	return;
}
int ListInsert(List *&l,ListElemType e){
	//在l中按序插入e。成功返回0，i不合法返回1，内存不足返回2 
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
	//删除l中index位置的元素并保持有序。成功返回0，表中无元素返回1，内存不足返回2 
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
	//查找l中index位置的元素并保持有序。成功返回0，表中无元素返回1
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
