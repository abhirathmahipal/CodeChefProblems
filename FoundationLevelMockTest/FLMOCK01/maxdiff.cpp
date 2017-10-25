#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    int total, group;
    int items[101];
    while(t--) {
        cin >> total >> group;
        long long weight = 0;

        for (int i = 1; i <= total; i++) {
            cin >> items[i];
            weight += items[i];
        }

        // The possibility that the other group can be bigger.
        // hence we find both the differences.

        sort(&items[1], &items[total+1]);

        int iter_count = min(total - group, group);
        // cout << iter_count << endl;
        // for (int i = 1; i <= total; i++) {
        //     cout << items[i] << " ";
        // }
        long long weight_copy = weight;
        for (int i = 1; i <= iter_count; i++) {
            weight_copy -= (2 * items[i]);
        }


        cout << weight_copy << endl;
    }

    return 0;
}