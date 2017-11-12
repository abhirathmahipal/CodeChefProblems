#include <iostream>
#include <vector>

using namespace std;
vector <int> solutions(10000, 0);

int recurse(int base) {
    if (base <= 3) {
        return 0;
    } else {
        if (solutions[base] != 0) {
            return solutions[base];
        } else {
            int result = (base / 2) - 1 + recurse(base - 2);
            solutions[base] = result;
            return result;
        }
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int b; 
        cin >> b;
        cout << recurse(b) << endl;
    }

    return 0;
}