#include<stdio.h>
int main(){
    int buffersize=5;
    int buffer=0;
    int bool=1;

    while(bool){
        printf("\n0. exit\n1. producer\n2. consumer\n Enter your choice: ");
        scanf("%d",&bool);
        if(bool==0){
            return 0;
        }
        else if(bool==1){
            if(buffer<buffersize){
                buffer++;
            }
            else{
                printf("Buffer is full\n");
            }
        }
        else if(bool==2){
            if(buffer> 0)
            {
                buffer--;
            }
            else{
                printf("Buffer is empty\n");
            }
        }
        else{
            printf("invalid");
        }
    }
    return 0;
}
