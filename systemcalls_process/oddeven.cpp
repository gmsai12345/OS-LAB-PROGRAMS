#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
void odd(int start,int end)
{
    for(int i =start;i<=end;i++)
    {
        if(i%2!=0)
        {
            cout << i<< " ";
        }
       
    } 
    cout <<endl;
}
void even(int start,int end)
{
    for(int i =start;i<=end;i++)
    {
        if(i%2==0)
        {
            cout << i<< " ";
        }
       
    } 
    cout <<endl;
}
int main()
{
    int start=1,end=20;
    pid_t child1,child2;
    child1=fork();
    if(child1<0)
    {
        cerr<< "fork failed"<<endl;
        return 1;
    }else if(child1==0)
    {
        cout << "odd number"<<endl;
        odd(start,end);
        exit(0);
    }
    else
    {
        child2=fork();
        if(child2<0)
        {
            cerr << "fork failed process 2"<<endl;
            return 1;
        } else if(child2==0)
        {
           cout <<"even numbers"<<endl;
            even(start,end);
            exit(0);
        }
        else
        {
            wait(NULL);
            wait(NULL);
            cout << "both process completed"<<endl;
        }
    }
   
    return 0;
}