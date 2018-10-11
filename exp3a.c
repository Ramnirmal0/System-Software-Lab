/* Program compiled and developed by : pineapplem3.com . open source code */
#include<stdio.h>
int main()
{
int limit,diskpos,arrival[100],time[100],sum=0,i;
printf("\n\n Program to find the FCFS disk Algorithm : powered by pineapplem3.com (open source code )\n==========================================================================\n\n");
printf("enter the number of location required : ");
scanf("%d",&limit);
printf("enter the Read/write Location Position : ");
scanf("%d",&diskpos);
printf("Insert the %d Disk Queue : ",limit);
for(i=0;i<limit;i++)
{
scanf("%d",&arrival[i]);
time[i]=diskpos-arrival[i];
if(time[i]<0)
{
time[i]=arrival[i]-diskpos;
}
diskpos=arrival[i];
sum=sum+time[i];
}
printf("\n\nThe calculation is as follows :\n");
for(i=0 ; i<limit;i++)
{
printf(" %d + ",time[i]);
}
printf("\n\n Total movement of disk : %d track ",sum);
printf("Find the seek time : ( seekrate = 5 millisecond)\n");
int seektime=sum*5;
printf("\n Seek Time = %d millisecond \n\n",seektime);
}
 
