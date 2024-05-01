#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n=8;
    int arr[n] = { 176, 79, 34, 60, 92, 11, 41, 114 };
    int head = 50;
    int seekdist=0;
    int disksize=200;
    vector<int>right,left;
    string distance="right";
    for(int i =0;i<n;i++)
    {
        if(arr[i]>head)
        {
            right.push_back(arr[i]);
        }
        else
        {
            left.push_back(arr[i]);
        }
    }
    // traverse right now
    right.push_back(disksize); // important
    sort(right.begin(),right.end());
    vector<int>seek;
    int cur=0;
    for(int i =0;i<right.size();i++)
    {
        seek.push_back(right[i]);
        cur=head;
        seekdist += abs(cur-right[i]);
        head=right[i];
    }
    seekdist += abs(head);
    head=0;
    seek.push_back(0);
    sort(left.begin(),left.end());
    for(int i =0;i<left.size();i++)
    {
        seek.push_back(left[i]);
        cur=head;
        seekdist += abs(cur-left[i]);
        head=left[i];
    }
    cout << seekdist<<endl;
    for(int i=0;i<seek.size();i++)
    {
        cout << seek[i] <<endl;
    }
    return 0;
}