#include<stdio.h>
int main()
{
int x[10],tmp[10],y,i,z,largest,size;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
for(size=9;size>0;size--)
{
for(largest=0,y=1;y<=size;y++)
{
if(x[y]>x[largest]) largest=y;
}
if(largest!=size)
{
for(z=largest,i=0;i<=largest;z--,i++) tmp[i]=x[z];
for(i=0;i<=largest;i++) x[i]=tmp[i];
for(i=0,z=size;i<=size;i++,z--) tmp[i]=x[z];
for(i=0;i<=size;i++) x[i]=tmp[i];
}
}
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
}