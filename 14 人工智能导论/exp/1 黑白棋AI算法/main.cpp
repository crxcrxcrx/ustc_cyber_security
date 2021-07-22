//main.cpp
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include<windows.h>
#include"MTCS.h"
#include"DRAW.h"
#include"MYTIME.h" 
//�����Ⱥ��֣���0��1 
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
			printf("����ִO����\n");
			gettimeofday(&tb,0);
#if FIRST==0
			Intelligence(WHITE);
#else
			Human(WHITE);
#endif
			gettimeofday(&ta,0);
			t=TimeDistance(tb,ta);
			printf("��ʱ%lfms\n",(double)(t.tv_sec*1000+t.tv_usec/1000.0));
			if(t.tv_sec>=60){
				printf("��ʱʧ��\n");
				exit(1);
			}
			PrintMap();
		}
		if(AbleDraw(map,WHITE)){
			printf("����ִX����\n");
			gettimeofday(&tb,0);
#if NEXT==0
			Intelligence(BLACK);
#else
			Human(BLACK);
#endif
			gettimeofday(&ta,0);
			t=TimeDistance(tb,ta);
			printf("��ʱ%lfms\n",(double)(t.tv_sec*1000+t.tv_usec/1000.0));
			if(t.tv_sec>=60){
				printf("��ʱʧ��\n");
				exit(1);
			}
			PrintMap();
		}
		if(End()==1){
			printf("��Ϸ����\n");
			err=FindWin(map);
			if(err>0){
				printf("����ʤ%d��\n",err);
			}
			else if(err<0){
				printf("����ʤ%d��\n",err);
			}
			else{
				printf("ƽ��\n");
			}
			break;
		}
	}
}
