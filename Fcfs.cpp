#include<iostream>
#include<vector>
using namespace std;

struct Process {
    int processid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

void completiontime(vector<Process>& process, int n) {
    process[0].completion_time = process[0].arrival_time + process[0].burst_time;
    for(int i = 1; i < n; i++){
        if(process[i-1].completion_time > process[i].arrival_time){
            process[i].completion_time = process[i-1].completion_time + process[i].burst_time;
        } else {
            process[i].completion_time = process[i].arrival_time + process[i].burst_time;
        }
    }
}

void turnaroundtime(vector<Process>& process, int n) {
    for(int i = 0; i < n; i++){
        process[i].turnaround_time = process[i].completion_time - process[i].arrival_time;
    }
}

void waitingtime(vector<Process>& process, int n) {
    for(int i = 0; i < n; i++){
        process[i].waiting_time = process[i].turnaround_time - process[i].burst_time;
    }
}

void display(vector<Process>& process, int n) {
    cout << string(75, '-') << endl;
    cout << "| PID | Arrival | Burst | Completion | Turnaround | Waiting |" << endl;
    cout << string(75, '-') << endl;
    for(int i = 0; i < n; i++){
        cout << "|  "          << process[i].processid
             << "  |    "      << process[i].arrival_time
             << "    |   "     << process[i].burst_time
             << "   |     "    << process[i].completion_time
             << "      |      "<< process[i].turnaround_time
             << "      |    "  << process[i].waiting_time
             << "    |"        << endl;
    }
    cout << string(75, '-') << endl;
}

int main() {
    cout << "First Come First Serve Algorithm" << endl;

    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> process(n);
    for(int i = 0; i < n; i++){
        process[i].processid = i + 1;
        cout << "\nProcess " << i+1 << ":" << endl;
        cout << "  Arrival Time: ";
        cin >> process[i].arrival_time;
        cout << "  Burst Time  : ";
        cin >> process[i].burst_time;
    }

    
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(process[j].arrival_time > process[j+1].arrival_time){
                swap(process[j], process[j+1]);
            }
        }
    }

    completiontime(process, n);
    turnaroundtime(process, n);
    waitingtime(process, n);
    display(process, n);

    return 0;
}
