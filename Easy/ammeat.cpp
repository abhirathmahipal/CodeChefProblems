#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
int main()
{
    int test_cases, plate_count, min_plates = 0;
    long long plate_capacity[7], requirement;

    bool isEnough = false;

    cin >> test_cases;

    for (int i = 0; i < test_cases; i++)
    {
        scanf("%d %lld", &plate_count, &requirement);

        for (int j = 0; j < plate_count; j++)
            cin >> plate_capacity[j];

        sort(plate_capacity, plate_capacity + plate_count);

        while(plate_count)
        {
            requirement -= plate_capacity[--plate_count];
            min_plates++;
            if(requirement <= 0)
            {
                isEnough = true;
                break;
            }
        }
        
        if(isEnough)
            cout << min_plates <<  endl;
        else
            cout << -1 << endl;
    
        isEnough = false;
        min_plates = 0;
    }

    return 0;
}

