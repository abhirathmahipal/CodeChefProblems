#include <iostream>

using namespace std;

int main() {
    // taking the greedy approach
    // we have values at regular intervals
    // and therefore don't need to use dynamic programming

    int t; 
    cin >> t;
    int powers[12];
    powers[0] = 1;

    for(int i = 1, j = 1; i < 12; i++) {
        j *= 2;
        powers[i] = j;
    }
    while(t--) {
        int p;
        cin >> p;
        int count = 0;

        for (int i = 11; p != 0;) {
            if (p >= powers[i]) {
                p -= powers[i];
                count++;
            } else {
                i--;
            }
        }
        cout << count << endl;
    }


    return 0;
}