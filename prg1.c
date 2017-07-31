#include <stdio.h>
#include<pthread.h>

void* print_msg(void *s);

int main(){

  pthread_t t1,t2;
  pthread_create(&t1, 0, print_msg, "thread 1");
  pthread_create(&t2, 0, print_msg, "thread 2");
  while(1);
}

void* print_msg(void *s){

  int i=0;
  while(1){
   
    printf("%s: %d\n", (char*)s, i);
    i++;
  }
}
