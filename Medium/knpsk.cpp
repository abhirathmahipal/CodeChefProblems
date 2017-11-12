#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>

// TLE in this problem becuase I've used dynamic programming
// the editorial says to use a greedy approach (special weights in this problem allow the usage of a greedy algorithm)

typedef long long LL;
using namespace std;
typedef pair<int, LL> PIL;

typedef struct weightcost {
   int weight;
   int cost;
} weigth_cost;

int n;
vector <weightcost> weight_cost(100001);
map <PIL, LL> memo_table;

bool sortWeightCost(weightcost a, weightcost b) {
    if (a.weight != b.weight) {
        return a.weight < b.weight;
    } else {
        return a.cost > b.cost;
    }
}

LL solve(int capacity, LL acc_cost, LL start) {


    if (capacity < weight_cost[start].weight || start > n) {
        return acc_cost;
    }
    PIL key = make_pair(capacity, start);
    if (memo_table.find(key) != memo_table.end()) {
        return memo_table[key] + acc_cost;
    }

    LL solution = max(solve(capacity - weight_cost[start].weight, acc_cost + weight_cost[start].cost, start + 1), 
                solve(capacity, acc_cost, start + 1));

    memo_table[key] = solution - acc_cost;
    return solution;
}

int main() {
    cin >> n;
    int total_weight = 0;
    
    LL sum_of_all_costs = 0; // for the optimal cost of total weight capacity bag
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &weight_cost[i].weight, &weight_cost[i].cost);
        // cin >> weight_cost[i].weight >> weight_cost[i].cost;
        total_weight += weight_cost[i].weight;
        sum_of_all_costs += weight_cost[i].cost;
    }

    sort(&weight_cost[1], &weight_cost[n + 1], &sortWeightCost);

    LL optimal[total_weight + 1]; // to easily index by capacity instead of weight - 1 notation
    optimal[total_weight] = sum_of_all_costs;

    for (int i = total_weight - 1; i > 0; i--) {
        optimal[i] = solve(i, 0, 1);
    }

    // bottom-up approach

    // testing if sorting worked or not
    // for (int i = 1; i <= n; i++) {
    //     cout << weight_cost[i].weight << ' ' << weight_cost[i].cost << endl;
    // }


    for (int i = 1; i <= total_weight; i++) {
        printf("%lld ", optimal[i]);
        // cout << optimal[i] << " ";
    }


    return 0;
}