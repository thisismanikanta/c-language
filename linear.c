#include<stdio.h>
int main()
{
    int a[5]={1,2,3,4,5};
    int key=5,flag=0;
    int i;
    for(i=0;i<5;i++)
    {
        if(key==a[i])
        {
            flag=1;
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
key is found
