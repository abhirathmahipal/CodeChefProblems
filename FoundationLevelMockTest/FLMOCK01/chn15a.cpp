#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    int minion_config[101];
    while(t--) {
        int num, sum, count = 0;
        cin >> num >> sum;

        for (int i = 0; i < num; i++) {
            cin >> minion_config[i];
            minion_config[i] += sum;
            if (minion_config[i] % 7 == 0) count++;
        }
        cout << count << endl;

    }

    return 0;
}