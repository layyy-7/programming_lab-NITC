#include <stdio.h>
#include <stdlib.h>

struct element
{
    char k;
    struct element *next;
};

typedef struct element node;
node *head=NULL;

node *create_node(char key);
node *list_insert_first(node *new,char key);
node *list_insert_last(node *new,char key);
node *list_delete_first(node *head);
node *list_delete_last(node *head);
node *locate(node *head);
node *find(node *head);
void print_list(node *head);

int main()
{
    char c,key;
    node *new;
    
    while(1)
    {
        scanf("%c",&c);
        
        switch(c)
        {
            case 'f':
            scanf(" %c",&key);
            new=create_node(key);
            head=list_insert_first(new,key);
            break;
            
            case 't':
            scanf(" %c",&key);
            new=create_node(key);
            head=list_insert_last(new,key);
            break;
            
            case 'i':
            if(head!=NULL)
            {
                head=list_delete_first(head);
            }
            else
            {
                printf("NULL\n");
            }
            break;
            
            case 'l':
            if(head!=NULL)
            {
                head=list_delete_last(head);
            }
            else
            {
                printf("NULL\n");
            }
            break;
            
            case 'p':
            if(head!=NULL)
            {
                print_list(head);
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
    
    return 0;
}

node *create_node(char key)
{
    node *new;
    new=(node *) malloc(sizeof(node));
    
    new->k=key;
    new->next=NULL;
    
    return new;
}

node *list_insert_first(node *new,char key)
{
    if(head==NULL)
    {
        head=new;
    }
    
    else
    {
        new->next=head;
        head=new;
    }
    
    return head;
}

node *list_insert_last(node *new,char key)
{
    node *tag;
    
    if(head==NULL)
    {
        head=new;
    }
    
    else
    {
        tag=locate(head);
        tag->next=new;
    }
    
    return head;
}

node *list_delete_first(node *head)
{
    node *temp;
    
    printf("%c\n",head->k);

    temp=head->next;
    free(head);
    head=temp;
    
    return head;
}

node *list_delete_last(node *head)
{
    node *tag;
    node *temp;
    
    if(head->next==NULL)
    {
        printf("%c\n",head->k);
        
        return NULL;
    }
    
    else
    {
        tag=find(head);
        printf("%c\n",tag->next->k);
        
        temp=tag->next->next;
        free(tag->next);
        tag->next=temp;
        
        return head;
    }    
}

node *locate(node *head)
{
    if(head->next==NULL)
    {
        return head;
    }
    
    else
    {
        return locate(head->next);
    }
}

node *find(node *head)
{
    if(head->next->next==NULL)
    {
        return head;
    }
    
    else
    {
        return find(head->next);
    }
}

void print_list(node *head)
{
    if(head->next!=NULL)
    {
        printf("%c ",head->k);
        print_list(head->next);
    }
    
    if(head->next==NULL)
    {
        printf("%c\n",head->k);
    }
}