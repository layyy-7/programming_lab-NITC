//assignment 1 question 3

#include <stdio.h>

int main()
{
    int i,j,l;
    char line[1000];
    
    scanf(" %[^\n]",line);
    
    l=0;
    
    for(i=0;line[i]!='\0';i++)
    {
        l++;
    }
    
    for(i=0;i<l;i++)
    {
        if(line[i]<='z' && line[i]>='a')
        {
            line[i]=line[i]-32;
        }
    }
    
    j=0;
    
    for(i=0;i<l;i++)
    {
        if(line[i]==line[l-i-1])
        {
            j++;
        }
    }
    
    if(j==l)
    {
        printf("YES");
    }
    
    else
    {
        printf("NO");
    }
}