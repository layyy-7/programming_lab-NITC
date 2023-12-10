//queue using singly linked list
#include <stdio.h>
#include <stdlib.h>

struct element
{
    int data;
    struct element *next;
};

typedef struct element queue;
queue *head=NULL;
queue *tail=NULL;

queue *create(int k)
{
    queue *new;
    new=(queue *) malloc(sizeof(queue));
    
    new->data=k;
    new->next=NULL;
    
    return new;
}

void enqueue(queue *new)
{
    if(tail==NULL)
    {
        tail=new;
    }
    
    else
    {
        tail->next=new;
        tail=new;
    }
    
    //this is imp,forms a new head after whole queue is dequeued
    if(head==NULL)
    {
        head=new;
    }
}

void dequeue()
{
    if(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;        
    }
    
    else
    {
        printf("Empty ");
    }
}

void queueempty()
{
    if(head!=NULL)
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
    queue *new;
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
            enqueue(new);
            break;
            
            case 'd':
            scanf("%d",&k);
            while(k--)
            {
                dequeue();
            }
            printf("\n");
            break;
            
            case 'e':
            queueempty();
            break;
            
            case 't':
            return 0;
        }
    }
}