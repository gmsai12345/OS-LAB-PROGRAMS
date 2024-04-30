#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

struct process {
    int procnum;
    int bur;
    int arr;
    int tut;
    int wai;
    int rem;
    int priority;
};

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int tottua = 0, totwai = 0, t = 0, completed = 0;
    vector<process> v(n);

    for (int i = 0; i < n; i++) {
        int arr, bur, pri;
        cout << "Enter arrival time and burst time for process " << i + 1 << ": ";
        cin >> arr >> bur;
        cout << "Enter priority for process " << i + 1 << ": ";
        cin >> pri;
        v[i].procnum = i + 1;
        v[i].arr = arr;
        v[i].bur = bur;
        v[i].tut = 0;
        v[i].wai = 0;
        v[i].rem = bur; // Initialize remaining time to burst time
        v[i].priority = pri;
    }

    while (completed < n) {
        int minIndex = -1;
        int minPriority = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (v[i].arr <= t && v[i].priority < minPriority && v[i].rem > 0) {
                minIndex = i;
                minPriority = v[i].priority;
            }
        }

        if (minIndex == -1) {
            t++; // No process arrived yet, move to the next time unit
            continue;
        }

        v[minIndex].rem--;

        // Check if the current process has completed
        if (v[minIndex].rem == 0) {
            completed++;
            v[minIndex].tut = t + 1 - v[minIndex].arr;
            v[minIndex].wai = v[minIndex].tut - v[minIndex].bur;
            tottua += v[minIndex].tut;
            totwai += v[minIndex].wai;
        }

        t++; // Move to the next time unit
    }

    // Output results
    for (int i = 0; i < n; i++) {
        cout << "Process " << v[i].procnum << " completed at time " << t 
             << ", waiting time: " << v[i].wai << ", turnaround time: " << v[i].tut << endl;
    }

    cout << "Average waiting time: " << (float)totwai / n << endl;
    cout << "Average turnaround time: " << (float)tottua / n << endl;

    return 0;
}
