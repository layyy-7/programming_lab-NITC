//postfix expression evaluation
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct
{
    int top;
    int a[10000];
}stack;

stack s;

void push(int k)
{
    s.a[s.top]=k;
    s.top=s.top+1;
}

void pop()
{
    if(s.top>0)
    {
        s.top=s.top-1;
    }
}

void evaluatepostfix(char e[])
{
    int i,j,r;
    int x,y,z;
    
    s.top=0;
    
    for(i=0,j=0;e[i]!='\0';i++)
    {
        if(e[i]==' ')
        {
            //converting char to integer(for more than 1 digit numbers)
            //minus '0' is imp or else you will get the the ascii value of char
            if(j>0)
            {
                r=0;
                while(j)
                {
                    r+=(e[i-j]-'0')*(int)pow(10,(double)j-1);
                    j--;
                }
                
                push(r);
            }
            
            j=0;
        }
        
        else if(e[i]>='0' && e[i]<='9')
        {
            //counting digits in the number
            j++;
        }
        
        else
        {
            pop();
            x=s.a[s.top];
            pop();
            y=s.a[s.top];
            
            switch(e[i])
            {
                case '+':
                z=y+x;
                break;
                
                case '-':
                z=y-x;
                break;
                
                case '*':
                z=y*x;
                break;
                
                case '/':
                z=y/x;
                break;
            }
            
            push(z);
        }
    }
    
    printf("%d\n",s.a[s.top-1]);
}

int main()
{
    int n;
    scanf("%d",&n);
    
    while(n--)
    {
        
        char e[10000];
        scanf(" %[^\n]",e);
        
        evaluatepostfix(e);
    }
    
    return 0;
}