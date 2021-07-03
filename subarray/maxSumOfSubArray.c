#include<stdio.h>
#include<stdlib.h>
int main()
{
int *x;
int req,y,z,e,f,g,a,b;
printf("Enter size of array : ");
scanf("%d",&req);
x=(int *)malloc (sizeof(int)*req);
for(y=0;y<req;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
g=x[0];
for(e=0;e<req;e++)
{
z=0;
for(f=e;f<req;f++)
{
z=z+x[f];
if(z>g)
{
a=e;
b=f;
g=z;
}
}
}
printf("Range of largest continues subarray is :");
for(y=a;y<=b;y++) printf("%d\t",x[y]);
printf("\nMax of largest continues subarray is : %d",g);
free(x);
return 0;
}