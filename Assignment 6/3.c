//queue using arrays
#include <stdio.h>

typedef struct
{
    int head;
    int tail;
    int a[100000];
}queue;

queue q;

void enqueue(int k,int n)
{
    if(q.tail==n-1)
    {
        if(q.head==0)
        {
            printf("Full\n");
        }
        
        else
        {
            q.a[q.tail]=k;
            q.tail=0;
        }
    }
    
    else
    {
        if(q.head!=q.tail+1)
        {
            q.a[q.tail]=k;
            q.tail=q.tail+1;
        }
        
        else
        {
            printf("Full\n");
        }
    }
}

void dequeue(int n)
{
    if(q.head!=q.tail)
    {
        printf("%d ",q.a[q.head]);
        
        if(q.head!=n-1)
        {
            q.head=q.head+1;
        }
        
        else
        {
            q.head=0;
        }
    }
    
    else
    {
        printf("Empty ");
    }
}

void queueempty(int n)
{
    if(q.head==q.tail)
    {
        printf("YES\n");
    }
    
    else
    {
        printf("NO\n");
    }
}

void queuefull(int n)
{
    if(q.tail==n-1)
    {
        if(q.head==0)
        {
            printf("YES\n");
        }
        
        else
        {
            printf("NO\n");
        }
    }
    
    else
    {
        if(q.head==q.tail+1)
        {
            printf("YES\n");
        }
        
        else
        {
            printf("NO\n");
        }
    }
}

int main()
{
    int n,k;
    char c;
    
    scanf("%d",&n);
    
    q.head=0;
    q.tail=0;
    
    while(1)
    {
        scanf("%c",&c);
        
        switch(c)
        {
            case 'i':
            scanf("%d",&k);
            enqueue(k,n);
            break;
            
            case 'd':
            scanf("%d",&k);
            while(k--)
            {
                dequeue(n);
            }
            printf("\n");
            break;
            
            case 'e':
            queueempty(n);
            break;
            
            case 'f':
            queuefull(n);
            break;
            
            case 't':
            return 0;
        }
    }
}