#include<iostream>
using namespace std;

struct Process{
    int processid; // Process ID
    int arrival_time; // Arrival Time
    int burst_time; // Burst Time
    int completion_time; // Completion Time
    int turnaround_time; // Turnaround Time
    int waiting_time; // Waiting Time
    
};


void complitiontime(Process process[], int n){

 process[0].completion_time =process[0].arrival_time +process[0].burst_time;

    for(int i=1;i < n;i++){
        process[i].completion_time = process[i-1].completion_time + process[i].burst_time;
    }
};



void turnaround_time(Process process[], int n){
   for(int i=0;i<n;i++){
        process[i].turnaround_time = process[i].completion_time - process[i].arrival_time;
   }
};


void waiting_time(Process process[], int n){
    process[0].waiting_time = 0;
   for(int i=1;i<n;i++){
        process[i].waiting_time = process[i].turnaround_time - process[i].burst_time;
   }
};

 void display(Process process[], int n){
    cout<<"Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time"<<endl;
    for(int i=0;i<n;i++){
        cout<<process[i].processid<<"\t\t"<<process[i].arrival_time<<"\t\t"<<process[i].burst_time<<"\t\t"<<process[i].completion_time<<"\t\t"<<process[i].turnaround_time<<"\t\t"<<process[i].waiting_time<<endl;
    }
};
int main(){
        cout<<" First come first serve algorithm"<<endl;
    
        int n;
        cout<<"Enter the number of processes: ";
        cin>>n;
        Process process[n];

        cout<<"Enter the arrival time and burst time for each process:"<<endl;
        for(int i=0; i<n; i++){
            cout<<"Process "<<i+1<<": ";
            process[i].processid = i+1;
            cout<<"Arrival Time: ";
            cin>>process[i].arrival_time;
            cout<<"\n Burst Time: ";
            cin>>process[i].burst_time;  
        }

    complitiontime(process, n);
    turnaround_time(process, n);
    waiting_time(process, n);


    display(process, n);

    return 0;
}