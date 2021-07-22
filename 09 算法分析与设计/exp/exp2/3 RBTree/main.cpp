#include<stdio.h>
#include<sys/time.h>
#include"RBTREENODE.h"
#include"STRINGHEAP.h"
#include"MYTIME.h"
main(){
	//声明变量 
	int flag,status,err;
	timeval timeBefore,timeAfter,timeDistance;
	String **s;
	RBTree *t;
	RBTreeElemType e;
	FILE *fp;
	
	//初始化 
	t=NULL;
	fp=fopen("data_100000.csv","r");
	if(fp==NULL){
		return(1);
	}
	s=(String **)malloc(100000*sizeof(String *));
	
	//操作 
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
	
	//插入计时 
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
	printf("插入后100个时间%.3f ms\n",timeDistance.tv_sec*1000+timeDistance.tv_usec/1000.0);
	
	//查找计时
	printf("输入-1结束查找，输入index对应数量查找相应结果\n");
	scanf("%d",&status); 
	while(status!=-1){
		gettimeofday(&timeBefore,NULL); 
		err=RBTreeFind(t,status,e);
		gettimeofday(&timeAfter,NULL); 
		timeDistance=TimeDistance(timeBefore,timeAfter);
		printf("寻找时间%.3f ms\n",timeDistance.tv_sec*1000+timeDistance.tv_usec/1000.0);
		if(err!=0){
			printf("查找失败\n");
		}
		else{
			printf("index:%d\n",e.index);
			PrintString(e.s);
			printf("\n");
		}
		printf("输入-1结束查找，输入index对应数量查找相应结果\n");
		scanf("%d",&status); 
	}
	
	//删除计时 
	printf("输入-1结束删除，输入index对应数量删除相应结果\n");
	scanf("%d",&status); 
	while(status!=-1){
		gettimeofday(&timeBefore,NULL); 
		err=RBTreeDelete(t,status,e);
		gettimeofday(&timeAfter,NULL); 
		timeDistance=TimeDistance(timeBefore,timeAfter);
		printf("删除时间%.3f ms\n",timeDistance.tv_sec*1000+timeDistance.tv_usec/1000.0);
		if(err!=0){
			printf("删除失败\n");
		}
		else{
			printf("index:%d\n",e.index);
			PrintString(e.s);
			printf("\n");
		}
		printf("输入-1结束删除，输入index对应数量删除相应结果\n");
		scanf("%d",&status); 
	}
	
	//善后工作 
	for(flag=0;flag<100000;flag++){
		DestroyString(s[flag]);
	}
	free(s);
	DestroyRBTree(t);
}
