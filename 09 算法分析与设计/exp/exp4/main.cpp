#include<stdio.h>
#include<stdlib.h>
#include"BAGGING.h" 
//�ļ���
#define FILENAME "testdata/20test.txt"
int ScanData(FILE *f,Bag &b){
	//���ļ������ݶ���b��
	int flag;
	fscanf(f,"%d",&b.number);
	fscanf(f,"%d",&b.capacity);
	b.weight=(int *)malloc(b.number*sizeof(int));
	b.value=(int *)malloc(b.number*sizeof(int));
	for(flag=0;flag<b.number;flag++){
		fscanf(f,"%d",&b.weight[flag]);
	}
	for(flag=0;flag<b.number;flag++){
		fscanf(f,"%d",&b.value[flag]);
	}
	return(0);
}
int TraverseData(Bag b){
	int flag;
	printf("number: %d\n",b.number);
	printf("capacity: %d\n",b.capacity);
	for(flag=0;flag<b.number;flag++){
		printf("%d ",b.weight[flag]);
	}
	printf("\n");
	for(flag=0;flag<b.number;flag++){
		printf("%d ",b.value[flag]);
	}
	printf("\n");
}
main(){
	//�������� 
	FILE *fp;
	Bag bag;
	int err,sta,flag;
	
	//��ʼ������ 
	fp=fopen(FILENAME,"r");
	ScanData(fp,bag);
	TraverseData(bag);
	
	//��ʼ����
	//��� 
	printf("\n\n����㷨\n"); 
	err=Exhausting(bag,sta); 
	TraverseResult(bag.number,err,sta);
	//����¼ 
	printf("\n\n����¼�㷨\n"); 
	err=Memorial(bag,sta); 
	TraverseResult(bag.number,err,sta);
	//��̬�滮 
	printf("\n\n��̬�滮�㷨\n"); 
	err=Dynamic(bag,sta); 
	TraverseResult(bag.number,err,sta);
	//���� 
	printf("\n\n�����㷨\n"); 
	err=Backtrack(bag,sta); 
	TraverseResult(bag.number,err,sta);
	//��֧�޽� 
	printf("\n\n��֧�޽��㷨\n"); 
	err=Broad(bag,sta); 
	TraverseResult(bag.number,err,sta);
	//���ؿ��� 
	printf("\n\n���ؿ����㷨\n"); 
	err=Broad(bag,sta); 
	TraverseResult(bag.number,err,sta);
	 
	//�ƺ��� 
	free(bag.weight);
	free(bag.value);
}
