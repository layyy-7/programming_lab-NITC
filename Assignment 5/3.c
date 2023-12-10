#include <stdio.h>
#include <stdlib.h>

struct element
{
    long k;
    struct element *next;
    struct element *prev;
};

typedef struct element node;
node *head=NULL;

node *create_node(long key);
void list_insert_first(node *new,long key);
void list_insert_last(node *new,long key);
void list_delete_first();
void list_delete_last();
node *locate();
void list_insert_after(node *new,long key,long n);
void list_insert_before(node *new,long key,long n);
void list_delete(long n);
node *list_search(long n);
void print_reverse(long n);
//void print_list();

int main()
{
    char c;
    long key,n;
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
            
            case 'i':
            if(head!=NULL)
            {
                list_delete_first();
            }
            else
            {
                printf("NULL\n");
            }
            break;
            
            case 'l':
            if(head!=NULL)
            {
                list_delete_last();
            }
            else
            {
                printf("NULL\n");
            }
            break;
            
            case 'a':
            scanf("%ld",&key);
            scanf("%ld",&n);
            if(head!=NULL)
            {
                new=create_node(key);
                list_insert_after(new,key,n);
            }
            else
            {
                printf("NULL\n");
            }
            break;
            
            case 'b':
            scanf("%ld",&key);
            scanf("%ld",&n);
            if(head!=NULL)
            {
                new=create_node(key);
                list_insert_before(new,key,n);
            }
            else
            {
                printf("NULL\n");
            }
            break;
            
            case 'd':
            scanf("%ld",&n);
            if(head!=NULL)
            {
                list_delete(n);
            }
            else
            {
                printf("NULL\n");
            }
            break;
            
            case 'r':
            scanf("%ld",&n);
            if(head!=NULL)
            {
                print_reverse(n);
            }
            else
            {
                printf("NULL\n");
            }
            break;
            
            //case 'p':
            //if(head!=NULL)
            //{
            //    print_list();
            //}
            //else
            //{
            //    printf("NULL\n");
            //}
            //break;
            
            case 'e':
            return 0;
        }
    }
}

node *create_node(long key)
{
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

void list_delete_first()
{
    node *tag;
    
    printf("%ld\n",head->k);

    tag=head->next;
    free(head);
    head=tag;
    
    //this is imp,if you write without condition head!=NULL it will terminate the program when head becomes null
    if(head!=NULL)
    {
        head->prev=NULL;
    }
    
    return;
}

void list_delete_last()
{
    node *tag;
    
    if(head->next==NULL)
    {
        printf("%ld\n",head->k);
        
        head=NULL;
        
        return;
    }
    
    else
    {
        tag=locate();
        printf("%ld\n",tag->k);
        
        tag->prev->next=NULL;
        free(tag);
        
        return;
    }
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

void list_insert_after(node *new,long key,long n)
{
    node *tag;
    
    tag=list_search(n);
    
    if(tag==NULL)
    {
        printf("ABSENT\n");
    }
    
    else
    {
        if(tag->next!=NULL)
        {
            tag->next->prev=new;
        }
        
        new->next=tag->next;
        tag->next=new;
        new->prev=tag;
    }
        
    return;
}

void list_insert_before(node *new,long key,long n)
{
    node *tag;
    
    tag=list_search(n);
    
    if(tag==NULL)
    {
        printf("ABSENT\n");
    }
    
    else
    {
        if(tag->prev==NULL)
        {
            head=new;
        }
        
        else
        {
            tag->prev->next=new;
        }
        
        new->prev=tag->prev;
        new->next=tag;
        tag->prev=new;
    }
        
    return;
}

void list_delete(long n)
{
    node *tag;
    
    tag=list_search(n);
    
    if(tag==NULL)
    {
        printf("ABSENT\n");
    }
    
    else
    {
        if(tag->prev!=NULL)
        {
            printf("%ld\n",tag->prev->k);
        }
        
        else
        {
            printf("FIRST\n");
        }
        
        if(tag->prev==NULL)
        {
            head=tag->next;
        }
        
        if(tag->next!=NULL)
        {
            tag->next->prev=tag->prev;
        }
        
        if(tag->prev!=NULL)
        {
            tag->prev->next=tag->next;
        }
        
        free(tag);
    }
    
    return;
}

node *list_search(long n)
{
    node *tag;
    tag=head;
    
    while(tag->k!=n)
    {
        if(tag->next==NULL)
        {
            return NULL;
        }
        
        tag=tag->next;
    }
    
    return tag;
}

void print_reverse(long n)
{
    node *tag;
    
    tag=list_search(n);
    
    if(tag==NULL)
    {
        printf("ABSENT\n");
    }
    
    else
    {
        while(tag->prev!=NULL)
        {
            printf("%ld ",tag->k);
            tag=tag->prev;
        }
        
        printf("%ld\n",tag->k);
    }
}

//void print_list()
//{
//    node *tag;
//    tag=head;
//    
//    while(tag->next!=NULL)
//    {
//        printf("%ld ",tag->k);
//        tag=tag->next;
//    }
//    
//    printf("%ld\n",tag->k);
//}