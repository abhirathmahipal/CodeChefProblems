#include<iostream>
#include<vector>
#include<map>

using namespace std;

// Used the editorial again :/
int main() {
    int t;
    int min[32];
    // min calculation in the start itself
    min[0] = 0, min[1] = 2, min[2] = 5;
    for (int i = 3; i < 31; i++) {
        int mid = i / 2;
        min[i] = min[mid] + min[i - mid - 1] + i + 1; // draw the splitting recurrence as mentioned in the tutorial
        // remember that the center connects to the right end, hence we add i to the solution
    }
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        bool spots[n + 2]; // two for the wall
        spots[0] = true, spots[n + 1] = true;
        
        // checking for maximum
        int max = ((n * n) + 3 * n) / 2; // maximum is always in continous order
        // so use n * (n + 1) / 2 to derive the above formula

        if (m  >= max) {
            cout << m - max << endl;
        } else if (m < min[n]) {
            cout << "-1" << endl;
        } else {
            cout << '0' << endl; // it is explained in the editorial that every value between min and max is attainable
        }
    }

    return 0;
}