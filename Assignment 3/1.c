//assignment 3 question 1
#include <stdio.h>

int main()
{
    int i,j,n;
    float a[1000],b[1000],t;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        scanf("%f",&a[i]);
        b[i]=a[i];
    }
    
    for(i=1;i<n;i++)
    {
        j=i;
        
        while(j>0 && a[j]<a[j-1])
        {
            t=a[j];
            a[j]=a[j-1];
            a[j-1]=t;
            
            j--;
        }
    } 
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(b[i]==a[j])
            {
                printf("%d ",j);
                break;
            }
        }
    }
}