#ifndef __SORT_H
#define __SORT_H
//�������������㷨�Ļ���������
//���ڸϹ���æ��������Щ��bug���Դ˱�����б�Ǹ�����н����Խ��飬��ͨ��QQ��1345578933��ϵ������껣�20210419���й���ѧ������ѧ�� 
#include<stdio.h>
#include<iostream>
#include<stdlib.h> 
#include<sys/time.h>
#include<limits.h> 
using namespace std; 
//�������� 
void TraverseArray(int *arr,int i,int j){
	//�����б� 
	int flag;
	for(flag=i;flag<j;flag++){
		cout<<arr[flag]<<endl;
	} 
	printf("\n\n");
}
void InsertSort(int *arr,int i,int j){
	//�������򣬰�����i��i��ֱ��j֮ǰ�����ݴ�С����������ʼΪ0����ֹΪarrSize 
	int flag1,flag2,key;
	for(flag1=i+1;flag1<j;flag1++){
		key=arr[flag1];
		for(flag2=flag1-1;key<arr[flag2]&&flag2>=i;flag2--){
			arr[flag2+1]=arr[flag2];
		}
		arr[flag2+1]=key;
	} 
}
void BubbleSort(int *arr,int i,int j){
	//ð�����򣬰�����i��i��ֱ��j֮ǰ�����ݴ�С����������ʼΪ0����ֹΪarrSize 
	int flag1,flag2,tmp;
	for(flag1=j-1;flag1>i;flag1--){
		for(flag2=i;flag2<flag1;flag2++){
			if(arr[flag2]>arr[flag2+1]){
				tmp=arr[flag2];
				arr[flag2]=arr[flag2+1];
				arr[flag2+1]=tmp;
			}
		}
	} 
}
void SelectSort(int *arr,int i,int j){
	//ѡ�����򣬰�����i��i��ֱ��j֮ǰ�����ݴ�С����������ʼΪ0����ֹΪarrSize 
	int flag1,flag2,key,tmp;
	for(flag1=j-1;flag1>i;flag1--){
		key=flag1;
		for(flag2=i;flag2<=flag1;flag2++){
			if(arr[flag2]>arr[key]){
				key=flag2;
			}
		}
		tmp=arr[key];
		arr[key]=arr[flag1];
		arr[flag1]=tmp;
	} 
}
void Merge(int *arr,int i,int j){
	//�鲢�����ӹ��̣�������i��i��ֱ��j֮ǰ�����ݴ�С����鲢 
	int flag,flag1,flag2;
	int *arr1,*arr2;
	arr1=(int *)malloc(((i+j+1)/2-i+1)*sizeof(int));
	arr2=(int *)malloc((j-(i+j+1)/2+1)*sizeof(int));
	for(flag=i,flag1=0;flag<(i+j+1)/2;flag++,flag1++){
		arr1[flag1]=arr[flag];
	}
	arr1[flag1]=INT_MAX;
	for(flag=(i+j+1)/2,flag2=0;flag<j;flag++,flag2++){
		arr2[flag2]=arr[flag];
	}
	arr2[flag2]=INT_MAX;
	flag1=0;
	flag2=0;
	for(flag=i;flag<j;flag++){
		if(arr1[flag1]<=arr2[flag2]){
			arr[flag]=arr1[flag1];
			flag1++;
		}
		else{
			arr[flag]=arr2[flag2];
			flag2++;
		}
	}
	free(arr1);
	free(arr2);
}
void MergeSort(int *arr,int i,int j){
	//�鲢���򣬰�����i��i��ֱ��j֮ǰ�����ݴ�С����������ʼΪ0����ֹΪarrSize 
	if(i<j-1){
		MergeSort(arr,i,(i+j+1)/2);
		MergeSort(arr,(i+j+1)/2,j);
		Merge(arr,i,j);
	}
}
int LeftChild(int *arr,int i,int j,int p){
	//����i��i��ֱ��j֮ǰ�����ݽ��ѣ��ҳ��ڵ�p�����ӽڵ����꣬������0 
	int tmp;
	tmp=2*(p-i)+1+i;
	if(!(0<=i&&i<=p&&p<tmp&&tmp<j)){
		return(0);
	}
	return(tmp);
}
int RightChild(int *arr,int i,int j,int p){
	//����i��i��ֱ��j֮ǰ�����ݽ��ѣ��ҳ��ڵ�p�����ӽڵ����꣬������0 
	int tmp;
	tmp=2*(p-i)+2+i;
	if(!(0<=i&&i<=p&&p<tmp&&tmp<j)){
		return(0);
	}
	return(tmp);
}
void Heapify(int *arr,int i,int j,int p){
	//�ѵ�p����ѻ�
	int l,r,max; 
	int tmp;
	l=LeftChild(arr,i,j,p);
	r=RightChild(arr,i,j,p);
	max=p;
	if(l!=0&&arr[l]>arr[max]){
		max=l;
	}
	if(r!=0&&arr[r]>arr[max]){
		max=r;
	}
	if(max!=p){
		tmp=arr[max];
		arr[max]=arr[p];
		arr[p]=tmp;
		Heapify(arr,i,j,max);
	}
}
void BuildHeap(int *arr,int i,int j){
	//�������� 
	int flag;
	for(flag=(j-i)/2+i-1;flag>=i;flag--){
		Heapify(arr,i,j,flag);
	}
}
void HeapSort(int *arr,int i,int j){
	//�����򣬰�����i��i��ֱ��j֮ǰ�����ݴ�С����������ʼΪ0����ֹΪarrSize 
	int flag;
	int tmp;
	BuildHeap(arr,i,j); 
	for(flag=j-1;flag>i;flag--){
		tmp=arr[flag];
		arr[flag]=arr[i];
		arr[i]=tmp;
		Heapify(arr,i,flag,i);
	}
}
int Partition(int *arr,int i,int j){
	//�ָ�������С�Ҵ󣬷���ֵ�Ƿָ������� 
	int key,tmp,midNum,min,flag;
	key=rand()%(j-i)+i;
	tmp=arr[key];
	arr[key]=arr[j-1];
	arr[j-1]=tmp;
	midNum=arr[j-1];
	min=i;
	for(flag=i;flag<j;flag++){
		if(arr[flag]<=midNum){
			tmp=arr[flag];
			arr[flag]=arr[i];
			arr[i]=tmp;
			i++;
		}
	}
	return(i-1);
} 
void QuickSort(int *arr,int i,int j){
	//�������򣬰�����i��i��ֱ��j֮ǰ�����ݴ�С����������ʼΪ0����ֹΪarrSize 
	int p;
	if(i<j){
		p=Partition(arr,i,j);
		QuickSort(arr,i,p);
		QuickSort(arr,p+1,j);
	}
}
timeval ProcTime(void fun(int *arr,int i,int j),int *arr,int i,int j){
	//���������i��i��ֱ��j֮ǰ�����ݴ�С���������ʱ�� 
	timeval timeBefore,timeAfter,timeDistance;
	int numBefore,numAfter,numDistance; 
	gettimeofday(&timeBefore,NULL);
	fun(arr,i,j);
	gettimeofday(&timeAfter,NULL);
	numBefore=timeBefore.tv_sec*1000000+timeBefore.tv_usec;
	numAfter=timeAfter.tv_sec*1000000+timeAfter.tv_usec;
	numDistance=numAfter-numBefore;
	timeDistance.tv_sec=numDistance/1000000;
	timeDistance.tv_usec=numDistance%1000000;
//	printf("����ʱ��%ds %dms %dus\n",timeDistance.tv_sec,timeDistance.tv_usec/1000,timeDistance.tv_usec%1000);
	return(timeDistance);
}
#endif 
