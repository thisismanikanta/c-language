#include <stdio.h>

void roundRobin(int n, int arrival_time[], int burst_time[], int quantum) {
    int remaining_time[n], completion_time[n], waiting_time[n], turnaround_time[n];
    int time = 0, completed = 0;

    for (int i = 0; i < n; i++)
        remaining_time[i] = burst_time[i];

    while (completed < n) {
        int executed = 0;

        for (int i = 0; i < n; i++) {
            if (arrival_time[i] <= time && remaining_time[i] > 0) {
                executed = 1;

                if (remaining_time[i] > quantum) {
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    time += remaining_time[i];
                    remaining_time[i] = 0;
                    completion_time[i] = time;
                    turnaround_time[i] = completion_time[i] - arrival_time[i];
                    waiting_time[i] = turnaround_time[i] - burst_time[i];
                    completed++;
                }
            }
        }

        if (!executed) {
            time++;
        }
    }

    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, arrival_time[i], burst_time[i], 
               completion_time[i], turnaround_time[i], waiting_time[i]);
    }

    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += waiting_time[i];
        total_tat += turnaround_time[i];
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrival_time[n], burst_time[n];

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    roundRobin(n, arrival_time, burst_time, quantum);

    return 0;
}
