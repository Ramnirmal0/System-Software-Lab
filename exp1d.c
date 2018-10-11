#include<stdio.h>
 
void main()
{
    int burst[20],p[20],waiting[20],turnaround[20],i,j,limit,total=0,pos,temp1,temp2,priority[20],min,temp;
    float avg_wt,avg_tat;
    printf("\n\nChecking average turnaround and waiting time of Priority Scheduling : From Pineapplem3.com \n===================================================================================================\n");
    printf("\n\nEnter number of process : ");
    scanf("%d",&limit);
 
    printf("\n\nInput Burst Time and priorirty of processes \n============================================\n");
    for(i=0;i<limit;i++)
    {
        printf("\nEnter burst time for process %d : ",i+1);
        scanf("%d",&burst[i]);
        p[i]=i+1;
      
       printf("\n Enter the priority for process %d : ",i+1);
       scanf("%d",&priority[i]);
    }
 printf("\nBurst Time and priorirty is succesfully added ! \n===========================================\n \n Processing............\n sorting process according to priority.................................Done!\n\nProcess Updated Succesfully !\n");
 
 for(i=0;i<limit;i++)          // sorting of process according to priority
    {
        pos=i;
        for(j=i+1;j<limit;j++)
        {
            if(priority[j]<priority[pos])
                pos=j;
        }
 
        temp1=burst[i];
        temp2=priority[i];
        burst[i]=burst[pos];
        priority[i]=priority[pos];
        burst[pos]=temp1;
        priority[pos]=temp2;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
        waiting[0]=0;            //waiting time for first process will be zero
 
    //calculate waiting time
    for(i=1;i<limit;i++)
    {
        waiting[i]=0;
        for(j=0;j<i;j++)
            waiting[i]+=burst[j];
 
        total+=waiting[i];
    }
 
    avg_wt=(float)total/limit;      //average waiting time
    total=0;
 printf("\n\n calculating Waiting time and Turn around time.....................\n===================================================================\n\n");
    printf("\nProcess\t  |  Burst Time    \t|  Waiting Time\t|  Turnaround Time\n\n");
    for(i=0;i<limit;i++)
    {
        turnaround[i]=burst[i]+waiting[i];     //calculate turnaround time
        total+=turnaround[i];
        printf("\nprocess %d\t\t  %d\t\t    %d\t\t\t%d",p[i],burst[i],waiting[i],turnaround[i]);
    }
 printf("\n\n===========================================================================================\n\n Calculating Average.......Done!\n\n");
    avg_tat=(float)total/limit;     //average turnaround time
    printf("\n\nAverage Waiting Time= %f",avg_wt);
    printf("\nAverage Turnaround Time= %f\n",avg_tat);
    printf("\n\nSucess!!\n\n===========================================================================================================\n\nProgram Ends\nDeveloped and compiled : pineapplem3.com\n\n\n");
}
