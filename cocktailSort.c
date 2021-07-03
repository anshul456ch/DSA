#include<stdio.h>
int main()
{
int x[10],y,si,ei,g,e,f,flag=1;
for(y=0;y<=9;y++)
{
printf("Enter the number : ");
scanf("%d",&x[y]);
}
si=0;
ei=9;
while(flag>=1)
{
flag=0;
e=si;
f=ei;
while(e<ei)
{
f=e+1;
if(x[e]>x[f])
{
g=x[e];
x[e]=x[f];
x[f]=g;
flag++;
}
e++;
}
while(f>si)
{
e=f-1;
if(x[e]>x[f])
{
g=x[e];
x[e]=x[f];
x[f]=g;
flag++;
}
f--;
}
si++;
ei--;
}

for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}