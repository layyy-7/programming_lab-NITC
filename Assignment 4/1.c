//assignment 4 question 1

#include <stdio.h>
#include <string.h>

int main()
{
    int i,j;
    int n,x,pivot;
    char cr[30];
    
    scanf("%d",&n);
    
    /*as variable(here,array class of 1000 members) is already declared within structure declaration,
    giving name to structure(here,student) is not mandatory*/
    struct student
    {
        char name[30];
        int marks;
    }a[1000],swap;
    
    for(i=0;i<n;i++)
    {
        //point to be noted,%s is used instead of %[^\n] so as to end the string after any whitespace
        //point to be noted,name doesnt require & as it is an array(same rule for structure variables as that of normal variables)
        scanf(" %s",a[i].name);
        scanf("%d",&a[i].marks);
    }
    
    scanf(" %s",cr);
    
    for(i=0;i<n;i++)
    {
        x=strcmp(cr,a[i].name);
        
        if(x==0)
        {
            pivot=i;
            break;
        }
    }
    
    j=0;
    
    for(i=0;i<n;i++)
    {
        if(a[i].marks<a[pivot].marks)
        {
            swap=a[i];
            a[i]=a[j];
            a[j]=swap;
            
            j++;
        }
    }
    
    swap=a[pivot];
    a[pivot]=a[j];
    a[j]=swap;
    
    for(i=0;i<n;i++)
    {
        printf("%s ",a[i].name);
    }
    
    return 0;
}