#include<stdio.h>
int main()
{
int x[10],g,y,z;
bool swap;
swap=false;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}

while(!swap)
{
swap=true;
for(z=1;z<9;z+=2)
{
if(x[z]>x[z+1])
{
g=x[z];
x[z]=x[z+1];
x[z+1]=g;
swap=false;
}
}

for(z=0;z<9;z+=2)
{
if(x[z]>x[z+1])
{
g=x[z];
x[z]=x[z+1];
x[z+1]=g;
swap=false;
}
}

}
for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}