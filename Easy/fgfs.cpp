#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

// google activity selection problem to know more about this algorithm

typedef struct customer {
    int start, finish; // int compartment
} customer;

bool customSort(customer a, customer b) {

    // if (a.compartment < b.compartment) {
    //     return true;
    // } else if (a.compartment > b.compartment) {
    //     return false;
    // } else { // compartments are equal
        // if (a.finish > b.finish) return false;
        // else return true;
    // }

    return a.finish < b.finish;
}


int main() {


    // referred solution when time limit exceeded
    // I think large sorts are causing problems
    // therefore splitting it into smaller chunks
    map <int, int> mapToPos;
    vector <vector<customer> > customers(100000);

    int t, n, k;

    cin >> t;
    while(t--) {
        cin >> n >> k;
        int s, f, p;
        int pos = -1;
        for (int i = 1; i <= n; i++) {
            cin >> s >> f >> p;
            customer temp;
            temp.start = s; temp.finish = f; //temp.compartment = p;
            if (mapToPos.find(p) == mapToPos.end()) {
                mapToPos[p] = ++pos;
            }
            customers[mapToPos[p]].push_back(temp);
        }

        long long answer = 0;
        // sort(&customers[1], &customers[n + 1], &customSort);
        for (int i = 0; i <= pos; i++) {
            // cout << "sorting pos " << i << " relates to room " << endl;
            int maxi = customers[i].size();
            sort(&customers[i][0], &customers[i][maxi], &customSort);
            // cout << "pos " << i << endl;
            // for (int a = 0; a < maxi; a++) cout << customers[i][a].finish << ' ';
            // cout << endl;
            int end = customers[i][0].finish;
            answer++; // first customer is always served
            for (int j = 1; j < maxi; j++) {
                // cout << customers[i][j].start << " " << end << endl;
                if (customers[i][j].start >= end) {
                    answer++;
                    end = customers[i][j].finish;
                }
            }
            // cout << "Done sorting for " << i << endl;
        }

        // for (int i = 1; i <= n;  i++) {
        //     int compartment = customers[i].compartment;
        //     int next_customer_compartment;
        //     int end = customers[i].finish;
        //     answer++; // first customer of the compartment
        //     while(i <= n) {
        //         next_customer_compartment = customers[i + 1].compartment;
        //         if (next_customer_compartment != compartment || i > n) {
        //             break;
        //         }
        //         if (customers[++i].start >= end) {
        //             answer++;
        //             end = customers[i].finish;
        //         }
        //     }
        // }


        // cout << "done calculation" << endl;
        cout << answer << endl;
        mapToPos.clear();
        for (int i = 0; i <= pos; i++)
            customers[i].clear();
    }




    return 0;
}