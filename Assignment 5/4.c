#include <stdio.h>
#include <stdlib.h>

struct element
{
    long k;
    struct element *prev;
    struct element *next;
};

typedef struct element node;
node *head=NULL;

node *create_node(long key);
void list_insert_first(node *new,long key);
void list_insert_last(node *new,long key);
node *locate();
void print_list(long x,long y);

long count=0;

int main()
{
    char c;
    long key;
    long x,y;
    node *new;
    
    while(1)
    {
        scanf("%c",&c);
        
        switch(c)
        {
            case 'f':
            scanf("%ld",&key);
            new=create_node(key);
            list_insert_first(new,key);
            break;
            
            case 't':
            scanf("%ld",&key);
            new=create_node(key);
            list_insert_last(new,key);
            break;
    
            case 'p':
            scanf("%ld",&x);
            scanf("%ld",&y);
            if(head!=NULL)
            {
                print_list(x,y);
            }
            else
            {
                printf("NULL\n");
            }
            break;
            
            case 'e':
            return 0;
        }
    }
}

node *create_node(long key)
{
    count++;
    
    node *new;
    new=(node *) malloc(sizeof(node));
    
    new->k=key;
    new->next=NULL;
    new->prev=NULL;
    
    return new;
}

void list_insert_first(node *new,long key)
{
    if(head==NULL)
    {
        head=new;
    }
    
    else
    {
        new->next=head;
        head->prev=new;
        head=new;
    }
    
    return;
}

void list_insert_last(node *new,long key)
{
    node *tag;
    
    if(head==NULL)
    {
        head=new;
    }
    
    else
    {
        tag=locate();
        tag->next=new;
        new->prev=tag;
    }
    
    return;
}

node *locate()
{
    node *tag;
    tag=head;
    
    while(tag->next!=NULL)
    {
        tag=tag->next;
    }
    
    return tag;
}

void print_list(long x,long y)
{
    long swap;
    node *tagx,*tagy;
    
    tagx=head;
    tagy=locate();
    
    if(x>count || y>count)
    {
        printf("NULL\n");
    }
    
    else
    {
        while(x!=1)
        {
            tagx=tagx->next;
            x--;
        }
        
        while(y!=1)
        {
            tagy=tagy->prev;
            y--;
        }
        
        swap=tagx->k;
        tagx->k=tagy->k;
        tagy->k=swap;
    }
    
    node *tag;
    tag=locate();
    
    while(tag->prev!=NULL)
    {
        printf("%ld ",tag->k);
        tag=tag->prev;
    }
    
    printf("%ld\n",tag->k);
}