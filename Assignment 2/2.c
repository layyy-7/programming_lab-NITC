//assignment 2 question 2

#include <stdio.h>

int main()
{
    int k,n,m,x;
    int i,j;
    int a[1000];
    
    scanf("%d",&n);
    scanf("%d",&k);
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    scanf("%d",&x);
    
    int z=0;
    m=n/k;
    
    for(i=0;i<k;i++)
    {
        for(j=i*m;j<(i+1)*m;j++)
        {
            if(a[j]==x)
            {
                z++;
                break;
            }
        }
    }
    
    printf("%d",z);
}