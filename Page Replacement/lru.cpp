#include <bits/stdc++.h>
using namespace std;

int main()
{
    int capacity = 4;
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    unordered_set<int> s;
    map<int,int>map;
    int miss=0,hit=0;
    for(int i =0;i<n;i++)
    {
        if(s.size()<capacity)
        {
            if(s.find(pages[i])==s.end())
            {
                s.insert(pages[i]);
                miss++;
            }
                map[pages[i]]=i;
        }
        else
        {
            if(s.find(pages[i])==s.end())
            {
                int lru=INT_MAX,val;
                 for (auto it=s.begin(); it!=s.end(); it++) 
                { 
                    if (map[*it] < lru) 
                    { 
                        lru = map[*it]; 
                        val = *it; 
                    } 
                } 
                s.erase(val);
                s.insert(pages[i]);
            }
            map[pages[i]]=i;
        }
    }
    cout << miss << " " << abs(n-miss) << endl;
    return 0;
}
