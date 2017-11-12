#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>


using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    char grid[1001][1001];
    while(t--) {
        // I'm aware that there are faster solutions but I like this approach
        // I feel it's more readable. If you introduce a new data type
        // that indicates mirror can't be placed but it doesn't block view
        // it becomes easier to understand

        
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s[^\n\0]", grid[i]);
        }

        // testing if input is right
        // for (int i = 0; i < n; i++) {
        //     printf("%s\n", grid[i]);
        // }
        
        // setting n + 1 th row and col to visible to avoid if condition
        for (int i = 0; i < n; i++) {
            grid[n][i] = '.';
            grid[i][n] = '.';
        }
        
        int count = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // adding a third type &. It is visible but cannot be used to set a mirror as it's blocked
                if (grid[i][j] == '#') {
                    int tempj = j, tempi = i;
                    while(--tempj >= 0) {
                        if (grid[i][tempj] == '.') {
                            // printf("j-- Changing [%d][%d] when i and j are [%d][%d]\n", i, tempj, i, j);
                            grid[i][tempj] = '&';
                        }
                    }
                    while(--tempi >= 0) {
                        if (grid[tempi][j] == '.') {
                            // printf("i-- Changing [%d][%d] when i and j are [%d][%d]\n", j, tempi, i, j);
                            grid[tempi][j] = '&';
                        }
                    }
                }
                if (grid[i][j] == '.' && grid[i + 1][j] != '#' && grid[i][j + 1] != '#') {
                    count++;
                }
            }
        }

        cout << count << endl;
        // for (int i = 0; i <= n; i++) {
        //     printf("%s\n", grid[i]);
        // }
    }
    return 0;
}