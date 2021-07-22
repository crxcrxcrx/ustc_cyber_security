#ifndef __STRINGHEAP_H
#define __STRINGHEAP_H
//�������ڶ�ʽ���Ļ���������ʹ��ʱ���ֶ���STRINGSIZE��STRINGADDON���壬�������޸�TraverseString������
//���ڸϹ���æ��������Щ��bug���Դ˱�����б�Ǹ�����н����Խ��飬��ͨ��QQ��1345578933��ϵ������껣�20191017���й���ѧ������ѧ�� 
#include<stdio.h>
#include<stdlib.h>
//����С���ȣ�ȱʡ500 
#define STRINGSIZE 10
//��ÿ��������Ԫ��������ȱʡ100 
#define STRINGADDON 5 
//��ʽ���������� 
struct String{
	char *str;
	int length;
	int size;
};
//�������� 
int InitString(String *&s){
	//��ʼ����s��s��Ĭ�ϳ�����STRINGSIZE,������ɾ���ɹ�����0��s�շ���1��str�շ���2 
	int flag;
	s=(String *)malloc(sizeof(String));
	if(s==NULL){
		return(1);
	}
	s->str=(char *)calloc(STRINGSIZE,sizeof(char));
	if(s->str==NULL){
		return(2);
	}
	s->length=0;
	s->size=STRINGSIZE;
	return(0);
}
void DestroyString(String *&s){
	//���ٴ�s 
	free(s->str); 
	free(s);
	s=NULL;
	return;
}
int ClearString(String *&s){
	//����s�ÿգ��ɹ�����0��str�շ���1 
	s->length=0;
	if(s->size>STRINGSIZE){
		s->str=(char *)realloc(s->str,STRINGSIZE*sizeof(char));
		if(s->str==NULL){
		    return(1);
	    }
		s->size=STRINGSIZE;
	}
	return(0); 
}
int StringEmpty(String *&s){
	//�жϴ�s�Ƿ�Ϊ�գ��Ƿ���1�����Ƿ���0 
	if(s->length==0){
		return(1);
	}
	else{
		return(0);
	}
}
int StringFull(String *&s){
	//�жϴ�s�Ƿ�Ϊ�����Ƿ���1�����Ƿ���0 
	if(s->length==s->size){
		return(1);
	}
	else{
		return(0);
	}
}
int StringLength(String *&s){
	//���ش�s���� 
	return(s->length);
}
int StringInsert(String *&s,String *&t,int i){
	//��s��iλ��ǰ����t����iΪ0�����ں󷽲��롣�ɹ�����0��i���Ϸ�����1���ڴ治�㷵��2 
	int flag,add;
	if(i<0||i>s->length){
		return(1);
	} 
	if(s->length+t->length>=s->size){
		add=(s->length+t->length-s->size)/STRINGADDON+1;
		s->str=(char *)realloc(s->str,(s->size+add*STRINGADDON)*sizeof(char));
		if(s->str==NULL){
			return(2);
		}
		s->size=s->size+add*STRINGADDON;
	}
	if(i==0){
		for(flag=0;flag<t->length;flag++){
			s->str[s->length+flag]=t->str[flag];
		}
		s->length=s->length+t->length;
		return(0);
	}
	for(flag=s->length-1;flag>=i-1;flag--){
		s->str[flag+t->length]=s->str[flag];
	}
	for(flag=0;flag<t->length;flag++){
		s->str[flag+i-1]=t->str[flag];
	}
	s->length=s->length+t->length;
	return(0);
}
int StringDelete(String *&s,String *&t,int i,int l){
	//ɾ��s��iλ�ú�Ϊl�Ĵ�����ֵ��t���ɹ�����0��i���Ϸ�����1���ڴ治�㷵��2 
	int flag,add;
	if(i<1||i>s->length){
		return(1);
	}
	if(l>=t->size){
		add=(l-t->size)/STRINGADDON+1;
		t->str=(char *)realloc(t->str,(t->size+add*STRINGADDON)*sizeof(char));
		if(t->str==NULL){
			return(2);
		}
		t->size=t->size+add*STRINGADDON;
	}
	for(flag=0;flag<i+l-1;flag++){
		t->str[flag]=s->str[flag+i-1];
	}
	t->length=l;
	for(flag=i-1;flag<s->length;flag++){
		s->str[flag]=s->str[flag+l];
	}
	s->length=s->length-l;
	if(s->size-s->length>STRINGADDON&&s->size>STRINGSIZE){
		add=(s->size-s->length)/STRINGADDON-1;
		s->str=(char *)realloc(s->str,(s->size-add*STRINGADDON)*sizeof(char));
		if(s->str==NULL){
			return(2);
		}
		s->size=s->size-add*STRINGADDON;
	}
	return(0);
}
int StringCompare(String *&s,String *&t){
	//�Ƚ��ַ�˳�򣬷������һλ�Ĳ�ֵ 
	int flag,i;
	for(flag=0;flag<s->length&&flag<t->length;flag++){
		i=s->str[flag]-t->str[flag];
		if(i!=0){
			return(i);
		}
	}
	if(s->length>t->length){
		return(s->str[t->length]);
	}
	else if(s->length<t->length){
		return(-t->str[s->length]);
	}
	return(0);
}
int StringCopy(String *&s,String *&t){
	//�Ѵ�t���Ƹ���s���ɹ�����0��ʧ�ܷ���1 
	int flag,add;
	ClearString(s);
	if(t->length>=s->size){
		add=(t->length-s->size)/STRINGADDON+1;
		s->str=(char *)realloc(s->str,(s->size+add*STRINGADDON)*sizeof(char));
		if(s->str==NULL){
			return(1);
		}
		s->size=s->size+add*STRINGADDON;
	}
	for(flag=0;flag<t->length;flag++){
		s->str[flag]=t->str[flag];
	} 
	s->length=t->length;
	return(0);
}
int Concat(String *&s,String *&t1,String *&t2){
	//����t1��t2���ӣ��浽��һ����s�У��ɹ�����0��ʧ�ܷ���1 
	int flag,add;
	ClearString(s);
	if(t1->length+t2->length>=s->size){
		add=(t1->length+t2->length-s->size)/STRINGADDON+1;
		s->str=(char *)realloc(s->str,(s->size+add*STRINGADDON)*sizeof(char));
		if(s->str==NULL){
			return(1);
		}
		s->size=s->size+add*STRINGADDON;
	}
	for(flag=0;flag<t1->length;flag++){
		s->str[flag]=t1->str[flag];
	}
	for(flag=t1->length;flag<t1->length+t2->length;flag++){
		s->str[flag]=t2->str[flag-t1->length];
	}
	s->length=t1->length+t2->length;
	return(1);
}
int SubString(String *&s,String *&t,int i,int l){
	//��s��iλ������l���Ӵ��浽t�У��ɹ�����0��i���Ϸ�����1��l���Ϸ�����2���ڴ治�㷵��3 
	int flag,add;
	if(i<1||i>s->length){
		return(1);
	} 
	if(l<1||i+l-1>s->length){
		return(2);
	}
	ClearString(t);
	if(l>=t->size){
		add=(l-t->size)/STRINGADDON+1;
		t->str=(char *)realloc(t->str,(t->size+add*STRINGADDON)*sizeof(char));
		if(t->str==NULL){
			return(1);
		}
		t->size=t->size+add*STRINGADDON;
	}
	for(flag=i-1;flag<i+l-1;flag++){
		t->str[flag-i+1]=s->str[flag];
	}
	t->length=l;
	return(0);
}
int Index(String *&s,String *&t,int i){
	//����s��iλ�ú��һ����t���Ӵ�λ��,û�оͷ���0��i���Ϸ�����-1 
	int flag1,flag2,flag3;
	if(i<1||i>s->length-t->length+1){
		return(-1);
	} 
	for(flag1=i-1;flag1<s->length;flag1++){
		flag3=flag1;
		for(flag2=0;flag2<t->length;flag2++,flag3++){
			if(s->str[flag3]!=t->str[flag2]){
				break;
			}
		}
		if(flag2==t->length){
			return(flag1+1);
		}
	}
	return(0);
}
int Replace(String *&s,String *&t,String *&v){
	//�ô�v�滻s�����в��ص��ĺ�t�ķ��ص��Ӵ����ɹ�����0��ʧ�ܷ���1  
	int flag,err;
	String *j;
	flag=1;
	err=InitString(j);
	if(err!=0){
		return(1);
	} 
	flag=Index(s,t,flag);
	do{
		StringDelete(s,j,flag,t->length);
		if(flag+t->length==s->length+1){
			StringInsert(s,v,0);
		}
		else{
			StringInsert(s,v,flag);
		}
		flag=flag+v->length;
		flag=Index(s,t,flag);
	}while(flag<=s->length&&flag>0);
	DestroyString(j);
	return(0);
}
int ScanString(String *&s){
	//����s�Ĵ����ݣ�#�������ɹ�����0��ʧ�ܷ���1 
	char c;
	int flag,add;
	ClearString(s);
	flag=0;
	c=getchar();
	while(c!='#'){
		s->str[flag]=c;
		s->length=flag+1;
		flag++;
		c=getchar();
		if(s->length>=s->size){
			add=(s->length-s->size)/STRINGADDON+1;
			s->str=(char *)realloc(s->str,(s->size+add*STRINGADDON)*sizeof(char));
			if(s->str==NULL){
				return(1);
			}
			s->size=s->size+add*STRINGADDON;
		}
	}
	fflush(stdin);
	return(0);
}
void PrintString(String *&s){
	//���s�Ĵ����� 
	int flag;
	for(flag=0;flag<s->length;flag++){
		printf("%c",s->str[flag]);
	}
	printf("#");
	return;
}
int FileScanString(String *&s,FILE *fp){
	//����s�Ĵ����ݣ�#�������ɹ�����0��ʧ�ܷ���1 
	char c;
	int flag,add;
	ClearString(s);
	flag=0;
	c=fgetc(fp);
	while(c!='#'){
		s->str[flag]=c;
		s->length=flag+1;
		flag++;
		c=fgetc(fp);
		if(s->length>=s->size){
			add=(s->length-s->size)/STRINGADDON+1;
			s->str=(char *)realloc(s->str,(s->size+add*STRINGADDON)*sizeof(char));
			if(s->str==NULL){
				return(1);
			}
			s->size=s->size+add*STRINGADDON;
		}
	}
	return(0);
}
void FilePrintString(String *&s,FILE *fp){
	//���s�Ĵ��������ļ���#���� 
	int flag;
	for(flag=0;flag<s->length;flag++){
		fprintf(fp,"%c",s->str[flag]);
	}
	fprintf(fp,"#");
	return;
}
void TraverseString(String *&s){
	//����s����������ִ���Զ������ 
	int flag;
	for(flag=0;flag<s->length;flag++){
		//�Զ��������ȱʡ��ӡ 
		printf("%d\n",s->str[flag]);
	}
	return;
}
#endif 
