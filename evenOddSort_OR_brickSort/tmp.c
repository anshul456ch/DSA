#include<stdio.h>
int main()
{
int x[10],y,swap,e,g;
for(y=0;y<=9;y++)
{
printf("Enter the number : ");
scanf("%d",&x[y]);
}

swap=1;
while(swap!=0)
{
y=0;
//logic of odd
e=1;
while(y<=9)
{
if(x[e]>x[e+1])
{
g=x[e];
x[e]=x[e+1];
x[e+1]=g;
y++;
}
e+=2;
}
y=0;
//logic of even
e=0;
while(y<=9)
{
if(x[e]>x[e+1])
{
g=x[e];
x[e]=x[e+1];
x[e+1]=g;
y++;
}
e+=2;
}
if(y==0) swap=0;
}

for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}