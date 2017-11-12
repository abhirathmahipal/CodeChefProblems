#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <map>
using namespace std;

typedef pair<int, int> PII;
typedef long long LL;


int gcdf(int a, int b) {
    if (b>a) {
        return gcdf(b, a);
    } else {
        return b == 0 ? a : gcdf(b, a%b);
    }
}
int t, n, numbers[150];
map <PII, LL> memo_table;

long dp_stuff(int pos, int gcd, int size) {
    if (pos == n) {
        if (gcd == 1 && size > 1) return 1;
        else return 0;
    }
    PII key = make_pair(pos, gcd);
    if (memo_table.find(key) != memo_table.end()) return memo_table[key];
    if (gcd == 1) {
        return pow(2, n - pos);
    } 
    // at each step taking a decision to pick it or not.
    // so all the permutations are ultimately visited
    return memo_table[key] = dp_stuff(pos + 1, gcd, size) + dp_stuff(pos + 1, gcdf(gcd, numbers[pos]), size + 1);
    // return dp_stuff(pos + 1, gcd, size) + dp_stuff(pos + 1, gcdf(gcd, numbers[pos]), size + 1);
}
int main() {
    cin >> t;
    while(t--) {
        cin >> n;


        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }
        // referred editorial for a better implemention :/
        // figured out the logic though

        // if you notice if you manage to get a single 1, everything can be made into 1's
        // we can brute force pairs and get an n2 algorithm. Any combination with that pair 
        // will result in one

        // any pair of coprime numbers can get the total to 1
        // so calculate HCF
        
        memo_table.clear();
        LL solution = 0;
        // starting at every position
        for (int i = 0; i < n; i++) solution += dp_stuff(i + 1, numbers[i], 1); // starting at every position, gcd is the current number
        cout << solution << endl;


    }
    return 0;
}