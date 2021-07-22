//DRAW.h
#ifndef __DRAW_H
#define __DRAW_H
//这是用于下翻转棋的操作，部分代码借鉴于同学，使用时请手动修改LINE定义 
//由于赶工繁忙，可能有些许bug，对此本人深感抱歉。如有建设性建议，可通过QQ：1345578933联系（麻治昊，20210612于中国科学技术大学） 
#include<stdio.h>
//棋盘行列，必须是偶数 
#define LINE 8
//白方先行 
#define WHITE 1
#define BLACK -1
//棋盘 
int map[LINE][LINE]={0};
int Rev(int x){
	//反转棋子 
	return(-x);
}
void MapInit() {
	//棋盘初始化 
	map[LINE/2-1][LINE/2-1]=BLACK;
	map[LINE/2-1][LINE/2]=WHITE;
	map[LINE/2][LINE/2-1]=WHITE;
	map[LINE/2][LINE/2]=BLACK;
}
void PrintMap(){
	//打印棋盘 
	int flag1,flag2;
	for(flag1=0;flag1<LINE;flag1++){
		for(flag2=0;flag2<LINE;flag2++){
			if(map[flag1][flag2]==NULL){
				printf("   |");
			}
			else if(map[flag1][flag2]==WHITE){
				printf(" O |");
			}
			else if(map[flag1][flag2]==BLACK){
				printf(" X |");
			}
		}
		printf("\n\n");
	}
}
bool ValidStep(int map[LINE][LINE],int x,int y,int col){
	//判断下的位置是否合法 
	int i,j,op;
	op=Rev(col);
	if(map[x][y]!=NULL||x>=LINE||x<0||y>=LINE||y<0){
		return false;
	}
	j=y+1;
	while(j<LINE-1&&map[x][j]==op){
		j++;
		if(map[x][j]==col){
			return true;
		}
	}
	j=y-1;
	while(j>0&&map[x][j]==op){
		j--;
		if(map[x][j]==col){
			return true;
		}
	}
	i=x+1;
	while(i<LINE-1&&map[i][y]==op){
		i++;
		if(map[i][y]==col){
			return true;
		}
	}
	i=x-1;
	while(i>0&&map[i][y]==op){
		i--;
		if(map[i][y]==col){
			return true;
		}
	}
	i=x+1;
	j=y-1;
	while(i<LINE-1&&j>0&&map[i][j]==op){
		i++;
		j--;
		if(map[i][j]==col){
			return true;
		}
	}
	i=x+1;
	j=y+1;
	while(i<LINE-1&&j<LINE-1&&map[i][j]==op){
		i++;
		j++;
		if(map[i][j]==col){
			return true;
		}
	}
	i=x-1;
	j=y+1;
	while(i>0&&j<LINE-1&&map[i][j]==op){
		i--;
		j++;
		if(map[i][j]==col){
			return true;
		}
	}
	i=x-1;
	j=y-1;
	while(i>0&&j>0&&map[i][j]==op){
		i--;
		j--;
		if(map[i][j]==col){
			return true;
		}
	}
	return false;
}
bool DrawIn(int map[LINE][LINE],int x,int y,int col){
	//判断所下位置是否合法并开启反转 
	int op,flag,i,j,a,b;
	if(map[x][y]!=NULL||x>=LINE||x<0||y>=LINE||y<0){
		return false;
	}
	op=Rev(col);
	flag=false;
	j=y+1;
	while(j<LINE-1&&map[x][j]==op){
		j++;
		if (map[x][j]==col){
			for(b=y+1;b<j;b++)
				map[x][b]=col;
			flag=true;
			break;
		}
	}
	j=y-1;
	while(j>0&&map[x][j]==op){
		j--;
		if(map[x][j]==col){
			for(b=y-1;b>j;b--){
				map[x][b] = col;
			}
			flag=true;
			break;
		}
	}
	i=x+1;
	while(i<LINE-1&&map[i][y]==op){
		i++;
		if (map[i][y]==col){
			for(a=x+1;a<i;a++){
				map[a][y]=col;
			}
			flag=true;
			break;
		}
	}
	i=x-1;
	while(i>0&&map[i][y]==op){
		i--;
		if(map[i][y]==col){
			for(a=x-1;a>i;a--)
				map[a][y]=col;
			flag=true;
			break;
		}
	}
	i=x+1;
	j=y-1;
	while(i<LINE-1&&j>0&&map[i][j]==op){
		i++;
		j--;
		if(map[i][j]==col){
			for(a=x+1,b=y-1;a<i&&b>j;a++,b--)
				map[a][b]=col;
			flag=true;
			break;
		}
	}
	i=x+1;
	j=y+1;
	while(i<LINE-1&&j<LINE-1&&map[i][j]==op){
		i++;
		j++;
		if(map[i][j]==col){
			for(a=x+1,b=y+1;a<i&&b<j;a++,b++){
				map[a][b] = col;
			}
			flag=true;
			break;
		}
	}
	i=x-1;
	j=y+1;
	while(i>0&&j<LINE-1&&map[i][j]==op){
		i--;
		j++;
		if(map[i][j]==col){
			for(a=x-1,b=y+1;a>i&&b<j;a--,b++){
				map[a][b] = col;
			}
			flag=true;
			break;
		}
	}
	i=x-1;
	j=y-1;
	while(i>0&&j>0&&map[i][j]==op){
		i--;
		j--;
		if(map[i][j]==col){
			for(a=x-1,b=y-1;a>i&&b>j;a--,b--){
				map[a][b]=col;
			} 
			flag=true;
			break;
		}
	}
	if(!flag){
		return false;
	}
	map[x][y]=col;
	return true;
}
bool AbleDraw(int map[LINE][LINE],int col){
	//判断可否进行下棋 
	int i,j; 
	for(i=0;i<LINE;i++){
		for(j=0;j<LINE;j++){
			if(ValidStep(map,i,j,col)){
				return true;
			}
		}
	}
	return false;
}
void Human(int colour){
	int x,y;
	printf("请下棋，输入格式：<x y>，先输入行号后输入列号\n");
	scanf("%d %d",&x,&y);
	while(DrawIn(map,x-1,y-1,colour)==0){
		printf("非法输入\n");
		scanf("%d %d",&x,&y);
	}
}
bool End(){
	//判断游戏结束 
	if(!AbleDraw(map,BLACK)||!AbleDraw(map,WHITE)){
		return true;
	}
	return false;
}
int FindWin(int map[LINE][LINE]){
	//找获胜方 
	int i,j,x,y;
	i=0;
	j=0;
	x=0;
	y=0;
	for(;x<LINE;x++){
		for(y=0;y<LINE;y++) {
			if(map[x][y]==WHITE){
				i++;
			}
			if(map[x][y]==BLACK){
				j++;
			}
		}
	}
	return(i-j);
}
#endif
