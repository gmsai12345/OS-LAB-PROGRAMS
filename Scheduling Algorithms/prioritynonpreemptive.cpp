#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct process
{
    int procnum;
    int bur;
    int arr;
    int tut;
    int wai;
    int priority;
};
bool comparePriority(const process &a, const process &b)
{
    return a.priority < b.priority;
}
int main()
{
    int n;
    cout << "Enter the number of the process"<<endl;
    cin >> n;
    int tottua=0,totwai=0;
    int t=0;
    vector<process>v(n);
    for(int i =0;i<n;i++)
    {
        int arr,bur,pri;
        cout << "enter arrival time && burst time:";
        cin >> arr >> bur;
        cout <<endl<< "enter priority";
        cin >> pri;
        v[i].procnum=i+1;
        v[i].arr=arr;
        v[i].bur=bur;
        v[i].tut=0;
        v[i].wai=0;
        v[i].priority=pri;
        cout <<endl;
    }
    sort(v.begin(),v.end(),comparePriority);
    for(int i =0;i<n;i++)
    {
        t=t+v[i].bur;
        v[i].tut=t-v[i].arr;
        v[i].wai=v[i].tut-v[i].bur;
        tottua += v[i].tut;
        totwai += v[i].wai;
        cout << v[i].procnum << " completed at: " << t << " waiting time: " << v[i].wai << " turnaround time: " << v[i].tut <<endl; 
    }
    cout << "average waiting time: " << totwai/n << endl << "average turnaround time: " << tottua/n << endl;  
    return 0;
}