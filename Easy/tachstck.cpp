#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    int lens[n], count = 0;

    for (int i = 0; i < n; i++)
        cin >> lens[i];

    sort(&lens[0], &lens[n]);


    for (int i = 0; i < n;) {
        int diff = abs(lens[i] - lens[i + 1]);
        if (diff <= d) {
            count++;
            i += 2;
        } else {
            i++;
        }
    }

    cout << count << endl;
    return 0;
}