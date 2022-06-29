#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
typedef enum{F}boolean;// no boolean datatype in C so defined boolean
struct jobs
{
    int waiting_time;
    int burst_time;
    int TAT;
    int priority;
    boolean done;
};
void swap(struct jobs* p1, struct jobs* p2)
{
    struct jobs temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
int main()
{
    int n;
    int time = 0;
    double avgwait = 0;
    double avgtat=0;
    printf("Enter number of processes\n");
    scanf("%d",&n);
    struct jobs process[n];
    for(int i=0; i<n; i++)
    {
        printf("Enter priority of process\n");
        scanf("%d",&process[i].priority);
        printf("Enter burst time of process\n");
        scanf("%d",&process[i].burst_time);
    }
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(process[j].priority<process[j+1].priority)
            {
                swap(&process[j], &process[j+1]);
            }// if priority is same so process with less burst time will execute first.
            else if(process[j].burst_time>process[j+1].burst_time&&process[j].priority==process[j+1].priority)
            {
                swap(&process[j],&process[j+1]);
            }
        }
    }
    // Assuming arrival time of all processes is 0
    for(int i=0; i<n; i++)
    {
        process[i].waiting_time=time;
        time=time+process[i].burst_time;
        process[i].TAT=time;
        process[i].done=true;
        avgtat=avgtat+process[i].TAT;
        avgwait=avgwait+process[i].waiting_time;
    }
    avgwait=avgwait/n;
    avgtat=avgtat/n;
    printf("Execution\t\tWait_time\t\tTurnArounttime\t\t\tpriority\n\n");
    for(int i=0; i<n; i++)
    {
        printf("   %d\t\t\t%d\t\t\t%d\t\t%d\n",process[i].burst_time,process[i].waiting_time,process[i].TAT,process[i].priority);
    }
    printf("\naverage waiting time is %2f\naverage turn around time is %2f",avgwait,avgtat);
}