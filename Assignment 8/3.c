#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element
{
    int k;
    struct element *left;
    struct element *right;
    struct element *p;
};

typedef struct element bst;
bst *root=NULL;

bst *create(int key)
{
    bst *new;
    new=(bst *) malloc(sizeof(bst));
    
    new->k=key;
    new->left=NULL;
    new->right=NULL;
    new->p=NULL;
    
    return new;
}

void insert(bst *new)
{
    bst *tag1,*tag2;
    tag1=root;
    tag2=NULL;
    
    while(tag1!=NULL)
    {
        tag2=tag1;
        
        if(new->k < tag1->k)
        {
            tag1=tag1->left;
        }
        
        else
        {
            tag1=tag1->right;
        }
    }
    
    new->p=tag2;
    
    if(tag2==NULL)
    {
        root=new;
    }
    
    else if(new->k < tag2->k)
    {
        tag2->left=new;
    }
    
    else
    {
        tag2->right=new;
    }
}

//modification of preorder traversal    
void print(bst *tag)
{
    printf("( ");
    
    if(tag!=NULL)
    {
        printf("%d ",tag->k);
        print(tag->left);
        print(tag->right);
    }
    
    printf(") ");
}

int main()
{
    char c;
    int key;
    bst *new,*tag;
    
    while(1)
    {
        scanf("%c",&c);
        
        switch(c)
        {
            case 'i':
            scanf("%d",&key);
            new=create(key);
            insert(new);
            break;
            
            case 'p':
            tag=root;
            print(tag);
            printf("\n");
            break;
            
            case 'e':
            return 0;
        }
    }
}    