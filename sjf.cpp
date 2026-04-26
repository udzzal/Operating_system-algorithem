#include <iostream>

using namespace std;

struct Process {
    int processid;
    int arrivaltime;
    int brusttime;
    int completiontime;
    int turnarouundtime;
    int watingtime;
};

void findsjf(Process process[],int n){
    int remaningtime[n];
    for(int i=0;i<n;i++){
        remaningtime[i]=process[i].brusttime;
    };

    int currenttime=0,complete=0;
    int shortestbustindex=0;
    int minbusttime=__INT_MAX__;

    while(complete<n){
        minbusttime=__INT_MAX__;
        for(int i=0;i<n;i++){
            if(process[i].arrivaltime<=currenttime && remaningtime[i]<minbusttime && remaningtime[i]>0){
                minbusttime=remaningtime[i];
                shortestbustindex=i;
            };
        };
        remaningtime[shortestbustindex]--;
        if(remaningtime[shortestbustindex]==0){
            complete++;
            process[shortestbustindex].completiontime=currenttime+1;    
            process[shortestbustindex].turnarouundtime=process[shortestbustindex].completiontime-process[shortestbustindex].arrivaltime;
            process[shortestbustindex].watingtime=process[shortestbustindex].turnarouundtime-process[shortestbustindex].brusttime;  
        };
        currenttime++;
    };
};

void printtable( Process process[],int n){
    cout<<"----------------------------------------------------------"<<endl;

    cout<<"| process_id | arrivaltime | brusttime | completiontime | turnaroundtime | watingtime |"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    for(int i=0;i<n;i++){
        cout<<"| "<<process[i].processid<<" \t\t| "<<process[i].arrivaltime<<" \t\t| "<<process[i].brusttime<<" \t\t| "<<process[i].completiontime<<" \t\t| "<<process[i].turnarouundtime<<" \t\t| "<<process[i].watingtime<<" \t\t|"<<endl;
    };
     
    cout<<"----------------------------------------------------------"<<endl;
    
};


int main(){
        // this is shortest job first algorithem

        int n;
        cout<<"Enter the number of process: ";
        cin>>n;
        Process process[n];

        cout<<"\n Enter process details;\n";
        for(int i=0;i<n;i++){
            cout<<"process id :"<<i+1<<endl;
            process[i].processid=i+1;
            cout<<"arrivaltime :";
            cin>>process[i].arrivaltime;
            cout<<"brusttime :";
            cin>>process[i].brusttime;
        }

        findsjf(process,n);
        printtable(process,n);

    return 0;
}

