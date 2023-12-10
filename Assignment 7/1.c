//infix to postfix
#include <stdio.h>
#include <string.h>

typedef struct
{
    int top;
    char a[10000];
}stack;

stack s;

void push(char k)
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

void infixtopostfix(char e[])
{
    int i,j,l,c;
    
    l=strlen(e);
    c=0;//count of brackets
    s.top=0;
    
    for(i=0,j=0;e[i]!='\0';i++)
    {
        if(e[i]=='(' || e[i]==')')
        {
            c++;
        }
        
        if(e[i]>='a' && e[i]<='z')
        {
            e[j]=e[i];
            j++;
        }
        
        else if(e[i]=='+' || e[i]=='-' )
        {
            if(s.top==0 || s.a[s.top-1]=='(')
            {
                push(e[i]);
            }
            
            else
            {
                while((s.a[s.top-1]=='+' || s.a[s.top-1]=='-' || s.a[s.top-1]=='*' || s.a[s.top-1]=='/') && s.top!=0)
                {
                    pop();
                    e[j]=s.a[s.top];
                    j++;
                }
                
                push(e[i]);
            }
        }
        
        else if(e[i]=='*' || e[i]=='/')
        {
            if(s.top==0 || s.a[s.top-1]=='+' || s.a[s.top-1]=='-' || s.a[s.top-1]=='(')
            {
                push(e[i]);
            }
            
            else
            {
                while((s.a[s.top-1]=='*' || s.a[s.top-1]=='/') && s.top!=0)
                {
                    pop();
                    e[j]=s.a[s.top];
                    j++;
                }
                
                push(e[i]);
            }
        }
        
        else if(e[i]=='(')
        {
            push(e[i]);
        }
        
        //when e[i]==')'
        else
        {
            while(s.a[s.top-1]!='(')
            {
                pop();
                e[j]=s.a[s.top];
                j++;
            }
            
            //to pop '('
            pop();
        }
    }
    
    //for operators remaining in the stack
    while(j<l-c)
    {
        pop();
        e[j]=s.a[s.top];
        j++;
    }
    
    for(i=0;i<j;i++)
    {
        printf("%c",e[i]);
    }
    
    printf("\n");
}

int main()
{
    int n;
    scanf("%d",&n);
    
    while(n--)
    {
        char e[10000];
        scanf(" %[^\n]",e);
        
        infixtopostfix(e);
    }
    
    return 0;
}