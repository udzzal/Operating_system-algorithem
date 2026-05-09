
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

struct Process {
    int processid;
    int arrivaltime;
    int bursttime;
    int completiontime;
    int turnaroundtime;
    int waitingtime;
};

void findSJF(vector<Process>& process, int n) {
    vector<int> remainingtime(n);
    for (int i = 0; i < n; i++)
        remainingtime[i] = process[i].bursttime;

    int currenttime = 0, complete = 0;
    int minbursttime, shortestindex;

    while (complete < n) {
        minbursttime = INT_MAX;
        shortestindex = -1; 

        for (int i = 0; i < n; i++) {
            if (process[i].arrivaltime <= currenttime &&
                remainingtime[i] < minbursttime &&
                remainingtime[i] > 0) {
                minbursttime = remainingtime[i];
                shortestindex = i;
            }
        }

    
        if (shortestindex == -1) {
            currenttime++;
            continue;
        }

        remainingtime[shortestindex]--;

        if (remainingtime[shortestindex] == 0) {
            complete++;
            process[shortestindex].completiontime = currenttime + 1;
            process[shortestindex].turnaroundtime =
                process[shortestindex].completiontime - process[shortestindex].arrivaltime;
            process[shortestindex].waitingtime =
                process[shortestindex].turnaroundtime - process[shortestindex].bursttime;
        }

        currenttime++;
    }
}

void printTable(const vector<Process>& process, int n) {
    cout << string(85, '-') << endl;
    cout << "| PID | Arrival | Burst | Completion | Turnaround | Waiting |" << endl;
    cout << string(85, '-') << endl;
    for (int i = 0; i < n; i++) {
        cout << "|  " << process[i].processid
             << "  |    " << process[i].arrivaltime
             << "    |   " << process[i].bursttime
             << "   |     " << process[i].completiontime
             << "      |      " << process[i].turnaroundtime
             << "      |    " << process[i].waitingtime
             << "    |" << endl;
    }
    cout << string(85, '-') << endl;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> process(n);
    cout << "\nEnter process details:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process ID: " << i + 1 << endl;
        process[i].processid = i + 1;
        cout << "Arrival time: ";
        cin >> process[i].arrivaltime;
        cout << "Burst time: ";
        cin >> process[i].bursttime;
    }

    findSJF(process, n);
    printTable(process, n);
    return 0;
}
