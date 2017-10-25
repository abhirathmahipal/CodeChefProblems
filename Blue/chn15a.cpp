#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, count = 0, k;
        cin >> n >> k;
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            if ((temp + k) % 7 == 0) count ++;
        }

        cout << count << endl;
        count = 0;
        
    }

    return 0;
}