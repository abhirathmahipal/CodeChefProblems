#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// not using a top-down approach now but letting the code be there
// this isn't used at all
int recurse_memoize(vector <int> *table, int distance, int *petrol_capacity, int petrol_cap_count) {

    // base case
    if (distance == 0) {
        return 0;
    }

    // even if we reach here, it should work
    // made sure we don't reach here though.
    if (distance < 0) {
        return 9999999;
    }

    // if memoized use it
    if ((*table)[distance] != 9999999) {
        return (*table)[distance];
    }

    int solution;
    for (int i = 0; i < petrol_cap_count; i++) {
        // cout << "Calculating for distance " << distance << " sending out a call for " << distance - petrol_capacity[i] << endl;
        if (petrol_capacity[i] <= distance) {
            solution = min(recurse_memoize(table, distance - petrol_capacity[i], petrol_capacity, petrol_cap_count) + 1, (*table)[distance]);
            (*table)[distance] = solution;
        }
        // cout << "updated solution to " << solution << endl;
    }

    // cout << "Solution for distance " << distance << " is " << solution << endl;
    (*table)[distance] = solution;
    return solution;

}

int main() {
    int t;
    cin >> t;

    while(t--) {
    int orders;
    cin >> orders;
    int distances[orders];
    int bunks[orders];

    // memoisation table
    vector <int> optimal_solution_for_distances(1005, 9999999);
    optimal_solution_for_distances[0] = 0;

    int largest_distance = -999999; int temp;
    for (int i = 0; i < orders; i++) {
        cin >> temp;
        distances[i] = 2 * temp;
        if (distances[i] > largest_distance) largest_distance = distances[i];

    }

    // let there be duplicates. It doesn't effect us
    for (int i = 0; i < orders; i++){
        cin >> bunks[i]; // kind of like getting the coin values
    }
    sort(&bunks[0], &bunks[orders]);
    // recurse_memoize(&optimal_solution_for_distances, largest_distance, bunks, orders);
    int solution = 0;

    // using bottom up approach this time
    for (int i = 0; i <= largest_distance; i++) {
        for (int j = 0; j < orders; j++) {
            if (bunks[j] > i) break;
            optimal_solution_for_distances[i] = min(optimal_solution_for_distances[i], optimal_solution_for_distances[i - bunks[j]] + 1);
        }
    }
    for (int i = 0; i < orders; i++) {
        // cout << "Distance " << distances[i] << " - " << optimal_solution_for_distances[distances[i]] << endl;
        solution += optimal_solution_for_distances[distances[i]];
    }
    // for (int i = 0; i <= largest_distance; i++) {
    //     cout << i << " - " << optimal_solution_for_distances[i] << endl;
    // }

    cout << solution << endl;

    }
    return 0;
}