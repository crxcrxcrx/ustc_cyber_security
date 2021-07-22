#ifndef __SINGLENODE_H
#define __SINGLENODE_H
//�������ڵ������Ա�Ļ�������
//���ڸϹ���æ��������Щ��bug���Դ˱�����б�Ǹ�����н����Խ��飬��ͨ��QQ��1345578933��ϵ������껣�20210508���й���ѧ������ѧ��  
#include<stdio.h> 
#include<stdlib.h> 
#include"STRINGHEAP.h"
//�������Ա��������ͣ�ȱʡint
struct Host{
	int index;
	String *s;
};  
typedef Host ListElemType;
struct ListNode{
	ListElemType data;
	ListNode *next;
};
struct List{
	int length;
	ListNode *p; 
};
//�������� 
int InitList(List *&l){
	//��ʼ��������l������һ���ս�㡣�ɹ�����0��l�շ���1�����շ���2  
	l=(List *)malloc(sizeof(List));
	if(l==NULL){
		return(1);
	}
	l->p=(ListNode *)malloc(sizeof(ListNode)); 
	if(l->p==NULL){
		return(2);
	}
	l->p->next=NULL; 
	l->length=0;
	return(0); 
}
void DestroyList(List *&l){
	//�����ٽ�㣬Ȼ������l��ʵ���������� 
	ListNode *flag,*res;
	flag=l->p;
	while(flag!=NULL){
		res=flag;
		flag=flag->next;
		free(res);
	}
	free(l);
	l=NULL;
	return;
}
int ListInsert(List *&l,int i,ListElemType e){
	//��l��iλ��ǰ����e����iΪ0�����ں󷽲��롣�ɹ�����0,i���Ϸ�����1��j�շ���2 
	//ͷ�巨i=1 
	int flag1;
	ListNode *flag2,*j,*a,*b;
	if(i<0||i>l->length){
		return(1);
	} 
	j=(ListNode *)malloc(sizeof(ListNode));
	if(j==NULL){
		return(2);
	}
	j->data=e;
	j->next=NULL;
	if(i==0){
		for(flag2=l->p;flag2->next!=NULL;flag2=flag2->next){
		}
		flag2->next=j;
		l->length++;
		return(0);
	}
	for(flag1=0,flag2=l->p;flag1<i-1;flag1++,flag2=flag2->next){
	}
	a=flag2;
	b=flag2->next;
	a->next=j;
	j->next=b;
	l->length++;
	return(0);
}
int ListDelete(List *&l,int index,ListElemType &e){
	//ɾ��l��indexλ�õ�Ԫ�ء��ɹ�����0��������Ԫ�ط���1
	int have;
	ListNode *flag,*j,*a,*b;
	have=0;
	for(flag=l->p;flag->next->next!=NULL;flag=flag->next){
		if(flag->next->data.index==index){
			have=1;
			break;
		}
	}
	if(flag->next->next==NULL){
		if(flag->data.index==index){
			have=1;
		}
		else if(flag->next->data.index==index){
			a=flag;
			j=flag->next;
			b=flag->next->next;
			a->next=b;
			e=j->data;
			free(j);
			l->length--; 
			return(0);
		}
	}
	if(have==0){
		return(1);
	}
	a=flag;
	j=flag->next;
	b=flag->next->next;
	a->next=b;
	e=j->data;
	free(j);
	l->length--; 
	return(0);
}
int ListFind(List *&l,int index,ListElemType &e){
	//����l��indexλ�õ�Ԫ�ز��������򡣳ɹ�����0��������Ԫ�ط���1
	ListNode *flag;
	for(flag=l->p;flag!=NULL;flag=flag->next){
		if(flag->data.index==index){
			e=flag->data;
			return(0);
		}
	}
	return(1);
}
#endif 
