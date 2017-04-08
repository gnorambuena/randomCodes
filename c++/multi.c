#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
typedef struct{
	int i;
	int j;
}args;

pthread_mutex_t mutex;
void* func(void* param){
	pthread_mutex_lock(&mutex);
	args *pr = (args*)param;
	printf("%d %d\n",pr->i,pr->j);
	for(int i = pr->i ; i < pr->j ; i++){
		printf("%d\n",i);
	}
	pthread_mutex_unlock(&mutex);
	int *k = (int*)malloc(sizeof(int));
	*k=1000;
	pthread_exit(k);
	return NULL;
}

int main(){
	pthread_t thread0;
	pthread_t thread1;
	args* param =(args*)malloc(sizeof(args));
	param->i = 1;
	param->j = 10;
	pthread_mutex_init(&mutex,NULL);
	pthread_create(&thread0,NULL,func,(void*)param);
	param->i = 20;
	param->j = 30;
	pthread_create(&thread1,NULL,func,(void*)param);
	for(int i = 10 ; i < 20 ; i++){
		printf("%d\n",i);
	}
	int *k;
	pthread_join(thread0,(void**)&k);
	printf("%d\n",*k);
	return 0;
}