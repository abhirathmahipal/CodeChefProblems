#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        string input;
        stack <string> print_order;
        cin >> input;
        for (int i = input.length() - 1; i > -1; i--) {
            if (input[i] == '?' || input[i] == 'F') {
                if (i - 3 > -1 && (input[i - 1] == '?' || input[i -1] == 'E') && (input[i - 2] == '?' || input[i - 2] == 'H') && (input[i - 3] == '?' || input[i - 3] == 'C')) {
                    print_order.push("CHEF");
                    i -= 3;
                } else {
                    if (input[i] == '?') print_order.push("A");
                    else {
                        print_order.push(string(1, input[i]));
                    }
                }
            } else {
                print_order.push(string(1, input[i]));
                continue;
            }
        }
        while(!print_order.empty()) {
            cout << print_order.top();
            print_order.pop();
        }

        cout << '\n';
    }


}