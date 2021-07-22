#include<stdio.h>
#include"AUTOARRAY.h"
int FileScanStock(List *l,FILE *fp){
	//输入数组[]，数据逗号分隔，返回输入数量
	char c;
	int i,flag;
	c=fgetc(fp);
	flag=0;
	while(c!=']'){
		fscanf(fp,"%d",&i);
		flag++;
		ListInsert(l,0,i);
		c=fgetc(fp);
	}
	return(flag);
}
main(){
	int flag;
	List *l0,*l1,*l2,*l3,*l4,*l5,*l6;
	FILE *fp0,*fq0,*fp1,*fq1,*fp2,*fq2,*fp3,*fq3,*fp4,*fq4,*fp5,*fq5,*fp6,*fq6;
	InitList(l0);
	InitList(l1);
	InitList(l2);
	InitList(l3);
	InitList(l4);
	InitList(l5);
	InitList(l6);
	fp0=fopen("data0.bin","wb");
	fp1=fopen("data1.bin","wb");
	fp2=fopen("data2.bin","wb");
	fp3=fopen("data3.bin","wb");
	fp4=fopen("data4.bin","wb");
	fp5=fopen("data5.bin","wb");
	fp6=fopen("data6.bin","wb");
	fq0=fopen("..\\实验要求\\实验三说明文档0.md","r");
	fq1=fopen("..\\实验要求\\实验三说明文档1.md","r");
	fq2=fopen("..\\实验要求\\实验三说明文档2.md","r");
	fq3=fopen("..\\实验要求\\实验三说明文档3.md","r");
	fq4=fopen("..\\实验要求\\实验三说明文档4.md","r");
	fq5=fopen("..\\实验要求\\实验三说明文档5.md","r");
	fq6=fopen("..\\实验要求\\实验三说明文档6.md","r");
	if(fp0==NULL||fq0==NULL||fp1==NULL||fq1==NULL||fp2==NULL||fq2==NULL||fp3==NULL||fq3==NULL||fp4==NULL||fq4==NULL||fp5==NULL||fq5==NULL||fp6==NULL||fq6==NULL){
		return(1);
	}
	FileScanStock(l0,fq0); 
	FileScanStock(l1,fq1); 
	FileScanStock(l2,fq2); 
	FileScanStock(l3,fq3); 
	FileScanStock(l4,fq4); 
	FileScanStock(l5,fq5); 
	FileScanStock(l6,fq6); 
	for(flag=0;flag<l0->length;flag++){
		fwrite(&(l0->data[flag]),sizeof(int),1,fp0);
	}
	for(flag=0;flag<l1->length;flag++){
		fwrite(&(l1->data[flag]),sizeof(int),1,fp1);
	}
	for(flag=0;flag<l2->length;flag++){
		fwrite(&(l2->data[flag]),sizeof(int),1,fp2);
	}
	for(flag=0;flag<l3->length;flag++){
		fwrite(&(l3->data[flag]),sizeof(int),1,fp3);
	}
	for(flag=0;flag<l4->length;flag++){
		fwrite(&(l4->data[flag]),sizeof(int),1,fp4);
	}
	for(flag=0;flag<l5->length;flag++){
		fwrite(&(l5->data[flag]),sizeof(int),1,fp5);
	}
	for(flag=0;flag<l6->length;flag++){
		fwrite(&(l6->data[flag]),sizeof(int),1,fp6);
	}
	DestroyList(l0);
	DestroyList(l1);
	DestroyList(l2);
	DestroyList(l3);
	DestroyList(l4);
	DestroyList(l5);
	DestroyList(l6);
	fclose(fp0);
	fclose(fq0);
	fclose(fp1);
	fclose(fq1);
	fclose(fp2);
	fclose(fq2);
	fclose(fp3);
	fclose(fq3);
	fclose(fp4);
	fclose(fq4);
	fclose(fp5);
	fclose(fq5);
	fclose(fp6);
	fclose(fq6);
}
