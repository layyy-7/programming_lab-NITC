#include <stdio.h>
#include <stdlib.h>

struct element
{
    int k;
    struct element *left;
    struct element *right;
    struct element *p;
};

typedef struct element *bst;
bst root=NULL;

bst create(int key)
{
    bst new;
    new=(bst) malloc(sizeof(struct element));
    
    new->k=key;
    new->left=NULL;
    new->right=NULL;
    new->p=NULL;
    
    return new;
}

void insert(bst new)
{
    bst tag1,tag2;
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

void preorder(bst tag)
{
    if(tag!=NULL)
    {
        printf("%d ",tag->k);
        preorder(tag->left);
        preorder(tag->right);
    }
}

bst search(bst tag,int key)
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
    
    return tag;
}

void successor(bst tag)
{
    bst tag2;
    
    if(tag->right!=NULL)
    {
        tag2=tag->right;
        
        while(tag2->left!=NULL)
        {
            tag2=tag2->left;
        }
    }
    
    else
    {
        tag2=tag->p;
        
        while(tag2!=NULL && tag==tag2->right)
        {
            tag=tag2;
            tag2=tag2->p;
        }
    }
    
    if(tag2!=NULL)
    {
        printf("%d\n",tag2->k);
    }
    
    else
    {
        printf("NotFound\n");
    }
}

void predecessor(bst tag)
{
    bst tag2;
    
    if(tag->left!=NULL)
    {
        tag2=tag->left;
        
        while(tag2->right!=NULL)
        {
            tag2=tag2->right;
        }
    }
    
    else
    {
        tag2=tag->p;
        
        while(tag2!=NULL && tag==tag2->left)
        {
            tag=tag2;
            tag2=tag2->p;
        }
    }
    
    if(tag2!=NULL)
    {
        printf("%d\n",tag2->k);
    }
    
    else
    {
        printf("NotFound\n");
    }
}

void transplant(bst tag1,bst tag2)
{
    if(tag1->p==NULL)
    {
        root=tag2;
    }
    
    else if(tag1==tag1->p->left)
    {
        tag1->p->left=tag2;
    }
    
    else
    {
        tag1->p->right=tag2;
    }
    
    if(tag2!=NULL)
    {
        tag2->p=tag1->p;
    }
}

void delete(bst tag)
{
    bst tag2;
    
    if(tag->left==NULL)
    {
        transplant(tag,tag->right);
    }
    
    else if(tag->right==NULL)
    {
        transplant(tag,tag->left);
    }
    
    else
    {
        tag2=tag->right;
        
        while(tag2->left!=NULL)
        {
            tag2=tag2->left;
        }
        
        if(tag2->p!=tag)
        {
            transplant(tag2,tag2->right);
            tag2->right=tag->right;
            tag2->right->p=tag2;
        }
        
        transplant(tag,tag2);
        tag2->left=tag->left;
        tag2->left->p=tag2;
    }
}

int main()
{
    char c;
    int key;
    bst new,tag;
    
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
            
            case 'd':
            scanf("%d",&key);
            tag=root;
            tag=search(tag,key);
            if(tag==NULL)
            {
                printf("NotFound\n");
            }
            else
            {
                delete(tag);
            }
            break;
            
            case 'c':
            scanf("%d",&key);
            tag=root;
            tag=search(tag,key);
            if(tag==NULL)
            {
                printf("NotFound\n");
            }
            else
            {
                successor(tag);
            }
            break;
            
            case 'r':
            scanf("%d",&key);
            tag=root;
            tag=search(tag,key);
            if(tag==NULL)
            {
                printf("NotFound\n");
            }
            else
            {
                predecessor(tag);
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
            
            case 'e':
            return 0;
        }
    }
}