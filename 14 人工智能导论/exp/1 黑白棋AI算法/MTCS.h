//MTCS.h
#ifndef __MTCS_H
#define __MTCS_H
//这是用于Monte Carlo树的操作，部分代码借鉴于同学，使用时请手动修改UCT，MAXCHILD，MAXPOINT定义 
//由于赶工繁忙，可能有些许bug，对此本人深感抱歉。如有建设性建议，可通过QQ：1345578933联系（麻治昊，20210612于中国科学技术大学） 
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include"DRAW.h"
//UCT超参
#define UCT 0.5
//最多子节点
#define MAXCHILD 50 
//最多尝试节点数
#define MAXPOINT 5000
struct Node{
	//总模拟受益,白棋胜数
	int q=0;
	//总访问次数
	int n=0;
	//棋盘状态
	int status[LINE][LINE];
	//哪一方的回合，甚至可能憋死 
	int turn;
	//父子节点 
	Node *parent=NULL;
	Node *child[MAXCHILD]={NULL};
	//子节点数
	int chnum=0;
};
double CalcUct(Node *p){
	//计算UCT权重 
	int col;
	double t;
	col=p->parent->turn;
	if(col==WHITE){
		t=(p->q/p->n)+UCT*sqrt(log(p->parent->n)/p->n);
	}
	if(col==BLACK){
		t=(1-(p->q/p->n))+UCT*sqrt(log(p->parent->n)/p->n);
	}
	return t;
}
bool Genchild(Node *p){
	//获取子节点 
	int x,y,chnum,i,j,col;
	chnum=0;
	Node *q;
	col=p->turn;
	if(col==NULL){
		return false;
	}
	for(x=0;x<LINE;x++){
		for(y=0;y<LINE;y++){
			if(ValidStep(p->status,x,y,col)){
				if(!(q=new Node)){
					exit(1);
				}
				for(i=0;i<LINE;i++){
					for(j=0;j<LINE;j++) {
						q->status[i][j]=p->status[i][j];
					}
				}
				q->parent=p;
				DrawIn(q->status,x,y,col);
				if(AbleDraw(q->status,Rev(col))){
					q->turn=Rev(col);
				}
				else if(AbleDraw(q->status,col)){
					q->turn=col;
				}
				else{
					q->turn=NULL;
				}
				p->child[chnum]=q;
				chnum++;
			}
		}
	}
	p->chnum=chnum;
	return true;
}
Node *SelectChild(Node *p,int colour){
	//选择子节点 
	int num,i,maxseq,minseq,seq;
	double max,min,tmp;
	Node **q;
	num=p->chnum;
	for(i=0;i<num;i++){
		if(p->child[i]->n==0){
			return p->child[i];
		}
	}
	if(colour==WHITE){
		minseq=0;
		min=CalcUct(p->child[0]);
		seq=1;
		q=p->child;
		while(seq<num){
			if((tmp=CalcUct(q[seq]))<min){
				min=tmp;
				minseq=seq;
			}
			seq++;
		}
		return q[minseq];
	}
	if(colour==BLACK){
		maxseq=0;
		max=CalcUct(p->child[0]);
		seq=1;
		q=p->child;
		while(seq<num){
			if((tmp=CalcUct(q[seq]))>max){
				max=tmp;
				maxseq=seq;
			}
			seq++;
		}
		return q[maxseq];
	}
}
int Step(int map[LINE][LINE],int &col){
	//单步模拟 
	int stepnum,x,y,stepx[MAXCHILD],stepy[MAXCHILD],step;
	stepnum=0;
	if(col==NULL){
		return 0;
	}
	for(x=0;x<LINE;x++){
		for(y=0;y<LINE;y++){
			if(ValidStep(map,x,y,col)){
					stepx[stepnum]=x;
					stepy[stepnum]=y;
					stepnum++;
			}
		}
	}
	if(stepnum==0){
		return 2;
	}
	step=rand()%stepnum;
	DrawIn(map,stepx[step],stepy[step],col);
	if(AbleDraw(map,Rev(col))){
		col=Rev(col);
		return 1;
	}
	else if(AbleDraw(map,col)){
		return 1;
	}
	else{
		col=NULL;
		return 1;
	}
}
int Roll(Node *p){
	//随机模拟，返回值为白棋方收益 
	int x,y,map[LINE][LINE];
	int col=p->turn;
	for(x=0;x<LINE;x++){
		for(y=0;y<LINE;y++){
			map[x][y]=p->status[x][y];
		}
	}
	if(col==NULL){
		if(FindWin(map)==WHITE)
			return 1;
		else{
			return 0;
		}
	}
	while(col!=NULL){
		if(Step(map,col)==2){
			return 2;
		}
	}
	if(FindWin(map)==WHITE)
		return 1;
	else{
		return 0;
	}
}
bool FeedBack(Node *p,int q){
	//反向传播 
	while(p!=NULL){
		p->q+=q;
		p->n+=1;
		p=p->parent;
	}
	return true;
}
void DeleteTree(Node *root){
	//释放树节点 
	int i;
	if(root==NULL){
		return;
	}
	for(i=0;i<root->chnum;i++){
		DeleteTree(root->child[i]);
	}
	delete root;
}
void Intelligence(int colour){
	//人工智能决策 
	Node *root,*p,**q;
	int x,y,i,j,maxseq,Max,Seq,temp,(*a)[LINE],err;
	if(!(root = new Node)){
		exit(1);
	}
	for(x=0;x<LINE;x++){
		for(y=0;y<LINE;y++){
			root->status[x][y]=map[x][y];
		}
	}
	root->turn=colour;
	p=root;
	for(i=0;i<MAXPOINT;i++){
		p=root;
		while(p->chnum!=0){
			p=SelectChild(p,colour);
		}
		err=Roll(p);
		if(err==2){
			printf("无子可下\n");
			err=FindWin(map);
			if(err>0){
				printf("先手胜%d子\n",err);
			}
			else if(err<0){
				printf("后手胜%d子\n",err);
			}
			else{
				printf("平局\n");
			}
			exit(1);
		}
		FeedBack(p,err);
		Genchild(p);
	}
	maxseq=0;
	Max=(root->child[0]->n);
	Seq=1;
	q=root->child;
	while(Seq<root->chnum){
		if((temp=q[Seq]->n)>Max){
			Max=temp;
			maxseq=Seq;
		}
		Seq++;
	}
	//寻找下一步
	a=root->child[maxseq]->status;
	for(x=0;x<LINE;x++){
		for(y=0;y<LINE;y++){
			if(root->status[x][y]==NULL&&a[x][y]!=NULL){
				i=x;
				j=y;
				break;
			}
		}
	}
	printf("MCTS:(%d,%d)\n",i+1,j+1);
	DrawIn(map,i,j,colour);
}
#endif
