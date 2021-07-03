#include<stdio.h>
int main()
{
int x[10],y,swap,z,g;
for(y=0;y<=9;y++)
{
printf("Enter the number : ");
scanf("%d",&x[y]);
}

swap=1;
while(swap!=0)
{
y=0;

for(z=1;z<9;z+=2)
{
if(x[z]>x[z+1])
{
g=x[z];
x[z]=x[z+1];
x[z+1]=g;
y++;
}
}

for(z=0;z<9;z+=2)
{
if(x[z]>x[z+1])
{
g=x[z];
x[z]=x[z+1];
x[z+1]=g;
y++;
}
}

if(y==0) swap=0;
}

for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}