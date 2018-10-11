#include<stdio.h> 

int main() 
{ 

int count,j,limit,time,remain,flag=0,time_quantum; 
int wait_time=0,turnaround_time=0,arrival[10],burst[10],rt[10]; 
printf("\n\n\nProgram to find out the Average Turnaround and Waiting Time of Round Robin Scheduling \nwithout arrival time (set arrival time = 0 ) \n\nDeveloped and compiled : Pineapplem3.com\n==============================================================================================\n\n");
printf("\nEnter Number of Process: "); 
scanf("%d",&limit); 
remain=limit; 
printf("\n\nInput Arrival time and Burst time for Processes \n===============================================================\n");
for(count=0;count<limit;count++) 
{ 
printf("\n\nEnter Arrival Time for Process %d : ",count+1); 
scanf("%d",&arrival[count]); 
printf("\n\nEnter Burst Time for Process %d : ",count+1); 
scanf("%d",&burst[count]); 
rt[count]=burst[count]; 
} 
printf("\n\n Arrival Time and Burst time for %d processes added Succesfully !!\n\n============================================================================\n",limit);
printf("\n Enter Time Quantum:\t"); 
scanf("%d",&time_quantum); 
printf("\n\n===================================================================\n\nProcessing.....................DONE !\nCalculating....................DONE !\nDisplaying Result.........................Done ! \n\n");
printf("\n\n Process \t Turnaround Time \t Waiting Time\n\n"); 
for(time=0,count=0;remain!=0;) 
{ 
if(rt[count]<=time_quantum && rt[count]>0) 
{ 
time+=rt[count]; 
rt[count]=0; 
flag=1; 
} 
else if(rt[count]>0) 
{ 
rt[count]-=time_quantum; 
time+=time_quantum; 
} 
if(rt[count]==0 && flag==1) 
{ 
remain--; 
printf("Process %d \t | \t%d\t | \t%d\n",count+1,time-arrival[count],time-arrival[count]-burst[count]); 
wait_time+=time-arrival[count]-burst[count]; 
turnaround_time+=time-arrival[count]; 
flag=0; 
} 
if(count==limit-1) 
count=0; 
else if(arrival[count+1]<=time) 
count++; 
else 
count=0; 
}
printf("\n\n================================================================================\n\nCalculating Average Waiting Time and Turnaround Time for %d Process",limit);
printf("\n\nAverage Waiting Time= %f\n",wait_time*1.0/limit); 
printf("\nAvg Turnaround Time = %f",turnaround_time*1.0/limit); 
printf("\n\n===============================================================================\n\n Program successful !\nDeveloped & Compiled : Pineapplem3.com\n\n\n"); 
return 0; 
}
