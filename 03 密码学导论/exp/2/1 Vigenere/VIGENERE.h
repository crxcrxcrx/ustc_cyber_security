#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"BMP.h"
#ifndef __VIGENERE_H
#define __VIGENERE_H
//��������Vigenere����BMPͼ��Ļ��������� 
//���ڸϹ���æ��������Щ��bug���Դ˱�����б�Ǹ�����н����Խ��飬��ͨ��QQ��1345578933��ϵ������껣�20191017���й���ѧ������ѧ�� 
//�������� 
void keygen(FILE *fp,int n){
	//���ɳ���Ϊn�ֽڵ���Կ 
	int flag;
	char ran;
	fwrite(&n,sizeof(int),1,fp);
	srand((unsigned int)time(0));
	for(flag=0;flag<n;flag++){
		ran=(char)rand();
		fwrite(&ran,sizeof(char),1,fp);
	}
}
void VigenereEncode(FILE *fin,FILE *fkey,FILE *fout){
	//��Vigenere�㷨���ܣ�n��ɫ���ֽ�����picsɫ���ֽ�����keyl��Կ�ֽ�����in�������ݣ�skey�����Կ��outд������ 
	int n,pics,keyl,flag;
	char in,*skey,out;
	BmpHeader bh;
	BmpInfo bi;
	BmpColor *bc;
	bc=NULL;
	n=FileReadBmp(fin,bh,bi,bc);
	FileWriteBmp(fout,bh,bi,bc,n);
	PrintBmpInfo(bh,bi,bc,n);
	fseek(fin,n+14+40,SEEK_SET);
	fseek(fout,0,SEEK_END);
	pics=bi.picsize;
	fread(&keyl,sizeof(int),1,fkey);
	skey=(char *)calloc(sizeof(char),keyl);
	fread(skey,sizeof(char),keyl,fkey);
	printf("\n��Կ���ȣ�%d\n",keyl);
	flag=0;
	while(pics!=0){
		pics--;
		flag=flag%keyl;
		fread(&in,sizeof(char),1,fin);
		out=in+skey[flag];
		fwrite(&out,sizeof(char),1,fout);
		flag++;
	}
	free(skey);
	free(bc);
}
#endif 
