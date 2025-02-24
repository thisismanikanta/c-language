#include<stdio.h>

int main(){
    int n,p[20],bt[20],wt[20],tat[20];
    printf("Enter the number of processes:");
    scanf("%d",&n);
    for(int i=1;i<n+1;i++){
         p[i] = i;
        printf("Enter the burst time for process %d--",i);
        scanf("%d",&bt[i]);
     }
     for(int i=1;i<n;i++){
          for(int j=1;j<n-i;j++){
              if(bt[j] > bt[j+1]){
                   int temp = bt[j];
                   bt[j] = bt[j+1];
                   bt[j+1] = temp;
                   int temp1= p[j];
                   p[j] = p[j+1];
                   p[j+1] = temp1;
               }
           }
      }
      
      printf("\nPROCESS\t\tBURST TIME\t\tTURNAROUND TIME\t\tWAITING TIME");
      int ct = 0;
      float avgwt = 0;
      for(int i=1;i<n+1;i++){
         ct = ct + bt[i];
          tat[i ] = ct;
          wt[i] = tat[i] - bt[i];
          avgwt = avgwt + wt[i];
          printf("\n%d                 %d                 %d                   %d",p[i],bt[i],tat[i],wt[i]);
       }
       printf("\nAverage Waiting Time: %f ",avgwt/n);
       return 0;
 }





// output:
// Enter the number of processes:5
// Enter the burst time for process 1--2
// Enter the burst time for process 2--5
// Enter the burst time for process 3--0
// Enter the burst time for process 4--1
// Enter the burst time for process 5--8

// PROCESS		BURST TIME		TURNAROUND TIME		WAITING TIME
// 3                 0                 0                   0
// 4                 1                 1                   0
// 1                 2                 3                   1
// 2                 5                 8                   3
// 5                 8                 16                   8
// Average Waiting Time: 2.400000 
