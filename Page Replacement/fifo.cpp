#include <bits/stdc++.h>
using namespace std;

int main()
{
    int capacity=4;
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 
                   2, 3, 0, 3, 2};
    int n = sizeof(pages)/sizeof(pages[0]); 
    unordered_set<int>s;
    queue<int>index;
    int miss=0,hit=0;
    for(int i =0;i<n;i++)
    {
        if(s.size()<capacity)
        {
            if(s.find(pages[i])==s.end())
            {
                s.insert(pages[i]);
                index.push(pages[i]);
                miss++;
            }
        }
        else
        {
            if(s.find(pages[i])==s.end())
            {
                int val=index.front();
                index.pop();
                s.erase(val);
                s.insert(pages[i]);
                index.push(pages[i]);
                miss++;
            }
            else
            {
                hit++;
            }
        }
    }    
    cout << "hit " << hit << " miss " <<miss <<endl; 
    return 0;
}