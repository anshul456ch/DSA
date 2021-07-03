#include<stdio.h>
int main()
{
int x[20],y,num,mid,si,ei,lb,ub,e;
lb=0;
printf("Enter upper bound :");
scanf("%d",&ub);
if(ub>=19 || ub<=0)
{
printf("Invalid upper bound %d\n",ub);
return 0;
}
for(y=lb;y<=ub;y++)
{
printf("Enter the number : ");
scanf("%d",&x[y]);
}

printf("Enter the number to insert : ");
scanf("%d",&num);
si=lb;
ei=ub;

while(si<=ei)
{
mid=si+(ei-si)/2;
if(x[mid]==num)
{
break;
}
if(x[mid]>num)
{
ei=mid-1;
}
if(x[mid]<num)
{
si=mid+1;
}
}
if(ub<si)
{
x[si]=num;
}
else
{
e=ub;
while(e>=si)
{
x[e+1]=x[e];
e--;
}
x[si]=num;
}
for(y=lb;y<=ub+1;y++)
{
printf("%d\n",x[y]);
}
return 0;
}