//assignment 3 question 3

#include <stdio.h>
#include <string.h>

void partition(char list[][1000],int low,int high);
void mergesort(char list[][1000],int low,int mid,int high);

int main()
{
    int i,n;
    char list[100][1000];
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        scanf(" %[^\n]",list[i]);//point to be noted,ampersand not to be used here
    }
    
    partition(list,0,n-1);
    
    for(i=0;i<n;i++)
    {
        printf("%s\n",list[i]);
    }
}

void partition(char list[][1000],int low,int high)
{
    int mid;
    
    if(high>low)
    {
        mid=(high+low)/2;
        partition(list,low,mid);
        partition(list,mid+1,high);
        mergesort(list,low,mid,high);
    }
}

void mergesort(char list[][1000],int low,int mid,int high)
{
    int i=low,j=mid+1,k=low,z;
    char sort[100][1000];
    
    while(i<=mid && j<=high)
    {
        for(z=0;list[i][z]!='\0' && list[j][z]!='\0';z++)
        {
            if(list[i][z]<list[j][z])
            {
                strcpy(sort[k],list[i]);
                i++;
                break;
            }
            
            if(list[i][z]>list[j][z])
            {
                strcpy(sort[k],list[j]);
                j++;
                break;
            }
        }
        
        k++;
    }
    
    //direct assignment for two dimensional arrays is not possible,so use strcpy function
    //i.e.,sort[k]=list[i] wont work
    //you can also use the concept of strcmp function for comparing strings
    
    while(i<=mid)
    {
        strcpy(sort[k],list[i]);
        i++;
        k++;
    }
    
    while(j<=high)
    {
        strcpy(sort[k],list[j]);
        j++;
        k++;
    }
    
    for(k=low;k<=high;k++)
    {
        strcpy(list[k],sort[k]);
    }
}