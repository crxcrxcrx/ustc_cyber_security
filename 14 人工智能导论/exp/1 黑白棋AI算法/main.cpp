//main.cpp
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include<windows.h>
#include"MTCS.h"
#include"DRAW.h"
#include"MYTIME.h" 
//决定先后手，机0人1 
#define FIRST 0
#define NEXT 0
main(){
	timeval tb,ta,t;
	int err;
	MapInit();
	PrintMap();
	srand(time(NULL));
	while(1){
		if(AbleDraw(map,BLACK)){
			printf("先手执O下棋\n");
			gettimeofday(&tb,0);
#if FIRST==0
			Intelligence(WHITE);
#else
			Human(WHITE);
#endif
			gettimeofday(&ta,0);
			t=TimeDistance(tb,ta);
			printf("用时%lfms\n",(double)(t.tv_sec*1000+t.tv_usec/1000.0));
			if(t.tv_sec>=60){
				printf("超时失败\n");
				exit(1);
			}
			PrintMap();
		}
		if(AbleDraw(map,WHITE)){
			printf("后手执X下棋\n");
			gettimeofday(&tb,0);
#if NEXT==0
			Intelligence(BLACK);
#else
			Human(BLACK);
#endif
			gettimeofday(&ta,0);
			t=TimeDistance(tb,ta);
			printf("用时%lfms\n",(double)(t.tv_sec*1000+t.tv_usec/1000.0));
			if(t.tv_sec>=60){
				printf("超时失败\n");
				exit(1);
			}
			PrintMap();
		}
		if(End()==1){
			printf("游戏结束\n");
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
			break;
		}
	}
}
