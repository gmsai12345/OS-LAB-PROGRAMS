#include <bits/stdc++.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;
int main()
{
    int n=5;
    sem_t chopsticks[n];
    for(int i =0;i<n;i++)
    {
        sem_init(&chopsticks[i],0,1);
    }
    for(int i=0;i<n;i++)
    {
        pid_t pid=fork();
        if(pid==0)
        {
            cout << "philosopher " <<i+1 << " is thinking" <<endl; 
            usleep(2000000);// simulate thinking time
             // to acquire left chopsticks
            sem_wait(&chopsticks[i]);
            cout << "philosopher " <<i+1 << " has acquired left chopstick" <<endl; 
             // to acquire left chopsticks
            sem_wait(&chopsticks[(i+1)%n]);
            cout << "philosopher " <<i+1 << " has acquired right chopstick" <<endl; 

            cout << "philosopher " << i+1 << "is eating"<<endl;
            usleep(1500000);
            sem_post(&chopsticks[i]);
            sem_post(&chopsticks[(i+1)%n]);
            cout << "philosopher " << i+1 << "dropped and done with eating"<<endl;
            return 0;
        }
        else
        {
            cout << "fork failed" <<endl;
        }
    }
    // wait for semaphores to finish
    int status;
    for(int i =0;i<n;i++)
    {
        wait(&status);
    }
    // destroy semaphores
    for(int i =0;i<n;i++)
    {
       sem_destroy(&chopsticks[i]);
    }
    return 0;
}