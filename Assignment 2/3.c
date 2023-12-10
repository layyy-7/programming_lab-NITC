//assignment 2 question 3

#include <stdio.h>

int main()
{
    int a[1000];
    int i,j,n;
    int x,y,p,q,t;
    int first,second;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    y=0;//for number of times of first(the largest element in list)
    
    for(i=0;i<n;i++)
    {
        x=0;//point to be noted,x will be zero after every occurence of for loop of i
        
        for(j=0;j<n;j++)
        {
            if(a[i]>=a[j])
            {
               x=x+1; 
            }
        }
        
        if(x==n)
        {
            first=a[i];
            y++;
        }
    }
    
    q=0;//for number of times of second(the second largest element in list)
    
    for(i=0;i<n;i++)
    {
        p=0;//point to be noted,p will be zero after every occurence of for loop of i
        
        for(j=0;j<n;j++)
        {
            if(a[i]>=a[j] && a[i]!=first && a[j]!=first)
            {
               p++; 
            }
        }
        
        if(p==n-y && n!=y)//n!=y is very important,it is for the case when all numbers in input are the same
        {
            second=a[i];
            q++;
        }
    }
    
    for(i=0;i<n;i++)
    {
        if(a[i]==second)
        {
            for(j=i;j<n-1;j++)
            {
                t=a[j+1];
                a[j+1]=a[j];
                a[j]=t;
            }
        }
    }
    
    //same loop as above for removal of remaining second largest numbers
    //the remaining second largest numbers occur when two or more second largest numbers occur together
    for(i=0;i<n;i++)
    {
        if(a[i]==second)
        {
            for(j=i;j<n-1;j++)
            {
                t=a[j+1];
                a[j+1]=a[j];
                a[j]=t;
            }
        }
    }
    
    for(i=0;i<n-q;i++)//loop is looped such that second largest numbers do not come in output
    {
        printf("%d ",a[i]);
    }
}