#include <stdio.h>
#include <stdlib.h>
#define LOW 0
#define HIGH 199

int main(){
int queue[20];
int head, max, q_size, temp, sum,i,j;
int dloc; //location of disk (head) arr
printf("scan disk algorithm\n\n");
printf("%s\t", "Input no of disk locations :");
scanf("%d", &q_size);
printf("%s\t", "Enter initial head position :");
scanf("%d", &head);
printf("%s\n", "Input elements into disk queue \n\n");
for( i=0; i<q_size; i++)
{
printf("Element %d : ",i+1);
scanf("%d", &queue[i]);
}
printf("\n\nSorting the array and add RW into Queue\n\n");
queue[q_size] = head; //add RW head intoqueue
q_size++;
//sort the array
for( i=0; i<q_size;i++)
{
for(j=i; j<q_size; j++)
{
if(queue[i]>queue[j])
{
temp = queue[i];
queue[i] = queue[j];
queue[j] = temp;
}
}
}
max = queue[q_size-1];
//locate head in the queue
for( i=0; i<q_size; i++)
{
    if(head == queue[i])
    {
dloc = i;
break;
}
}
if(abs(head-LOW) <= abs(head-HIGH))
{
for(j=dloc; j>=0; j--)
{
printf("%d --> ",queue[j]);
}
for(j=dloc+1; j<q_size; j++)
{
printf("%d --> ",queue[j]);
}
} else 
{

for(j=dloc+1; j<q_size; j++)
{
printf("%d --> ",queue[j]);
}

for(j=dloc; j>=0; j--)
{
printf("%d --> ",queue[j]);
}
}

sum = head + max;
printf("\ntotal head movement of  cylinders = %d tracks \n\n",sum);
printf("\nEnd of program.\n\n\n");
return 0;
}
