#include<stdio.h>
#include<stdlib.h>
int main()
{
int x[10],e,f,*z,y,largest;
for(y=0;y<=9;y++)
{
printf("Enter the number : ");
scanf("%d",&x[y]);
}
largest=x[0];
y=1;
while(y<=9)
{
if(x[y]>largest) 
{
largest=x[y];
}
y++;
}
z=(int *)malloc(sizeof(int)*largest);
for(y=0;y<=largest;y++)
{
z[y]=0;
}
y=0;
while(y<=9)
{
e=x[y];
z[e]=z[e]+1;
y++;
}
f=0;
for(y=0;y<=largest;y++)
{
e=z[y];
while(e>0)
{
x[f]=y;
f++;
e--;
}
}
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}