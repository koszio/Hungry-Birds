#ifndef _REENTRANT
#define _REENTRANT
#endif
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <semaphore.h>
#include <unistd.h>


#define NO_OF_CONSUMERS 8
#define MAX_BUFFER 5
sem_t empty;
sem_t full;
sem_t mutex;
sem_t cond;

int buffer[MAX_BUFFER];
int front = 0;
int rear = 0;
bool emptySpace = false;
pthread_t cons[NO_OF_CONSUMERS];
pthread_t prod;

void put(int value)
{
    buffer[front] = value;
    front = (front + 1) % MAX_BUFFER;
}

int get()
{
    int tmp = buffer[rear]; // Line G1
    rear = (rear + 1) % MAX_BUFFER; // Line G2
    return tmp;
}

void *producer(void *arg)
{
    int i;
    while(true){
      if(!emptySpace){

        sem_wait(&mutex);
        for(i=0;i<MAX_BUFFER; i++)
            put(i);
      printf("Producer is finished\n");
      emptySpace=true;
      sem_post(&cond);
      sem_post(&mutex);
    }

  }
return NULL;

}

void *consumer(void *arg)
{
  long id = (long) arg;

 int temp, position;

    while(true){
      sem_wait(&mutex);
      while(!emptySpace){
        sem_post(&mutex);
        sem_wait(&cond);
        sem_wait(&mutex);
      }

      position = rear;
temp=get();
printf("Consumer %ld -> %d\n", id, temp);

if(position==(MAX_BUFFER-1)){
  emptySpace = false;
}
sem_post(&mutex);
sleep(1);
}
return NULL;



}

int main()
{


    sem_init(&mutex, 0, 1);
    sem_init(&cond, 0, 0);

    pthread_create(&prod, NULL, producer, NULL);


    for(long i = 0; i<NO_OF_CONSUMERS; i++){
      pthread_create(&cons[i], NULL, consumer, (void *)i);




    }

    pthread_exit(NULL);



}
