#include <bits/stdc++.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int factorial(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return n*factorial(n-1);
    }
}
int main()
{
    // 0 to read message from respective pipe and 1 to write message to 
    // your pipe
    int pipefds1[2],pipefds2[2];
    int return1,return2,pid;
    char pipe1wm[20]="compute factorial";
    char readm[20];
    int n;
    return1=pipe(pipefds1);
    if(return1==-1)
    {
        cout << "unable to create pipe 1"<<endl;
        return -1;
    }
    return2=pipe(pipefds2);
    if(return2==-1)
    {
        cout << "unable to create pipe 2"<<endl;
        return -1;
    }
    pid=fork();
    if(pid!=0)
    {
        cout << "enter a number"<<endl;
        cin >>n;
        write(pipefds1[1],&n,sizeof(n));
        read(pipefds2[0],&n,sizeof(n));
        cout << "factorial computed by " << n <<endl;
    }
    else
    {
        read(pipefds1[0],&n,sizeof(n));
        n=factorial(n);
        write(pipefds2[1],&n,sizeof(n));
    }
    return 0;

}