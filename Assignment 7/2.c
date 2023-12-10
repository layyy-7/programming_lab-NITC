//converting postfix form to expression tree
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//for building the tree
struct element1
{
    char k;
    struct element1 *left;
    struct element1 *right;
};

//datatype tree is a pointer to the structure element1
typedef struct element1 *tree;
tree root=NULL;
tree l,r;

//for building the stack
struct element2
{
    tree data;
    struct element2 *next;
};

//datatype stack is a pointer to the structure element2
typedef struct element2 *stack;
stack top=NULL;

/*
point to be noted,previously i used

struct element1
{
    char k;
    struct element1 *left;
    struct element1 *right;
};

typedef struct element1 tree;
tree *root=NULL;
tree *l;
tree *r;

so malloc statement is also changed accordingly
*/

stack create(char key)
{
    tree new1;
    new1=(tree) malloc(sizeof(struct element1));
    
    stack new2;
    new2=(stack) malloc(sizeof(struct element2));
    
    new1->k=key;
    new1->left=NULL;
    new1->right=NULL;
    
    new2->data=new1;
    new2->next=NULL;
    
    return new2;
}

void push(char key)
{
    stack new;
    new=create(key);
    
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

tree pop()
{
    tree tag;
    
    if(top!=NULL)
    {
        tag=top->data;
        top=top->next;
        
        return tag;
    }
    
    else
    {
        return NULL;
    }
}

void constructtree(char e[])
{
    int i,n;
    n=strlen(e);
    
    for(i=0;i<n;i++)
    {
        if(e[i]>='a' && e[i]<='z')
        {
            push(e[i]);
        }
        
        else
        {
            r=pop();
            l=pop();
            push(e[i]);
            top->data->right=r;
            top->data->left=l;
        }
    }
    
    root=top->data;
    free(top);
}

void inorder(tree tag)
{
    if(tag!=NULL)
    {
        inorder(tag->left);
        printf("%c",tag->k);
        inorder(tag->right);
    }
}

void preorder(tree tag)
{
    if(tag!=NULL)
    {
        printf("%c",tag->k);
        preorder(tag->left);
        preorder(tag->right);
    }
}

void postorder(tree tag)
{
    if(tag!=NULL)
    {
        postorder(tag->left);
        postorder(tag->right);
        printf("%c",tag->k);
    }
}

int main()
{
    char e[100000];
    tree tag;
    
    while(1)
    {
        char c;
        scanf("%c",&c);
        
        switch(c)
        {
            case 'e':
            scanf(" %[^\n]",e);
            constructtree(e);
            break;
            
            case 'i':
            tag=root;
            inorder(tag);
            printf("\n");
            break;
            
            case 'p':
            tag=root;
            preorder(tag);
            printf("\n");
            break;
            
            case 's':
            tag=root;
            postorder(tag);
            printf("\n");
            break;
            
            case 't':
            return 0;
        }
    }
}