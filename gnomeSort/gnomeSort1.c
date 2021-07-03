#include<stdio.h>
int main()
{
int x[10],y,g;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
y=0;
while(y<=9)
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
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}