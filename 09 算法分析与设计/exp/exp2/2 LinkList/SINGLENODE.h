#ifndef __SINGLENODE_H
#define __SINGLENODE_H
//这是用于单链线性表的基本操作
//由于赶工繁忙，可能有些许bug，对此本人深感抱歉。如有建设性建议，可通过QQ：1345578933联系（麻治昊，20210508于中国科学技术大学）  
#include<stdio.h> 
#include<stdlib.h> 
#include"STRINGHEAP.h"
//单链线性表数据类型，缺省int
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
//函数内容 
int InitList(List *&l){
	//初始化单链表l并创造一个空结点。成功返回0，l空返回1，结点空返回2  
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
	//先销毁结点，然后销毁l，实现销毁链表 
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
	//在l的i位置前插入e，若i为0，则在后方插入。成功返回0,i不合法返回1，j空返回2 
	//头插法i=1 
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
	//删除l中index位置的元素。成功返回0，表中无元素返回1
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
	//查找l中index位置的元素并保持有序。成功返回0，表中无元素返回1
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
