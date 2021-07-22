#ifndef __VIGENERE_H
#define __VIGENERE_H
//��������Vigenere���ܵ��㷨��
//���ڸϹ���æ��������Щ��bug���Դ˱�����б�Ǹ�����н����Խ��飬��ͨ��QQ��1345578933��ϵ������껣�20200925���й���ѧ������ѧ�� 
#include<stdio.h>
#include<stdlib.h>
#include"STRINGHEAP.h"
//�������� 
int VigenereEncode(String *skey,String *splt,String *scip){
	//��Vigenere���ܷ�ʽ��splt����skey���м��ܣ��ɹ�����0����Կ�շ���1
	int flag1,flag2;
	String *res;
	InitString(res);
	if(skey->length==0){
		return(1);
	}
	flag2=0;
	for(flag1=0;flag1<splt->length;flag1++){
		res->str[0]=(splt->str[flag1]-'a'+skey->str[flag2]-'a')%26+'A';
		res->length=1;
		StringInsert(scip,res,0);
		flag2++;
		if(flag2>=skey->length){
			flag2=flag2-skey->length;
		}
	}
	DestroyString(res);
	return(0);
}
int VigenereDencode(String *skey,String *splt,String *scip){
	//��Vigenere���ܷ�ʽ��scip����skey���м��ܣ��ɹ�����0����Կ�շ���1
	int flag1,flag2;
	String *res;
	InitString(res);
	if(skey->length==0){
		return(1);
	}
	flag2=0;
	for(flag1=0;flag1<splt->length;flag1++){
		res->str[0]=(splt->str[flag1]-'A'-skey->str[flag2]-'a'+26)%26+'a';
		res->length=1;
		StringInsert(splt,res,0);
		flag2++;
		if(flag2>=skey->length){
			flag2=flag2-skey->length;
		}
	}
	DestroyString(res);
	return(0);
}
int VigenereKey(String *skey,String *splt,String *scip){
	//��Vigenere���ܷ�ʽ��splt���ܳ�scipѰ����Կ���ɹ�������Կ����ʧ�ܷ���0
	int flag1,flag2,err;
	String *res,*tmp;
	InitString(res);
	InitString(tmp);
	skey->str=(char *)realloc(skey->str,(STRINGSIZE+(splt->length-STRINGSIZE)/STRINGADDON+1)*STRINGADDON*sizeof(char));
	skey->length=splt->length;
	skey->size=splt->size;
	for(flag1=0;flag1<splt->length;flag1++){
		skey->str[flag1]=(scip->str[flag1]-'A'-(splt->str[flag1]-'a')+26)%26+'a';
	}
	for(flag1=1;flag1<skey->length;flag1++){
		SubString(skey,res,1,flag1);
		for(flag2=1;flag2<skey->length/res->length;flag2++){
			err=Index(skey,res,flag2*res->length+1);
			if(err!=1+res->length*flag2){
				break;
			}
		}
		if(flag2==skey->length/res->length){
			if(flag2*res->length<skey->length){
				SubString(skey,tmp,flag2*res->length+1,skey->length-flag2*res->length);
				err=Index(res,tmp,1);
				if(err==1){
					StringCopy(skey,res);
					return(flag1);
				}
			}
			else{
				StringCopy(skey,res);
				return(flag1);
			}
		}
	}
	DestroyString(res);
	DestroyString(tmp);
	return(0);
}
#endif 
