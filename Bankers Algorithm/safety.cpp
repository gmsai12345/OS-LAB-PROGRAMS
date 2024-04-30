#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n=5,m=3;
     int alloc[5][3] = { { 0, 1, 0 }, // P0 // Allocation Matrix
                     { 2, 0, 0 }, // P1
                     { 3, 0, 2 }, // P2
                     { 2, 1, 1 }, // P3
                     { 0, 0, 2 } }; // P4
 
  int max[5][3] = { { 7, 5, 3 }, // P0 // MAX Matrix
                   { 3, 2, 2 }, // P1
                   { 9, 0, 2 }, // P2
                   { 2, 2, 2 }, // P3
                   { 4, 3, 3 } }; // P4
 
  int avail[3] = { 3, 3, 2 }; // Available Resources
  int need[n][m];
  int finish[n];
  for(int i =0;i<n;i++)
  {
    finish[i]=0;
  }
  for(int i =0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
        need[i][j]=max[i][j]-alloc[i][j];
    }
  }
  int ans[n];
  int ind=0;
  int flag=1;
  // another for loop in top to just complete
  for(int k =0;k<5;k++)
  {
    for(int i=0;i<n;i++)
    {
        if(finish[i]==0)
        {
            int flag=0;
            for(int j=0;j<m;j++)
            {
                if(need[i][j]>avail[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                ans[ind++]=i;
                for(int y=0;y<m;y++)
                {
                    avail[y] += alloc[i][y];
                    finish[i]=1;
                }
            }
        }
    }
  }
  flag=1;
  for(int i=0;i<n;i++)
  {
    if(finish[i]==0)
    {
        flag=0;
        cout << "The given sequence is not safe";
        break;
    }
  }
  if(flag==1)
  {
    cout << "Following is the SAFE Sequence" << endl;
      for (int i = 0; i < n - 1; i++)
        cout << " P" << ans[i] << " ->";
      cout << " P" << ans[n - 1] <<endl;
  }
  return 0;
}