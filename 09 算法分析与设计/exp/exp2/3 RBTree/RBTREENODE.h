#ifndef __RBTREENODE_H
#define __RBTREENODE_H
//�������ں�����Ļ�������
//���ڸϹ���æ��������Щ��bug���Դ˱�����б�Ǹ�����н����Խ��飬��ͨ��QQ��1345578933��ϵ������껣�20210510���й���ѧ������ѧ�� 
#include<stdio.h>
#include<stdlib.h> 
#include<math.h> 
#include"STRINGHEAP.h"
//������������ͣ�ȱʡint 
struct Host{
	int index;
	String *s;
};
enum RBTreeColor{
	red,
	black
};
enum RBTreeRank{
	left,
	right,
	root
};
typedef Host RBTreeElemType;
struct RBTree{
	RBTreeElemType data;
	RBTreeColor color;
	RBTreeRank rank;
	RBTree *left;
	RBTree *right;
	RBTree *parent;
};
//�������� 
void DestroyRBTree(RBTree *&t){
	//���ٺ����t 
	if(t!=NULL){
		DestroyRBTree(t->left);
		DestroyRBTree(t->right);
		free(t);
		t=NULL;
		return;
	}
	return;
} 
int RBTreeLeftRotate(RBTree *&treeroot,RBTree *t){
	//�����ڵ�t���ɹ�����0�������������1 
	RBTree *p,*r,*rl;
	RBTreeRank tmp;
	if(t->right==NULL){
		return(1);
	}
	tmp=t->rank;
	//�̶��ڵ� 
	p=t->parent;
	r=t->right;
	rl=t->right->left;
	//����
	//������ڵ�
	if(rl!=NULL){
		rl->parent=t; 
		rl->rank=right;
	}
	//�����ڵ� 
	t->right=rl;
	t->parent=r;
	t->rank=left;
	//�����ӽڵ�
	r->left=t;
	r->parent=p;
	r->rank=tmp; 
	//�������ڵ� 
	if(tmp==left){
		p->left=r;
	}
	else if(tmp==right){
		p->right=r;
	}
	else{
		treeroot=r;
	}
	return(0);
}
int RBTreeRightRotate(RBTree *&treeroot,RBTree *t){
	//�����ڵ�t���ɹ�����0�������������1 
	RBTree *p,*l,*lr;
	RBTreeRank tmp;
	if(t->left==NULL){
		return(1);
	}
	tmp=t->rank;
	//�̶��ڵ� 
	p=t->parent;
	l=t->left;
	lr=t->left->right;
	//����
	//������ڵ�
	if(lr!=NULL){
		lr->parent=t; 
		lr->rank=left;
	}
	//�����ڵ� 
	t->left=lr;
	t->parent=l;
	t->rank=right;
	//�����ӽڵ�
	l->right=t;
	l->parent=p;
	l->rank=tmp; 
	//�������ڵ� 
	if(tmp==right){
		p->right=l;
	}
	else if(tmp==left){
		p->left=l;
	}
	else{
		treeroot=l;
	}
	return(0);
}
void RBTreeInsertFix(RBTree *&treeroot,RBTree *p){
	//�������
	if(p->rank==root){
		p->color=black;
		return;
	}
	if(p->parent->color==black){
		return;
	}
	else if(p->parent->rank==left){
		//case1
		if(p->parent->parent->right!=NULL&&p->parent->parent->right->color==red){
			p->parent->color=black;
			p->parent->parent->right->color=black;
			p->parent->parent->color=red;
			RBTreeInsertFix(treeroot,p->parent->parent);
			return;
		}
		if(p->parent->parent->right==NULL||p->parent->parent->right->color==black){
			//case2
			if(p->rank==right){
				RBTreeLeftRotate(treeroot,p->parent);
				p=p->left;
			}
			//case3
			p->parent->color=black;
			p->parent->parent->color=red;
			RBTreeRightRotate(treeroot,p->parent->parent);
			return;
		}
	}
	else if(p->parent->rank==right){
		//case4
		if(p->parent->parent->left!=NULL&&p->parent->parent->left->color==red){
			p->parent->color=black;
			p->parent->parent->left->color=black;
			p->parent->parent->color=red;
			RBTreeInsertFix(treeroot,p->parent->parent);
			return;
		}
		if(p->parent->parent->left==NULL||p->parent->parent->left->color==black){
			//case5
			if(p->rank==left){
				RBTreeRightRotate(treeroot,p->parent);
				p=p->right;
			}
			//case6
			p->parent->color=black;
			p->parent->parent->color=red;
			RBTreeLeftRotate(treeroot,p->parent->parent);
			return;
		}
	}
}
int RBTreeInsert(RBTree *&t,RBTreeElemType e){
	//����ڵ㣬�ɹ�����0���ظ��ڵ㷵��1 
	RBTree *tmp,*pretmp,*p;
	tmp=t;
	p=(RBTree *)malloc(sizeof(RBTree));
	p->data=e;
	p->color=red;
	p->left=NULL;
	p->right=NULL;
	if(t==NULL){
		p->color=black;
		p->rank=root;
		p->parent=NULL;
		t=p;
		return(0);
	}
	//��λ
	do{
		if(e.index<tmp->data.index){
			pretmp=tmp;
			tmp=tmp->left;
		}
		else if(e.index>tmp->data.index){
			pretmp=tmp;
			tmp=tmp->right;
		}
		else{
			return(1);
		}
	}while(tmp!=NULL);
	//����
	if(e.index<pretmp->data.index){
		pretmp->left=p;
		p->parent=pretmp;
		p->rank=left;
	}
	else if(e.index>pretmp->data.index){
		pretmp->right=p;
		p->parent=pretmp;
		p->rank=right;
	}
	//����
	RBTreeInsertFix(t,p);
	return(0);
}
void RBTreeDeleteFix(RBTree *&treeroot,RBTree *p){
	//����ڵ㣬�ɹ�����0��û�нڵ㷵��1 
	if(p->rank==root){
		p->color=black;
		return;
	}
	if(p->rank==left){
		//case1
		if(p->parent->right!=NULL&&p->parent->right->color==red){
			p->parent->right->color=black;
			p->parent->color=red;
			RBTreeLeftRotate(treeroot,p->parent);
		}
		if(p->parent->right!=NULL&&p->parent->right->color==black){
			//case2
			if((p->parent->right->left==NULL||p->parent->right->left->color==black)&&(p->parent->right->right==NULL||p->parent->right->right->color==black)){
				p->parent->right->color=red;
				RBTreeDeleteFix(treeroot,p->parent);
				return;
			}
			//case3
			if(p->parent->right->left!=NULL&&p->parent->right->left->color==red&&(p->parent->right->right==NULL||p->parent->right->right->color==black)){
				p->parent->right->left->color=black;
				p->parent->right->color=red;
				RBTreeRightRotate(treeroot,p->parent->right);
			}
			//case4
			if(p->parent->right!=NULL&&p->parent->right->right->color==red){
				p->parent->right->color=p->parent->color;
				p->parent->color=black;
				p->parent->right->right->color=black;
				RBTreeLeftRotate(treeroot,p->parent);
				return;
			}
		}
	}
	else if(p->rank==right){
		//case5
		if(p->parent->left->color==red){
			p->parent->left->color=black;
			p->parent->color=red;
			RBTreeRightRotate(treeroot,p->parent);
		}
		if(p->parent->left->color==black){
			//case6
			if((p->parent->left->right==NULL||p->parent->left->right->color==black)&&(p->parent->left->left==NULL||p->parent->left->left->color==black)){
				p->parent->left->color=red;
				RBTreeDeleteFix(treeroot,p->parent);
				return;
			}
			//case7
			if(p->parent->left->right!=NULL&&p->parent->left->right->color==red&&(p->parent->left->left==NULL||p->parent->left->left->color==black)){
				p->parent->left->right->color=black;
				p->parent->left->color=red;
				RBTreeLeftRotate(treeroot,p->parent->left);
			}
			//case8
			if(p->parent->left!=NULL&&p->parent->left->left->color==red){
				p->parent->left->color=p->parent->color;
				p->parent->color=black;
				p->parent->left->left->color=black;
				RBTreeRightRotate(treeroot,p->parent);
				return;
			}
		}
	}
	else if(p->rank==root){
		p->color=black;
		return;
	}
}
int RBTreeDelete(RBTree *&t,int index,RBTreeElemType &e){
	//����ڵ㣬�ɹ�����0��û�нڵ㷵��1 
	RBTree *tmp,*pretmp;
	RBTreeColor tmpc;
	tmp=t;
	if(t==NULL){
 		return(1);
	}
	//��λ
	do{
		if(index<tmp->data.index){
			tmp=tmp->left;
		}
		else if(index>tmp->data.index){
			tmp=tmp->right;
		}
		else{
			break;
		}
	}while(tmp!=NULL);
	if(tmp==NULL){
		return(2);
	}
	e=tmp->data;
	//ɾ����pretmp���汻ɾ���ڵ� 
	pretmp=tmp;
	//��֤��ɾ���ڵ��п��ӽڵ� 
	if(tmp->left!=NULL&&tmp->right!=NULL){
		if(rand()%2==0){
			tmp=tmp->right;
			while(tmp->left!=NULL){
				tmp=tmp->left;
			}
			pretmp->data=tmp->data;
		} 
		else{
			tmp=tmp->left;
			while(tmp->right!=NULL){
				tmp=tmp->right;
			}
			pretmp->data=tmp->data;
		}
	}
	pretmp=tmp;
	//��ɾ���ڵ���Ҷ�� 
	if(tmp->left==NULL&&tmp->right==NULL){
		//����Ǹ� 
		if(tmp->rank==root){
			free(tmp);
			t=NULL;
			return(0); 
		}
		if(tmp->color==red){
			if(tmp->rank==left){
				tmp->parent->left=NULL;
			}
			else if(tmp->rank==right){
				tmp->parent->right=NULL;
			}
			free(tmp);
			return(0);
		}
		else if(tmp->color==black){
			if(tmp->rank==left){
				tmp->parent->left=NULL;
			}
			else if(tmp->rank==right){
				tmp->parent->right=NULL;
			}
			tmp=pretmp->parent;
			free(pretmp);
			//Ȼ����Ҫ���� 
		}
	}
	//��ɾ���ڵ�����ڵ� 
	else if(tmp->left!=NULL){
		if(tmp->rank==left){
			tmp->parent->left=tmp->left;
			tmp->parent->left->color=black;
			tmp->left->rank=left;
			tmp->left->parent=tmp->parent; 
		}
		else if(tmp->rank==right){
			tmp->parent->right=tmp->left;
			tmp->parent->right->color=black;
			tmp->left->rank=right;
			tmp->left->parent=tmp->parent; 
		}
		tmpc=tmp->color;
		free(tmp);
		//��ɾ���ӽڵ�죬ֱ�ӷ��أ���������� 
		if(tmpc==red){
			return(0);
		}
	}
	//��ɾ���ڵ����ҽڵ� 
	else if(tmp->right!=NULL){
		if(tmp->rank==right){
			tmp->parent->right=tmp->right;
			tmp->parent->right->color=black;
			tmp->right->rank=right;
			tmp->right->parent=tmp->parent; 
		}
		else if(tmp->rank==left){
			tmp->parent->left=tmp->right;
			tmp->parent->left->color=black;
			tmp->right->rank=left;
			tmp->right->parent=tmp->parent; 
		}
		tmpc=tmp->color;
		free(tmp);
		//��ɾ���ӽڵ�죬ֱ�ӷ��أ���������� 
		if(tmpc==red){
			return(0);
		}
	}
	//����
	RBTreeDeleteFix(t,tmp);
	return(0);
}
int RBTreeFind(RBTree *&t,int index,RBTreeElemType &e){
	//����t��indexλ�õ�Ԫ�ز��������򡣳ɹ�����0��������Ԫ�ط���1 
	RBTree *tmp;
	tmp=t;
	do{
		if(index==tmp->data.index){
			e=tmp->data;
			return(0);
		}
		else if(index>tmp->data.index){
			tmp=tmp->right;
		}
		else if(index<tmp->data.index){
			tmp=tmp->left;
		}
	}while(tmp!=NULL);
	if(tmp==NULL){
		return(1);
	}
}
#endif
