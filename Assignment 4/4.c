//assignment 4 question 4

#include <stdio.h>

void heapsort(int a[],int n,int k);

int main()
{
    int i,k,n;
    int a[1000];
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    scanf("%d",&k);
    
    heapsort(a,n,k);
    return 0;
}
 
void heapsort(int a[],int n,int k)
{
    int i,j,z;
    int swap,heapsize;
    int x[1000];
    
    for(i=0;i<n;i++)
    {
        x[i]=1;
    }
    
    heapsize=n;
    
    for(i=0;i<heapsize;i++)
    {
        for(j=i+1;j<heapsize;j++)
        {
            if(a[i]==a[j])
            {
                for(z=j;z<heapsize-1;z++)
                {
                    a[z]=a[z+1];
                }
                
                j--;
                x[i]++;
                heapsize--;
            }
        }
    }
    
    for(i=1;i<heapsize;i++)
    {
        j=i;
        
        while(j>0 && x[j-1]<x[j])
        {
            swap=a[j];
            a[j]=a[j-1];
            a[j-1]=swap;
            
            swap=x[j];
            x[j]=x[j-1];
            x[j-1]=swap;
            
            j--;
        }
    }
    
    for(i=0;i<k;i++)
    {
        printf("%d ",a[i]);
    }
}