//assignment 1 question 2

#include <stdio.h>

int main()
{
    int n,m,i;
    
    scanf("%d",&n);
    
    int a[n];
    int b[n];
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    
    scanf("%d",&m);
    
    for(i=0;i<n-m;i++)
    {
        a[i]=b[i+m];
    }
    
    for(i=n-m;i<n;i++)
    {
        a[i]=b[m-n+i];
    }
    
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}