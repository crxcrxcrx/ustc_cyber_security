#ifndef __BM_H
#define __BM_H
//��������BM�㷨�Ļ��������� 
//���ڸϹ���æ��������Щ��bug���Դ˱�����б�Ǹ�����н����Խ��飬��ͨ��QQ��1345578933��ϵ������껣�20201109���й���ѧ������ѧ�� 
#include<stdio.h>
#include<stdlib.h>
#include"STRINGHEAP.h"
//�������� 
int StringToBool(String *s,bool *b){
	//���ַ���ת���ɲ������У��ɹ�����0��ʧ�ܷ���1 
	int flag;
	for(flag=0;flag<s->length;flag++){
		if(s->str[flag]=='0'){	
			b[flag]=0;
		}
		else if(s->str[flag]=='1'){
			b[flag]=1;
		}
		else{
			return(1);
		}
	}
	return(0);
}
bool Distance(bool *c,bool *s,int j,int l){
	//�����j�ֵ�������һ����� 
	int flag;
	bool d; 
	d=s[j];
	for(flag=1;flag<=l;flag++){
		d=d^(c[flag]&s[j-flag]);
	}
	return(d);
} 
int PrintFomula(bool *c,int l){
	int flag;
	printf("1");
	if(l>1){
		printf("+");
	}
	for(flag=1;flag<l;flag++){
		if(c[flag]==1){
			printf("D^%d+",flag);
		}
	}
	if(l>1){
		printf("D^%d\n",l);
	}
	return(0);
}
#endif 
