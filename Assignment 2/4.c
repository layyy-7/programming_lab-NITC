//assignment 2 question 4

#include <stdio.h>

int main()
{
    int i,n,t,x;
    int first,last,mid;
    int a[1000];
    
    scanf("%d",&n);
    scanf("%d",&t);
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    first=0;
    last=n-1;
    mid=(first+last)/2;
    
    while(first<=last)
    {
        if(t<a[mid])
        {
            last=mid-1;
            mid=(first+last)/2;
        }
        
        if(t>a[mid])
        {
            first=mid+1;
            mid=(first+last)/2;
        }
        
        if(t==a[mid])
        {
            printf("%d\n",mid);
            goto there;
        }
    }
    
    printf("-1\n-1");
    return 0;
    
    there:
    x=0;//for counting the number of target elements after the target element of mid
    
    for(i=mid+1;i<n;i++)
    {
        if(a[mid]==a[i])
        {
            x++;
        }
    }
    
    for(i=(mid+1)+x;i<n;i++)//printing elements after target elements
    {
        printf("%d ",i);
    }
    
    if((n-1)==(mid+x))//if target element is largest
    {
        printf("-1");
    }
}