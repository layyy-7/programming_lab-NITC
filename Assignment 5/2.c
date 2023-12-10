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
node *list_search(node *head,char n);
node *list_insert_after(node *new,char key,char n);
node *list_insert_before(node *new,char key,char n);
node *list_delete(node *head,char n);
void print_list(node *head);

int main()
{
    char c,key,n;
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
            //this is imp,dont call the function if head is NULL
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
            //this is imp,dont call the function if head is NULL
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
            //this is imp,dont call the function if head is NULL
            if(head!=NULL)
            {
                print_list(head);
            }
            else
            {
                printf("NULL\n");
            }
            break;
            
            case 'a':
            scanf(" %c %c",&key,&n);
            //this is imp,dont call the functions if head is NULL(as obviously node with value n will not be found)
            if(head!=NULL)
            {
                new=create_node(key);
                head=list_insert_after(new,key,n);
            }
            else
            {
                printf("NULL\n");
            }
            break;
            
            case 'b':
            scanf(" %c %c",&key,&n);
            //this is imp,dont call the functions if head is NULL(as obviously node with value n will not be found)
            if(head!=NULL)
            {
                new=create_node(key);
                head=list_insert_before(new,key,n);
            }
            else
            {
                printf("NULL\n");
            }
            break;
            
            case 'd':
            scanf(" %c",&n);
            //this is imp,dont call the function if head is NULL(as obviously node with value n will not be found)
            if(head!=NULL)
            {
                head=list_delete(head,n);
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

//new node is created such that its pointer points to NULL
node *create_node(char key)
{
    node *new;
    new=(node *) malloc(sizeof(node));
    
    new->k=key;
    new->next=NULL;
    
    return new;
}

//node is inserted at first position of list
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

//node is inserted at last position of list using locate function
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

//first node is deleted from the list
node *list_delete_first(node *head)
{
    node *temp;
    
    printf("%c\n",head->k);

    temp=head->next;
    free(head);
    head=temp;
    
    return head;
}

//last node is deleted from the list with the help of find function
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

//locates the last node in the list
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

//locates the second last node in the list
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

//inserts a node with value key after a given node with value n with the help of function search
//prints absent if the given value n is not present in the list
node *list_insert_after(node *new,char key,char n)
{
    node *tag;
    
    if(head->next!=NULL)
    {
        if(head->k==n)
        {
            new->next=head->next;
            head->next=new;
        }
        
        else
        {
            tag=list_search(head,n);
            
            if(tag==NULL)
            {
                printf("ABSENT\n");
            }
            
            else
            {
                new->next=tag->next->next;
                tag->next->next=new;

            }
        }
    }
    
    else
    {
        if(head->k==n)
        {
            new->next=head->next;
            head->next=new;
        }
        
        else
        {
            printf("ABSENT\n");
        }
    }
    
    return head;
}

//inserts a node with value key before a given node with value n with the help of function search
//prints absent if the given value n is not present in the list
node *list_insert_before(node *new,char key,char n)
{
    node *tag;
    
    if(head->next!=NULL)
    {
        if(head->k==n)
        {
            head=list_insert_first(new,key);
        }
        
        else
        {
            tag=list_search(head,n);
            
            if(tag==NULL)
            {
                printf("ABSENT\n");
            }
            
            else
            {
                new->next=tag->next;
                tag->next=new;
            }
        }
    }
    
    else
    {
        if(head->k==n)
        {
            head=list_insert_first(new,key);
        }
        
        else
        {
            printf("ABSENT\n");
        }
    }
    
    return head;
}

//deletes the node with value n from the list with the help of function search
//prints absent if the given value n is not present in the list
//prints the value of node after it and prints last if the deleted node was last 
node *list_delete(node *head,char n)
{
    node *tag;
    node *temp;
    
    if(head->next!=NULL)
    {
        if(head->k==n)
        {
            printf("%c\n",head->next->k);
                
            temp=head->next;
            free(head);
            head=temp;
        }
        
        else
        {
            tag=list_search(head,n);
            
            if(tag==NULL)
            {
                printf("ABSENT\n");
            }
            
            else
            {
                if(tag->next->next!=NULL)
                {
                    printf("%c\n",tag->next->next->k);
                        
                    temp=tag->next->next;
                    free(tag->next);
                    tag->next=temp;
                }
                
                else
                {
                    printf("LAST\n");
                    
                    temp=tag->next->next;
                    free(tag->next);
                    tag->next=temp;
                }
            }
        }
    }
    
    //this else is imp,you cannot use if(head->next==NULL)
    //the reason being one node is deleted so both conditions can be satisfied while deleting a single node
    //such case occurs when list has exactly two nodes
    else
    {
        if(head->k==n)
        {
            printf("LAST\n");
                
            temp=head->next;
            free(head);
            head=temp;
        }
        
        else
        {
            printf("ABSENT\n");
        }
    }
    
    return head;
}

//loactes the node before the target node with value n
node *list_search(node *head,char n)
{
    if(head->next->k==n)
    {
        return head;
    }
    
    else
    {
        if(head->next->next==NULL)
        {
            return NULL;
        }
        
        else
        {
            return list_search(head->next,n);
        }
    }
}

//prints the list
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