#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n=8;
    int arr[n] = { 176, 79, 34, 60, 92, 11, 41, 114 };
    int head = 50;
    int seekdist=0;
    int curr=0;
    for(int i=0;i<n;i++)
    {
        curr=head;
        seekdist += abs(curr-arr[i]);
        head=arr[i];
    }
    // print seek sequence
    for(int i =0;i<n;i++)
    {
        cout << arr[i] << " ->  ";
    }
    cout <<endl;
    cout << "seekdist = " << seekdist <<endl;
    return 0;
}