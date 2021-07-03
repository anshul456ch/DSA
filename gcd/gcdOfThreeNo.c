#include<stdio.h>
#include<stdlib.h>
int main()
{
int *x;
int req,y,gcd,z;
printf("Enter requirement : ");
scanf("%d",&req);
x=(int *)malloc(sizeof(int)*req);
for(y=0;y<req;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
gcd=x[0];
z=1;
while(z<req)
{
if(x[z]%gcd==0) z++;
else
{
gcd=x[z]%gcd;
y++;
}
}
printf("GCD is : %d",gcd);
free(x);
return 0;
}