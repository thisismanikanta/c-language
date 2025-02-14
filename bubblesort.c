#include<stdio.h>
int bubsort(int a[],int n)
{   
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
           if(a[j]>a[j+1])
           {
              temp=a[j];
              a[j]=a[j+1];
              a[j+1]=temp;
           }
        }
    }
    for(i=0;i<n;i++)
    {
       printf("%5d",a[i]);
    }
    return 0;
}
int main()
{
    int a[6]={65,34,25,12,22,11};
    bubsort(a,6);
    return 0;
}
