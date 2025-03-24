#include<stdio.h> 
int main()
{
   int framesize=4;
   int frame[4];
   int npages = 0;
   int pagefault=0;
   int index=0;
   printf("enter the no of pages");
   scanf("%d",&npages);
   int pages[npages];
   for(int i=0;i<npages;i++){
       printf("enter the %dth page:",i);
       scanf("%d",&pages[i]);
   }
   for(int i=0;i<npages;i++){
    int isthere=0;
    for(int j=0;j<4;j++){ 
      if(pages[i]==frame[j]){
           isthere=1;
      }
   }
   if(isthere==0){
     pagefault++;
     if(index>=framesize){
        index=0;
        frame[index]=pages[i];
     }
     else{
            frame[index]=pages[i];
     }
     index++;
    }
}
printf("%d",pagefault);
   }
