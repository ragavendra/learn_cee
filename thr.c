#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t lock;
static int sta = 0;

// works in gcc
void *wait(void *a)
{

	 pthread_mutex_lock(&lock);

	 ++sta;
	 sleep(1);
	 printf("Sleep is over %d !", sta);

	 pthread_mutex_unlock(&lock);

	 return NULL;
}

int main()
{
	 pthread_t thr, thr_2;
	 int err = pthread_create(&thr, NULL, wait, NULL);
	 int err_2 = pthread_create(&thr_2, NULL, wait, NULL);

	 if(err || err_2)
	 {
		  printf("Unable to create thr %d", err);
		  printf("Unable to create thr_2 %d", err_2);
		  return 1;
	 }

	 printf("Waitin for thr to end ... \n");

	 // pthread_join(thr, NULL);
	 // printf("Thr 1 ended!");

	 // wait for second one to finish, since first can take lock first, 
	 // both thrds will wait till this
	 pthread_join(thr_2, NULL);

	 printf("Threads ended!");

	 return 0;
}

