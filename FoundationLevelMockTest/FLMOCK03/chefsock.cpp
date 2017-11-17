#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int j, s, m;
    cin >> j >> s >> m;
    string answer;
    int afterJacket = m - j;
    if (afterJacket >= 0) {
        int numberOfSocks = (afterJacket == 0) ? 0 : afterJacket / s;
        answer = (numberOfSocks % 2 == 0) ? "Lucky Chef" : "Unlucky Chef";
        cout << answer;
    } else {
        int numberOfSocks = m / s;
        answer = (numberOfSocks % 2 == 0) ? "Lucky Chef" : "Unlucky Chef";
        cout << answer;
    }
    cout << '\n';

    return 0;
}