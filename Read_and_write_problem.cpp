#include<iostream>
#include<stdint.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

using namespace std;



sem_t mutex_sem,writeblock;
int sdata=0,readcount=0;

void *reader(void *arg){
    int f=(intptr_t)arg;

    sem_wait(&mutex_sem);
    readcount++;
    if(readcount==1){
        sem_wait(&writeblock);
    }

    sem_post(&mutex_sem);

     cout<<"data reader by R[" <<f<<"] = "<< sdata <<endl;
    sleep(1);

    sem_wait(&mutex_sem);
    readcount--;

    if (readcount==0){
            sem_post(&writeblock);
        }
    sem_post(&mutex_sem);

    pthread_exit(NULL);

};

void *writer(void *arg){
    int f =(intptr_t)arg;

    sem_wait(&writeblock);

    sdata++;

    cout<<"data written by w[" <<f<<"] = "<< sdata <<endl;
    sem_post(&writeblock);

    sleep(1);

    pthread_exit(NULL);

};

int main(){
    int i=0;
    pthread_t read[5],write[5];

    sem_init(&mutex_sem,0,1);
    sem_init(&writeblock,0,1);

for(i=0;i<4;i++){
    pthread_create(&write[i],NULL,writer,(void*)(intptr_t)i); 
    pthread_create(&read[i],NULL,reader,(void*)(intptr_t)i); 
    };

for(i=0;i<4;i++){
    pthread_join(write[i],NULL);
    pthread_join(read[i],NULL);
};
 sem_destroy(&mutex_sem);
 sem_destroy(&writeblock);


  return 0;
}