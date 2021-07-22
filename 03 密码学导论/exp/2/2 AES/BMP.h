#include<stdio.h>
#include<stdlib.h>
#ifndef __BMP_H
#define __BMP_H
//�������ڶ�ȡBMPͼ��Ļ��������� 
//���ڸϹ���æ��������Щ��bug���Դ˱�����б�Ǹ�����н����Խ��飬��ͨ��QQ��1345578933��ϵ������껣�20201029���й���ѧ������ѧ�� 
//BMP�ļ�ͷ 
struct BmpHeader{
	unsigned short type;
	//�ļ����ͣ�ͨ��BM
	unsigned long size;
	//�����ļ���С
	unsigned long reserved;
	//����λ��Ϊ0
	unsigned long offbits;
	//ͼƬɫ����ǰ��λ������ɫλ40��16ɫλ118��256ɫλ1078��16λ��24λ��32λɫλ54 
};
//BMP��Ϣ 
struct BmpInfo{
	unsigned long infosize;
	//�ýṹ���С��һ��Ϊ40 
	unsigned long width;	
	//ͼƬ�������ظ��� 
	unsigned long height;
	//ͼƬ�������ظ��� 
	unsigned short plane;
	//ͼ��������Ϊ1 
	unsigned short pictype;
	//ͼƬ���ͣ���ɫλ1��16ɫλ4��256ɫλ8��16λɫλ16��24λɫλ24��32λɫλ32 
	unsigned long compress;
	//ѹ����ʽ��0��ѹ����1RLE8��2RLE4��3�����������
	unsigned long picsize;
	//ɫ�������ֽ�����������4�ı��� 
	unsigned long xppx;
	//����ֱ��ʣ�����/�� 
	unsigned long yppx;
	//����ֱ��ʣ�����/�� 
	unsigned long clrused;
	//���õ���ɫ��Ŀ��0��ʾȫ�� 
	unsigned long clrimp;
	//��Ҫ��ɫ��Ŀ��0��ʾͬ����Ҫ 
};
//BMP��ɫ�����鵥Ԫ 
typedef int BmpColor;
//�������� 
int FileReadBmp(FILE *fp,BmpHeader &bh,BmpInfo &bi,BmpColor *&bc){
	//��ȡbmp�����ص�ɫ���ֽ��� 
	fread(&bh.type,sizeof(short),1,fp);
	fread(&bh.size,sizeof(long),1,fp);
	fread(&bh.reserved,sizeof(long),1,fp);
	fread(&bh.offbits,sizeof(long),1,fp);
	fread(&bi.infosize,sizeof(long),1,fp);
	fread(&bi.width,sizeof(long),1,fp);
	fread(&bi.height,sizeof(long),1,fp);
	fread(&bi.plane,sizeof(short),1,fp);
	fread(&bi.pictype,sizeof(short),1,fp);
	fread(&bi.compress,sizeof(long),1,fp);
	fread(&bi.picsize,sizeof(long),1,fp);
	fread(&bi.xppx,sizeof(long),1,fp);
	fread(&bi.yppx,sizeof(long),1,fp);
	fread(&bi.clrused,sizeof(long),1,fp);
	fread(&bi.clrimp,sizeof(long),1,fp);
	if(bi.pictype==16||bi.pictype==24||bi.pictype==32){
		bc=NULL;
		return(0);
	}
	else if(bi.pictype==1){
		bc=(BmpColor *)calloc(sizeof(BmpColor),2);
		fread(bc,sizeof(BmpColor),2,fp);
		return(8);
	}
	else if(bi.pictype==4){
		bc=(BmpColor *)calloc(sizeof(BmpColor),16);
		fread(bc,sizeof(BmpColor),16,fp);
		return(64);
	}
	else if(bi.pictype==8){
		bc=(BmpColor *)calloc(sizeof(BmpColor),256);
		fread(bc,sizeof(BmpColor),256,fp);
		return(1024);
	}
}
void FileWriteBmp(FILE *fp,BmpHeader bh,BmpInfo bi,BmpColor *bc,int n){
	//д���µ�bmp�ļ� 
	fwrite(&bh.type,sizeof(short),1,fp);
	fwrite(&bh.size,sizeof(long),1,fp);
	fwrite(&bh.reserved,sizeof(long),1,fp);
	fwrite(&bh.offbits,sizeof(long),1,fp);
	fwrite(&bi.infosize,sizeof(long),1,fp);
	fwrite(&bi.width,sizeof(long),1,fp);
	fwrite(&bi.height,sizeof(long),1,fp);
	fwrite(&bi.plane,sizeof(short),1,fp);
	fwrite(&bi.pictype,sizeof(short),1,fp);
	fwrite(&bi.compress,sizeof(long),1,fp);
	fwrite(&bi.picsize,sizeof(long),1,fp);
	fwrite(&bi.xppx,sizeof(long),1,fp);
	fwrite(&bi.yppx,sizeof(long),1,fp);
	fwrite(&bi.clrused,sizeof(long),1,fp);
	fwrite(&bi.clrimp,sizeof(long),1,fp);
	fwrite(bc,sizeof(BmpColor),n/4,fp);
}
void PrintBmpInfo(BmpHeader bh,BmpInfo bi,BmpColor *bc,int n){
	//��ӡbmp��Ϣ 
	printf("��Ϣ���£�\n");
	printf("�ļ���С��%d Bytes\n",bh.size);
	printf("ˮƽ���ȣ�%d pix\n",bi.width);
	printf("��ֱ���ȣ�%d pix\n",bi.height);
	printf("ͼƬ��ɫ���ͣ�2^%d\n",bi.pictype);
	printf("ѹ�����ͣ�%d ��0��ѹ����1RLE8��2RLE4��3�������������\n",bi.compress);
	printf("ͼƬɫ������С��%d �����ֽ�\n",bi.picsize/4);
	printf("ˮƽ�ֱ��ʣ�%d ppm ��0��δ���壩\n",bi.xppx);
	printf("��ֱ�ֱ��ʣ�%d ppm ��0��δ���壩\n",bi.yppx);
	printf("ʹ����ɫ����%d ��0��ȫ����\n",bi.clrused);
	printf("��Ҫ��ɫ����%d ��0��ȫ����\n",bi.clrimp);
	printf("�����ɫ����ɫ����%d\n",n/4);
}
#endif
