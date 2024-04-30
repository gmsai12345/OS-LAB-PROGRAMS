#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct process {
    int procnum;
    int bur;
    int arr;
    int tut;
    int wai;
    int rem;
};

bool compareBurstTime(const process &a, const process &b) {
    return a.bur < b.bur;
}

int main() {
    int n, q;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the quantum slice: ";
    cin >> q;

    int tottua = 0, totwai = 0;
    int t = 0;
    vector<process> v(n);

    for (int i = 0; i < n; i++) {
        int arr, bur;
        cout << "Enter arrival time and burst time for process " << i + 1 << ": ";
        cin >> arr >> bur;
        v[i].procnum = i + 1;
        v[i].arr = arr;
        v[i].bur = bur;
        v[i].tut = 0;
        v[i].rem = bur;
        v[i].wai = 0;
    }

    vector<bool> visited(n, false); // Initialize visited array with false

    int completed = 0;
    int i = 0;

    while (completed < n) {
        if (v[i].rem != 0) {
            int slice = min(q, v[i].rem);
            t += slice;
            v[i].rem -= slice;
        }
            if (v[i].rem == 0&&!visited[i]) {
                completed++;
                visited[i] = true; // Mark process as visited
                v[i].tut = t - v[i].arr;
                v[i].wai = v[i].tut - v[i].bur;
                cout << "Process " << v[i].procnum << " completed at time " << t 
                     << ", waiting time: " << v[i].wai << ", turnaround time: " << v[i].tut << endl;
            }
        

        // Move to the next process
        i = (i + 1) % n;
    }

    return 0;
}
