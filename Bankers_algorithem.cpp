#include<iostream>

using namespace std;

int main(){
    int n=5;
    int r=3;

    int allocation[5][3]={

        {0,0,1},//p0
        {3,0,0},//p1
        {1,0,1},//p2
        {2,3,2},//p3
        {0,0,3}//p4
    };

    int max[5][3]={
        {7,6,3},
        {3,2,2},
        {8,0,2},
        {2,1,2},
        {5,2,3}
    };

    int aval[3]={2,3,2};

    int need[n][r];

    for(int i=0;i<n;i++){
        for(int j=0;j<r;j++){
            need[i][j]=max[i][j]-allocation[i][j];

        }
    }

    int f[n],ans[n],index=0;

    for(int i=0;i<5;i++){
        f[i]=0;
    }

    for(int k=0;k<5;k++){
        for(int i=0;i<n;i++){
        if(f[i]==0){
           int flag=0;
           for(int j=0;j<r;j++){ 
             if(need[i][j]>aval[j]){
                flag=1;
                break;
             }
           }  
           
              if(flag==0){
                ans[index++]=i;
                for(int y=0;y<r;y++){
                     aval[y]+=allocation[i][y];
                }
                f[i]=1;
              }
        }
        };
    }

    cout<<"Safe Sequence: ";
    for(int i=0;i<n;i++){
        cout<<"P"<< ans[i]<<" ";
    }


    return 0;
}

