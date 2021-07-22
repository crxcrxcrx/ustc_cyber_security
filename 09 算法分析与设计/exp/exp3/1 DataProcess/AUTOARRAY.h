#ifndef __AUTOARRAY_H
#define __AUTOARRAY_H
//�������ڶ�̬�������Ա�Ļ���������ʹ��ʱ���ֶ���LISTSIZE��LISTADDON��ListElemType���壬�������޸�TraverseList������
//���ڸϹ���æ��������Щ��bug���Դ˱�����б�Ǹ�����н����Խ��飬��ͨ��QQ��1345578933��ϵ������껣�20190917���й���ѧ������ѧ�� 
#include<stdio.h>
#include<stdlib.h>
//��̬������С���ȣ�ȱʡ50 
#define LISTSIZE 50
//��̬����ÿ��������Ԫ��������ȱʡ10 
#define LISTADDON 10 
//��̬�������Ա��������ͣ�ȱʡint 
typedef int ListElemType; 
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
int ClearList(List *&l){
	//����̬����l�ÿգ��ɹ�����0��data�շ���1 
	l->length=0;
	if(l->size>LISTSIZE){
		l->data=(ListElemType *)realloc(l->data,LISTSIZE*sizeof(ListElemType));
		if(l->data==NULL){
		    return(1);
	    }
		l->size=LISTSIZE;
	}
	return(0); 
}
int ListEmpty(List *&l){
	//�ж϶�̬����l�Ƿ�Ϊ�գ��Ƿ���1�����Ƿ���0 
	if(l->length==0){
		return(1);
	}
	else{
		return(0);
	}
}
int ListFull(List *&l){
	//�ж϶�̬����l�Ƿ�Ϊ�����Ƿ���1�����Ƿ���0 
	if(l->length==l->size){
		return(1);
	}
	else{
		return(0);
	}
}
int ListLength(List *&l){
	//���ض�̬����l���� 
	return(l->length);
}
int GetElem(List *&l,int i,ListElemType &e){
	//���ض�̬����l��i��Ԫ��,�ɹ���ֵ��ֵ��e���ڵ�ַ������0��ʧ�ܷ���1 
	if(i<1||i>l->length){
		return(1); 
	}
	e=l->data[i-1];
	return(0);
}
int LocateItem(List *&l,ListElemType e){
	//���ض�̬�����һ��ֵΪe��Ԫ��λ�ã�û�з���0 
	int flag;
	for(flag=0;flag<l->length;flag++){
		if(l->data[flag]==e){
			return(flag+1);
		}
	} 
	return(0);
}
int PriorElem(List *&l,ListElemType e,ListElemType &pe){
	//���ض�̬�����һ��ֵΪe��Ԫ��ǰ�����ɹ�����ֵ��pe���ڵ�ַ������0��û�з���1 
	int flag;
	flag=LocateItem(l,e)-1;
	if(flag<1){
		return(1);
	}
	pe=l->data[flag-1];
	return(0);
}
int NextElem(List *&l,ListElemType e,ListElemType &ne){
	//���ض�̬�����һ��ֵΪe��Ԫ�غ�̣��ɹ�����ֵ��ne���ڵ�ַ������0��û�з���1 
	int flag;
	flag=LocateItem(l,e)-1;
	if(flag==l->length-1){
		return(1);
	}
	ne=l->data[flag+1];
	return(0);
}
int ListInsert(List *&l,int i,ListElemType e){
	//��l��iλ��ǰ����e����iΪ0�����ں󷽲��롣�ɹ�����0��i���Ϸ�����1���ڴ治�㷵��2 
	int flag;
	if(i<0||i>l->length){
		return(1);
	} 
	if(l->length==l->size){
		l->data=(ListElemType *)realloc(l->data,(l->size+LISTADDON)*sizeof(ListElemType));
		if(l->data==NULL){
			return(2);
		}
		l->size=l->size+LISTADDON;
	}
	if(i==0){
		l->data[l->length]=e;
		l->length++;
		return(0);
	}
	for(flag=l->length-1;flag>=i-1;flag--){
		l->data[flag+1]=l->data[flag];
	}
	l->data[i-1]=e;
	l->length++;
	return(0);
}
int ListDelete(List *&l,int i,ListElemType &e){
	//ɾ��l��iλ�õ�Ԫ�ز���ֵ��e���ɹ�����0��i���Ϸ�����1���ڴ治�㷵��2 
	int flag;
	if(i<1||i>l->length){
		return(1);
	}
	e=l->data[i-1];
	for(flag=i;flag<l->length;flag++){
		l->data[flag-1]=l->data[flag];
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
void TraverseList(List *&l){
	//����l����������ִ���Զ������ 
	int flag;
	for(flag=0;flag<l->length;flag++){
		//�Զ��������ȱʡ��ӡ 
		printf("%d\n",l->data[flag]); 
	}
	return;
}
#endif
