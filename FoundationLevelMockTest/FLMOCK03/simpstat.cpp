#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int numbers[n];
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }
        sort(&numbers[0], &numbers[n]);
        double sum = 0;
        for (int i = 0 + k; i < n - k; i++){
            sum += numbers[i];
        }

        sum = sum / (double)(n - 2 * k);
        printf("%.6f\n", sum);        

    }
    return 0;
}