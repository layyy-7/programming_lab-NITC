#include <stdio.h>
#include <stdlib.h>

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

void inorder(bst *tag)
{
    if(tag!=NULL)
    {
        inorder(tag->left);
        printf("%d ",tag->k);
        inorder(tag->right);
    }
}

void preorder(bst *tag)
{
    if(tag!=NULL)
    {
        printf("%d ",tag->k);
        preorder(tag->left);
        preorder(tag->right);
    }
}

void postorder(bst *tag)
{
    if(tag!=NULL)
    {
        postorder(tag->left);
        postorder(tag->right);
        printf("%d ",tag->k);
    }
}

void max(bst *tag)
{
    while(tag->right!=NULL)
    {
        tag=tag->right;
    }
    
    printf("%d\n",tag->k);
}

void min(bst *tag)
{
    while(tag->left!=NULL)
    {
        tag=tag->left;
    }
    
    printf("%d\n",tag->k);
}

void search(bst *tag,int key)
{
    while(tag!=NULL && key!=tag->k)
    {
        if(key<tag->k)
        {
            tag=tag->left;
        }
        
        else
        {
            tag=tag->right;
        }
    }
    
    if(tag==NULL)
    {
        printf("NotFound\n");
    }
    
    else
    {
        printf("Found\n");
    }
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
            case 'a':
            scanf("%d",&key);
            new=create(key);
            insert(new);
            break;
            
            case 's':
            scanf("%d",&key);
            tag=root;
            search(tag,key);
            break;
            
            case 'x':
            if(root==NULL)
            {
                printf("NIL\n");
            }
            else
            {
                tag=root;
                max(tag);
            }
            break;
            
            case 'n':
            if(root==NULL)
            {
                printf("NIL\n");
            }
            else
            {
                tag=root;
                min(tag);
            }
            break;
            
            case 'i':
            if(root==NULL)
            {
                printf("NIL\n");
            }
            else
            {
                tag=root;
                inorder(tag);
                printf("\n");
            }
            break;
            
            case 'p':
            if(root==NULL)
            {
                printf("NIL\n");
            }
            else
            {
                tag=root;
                preorder(tag);
                printf("\n");
            }
            break;
            
            case 't':
            if(root==NULL)
            {
                printf("NIL\n");
            }
            else
            {
                tag=root;
                postorder(tag);
                printf("\n");
            }
            break;
            
            case 'e':
            return 0;
        }
    }
}