#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t; 
    cin >> t;
    while(t--){
        string input;
        cin >> input;
        int mid;
        if (input.length() % 2 == 0) mid = input.length() / 2 - 1;
        else mid = input.length() / 2 - 1;

        int i, j;
        vector <int> store1(26, 0);
        vector <int> store2(26, 0);
        for (i = 0, j = input.length() - 1; i <= mid; i++, j--) {
            store1[input[i] - 'a']++;
            store2[input[j] - 'a']++;
        }

        bool match = true;
        for (int i = 0; i < 26; i++) {
            if (store1[i] != store2[i]) {
                match = false;
                break;
            }
        }
        if (match) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}