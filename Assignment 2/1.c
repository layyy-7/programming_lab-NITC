//assignment 2 question 1

#include <stdio.h>
#include <string.h>

int main()
{
    char a[1000];
    int i,j,n;
    int x[1000],y[1000];
    
    scanf(" %[^\n]",a);
    n=strlen(a);
    
    for(i=0;i<1000;i++)
    {
        y[i]=-1;//assigning any random value which cannot be possible for j
    }
    
    for(i=0;a[i]!='\0';i++)
    {
        x[i]=1;
        
        if(y[i]==-1)
        {
            for(j=i+1;a[j]!='\0';j++)
            {
                if(a[i]==a[j])
                {
                    x[i]=x[i]+1;
                    y[j]=j;//very important to prevent letters which are already counted(if more than two same letters occur)
                }
            }
        }
    }
    
    for(i=0;i<n-1;i++)
    {
        x[i+1]=x[i]*x[i+1];
    }
    
    printf("%d",x[n-1]);
}