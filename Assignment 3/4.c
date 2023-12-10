//assignment 3 question 4

#include <stdio.h>

void read_and_store(int a[],int *n);
void print(int a[],int n);
int digit_sum(int x);
void digit_sort(int a[],int n);

int main()
{
    char c;
    int n,i,x,a[100000];
    
    
    while(1)
    {
        scanf("%c",&c);
        
        switch(c)
        {
            case 'r':
            read_and_store(a,&n);//passed as a pointer so as to alter the value of n in main also
            break;
            
            case 'p':
            print(a,n);
            break;
            
            case 'd':
            scanf("%d",&i);
            x=digit_sum(a[i]);
            printf("%d\n",x);
            break;
            
            case 's':
            digit_sort(a,n);
            break;
            
            case 't':
            printf("-1");
            return 0;
        }
    }
    
}

void read_and_store(int a[],int *n)
{
    int i;
    
    scanf("%d",n);
    
    for(i=0;i<*n;i++)
    {
        scanf("%d",&a[i]);
    }
}

void print(int a[],int n)
{
    int i;
    
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    
    printf("\n");
}

int digit_sum(int x)
{
    int sum=0;
    
    while(x>0)
    {
        sum+=x%10;
        x=x/10;
    }
    
    return sum;
}

void digit_sort(int a[],int n)
{
    int i,j,t;
    
    for(i=1;i<n;i++)
    {
        j=i;
        
        while(j>0 && digit_sum(a[j])<digit_sum(a[j-1]))
        {
            t=a[j];
            a[j]=a[j-1];
            a[j-1]=t;
            
            j--;
        }
    }
}