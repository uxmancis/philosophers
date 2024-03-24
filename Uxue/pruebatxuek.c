#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int counter;

void    *make_coffee (void *data)
{
    (void) data;
    printf("Barista preparing coffee\n");
    counter++;
    printf("counter = %d\n", counter);
    usleep(2);
    printf("🥤ready!\n");
    return (0);
}

int main(void)
{
    pthread_t barista1;
    pthread_t barista2;
    //pthread_t   baristas[500];

    pthread_create(&barista1, NULL, make_coffee, NULL);//2nd NULL = arguments to pass to make_coffee function
    pthread_create(&barista2, NULL, make_coffee, NULL);
    //printf("counter = %d\n", counter);
    //sleep: suspends execution of current thread for X seconds. Commonly used to introduce a delay or pause in program execution.
    //When timing and/or thread-coordination is important, sleep can be used to give a thread enough time to finisih its execution
    pthread_join(barista1, NULL); //taked thread_id, "let's just wait so that thread finishes its execution", it's like wait function for processes, we wait thread to finish executing
    pthread_join(barista2, NULL);
    return (0);
}
