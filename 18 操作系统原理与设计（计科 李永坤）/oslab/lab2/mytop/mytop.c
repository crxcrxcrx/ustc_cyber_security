#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/syscall.h>
#include<linux/sched.h>

struct task_info{
    pid_t pid;
    char comm[16];
    unsigned long long  vruntime;
    unsigned long long  lastvruntime;
    double cpu;
    int is_running;
};

int CompareTask(const void * elem1,const void * elem2)
{
    struct task_info * p1 = (struct task_info *) elem1;
    struct task_info * p2 = (struct task_info *) elem2;
    if (p1->cpu > p2->cpu)
    {
        return -1;
    }
    else if (p1->cpu < p2->cpu)
    {
        return 1;
    }
    else return 0;
}

int main(void)
{
    int num_task;
    struct task_info infos_buffer[128];

    while (1)
    {
        system("clear");
        syscall(548, &num_task, (int *)infos_buffer);
        printf("pid\t\tcomm\t\t\tcpu\t\tis_running\n");
        for (size_t i = 0; i < num_task; i++)
        {
            infos_buffer[i].cpu = (double)(infos_buffer[i].vruntime - infos_buffer[i].lastvruntime) / (double)1000000000.0;
        }
        
        qsort(infos_buffer,num_task,sizeof(struct task_info), CompareTask);
        for (size_t i = 0; i < num_task; i++)
        {
            if (i < 50)
            {
                struct task_info info = infos_buffer[i];
                printf("%d\t\t%s\t\t\t%lf\t\t%d\n", info.pid, info.comm, info.cpu, info.is_running);
            }
        }
        sleep(1);
    }
    
    return 0;
}