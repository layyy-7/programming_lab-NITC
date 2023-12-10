//assignment 4 question 2

#include <stdio.h>

void heapsort(int a[],int n);
void buildmaxheap(int a[],int heapsize);
void maxheapify(int a[],int i,int heapsize);

int x;

int main()
{
    int i,n;
    int a[1000];
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    heapsort(a,n);

    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    
    printf("\n%d",x);
    
    return 0;
}

void heapsort(int a[],int n)
{
    int swap,heapsize;
    
    heapsize=n;
    buildmaxheap(a,heapsize);
    
    while(heapsize>0)
    {
        swap=a[heapsize-1];
        a[heapsize-1]=a[0];
        a[0]=swap;
        
        heapsize--;
        
        maxheapify(a,0,heapsize);
    }
}

void buildmaxheap(int a[],int heapsize)
{
    int i;
    
    for(i=(heapsize/2)-1;i>=0;i--)
    {
        maxheapify(a,i,heapsize);
    }
}

void maxheapify(int a[],int i,int heapsize)
{
    int left,right;
    int largest,swap;
    
    largest=i;
    left=2*i+1;
    right=2*i+2;
    
    if(a[i]<a[left] && left<heapsize)
    {
        largest=left;
    }
    
    if(left<heapsize)
    {
        x++;
    }
    
    if(a[largest]<a[right] && right<heapsize)
    {
        largest=right;
    }
    
    if(right<heapsize)
    {
        x++;
    }
    
    if(largest!=i)
    {
        swap=a[i];
        a[i]=a[largest];
        a[largest]=swap;
        
        maxheapify(a,largest,heapsize);
    }
}