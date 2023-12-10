//assignment 4 question 5(priority queue implemented as a min heap)

#include <stdio.h>

void insert_process(int q[],int k);
void extract_next_process(int q[]);
void get_next_process(int q[]);
void change_priority(int q[],int k,int x);
void display_queue(int q[]);
void min_heapify(int q[],int i);

int heapsize;

int main()
{
    char c;
    int k,x;
    int q[1000];
    
    while(1)
    {
        scanf("%c",&c);
        
        switch(c)
        {
            case 'i':
            scanf("%d",&k);
            insert_process(q,k);
            break;
            
            case 'e':
            extract_next_process(q);
            break;
            
            case 'm':
            get_next_process(q);
            break;
            
            case 'c':
            scanf("%d",&k);
            scanf("%d",&x);
            change_priority(q,k,x);
            break;
            
            case 'd':
            display_queue(q);
            break;
            
            case 's':
            return 0;
        }
    }
}

//inserting an element to the last position and then comparing it with its parent(somewhat similar to reverse of heapify process)
void insert_process(int q[],int k)
{
    int i,swap;
    
    heapsize++;
    
    i=heapsize-1;
    
    q[heapsize-1]=k;
    
    while(k<q[(i-1)/2])
    {
        swap=q[i];
        q[i]=q[(i-1)/2];
        q[(i-1)/2]=swap;
        
        i=(i-1)/2;//point to be noted,position of parent will be given by (i-1)/2
    }
}

//printing and removing the element at first position
void extract_next_process(int q[])
{
    if(heapsize==0)
    {
        printf("-1\n");
    }
    
    else
    {
        printf("%d\n",q[0]);
        
        q[0]=q[heapsize-1];
        
        heapsize--;
        
        min_heapify(q,0);
    }
}

//printing the element at first position
void get_next_process(int q[])
{
    if(heapsize==0)
    {
        printf("-1\n");
    }
    
    else
    {
        printf("%d\n",q[0]);
    }
}

//changing the priority of element by finding its position
void change_priority(int q[],int k,int x)
{
    int i,swap;
    
    for(i=0;i<heapsize;i++)
    {
        if(q[i]==k)
        {
            q[i]=x;
            break;//break is imp,to keep the value of i intact
        }
    }
    
    if(x<k)//if priority is decreased,a process somewhat similar to reverse of min heapify
    {
        while(x<q[(i-1)/2])
        {
            swap=q[i];
            q[i]=q[(i-1)/2];
            q[(i-1)/2]=swap;
            
            i=(i-1)/2;
        }
    }
    
    else//if priority is increased, process of min heapify
    {
        min_heapify(q,i);
    }
}

void display_queue(int q[])
{
    int i,j,swap;
    int p[1000];
    
    for(i=0;i<heapsize;i++)
    {
        p[i]=q[i];
    }
    
    for(i=1;i<heapsize;i++)
    {
        j=i;
        
        while(j>0 && p[j]<p[j-1])//be careful,use p[j]<p[j-1] and not p[j+1]<p[j]
        {
            swap=p[j];
            p[j]=p[j-1];
            p[j-1]=swap;
            
            j--;
        }   
    }
    
    for(i=0;i<heapsize;i++)
    {
        printf("%d ",p[i]);
    }
    
    if(heapsize==0)
    {
        printf("-1");
    }
    
    printf("\n");
}

void min_heapify(int q[],int i)
{
    int left,right;
    int swap,smallest;
    
    left=2*i+1;
    right=2*i+2;
    
    if(q[i]>q[left] && left<heapsize)
    {
        smallest=left;
    }
    
    else
    {
        smallest=i;
    }
    
    if(q[smallest]>q[right] && right<heapsize)
    {
        smallest=right;
    }
    
    if(smallest!=i)
    {
        swap=q[i];
        q[i]=q[smallest];
        q[smallest]=swap;
        
        min_heapify(q,smallest);
    }
}