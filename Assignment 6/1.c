//stack using arrays
#include <stdio.h>

typedef struct
{
    int top;
    int a[100000];
}stack;

stack s;

void push(int k,int n)
{
    if(s.top<n)
    {
        s.a[s.top]=k;
        s.top=s.top+1;
    }
    
    else
    {
        printf("Full\n");
    }
}

void pop(int n)
{
    if(s.top>0)
    {
        s.top=s.top-1;
        printf("%d ",s.a[s.top]);
    }
    
    else
    {
        printf("Empty ");
    }
}

void stackempty(int n)
{
    if(s.top>0)
    {
        printf("NO\n");
    }
    
    else
    {
        printf("YES\n");
    }
}

void stackfull(int n)
{
    if(s.top<n)
    {
        printf("NO\n");
    }
    
    else
    {
        printf("YES\n");
    }
}

int main()
{
    int n,k;
    char c;
    
    scanf("%d",&n);
    
    s.top=0;
    
    while(1)
    {
        scanf("%c",&c);
        
        switch(c)
        {
            case 'i':
            scanf("%d",&k);
            push(k,n);
            break;
            
            case 'd':
            scanf("%d",&k);
            while(k--)
            {
                pop(n);
            }
            printf("\n");
            break;
            
            case 'e':
            stackempty(n);
            break;
            
            case 'f':
            stackfull(n);
            break;
            
            case 't':
            return 0;
        }
    }
}