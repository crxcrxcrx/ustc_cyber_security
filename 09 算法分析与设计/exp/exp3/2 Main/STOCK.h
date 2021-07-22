#ifndef __STOCK_H
#define __STOCK_H
//�������ڶ�̬�滮��̰���㷨�������������� 
//���ڸϹ���æ��������Щ��bug���Դ˱�����б�Ǹ�����н����Խ��飬��ͨ��QQ��1345578933��ϵ������껣�20210523���й���ѧ������ѧ�� 
#include<stdio.h>
#include<stdlib.h>
//�������� 
int Profit1(int *a,int size,int fee){
	//DP�㷨��o(n^2) 
	int flag1,flag2,*p,*b,max,tmp;
	p=(int *)malloc(sizeof(int)*size);
	b=(int *)malloc(sizeof(int)*size);
	p[0]=0;
	b[0]=0;
	for(flag1=1;flag1<size;flag1++){
		if(a[flag1]<a[flag1-1]){
			b[flag1]=flag1;
			p[flag1]=p[flag1-1];
		}
		else{
			b[flag1]=b[flag1-1];
			max=p[flag1-1];
			for(flag2=0;flag2<=flag1;flag2++){
				tmp=p[b[flag2]]+a[flag1]-a[b[flag2]]-fee;
				if(tmp>max){
					max=tmp;
				}
			}
			p[flag1]=max;
		}
	}
	free(b);
	free(p);
	return(max);
} 
int Profit2(int *a,int size,int fee){
	//DP�㷨��o(n) 
	int **profit,tmp,tmp0,tmp1,flag;
	profit=(int **)malloc(sizeof(int *)*2);
	profit[0]=(int *)malloc(sizeof(int)*size);
	profit[1]=(int *)malloc(sizeof(int)*size);
	profit[0][0]=0;
	profit[1][0]=-a[0];
	for(flag=1;flag<size;flag++){
		tmp=profit[1][flag-1]+a[flag]-fee;
		if(tmp<profit[0][flag-1]){
			profit[0][flag]=profit[0][flag-1]; 
		}
		else{
			profit[0][flag]=tmp; 
		}
		tmp=profit[0][flag-1]-a[flag];
		if(tmp<profit[1][flag-1]){
			profit[1][flag]=profit[1][flag-1]; 
		}
		else{
			profit[1][flag]=tmp; 
		}
	}
	tmp0=profit[0][size-1];
	tmp1=profit[1][size-1];
	if(tmp0>tmp1){
		tmp=tmp0;
	}
	else{
		tmp=tmp1;
	}
	free(profit[0]);
	free(profit[1]);
	free(profit);
	return(tmp);
} 
int Profit3(int *a,int size,int fee){
	//greedy�㷨��o(n)
    int profit,stock,flag,tmp;
    profit=0;
    stock=a[0];
    for(flag=1;flag<size;flag++) {
    	tmp=a[flag]-stock-fee;
    	if(tmp-profit>0){
    		profit=tmp;
		}
		tmp=a[flag]-profit;
		if(tmp-stock<0){
			stock=tmp;
		}
    }
    return(profit);
} 
#endif
