//assignment 1 question 1 

#include <stdio.h>

long double power(int a,int e);

int main()

{
    int n,e,i;
    long double sum;
    int x[5];
    long double y[5];
    
    scanf("%d",&n);
    scanf("%d",&e);
    
    sum=0;
    
    for(i=4;i>=0;i--)
    {
        x[i]=n%10;
        n=n/10;
        y[i]=power(x[i],e);
        sum+=y[i];
    }
    
    printf("%0.Lf",sum);
} 

long double power(int a,int e)
{
    long double z;
    int i;
    
    z=1;
    
    for(i=1;i<=e;i++)
    {
        z=z*a;
    }
    return z;
}