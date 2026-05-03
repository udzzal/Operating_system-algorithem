#include<iostream>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

using namespace std;
#define num_person 5

sem_t camoch[num_person];

void *philosoper(void *num){

    int id=*(int*)num;

    cout<<"Philosoper "<<id<<" is thinking"<<endl;
    sleep(1);
    sem_wait(&camoch[id]);
    sem_wait(&camoch[(id+1) % num_person]);

    cout<<"Philosoper "<<id<<" is eating"<<endl;
    sleep(1);

    sem_post(&camoch[id]);
    sem_post(&camoch[(id+1) % num_person]);

    cout<<"Philosoper "<<id<<" is done eating"<<endl;
return NULL;
};

int main(){

    cout<<"Dining Phylshoper Problem"<<endl;

    pthread_t philosopers[num_person];
    int i,id[num_person];


    for(i=0;i<num_person;i++){
        sem_init(&camoch[i],0,1);

    }

    for(i=0;i<num_person;i++){
        id[i]=i;
        pthread_create(&philosopers[i],NULL,philosoper,&id[i]);
    }

    for(i=0;i<num_person;i++){
        pthread_join(philosopers[i],NULL);

    }

    for(i=0;i<num_person;i++){
        sem_destroy(&camoch[i]);
    }

    cout<<"\n all philopers have eaten";
    return 0;
};
