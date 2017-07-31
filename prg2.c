#include<stdio.h>
#include<pthread.h>

pthread_mutex_t mutex;

void *fun(void *arg);

int main(){


  pthread_t t1, t2;
  pthread_mutex_init(&mutex, 0);
  pthread_create(&t1, NULL, fun, "thread 1");
  pthread_create(&t2, NULL, fun, "thread 2");
  while(1);
}

void *fun(void *arg){

  int i;
    pthread_mutex_lock(&mutex);
    for(i=0;i<5;i++){
    
      printf("%s: %d\n", (char*)arg, i);
      sleep(1);
    }
    pthread_mutex_unlock(&mutex);
  
}
