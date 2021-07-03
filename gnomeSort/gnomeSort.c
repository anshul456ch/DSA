#include<stdio.h>
#include<stdlib.h>
int main()
{
int *x;
int req,y,g;
printf("Enter your requirement :");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement\n");
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Unable to allocate memory for %d numbers\n",req);
return 0;
}
for(y=0;y<req;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}

y=0;
while(y<req)
{
if(y==0) y++;
if(x[y]>=x[y-1]) y++;
else
{
g=x[y];
x[y]=x[y-1];
x[y-1]=g;
y--;
}
}
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}