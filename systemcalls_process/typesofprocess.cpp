#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;
int main()
{
    // creating child process
    pid_t pid;
    pid=fork();

    if(pid==0)
    {
        cout<< "child process 1"<<endl;
        cout << getpid()<<endl;
    }
    else if(pid>0)
    {
        cout << "parent process 1"<<endl;
        cout << getpid();
    }
    else
    {
        cout << "Fork failed 1"<<endl;
    }
    // orphan process
    pid_t pid1;
    pid1=fork();
    if(pid1==0)
    {
        cout << "child process 2" <<getpid() <<endl;
        sleep(10);
    }
    else if(pid1>0)
    {
        cout << "parent process 2" << getpid();
    }
    else
    {
        cout << "fork failed 2"<<endl;
    }
    //zombie process
    pid_t pid2;
    pid2=fork();
   if(pid1==0)
    {
        cout << "child process 3" <<getpid() <<endl;
    }
    else if(pid2>0)
    {
        cout << "parent process 3" << getpid()<<endl;
        sleep(10);
        int status;
        wait(&status); // Wait for the child process to terminate
    }
    else
    {
        cout << "fork failed 3"<<endl;
    }
}