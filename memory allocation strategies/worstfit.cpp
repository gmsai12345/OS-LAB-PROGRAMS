#include <bits/stdc++.h>
using namespace std;

int main()
{
     int blockSize[] = {100, 500, 200, 300, 600}; 
    int processSize[] = {212, 417, 112, 426}; 
    int n=4,m=5;
    int allocation[n],allocation1[m];
    // allocation array for process and allocation array for memory to keep track
    for(int i =0;i<n;i++)
    {
        allocation[i]=-1;
    }
    for(int i =0;i<m;i++)
    {
        allocation1[i]=-1;
    }
    for(int i =0;i<n;i++)
    {
        int maxi=INT_MIN;
        int maxindex=-1;
        for(int j=0;j<m;j++)
        {
           if(processSize[i]<=blockSize[j]&&allocation1[j]==-1&&(blockSize[j]-processSize[i])>=maxi)
           {
                maxi=blockSize[j]-processSize[i];
                maxindex=j;
           }
        }
        if(maxindex!=-1)
        {
             allocation[i]=maxindex;
             allocation1[maxindex]=1;
        }
    }
     cout << "\nProcess No.\tProcess Size\tBlock no.\n"; 
    for (int i = 0; i < n; i++) 
    { 
        cout << " " << i+1 << "\t\t\t\t" 
             << processSize[i] << "\t\t\t\t"; 
        if (allocation[i] != -1) 
            cout << allocation[i]+1 ; 
        else
            cout << "Not Allocated"; 
        cout << endl; 
    } 
    return 0;
}