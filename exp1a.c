#include <stdio.h>
void main()
{
int i=0,limit,min,arrive[10],burst[10],completetime[10],turnaround[10],waiting[10],b[10],p[10],j;
float avwt=0.0,avta=0.0;
printf("\n\nChecking Turnaround Time and Average of FCFS scheduling | from : pineapplem3.com \n=============================================================================================\n\n");
printf("Enter the number of process : ");
scanf("%d",&limit);
printf("\nEnter the Arrival time and Burst time of processes :\n=================================================\n\n ");
for(i=0;i<limit;i++)
{
printf("\nEnter the arrival time of process %d : ",(i+1));
scanf("%d",&arrive[i]);
printf("\nEnter the burst time of process %d : ",(i+1));
scanf("%d",&burst[i]);
p[i]=i+1;
}
printf("\n\n Arrival Time and Burst Time addded succesfully ! \n=======================================================\n\n");
for (i=0;i<limit;i++)
{ min=i;
for(j=i+1;j<limit;j++)
if(arrive[j]<arrive[min])
min=j;
int temp1=arrive[i];
int temp2=burst[i];
int temp3=p[i];
arrive[i] = arrive[min];
burst[i] = burst[min];
p[i]=p[min];
arrive[min]=temp1;
burst[min]=temp2;
p[min]=temp3;
}
printf("calculating Completion time , Turnaround time , waiting Time ..........................Done.\n\n");

completetime[0]=burst[0]+arrive[0];
for(j=0;j<limit;j++)
{
printf("\n Process %d: ",p[j]);
if(completetime[j]<arrive[j+1])
completetime[j+1]=burst[j+1]+arrive[j+1];
else
completetime[j+1]=burst[j+1]+completetime[j];
turnaround[j]=completetime[j]-arrive[j];
waiting[j]=turnaround[j]-burst[j];
printf("\tcompletion Time of %d\t |",completetime[j]);
printf("\tTurnaround Time of %d\t |",turnaround[j]);
printf("\twaiting Time of %d\t |\n",waiting[j]);
}
printf("\n\nCalculating Average waiting time and Turnaround time..........................Done.\n\n=========================================================================\n\n");
for(i=0;i<limit;i++)
{
avwt=avwt+waiting[i];
avta=avta+turnaround[i];
}
avwt=avwt/3;
avta=avta/3;
printf("average turn around time of %d processes = %f\n ",limit,avta);
printf("average waiting time of %d processes = %f\n",limit,avwt);
printf("\n\nProgram succesfully completed......Congratulation!\n From: Pineapplem3.com\n\nProgram Ends.\n\n\n");
}

