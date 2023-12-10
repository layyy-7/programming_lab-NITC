//assignment 4 question 3

#include <stdio.h>

void heapsort(float a[],int n,int k);
void buildmaxheap(float a[],int heapsize);
void maxheapify(float a[],int i,int heapsize);

int main()
{
    int i,n,k;
    float a[1000];
    
    scanf("%d",&n);
    scanf("%d",&k);
    
    for(i=0;i<n;i++)
    {
        scanf("%f",&a[i]);
    }
    
    heapsort(a,n,k);

    return 0;
}

void heapsort(float a[],int n,int k)
{
    float swap;
    int i,j,x,heapsize;
    
    x=n/k;//total number of groups
    
    heapsize=k;
    
    for(j=1;x>0;j++)
    {
        buildmaxheap(a,heapsize);
        
        printf("%0.2f ",a[0]);
        
        for(i=0;i<k;i++)
        {
            swap=a[i+j*k];
            a[i+j*k]=a[i];
            a[i]=swap;
        }
        
        x--;
    }
}

void buildmaxheap(float a[],int heapsize)
{
    int i;
    
    for(i=heapsize/2;i>=0;i--)
    {
        maxheapify(a,i,heapsize);
    }
}

void maxheapify(float a[],int i,int heapsize)
{
    int left,right,largest;
    float swap;
    
    left=2*i+1;
    right=2*i+2;
    
    if(a[i]<a[left] && left<heapsize)
    {
        largest=left;
    }
    
    else
    {
        largest=i;
    }
    
    if(a[largest]<a[right] && right<heapsize)
    {
        largest=right;
    }
    
    if(largest!=i)
    {
        swap=a[i];
        a[i]=a[largest];
        a[largest]=swap;
        
        maxheapify(a,largest,heapsize);
    }
}