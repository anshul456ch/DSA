#include<stdio.h>
#include<stdlib.h>
int findPartitionPoint(int *x,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && x[e]<=x[lb]) e++;
while(x[f]>x[lb]) f--;
if(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
g=x[lb];
x[lb]=x[f];
x[f]=g;
}
}
return f;
}

void quickSort(int *x,int lb,int ub)
{
int pp;
if(ub<=lb) return;
pp=findPartitionPoint(x,lb,ub);
quickSort(x,lb,pp-1);
quickSort(x,pp+1,ub);
}

int main()
{
int *x;
int y,req,k;
printf("Enter your requirement : ");
scanf("%d",&req);
x=(int *)malloc(sizeof(int)*req);
for(y=0;y<req;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}

//logic to find kth smallest number
printf("Enter kth small to find :");
scanf("%d",&k);
quickSort(x,0,req-1);
printf("kth smallest : %d\n",x[k-1]);
free(x);
return 0;
}