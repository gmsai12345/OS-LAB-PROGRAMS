#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>
using namespace std;
struct process
{
    int procnum;
    int bur;
    int arr;
    int tut;
    int wai;
    int rem;
};
bool compareBurstTime(const process &a, const process &b)
{
    return a.bur < b.bur;
}
// main thing here is for each time lap we are doing it to find the minimum time
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
        int arr,bur;
        cout << "enter arrival time && burst time:";
        cin >> arr >> bur;
        v[i].procnum=i+1;
        v[i].arr=arr;
        v[i].bur=bur;
        v[i].tut=0;
        v[i].wai=0;
        v[i].rem=bur;
        cout <<endl;
    }
    int maxi=1e7;
   int completed=0;
   int remm=maxi;
   int rems=-1;
   while (completed < n) {
    int minIndex = -1;
    int minRemTime = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (v[i].arr <= t && v[i].rem < minRemTime && v[i].rem > 0) {
            minIndex = i;
            minRemTime = v[i].rem;
        }
    }
    // important at that time if process is not there then you just increament t and continue important part of the logic
    if (minIndex == -1) {
        t++;
        continue;
    }

    v[minIndex].rem--;

    if (v[minIndex].rem == 0) {
        completed++;
        v[minIndex].tut = t + 1 - v[minIndex].arr;
        v[minIndex].wai = v[minIndex].tut - v[minIndex].bur;
        tottua += v[minIndex].tut;
        totwai += v[minIndex].wai;
    }

    t++;
}
     for(int i =0;i<n;i++)
    {
        cout << v[i].procnum << " completed at: " << t << " waiting time: " << v[i].wai << " turnaround time: " << v[i].tut <<endl; 
    }
    cout << "average waiting time: " << totwai/n << endl << "average turnaround time: " << tottua/n << endl;  
    return 0;
}