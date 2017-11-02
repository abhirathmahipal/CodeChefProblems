#include <iostream>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

int main() {
    // referred solution :(
    // max xor can be 1023 (obvious because max number is 1000)
    int t;
    cin >> t;
    while(t--) {
        bool xor_exists[1024];
        memset(xor_exists, false, sizeof(bool) * 1024);
        int n, k;
        cin >> n >> k;
        int elements[n];
        for (int i = 0; i < n; i++) {
            cin >> elements[i];
        }
        int answer = k; // k is definitely possible so setting it
        xor_exists[0] = true; // 0 can be made from the set is what it means, empty sets are zero na
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 1024; j++) {
                // copied from a solved problen
                // we basically set if a particular xor can be made
                // using the previous xor's that can be made using a set
                // we find new xor values that can be obtained with every 
                // additional element from the set
                int xor_so_created = j ^ elements[i];
                if (xor_exists[j] || xor_exists[xor_so_created]){
                    xor_exists[xor_so_created] = true;
                }
            }
        }

        for (int i = 0; i < 1024; i++) {
            // checking the max with each possible value of xor
            if (xor_exists[i])
                answer = max(answer, k ^ i);
        }

        cout << answer << endl;
    }


    return 0;
}