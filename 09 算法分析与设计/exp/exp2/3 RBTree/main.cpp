#include<stdio.h>
#include<sys/time.h>
#include"RBTREENODE.h"
#include"STRINGHEAP.h"
#include"MYTIME.h"
main(){
	//�������� 
	int flag,status,err;
	timeval timeBefore,timeAfter,timeDistance;
	String **s;
	RBTree *t;
	RBTreeElemType e;
	FILE *fp;
	
	//��ʼ�� 
	t=NULL;
	fp=fopen("data_100000.csv","r");
	if(fp==NULL){
		return(1);
	}
	s=(String **)malloc(100000*sizeof(String *));
	
	//���� 
	fscanf(fp,"%d,",&e.index);
	InitString(s[0]);
	FileScanString(s[0],fp);
	e.s=s[0];
	RBTreeInsert(t,e);
	for(flag=1;flag<99900;flag++){
		fscanf(fp,"%d,",&e.index);
		InitString(s[flag]);
		FileScanString(s[flag],fp);
		e.s=s[flag];
		RBTreeInsert(t,e);
	}
	
	//�����ʱ 
	gettimeofday(&timeBefore,NULL); 
	for(flag=99900;flag<100000;flag++){
		fscanf(fp,"%d,",&e.index);
		InitString(s[flag]);
		FileScanString(s[flag],fp);
		e.s=s[flag];
		RBTreeInsert(t,e);
	}
	gettimeofday(&timeAfter,NULL); 
	timeDistance=TimeDistance(timeBefore,timeAfter);
	printf("�����100��ʱ��%.3f ms\n",timeDistance.tv_sec*1000+timeDistance.tv_usec/1000.0);
	
	//���Ҽ�ʱ
	printf("����-1�������ң�����index��Ӧ����������Ӧ���\n");
	scanf("%d",&status); 
	while(status!=-1){
		gettimeofday(&timeBefore,NULL); 
		err=RBTreeFind(t,status,e);
		gettimeofday(&timeAfter,NULL); 
		timeDistance=TimeDistance(timeBefore,timeAfter);
		printf("Ѱ��ʱ��%.3f ms\n",timeDistance.tv_sec*1000+timeDistance.tv_usec/1000.0);
		if(err!=0){
			printf("����ʧ��\n");
		}
		else{
			printf("index:%d\n",e.index);
			PrintString(e.s);
			printf("\n");
		}
		printf("����-1�������ң�����index��Ӧ����������Ӧ���\n");
		scanf("%d",&status); 
	}
	
	//ɾ����ʱ 
	printf("����-1����ɾ��������index��Ӧ����ɾ����Ӧ���\n");
	scanf("%d",&status); 
	while(status!=-1){
		gettimeofday(&timeBefore,NULL); 
		err=RBTreeDelete(t,status,e);
		gettimeofday(&timeAfter,NULL); 
		timeDistance=TimeDistance(timeBefore,timeAfter);
		printf("ɾ��ʱ��%.3f ms\n",timeDistance.tv_sec*1000+timeDistance.tv_usec/1000.0);
		if(err!=0){
			printf("ɾ��ʧ��\n");
		}
		else{
			printf("index:%d\n",e.index);
			PrintString(e.s);
			printf("\n");
		}
		printf("����-1����ɾ��������index��Ӧ����ɾ����Ӧ���\n");
		scanf("%d",&status); 
	}
	
	//�ƺ��� 
	for(flag=0;flag<100000;flag++){
		DestroyString(s[flag]);
	}
	free(s);
	DestroyRBTree(t);
}
