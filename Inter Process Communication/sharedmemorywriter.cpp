#include <bits/stdc++.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
using namespace std;

int main()
{
    key_t key=ftok("shmfile",65);
    int shmid=shmget(key,1026,0666|IPC_CREAT);
    char* str=(char*)shmat(shmid,(void*)0,0);
    cout << "enter string";
    cin >> str;
    // detach from shared memory
    shmdt(str);
    return 0;
}