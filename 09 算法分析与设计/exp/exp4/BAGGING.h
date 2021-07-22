#ifndef __BAGGING_H
#define __BAGGING_H
//�������ڱ�������Ļ���������
//���ڸϹ���æ��������Щ��bug���Դ˱�����б�Ǹ�����н����Խ��飬��ͨ��QQ��1345578933��ϵ������껣�20210616���й���ѧ������ѧ�� 
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<queue>
#include<time.h>
using namespace std;
//��������ṹ�� 
struct Bag{
	int number;
	int capacity;
	int *weight;
	int *value;
};
//��֧�޽�Ľṹ�壬��ǰ�أ���ǰ��ֵ����ǰ��� 
struct Node {
    int tmpwei=0;
    int tmpval=0;
    int status=0;
};
//�������� 
void TraverseResult(int num,int val,int sta){
	//��ӡ��� 
	int flag;
	bool *result;
	result=(bool *)malloc(sizeof(bool)*num);
	printf("value:%d\nchoose:",val);
	for(flag=0;flag<num;flag++){
		result[num-flag-1]=sta%2;
		sta=sta>>1;
	}
	for(flag=0;flag<num;flag++){
		printf("%d ",result[flag]);
	}
	printf("\n\n");
	free(result);
}
int Exhausting(Bag b,int &out){
	//��ٷ�����������ֵ�����Դ���out�� 
	//ö��״̬���洢�����ֵ���洢�����״̬��ѭ������ 
	int sta,val,flag;
	out=0;
	val=0;
	for(sta=0;sta<pow(2,b.number);sta++){
		int tmpsta,tmpval,tmpwei;
		tmpsta=sta;
		tmpval=0;
		tmpwei=0;
		flag=b.number-1;
		while(tmpsta!=0&&tmpwei<=b.capacity){
			if(tmpsta%2==1){
				tmpval=tmpval+b.value[flag];
				tmpwei=tmpwei+b.weight[flag];
			}
			tmpsta=tmpsta>>1;
			flag--;
		}
		if(tmpwei<=b.capacity&&tmpval>val){
			val=tmpval;
			out=sta;
		} 
	}
	return(val);
}
void Init(int **&mem,int number,int capacity){
	//��ʼ��
	int flag,flag1,flag2;
	mem=(int **)malloc(sizeof(int *)*number);
	for(flag=0;flag<number;flag++){
		mem[flag]=(int *)malloc(sizeof(int)*(capacity+1));
	}
	for(flag1=0;flag1<number;flag1++){
		for(flag2=0;flag2<capacity+1;flag2++){
			mem[flag1][flag2]=-1;
		}
	}
}
void Delete(int **&mem,int number,int capacity){
	//ɾ��
	int flag;
	for(flag=0;flag<number;flag++){
		free(mem[flag]);
	}
	free(mem);
}
int MemorialRec(Bag b,int **mem,int i,int capacity){
	//�ݹ�ʽ���м��� 
	int result;
	result=0;
	if(mem[i][capacity] != -1){
		//ʹ��m[i][capacity]��Ҫ��������±��Ƿ����
		return(mem[i][capacity]); 
	}
	if(i==b.number-1){
		//����¼���м�¼�Ļ� 
		if(capacity>=b.weight[i]){
			//��װ��װ 
			mem[i][capacity]=b.value[i];
			return(b.value[i]);
		}			
		else{
			mem[i][capacity]=0;
			return(0);
		}
	}
	else{
		if(capacity>=b.weight[i]){
			//�һ���װ 
			int selected,unselected;
			selected=MemorialRec(b,mem,i+1,capacity-b.weight[i])+b.value[i];
			unselected=MemorialRec(b,mem,i+1,capacity);
			result=(selected>unselected)?selected:unselected;
			mem[i][capacity]=result;
			return(result);
		}
		else{
			//װ������ 
			result=MemorialRec(b,mem,i+1,capacity);
			mem[i][capacity]=result;
			return(result);
		}	
	}
}
void OutRec(Bag b,int **mem,int i,int capacity,int &out){
	//����mem������
	if(i==b.number-1){
		//�ݹ����� 
		if(mem[i][capacity]==b.value[i]){
			out=out+pow(2,(b.number-i-1));
		}
		return;
	}
	else{		
		if (mem[i][capacity]==mem[i+1][capacity]){
			OutRec(b,mem,i+1,capacity,out);
		}
		else{
			out=out+pow(2,(b.number-i-1));
			OutRec(b,mem,i+1,capacity-b.weight[i],out);
		}
	}
}
int Memorial(Bag b,int &out){
	//����¼������������ֵ�����Դ���out�� 
	int **mem,value;
	Init(mem,b.number+1,b.capacity+1);
	value=MemorialRec(b,mem,0,b.capacity);
	out=0;
	OutRec(b,mem,0,b.capacity,out);
	Delete(mem,b.number,b.capacity);
	return(value);
}
int Dynamic(Bag b,int &out){
	//��̬�滮������������ֵ�����Դ���out�� 
	int **dp,value,flag1,flag2,tmp;
	Init(dp,b.number+1,b.capacity+1);
	for(flag2=0;flag2<b.capacity+1;flag2++){
		dp[0][flag2]=0;
	}
	for(flag1=1;flag1<b.number+1;flag1++){
		for(flag2=0;flag2<b.capacity+1;flag2++){
			if(flag2<b.weight[flag1-1]){
                dp[flag1][flag2]=dp[flag1-1][flag2];
			}
            else{
                dp[flag1][flag2]=(dp[flag1-1][flag2]>dp[flag1-1][flag2-b.weight[flag1-1]]+b.value[flag1-1])?dp[flag1-1][flag2]:dp[flag1-1][flag2-b.weight[flag1-1]]+b.value[flag1-1];
			}
		}
	}
	tmp=dp[b.number][b.capacity];
	//��� 
	Delete(dp,b.number,b.capacity);
	return(tmp);
}
int BacktrackRec(Bag b,int i,int &out,int zero){ 
	//tmpwei��ǰ����������tmpval��ǰ������ֵ��best����ֵ��zero�ݹ��ʼ�� 
    static int tmpwei;
    static int tmpval;
    static int best;
    if(zero==1){
    	tmpwei=0;
    	tmpval=0;
    	best=0;
	}
    if(i>=b.number){ 
		//���������н�
		if(best<tmpval){
			best=tmpval;
		}
    }
    else{
        if(tmpwei+b.weight[i]<=b.capacity){ 
			//��������
            tmpwei=tmpwei+b.weight[i];
			tmpval=tmpval+b.value[i];
            BacktrackRec(b,i+1,out,0);
            tmpwei=tmpwei-b.weight[i];
			tmpval=tmpval-b.value[i];
        }
        //������������
        BacktrackRec(b,i+1,out,0);
    }
    return(best);
}
int Backtrack(Bag b,int &out){
	//���ݷ� 
	int result;
	//out 
	BacktrackRec(b,0,out,1);
	result=BacktrackRec(b,0,out,0);
	return(result);
}
int Broad(Bag b,int &out){
	//������� 
    int max;
    queue<Node> q;
    Node item0,item1;
	max=0;
    q.push(item1);
    while (!q.empty()){
        item0=q.front();
        q.pop();
        if (item0.status<b.number){
            if (b.weight[item0.status]+item0.tmpwei<=b.capacity){
                item1.tmpwei=item0.tmpwei+b.weight[item0.status];
                item1.tmpval=item0.tmpval+b.value[item0.status];
                item1.status = item0.status+1;
                q.push(item1);
            }
            item0.status++;
            q.push(item0);
        }
        else{
            max=(item0.tmpval>max)?item0.tmpval:max;
        }
    }
    return(max);
}
int Monte(Bag b,int &out){
	//���ؿ��� 
    int *x,all,max,flag1,flag2,tmpout;
    x=(int *)malloc(sizeof(int)*b.number);
    memset(x,0,sizeof(int)*b.number);
	all=pow(2,b.number);
    srand(time(NULL));
    max=0;
    for(flag1=0;flag1<all;flag1++){
    	//ȫ�ܣ�������� 
        int tmpwei,tmpval,a;
        tmpwei=0;
        tmpval=0;
        a=rand();
        for(flag2=0;flag2<b.number;flag2++){
            x[flag2]=a%2;
            a=a>>1;
            if((flag2+1)%15==0){
            	//��ΪRAND_MAX=0x7fff�൱��15��1���ƶ�15�ξ���0�� 
            	a=rand();
			} 
        }
        tmpout=0;
        for(flag2=0;flag2<b.number;flag2++){
            tmpwei=tmpwei+x[flag2]*b.weight[flag2];
            tmpval=tmpval+x[flag2]*b.value[flag2];
            if (tmpwei<=b.capacity){
            	if(max<tmpval){
            		max=tmpval;
					if(x[flag2]==1){
            			tmpout=tmpout<<1+1;
					}
					else{
						tmpout=tmpout<<1;
					}
				}
            }
            else{
                break;
			}
        }
        for(flag2=0;flag2<b.number;flag2++){
        	//��������Ҫ���� 
            x[flag2]=0;
		}
    }
    free(x);
    return max;
}
#endif
