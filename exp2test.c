//Bankers algorithm for deadlock avaoidance
#include<stdio.h>
int current[5][5],maximum_claim[5][5],available[5];
int allocation[5]={0,0,0,0,0};
int maxres[5],running[5],safe=0;
int counter=0,i,j,exec,resources,processes ,k=1;
int main()
{
printf("Enter no.of process ");
scanf("%d",&processes);
for(i=0;i<processes;i++)
{
running[i]=1;
counter++;
}
printf("\n Enter no.of resources:");
scanf("%d",&resources);
printf("\n Enter claim vactor:");
for(i=0;i<resources;i++)
{
scanf("%d",&maxres[i]);
}
printf("Enter allocated resource table :");
for(i=0;i<processes;i++)
{
for(j=0;j<resources;j++)
{
scanf("%d",&current[i][j]);
}
}
printf("enter maximum claim table : ");
for(i=0;i<processes;i++)
{
for(j=0;j<resources;j++)
{
scanf("%d",&maximum_claim[i][j]);
}
}
printf("the claim vector is :");
for(i=0;i<resources;i++)
{
printf("%d",maxres[i]);
}
printf("the allocated resource table :");
for(i=0;i<processes;i++)
{
for(j=0;j<resources;j++)
{
printf("%d",current[i][j]);
}
printf("\n");
}
printf("the manximum claim table:");
for(i=0;i<processes;i++)
{
for(j=0;j<resources;j++)
{
printf("%d",maximum_claim[i][j]);
}
printf("\n");
}
for(i=0;i<processes;i++)
{
for(j=0;j<resources;j++)
{
allocation[j]+=current[i][j];
}
}
printf("\nallocated resources:");
for(i=0;i<resources;i++)
{
printf("\t%d",allocation[i]);
}
for (i=0;i<resources;i++)
{
available[i]=maxres[i]-allocation[i];
}
printf("\navaialable resources :");
for(i=0;i<resources;i++)
{
printf("\t%d",available[i]);
}
printf("\n");
while (counter!=0)
{
safe=0;
for(i=0;i<processes;i++)
{
if(running[i])
{
exec=1;
for(j=0;j<resources;j++)
{
if (maximum_claim[i][j]-current[i][j]>available[j]);
{
exec=0;
break;
}
}
if (exec)
{
printf("\nprocess %d is executing\n",i+1);
running[i]=0;
counter--;
safe=1;
for(j=0;j<resources;j++)
{
available[j]+=current[i][j];
}
break;
}
}
}
if(!safe)
{
printf("\nthe process are unsafe state\n ");
break;
}
else
{
printf("\nthe process is safe state ");
printf("\navaialable vector:");
for(i=0;i<resources;i++)
{
printf("\t%d",available[i]);
}
printf("\n");
}
}
return 0;
}
