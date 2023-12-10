//assignment 3 question 2

#include <stdio.h>

void merge(int a[],int b[],int m,int n,int x);

int main()
{
    int a[10000],b[10000];
    int i,m,n,x;
    
    scanf("%d",&m);
    scanf("%d",&n);
    
    for(i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    
    scanf("%d",&x);
    
    merge(a,b,m,n,x);
}

void merge(int a[],int b[],int m,int n,int x)
{
    int c[20000];
    int i=0,j=0,k=0;//two different sorted arrays to be merged into a single sorted array,so all indices start from 0 
    
    while(i<m && j<n)
    {
        if(a[i]<b[j])
        {
            c[k]=a[i];
            i++;
        }
        
        else
        {
            c[k]=b[j];
            j++;
        }
        k++;
    }
    
    while(i<m)
    {
        c[k]=a[i];
        i++;
        k++;
    }
    
    while(j<n)
    {
        c[k]=b[j];
        j++;
        k++;
    }
    
    for(k=0;k<n+m;k++)
    {
        if(c[k]==x)
        {
            printf("%d",k);
            break;
        }
    }
    
    if(k==(n+m))
    {
        printf("-1");
    }
}