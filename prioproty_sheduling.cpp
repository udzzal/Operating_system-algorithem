#include<iostream>
using namespace std;

struct Process {
    int processid;
    int arrival_time;
    int priority;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

void findCompletionTime(Process p[], int n) {
    int currenttime = 0;
    bool done[1000] = {false};
    int completed = 0;

    while (completed < n) {
        int minpriority = 1e9;   // FIXED: look for LOWEST priority number
        int idx = -1;

        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].arrival_time <= currenttime) {
                if (p[i].priority < minpriority) {   // FIXED: < instead of >
                    minpriority = p[i].priority;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            p[idx].completion_time = currenttime + p[idx].burst_time;
            currenttime = p[idx].completion_time;
            done[idx] = true;
            completed++;
        } else {
            currenttime++;
        }
    }
}

void findTurnAroundTime(Process p[], int n) {
    for (int i = 0; i < n; i++)
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
}

void findWaitingTime(Process p[], int n) {
    for (int i = 0; i < n; i++)
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
}

void findResponseTime(Process p[], int n) {
    for (int i = 0; i < n; i++)
        p[i].response_time = p[i].waiting_time;
}

void display(Process p[], int n) {
    float totalWT = 0, totalTAT = 0;
    cout << "\n----------------------------------------------------------\n";
    cout << "PID\tAT\tPRI\tBT\tCT\tTAT\tWT\tRT\n";
    cout << "----------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].processid      << "\t"
             << p[i].arrival_time   << "\t"
             << p[i].priority       << "\t"
             << p[i].burst_time     << "\t"
             << p[i].completion_time<< "\t"
             << p[i].turnaround_time<< "\t"
             << p[i].waiting_time   << "\t"
             << p[i].response_time  << "\n";
        totalWT  += p[i].waiting_time;
        totalTAT += p[i].turnaround_time;
    }
    cout << "----------------------------------------------------------\n";
    cout << "Average Waiting Time    : " << totalWT  / n << "\n";
    cout << "Average Turnaround Time : " << totalTAT / n << "\n";
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].processid = i + 1;
        cout << "\nEnter arrival time of P" << i+1 << ": ";
        cin >> p[i].arrival_time;
        cout << "Enter priority of P" << i+1 << ": ";
        cin >> p[i].priority;
        cout << "Enter burst time of P" << i+1 << ": ";
        cin >> p[i].burst_time;
    }

    findCompletionTime(p, n);
    findTurnAroundTime(p, n);
    findWaitingTime(p, n);
    findResponseTime(p, n);
    display(p, n);

    return 0;
}
