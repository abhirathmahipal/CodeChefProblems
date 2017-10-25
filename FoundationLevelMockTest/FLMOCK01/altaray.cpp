#include <vector>
#include <iostream>

using namespace std;

char sign_return(int foo) {
    return (foo > 0) ? '+' : '-';
}
int main() {
    int t, numbers[1000002], n;
    cin >> t;
    while(t--) {
        vector <pair <int, int> > sub_arrays;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> numbers[i];
        }

        char sign = (sign_return(numbers[1]) == '+') ? '-' : '+'; // getting opposite sign
        int start = 1, last = 0;
        for (int i = 1; i <= n;i++) {
            if (sign_return(numbers[i]) != sign) {
                last++;
            }
            else {

                sub_arrays.push_back(std::make_pair(start, last));
                start = i;
                last = i;
            }
            sign  = sign_return(numbers[i]);
        }
        sub_arrays.push_back(std::make_pair(start, last));

        // iterating over each pair
        for (vector<pair<int, int> >::iterator it = sub_arrays.begin(); it != sub_arrays.end(); it++) {
            int a = it->first, b = it->second;
            // cout << "a is " << a << "  " << "b is " << b << "  ";
            if (a == b) cout << "1 ";
            else {
                for (int i = a; i <= b; i++) {
                    cout << (b - i + 1) << ' ';
                }
            }
        }

        cout << endl;
    }


    return 0;
}