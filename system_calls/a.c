#include <stdio.h>

struct Process {
    int pid;           // Process ID
    int arrivalTime;   // Arrival time
    int burstTime;     // Burst time
    int waitingTime;   // Waiting time
    int turnAroundTime;// Turnaround time
};

// Function to sort processes by arrival time for FCFS
void sortByArrivalTime(struct Process proc[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].arrivalTime > proc[j].arrivalTime) {
                struct Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

// Function to sort processes by burst time for SJF
void sortByBurstTime(struct Process proc[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].burstTime > proc[j].burstTime) {
                struct Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

// Function to calculate waiting time and turnaround time
void calculateTimes(struct Process proc[], int n) {
    proc[0].waitingTime = 0;
    proc[0].turnAroundTime = proc[0].burstTime;
    
    for (int i = 1; i < n; i++) {
        proc[i].waitingTime = proc[i-1].waitingTime + proc[i-1].burstTime;
        proc[i].turnAroundTime = proc[i].waitingTime + proc[i].burstTime;
    }
}

// Function to display process details
void displayProcesses(struct Process proc[], int n) {
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
                proc[i].pid, proc[i].arrivalTime, proc[i].burstTime, proc[i].waitingTime, proc[i].turnAroundTime);
    }
}

// First-Come, First-Served (FCFS) Scheduling
void fcfs(struct Process proc[], int n) {
    sortByArrivalTime(proc, n);  // Sort by arrival time
    calculateTimes(proc, n);     // Calculate waiting and turnaround times

    printf("\nFirst-Come, First-Served (FCFS) Scheduling:");
    displayProcesses(proc, n);
}

// Shortest Job First (SJF) Scheduling
void sjf(struct Process proc[], int n) {
    sortByBurstTime(proc, n);    // Sort by burst time
    calculateTimes(proc, n);     // Calculate waiting and turnaround times

    printf("\nShortest Job First (SJF) Scheduling:");
    displayProcesses(proc, n);
}

int main() {
    // Predefined number of processes
    int n = 4;
    
    // Predefined process details
    struct Process proc[] = {
        {1, 0, 6},  // {Process ID, Arrival Time, Burst Time}
        {2, 1, 8},
        {3, 2, 7},
        {4, 3, 3}
    };

    // FCFS Scheduling
    fcfs(proc, n);

    // SJF Scheduling
    sjf(proc, n);

    return 0;
}
