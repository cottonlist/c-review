#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *func1 (void *arg)
{
	printf("1\n");
	// sleep(1);
	printf("1\n");
	printf("1\n");
	printf("1\n");
	printf("1\n");
	printf("1\n");
	printf("1\n");
	printf("1\n");
	printf("1\n");
	printf("1\n");
	printf("1\n");
	printf("1\n");
	printf("1\n");
	printf("1\n");
	printf("1\n");
	printf("1\n");
	printf("1\n");
	printf("1\n");

	return NULL;
}

void *func2 (void *arg)
{
	printf("2\n");
	printf("2\n");
	printf("2\n");
	printf("2\n");
	printf("2\n");
	printf("2\n");
	printf("2\n");
	printf("2\n");
	printf("2\n");
	printf("2\n");
	printf("2\n");
	printf("2\n");
	printf("2\n");
	printf("2\n");
	printf("2\n");
	printf("2\n");
	printf("2\n");
	printf("2\n");
	printf("2\n");
	printf("2\n");
	printf("2\n");
	printf("2\n");
	printf("2\n");

	return NULL;
}

int main(void)
{
	static struct sched_param schedparam1, schedparam2;
	schedparam1.sched_priority = 3;
	schedparam2.sched_priority = 2;

	pthread_attr_t attr1, attr2;
	pthread_attr_init(&attr1);
	pthread_attr_init(&attr2);
	pthread_attr_setinheritsched(&attr1, PTHREAD_EXPLICIT_SCHED);
	pthread_attr_setinheritsched(&attr2, PTHREAD_EXPLICIT_SCHED);
	pthread_attr_setschedpolicy(&attr1, SCHED_RR);
	pthread_attr_setschedpolicy(&attr2, SCHED_RR);
	pthread_attr_setschedparam(&attr1, &schedparam1);
	pthread_attr_setschedparam(&attr2, &schedparam2);

	pthread_t t1;
	pthread_t t2;

	pthread_create(&t1, &attr1, func1, NULL);
	pthread_create(&t2, &attr2, func2, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	pthread_attr_destroy(&attr1);
	pthread_attr_destroy(&attr2);

	return 0;
}