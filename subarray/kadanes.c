#include<stdio.h>
#include<stdlib.h>
int main()
{
int *x;
int req,y;
int localMax,globalMax;
printf("Enter size of array : ");
scanf("%d",&req);
x=(int *)malloc (sizeof(int)*req);
for(y=0;y<req;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
localMax=x[0];
globalMax=x[0];
for(y=1;y<req;y++)
{
if(localMax>=0)
{
localMax+=x[y];
}
else
{
localMax=x[y];
}
if(localMax>globalMax)
{
globalMax=localMax;
}
}
printf("Max of largest continues subarray is : %d",globalMax);
free(x);
return 0;
}