/* Includes */
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

sem_t sem1, sem2, sem3, sem4;

void* threadHello(void* arg) {
    while (1) {
        sem_wait(&sem1); // Wait for semaphore 1
        printf("Hello ");
        sem_post(&sem2); // Signal semaphore 2
    }
}

void* threadThere(void* arg) {
    while (1) {
        sem_wait(&sem2); // Wait for semaphore 2
        printf("there ");
        sem_post(&sem3); // Signal semaphore 3
    }
}

void* threadWonderful(void* arg) {
    while (1) {
        sem_wait(&sem3); // Wait for semaphore 3
        printf("wonderful ");
        sem_post(&sem4); // Signal semaphore 4
    }
}

void* threadWorld(void* arg) {
    while (1) {
        sem_wait(&sem4); // Wait for semaphore 4
        printf("world!\n");
        sem_post(&sem1); // Signal semaphore 1
    }
}

int main(int argc, char* argv[]) {
    
    //Initializing semaphores
    sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 0);
    sem_init(&sem3, 0, 0);
    sem_init(&sem4, 0, 0);
    
    //Creating threads
    pthread_t thread1, thread2, thread3, thread4;
    pthread_create(&thread1, NULL, threadHello, NULL);
    pthread_create(&thread2, NULL, threadThere, NULL);
    pthread_create(&thread3, NULL, threadWonderful, NULL);
    pthread_create(&thread4, NULL, threadWorld, NULL);
    
    //Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    
    return 0;
}