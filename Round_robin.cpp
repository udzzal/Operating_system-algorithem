#include<iostream>
using namespace std;

struct Process{
    int process_id;
    int arrivaltime;
    int brusttime;
    int completiontime;
    int turnaroundtime;
    int watingtime;
};

void calculateTime(Process process[],int n,int quantum){
    int remaningtime[n];

    for(int i=0;i<n;i++){
        remaningtime[i]=process[i].brusttime;
    }

    int currenttime=0;
    bool alldone=false;

    while(!alldone){
        alldone=true;

        for(int i=0;i<n;i++){
            if(remaningtime[i]>0){
            alldone=false;

            if(remaningtime[i]>quantum){
                    currenttime=currenttime+quantum;
                    remaningtime[i]=remaningtime[i]-quantum;

            }else{
                currenttime=currenttime+remaningtime[i];
                process[i].completiontime=currenttime;
                remaningtime[i]=0;
            }
            
        }
        }
    }

};

void calculateTurnaroundtime(Process process[],int n){
    for(int i=0;i<n;i++){
        process[i].turnaroundtime=process[i].completiontime-process[i].arrivaltime;
    }

};

void calculateWatingtime(Process process[],int n){
    for(int i=0;i<n;i++){
        process[i].watingtime=process[i].turnaroundtime-process[i].brusttime;
    }

};

void print_table(Process process[],int n){
    cout<<"----------------------------------------------------------"<<endl;

    cout<<"| process_id | arrivaltime | brusttime | completiontime | turnaroundtime | watingtime |"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    for(int i=0;i<n;i++){
        cout<<"| "<<process[i].process_id<<"      | "<<process[i].arrivaltime<<"           | "<<process[i].brusttime<<"         | "
        <<process[i].completiontime<<"             | "<<process[i].turnaroundtime<<"          | "<<process[i].watingtime<<"        |"<<endl;
    }
    cout<<"----------------------------------------------------------"<<endl;
    
};

int main(){

    cout<<"this is a cpu sheduling algorithem  called round robin"<<endl;

    int n,quantum;
    cout<<"Enter the number of process : ";
    cin>>n;
    cout<<endl<<"Enter the quantum time : ";
    cin>>quantum;

    Process process[n];
    cout<<endl<<"enter the process details "<<endl;

    for(int i=0;i<n;i++){
        cout<<"process_id :"<<i+1<<endl;
        process[i].process_id=i+1;
        cout<<" arrivaltime  :";
        cin>>process[i].arrivaltime;
        cout<<" brusttime  :";
        cin>>process[i].brusttime;
        cout<<endl;
    }
    
    calculateTime(process,n,quantum);

    calculateTurnaroundtime(process,n);

    calculateWatingtime(process,n);

    cout<<endl<<"Round robin scheduling table "<<endl;
    print_table(process,n);

    return 0;
}