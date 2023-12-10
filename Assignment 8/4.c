#include <stdio.h>
#include <stdlib.h>

struct element1
{
    int k;
    struct element1 *l;
    struct element1 *r;
};
typedef struct element1 *node;

struct element2
{
    node root;    
};
typedef struct element2 *binarytree;

node create(int num)
{
    node new;
    new=(node) malloc(sizeof(struct element1));
    
    new->l=NULL;
    new->r=NULL;
    new->k=num;
    
    return new;
}

node build(char *s)
{
    int num,sign,temp;
    node tag;
    
    sign=0;
    num=0;
    s=s+2;
    
    if(*s==')')
    {
        return NULL;
    }
    
    //for negative numbers
    if(*s=='-')
    {
        sign=1;
        s++;
    }
    
    //for numbers which have more than 1 decimal digit
    while(*s!=' ')
    {
        num=num*10+*s-'0';
        s++;
    }
    
    if(sign==1)
    {
        num=num*(-1);
    }
    
    tag=create(num);
    
    s++;
    tag->l=build(s);
    
    s++;
    temp=1;
    
    while(temp!=0)
    {
        if(*s=='(')
        {
            temp++;
        }
        
        if(*s==')')
        {
            temp--;
        }
        
        s++;
    }
    
    s++;
    tag->r=build(s);
    
    return tag;
}

void postorder(node tag)
{
    if(tag!=NULL)
    {
        postorder(tag->l);
        postorder(tag->r);
        printf("%d ",tag->k);
    }
}

int main()
{
    char *s;
    s=(char *) malloc(1000 * sizeof(char));
    scanf(" %[^\n]",s);
    
    binarytree bt;
    bt=(binarytree)malloc(sizeof(struct element2));
    
    bt->root=build(s);
    postorder(bt->root);
    
    return 0;
}