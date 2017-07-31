#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int main(){

  int val;
  sem_t sem;
  sem_init(&sem, 0, 0);
  sem_getvalue(&sem ,&val);
  printf("%d\n",val);
  sem_post(&sem);
  
  sem_getvalue(&sem, &val);
  printf("%d\n",val);
  sem_wait(&sem);
  sem_getvalue(&sem, &val);
  printf("%d\n",val);
  sem_wait(&sem);
  sem_getvalue(&sem, &val);
  printf("%d\n",val);
}
