#include <iostream>
#include <stack>

using namespace std;

int main() {
    int t;
    cin >> t;
    string input;
    stack <char> track;
    while(t--) {
        cin >> input;
        int i;
        int last = 0;
        int len = 0;
        int counter = 0;
        for (i = 0; input[i] != '\0'; i++) {
            // referred a solution from github
            if (input[i] == '<') counter++;
            else counter--;
            if (counter < 0) {
                cout << len << endl;
                break;
            }
            len++;
            if (counter == 0) {
                last = len;
            }

        }
        if(input[i] == '\0') cout << last << endl;

    }

    return 0;
}
