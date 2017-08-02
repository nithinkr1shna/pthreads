//implementing semaphore using mutex and condition variables.

#include<stdio.h>
#include<pthread.h>

typedef struct{
  int val; // for count
  pthread_mutex_t mutex;
  pthread_cond_t cond;
   
}semaphore;

semaphore s;

//functions
void init(semaphore *s); // for initiaalisation
void up(semaphore *s);   // up the count
void down(semaphore *s); // down the count

int main(){

  int i;
  init(&s);
  for(i=0;i<3;i++)
    up(&s);
  printf("%d\n", s.val);
  for(i=0; i<3; i++)
    down(&s);
  printf("%d\n",s.val);

}

void init(semaphore *s){

  printf("INIT\n");
  s->val=0;
  pthread_mutex_init(&s->mutex, NULL);
  pthread_cond_init(&s->cond, NULL);
}

void down(semaphore *s){

  printf("DOWN\n");
  pthread_mutex_lock(&s->mutex);
  if(s->val == 0){
    pthread_cond_wait(&s->cond, &s->mutex);
  }
  s->val--;
  pthread_mutex_unlock(&s->mutex);
  
} 


void up(semaphore *s){

  printf("UP\n");
  pthread_mutex_lock(&s->mutex);
  s->val++;
  pthread_cond_broadcast(&s->cond);
  pthread_mutex_unlock(&s->mutex);
}
