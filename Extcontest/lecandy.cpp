#include <iostream>
#include <vector>

using namespace std;
int main() {
    int t, elephant_count, candy_count;
    int temp_holder;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> elephant_count >> candy_count;
        for (int j = 0; j < elephant_count; j++) {
            cin >> temp_holder;
            candy_count -= temp_holder;
        }

        if (candy_count >= 0) cout << "Yes\n";
        else cout << "No\n";

    }

    return 0;
}