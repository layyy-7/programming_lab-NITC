//stack using singly linked list
#include <stdio.h>
#include <stdlib.h>

struct element
{
    int data;
    struct element *next;
};

typedef struct element stack;
stack *top=NULL;

stack *create(int k)
{
    stack *new;
    new=(stack *) malloc(sizeof(stack));
    
    new->data=k;
    new->next=NULL;
    
    return new;
}

void push(stack *new)
{
    if(top==NULL)
    {
        top=new;
    }
    
    else
    {
        new->next=top;
        top=new;
    }
}

void pop()
{
    if(top!=NULL)
    {
        printf("%d ",top->data);
        top=top->next;        
    }
    
    else
    {
        printf("Empty ");
    }
}

void stackempty()
{
    if(top!=NULL)
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
    stack *new;
    int k;
    char c;
    
    while(1)
    {
        scanf("%c",&c);
        
        switch(c)
        {
            case 'i':
            scanf("%d",&k);
            new=create(k);
            push(new);
            break;
            
            case 'd':
            scanf("%d",&k);
            while(k--)
            {
                pop();
            }
            printf("\n");
            break;
            
            case 'e':
            stackempty();
            break;
            
            case 't':
            return 0;
        }
    }
}