#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int my_binary_search(int *haystack, int size, int needle) {
    int result = -1;
    for (int start = 0, end = size - 1, mid = (start + end) / 2; start <= size && end >= 0; mid = (start + end) / 2) {
        if (haystack[mid] == needle) {
            result = mid;
            break;
        } else if (haystack[mid] > needle) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }    
    return result;
}


int main() {
    int frog_count, range, pairs;
    cin >> frog_count >> range >> pairs;

    int positions[frog_count];
    int sorted_positions[frog_count];
    int max_reach[frog_count];

    for (int i = 0; i < frog_count; i++) {
        cin >> positions[i];
        sorted_positions[i] = positions[i];
    }

    sort(&sorted_positions[0], &sorted_positions[frog_count]);

    // reverse order filling maximum distances reachable
    max_reach[frog_count - 1] = sorted_positions[frog_count - 1] + range;
    for (int i = frog_count - 2; i > -1; i--) {
        int unaided_range = sorted_positions[i] + range;
        if(unaided_range >= sorted_positions[i + 1]) {
            max_reach[i] = max_reach[i + 1];
        } else {
            max_reach[i] = unaided_range;
        }
    }

    // for (int i = 0; i < frog_count; i++) {
    //     cout << sorted_positions[i] << " - " << max_reach[i] << endl;
    // }

    int source, destination;
    for (int i = 0; i < pairs; i++) {
        cin >> source >> destination;
        int first = min(positions[source - 1], positions[destination - 1]);
        int second = max(positions[source - 1], positions[destination - 1]);

        int pos_in_sorted_array = my_binary_search(sorted_positions,frog_count, first);
        if (max_reach[pos_in_sorted_array] >= second) cout << "Yes" << endl;
        else cout << "No" << endl;
    }


    return 0;
}