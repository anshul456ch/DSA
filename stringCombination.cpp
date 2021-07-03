#include<iostream>
#include<string.h>
using namespace std;
void swap(char *x,char *y)
{
char g;
g=*x;
*x=*y;
*y=g;
}

void permute(char *a,int l,int r)
{
int i;
if(l==r) cout<<a<<endl;
else
{
for(i=l;i<=r;i++)
{
swap((a+l),(a+i));
permute(a,l+1,r);
swap((a+l),(a+i));
}
}
}

int main()
{
char str[]="ABC";
int n=strlen(str);
permute(str,0,n-1);
return 0;
}