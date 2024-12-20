#include<stdio.h>
int main()
{
    int a[5]={1,2,3,4,5};
    int key=20,flag=0;
    int high=4,low=0,mid;
    if(high>=low)
    {
        
        a[mid]=(high+low)/2;
        if(key==a[mid])
        {
            flag=1;
        }
        else if(key<a[mid])
        {
            high=mid-1;
        }
        else if(key>a[mid])
        {
            low=mid+1;
        }
    }
    if(flag==1)
    {
        printf("key is found");
    }
    else
    {
        printf("key is not found");
    }
}
output
key is not found
