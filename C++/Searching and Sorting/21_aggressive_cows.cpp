/*
Idea:
sorting the array, and using binary search to solve
-at each iteration of calculating 'mid' of the array,
 checking if all cows can be placed in the array at distance calculated by 'mid'
*/


#include <bits/stdc++.h>
using namespace std;

bool canPlaceCows(const vector<int>& stalls, int n, int c, int minDist) {
    int cowsPlaced = 1;
    int lastPosition = stalls[0];

    for (int i = 1; i < n; ++i) {
        if (stalls[i] - lastPosition >= minDist)
            // putting each cow in position with distance between them as 'minDist'
        {
            cowsPlaced++;
            lastPosition = stalls[i];
        }

        if (cowsPlaced == c) {
            return true;
        }
    }

    return false;
}

int largestMinDistance(vector<int>& stalls, int n, int c) {
    sort(stalls.begin(), stalls.end());

    int low = 1;  // Minimum possible distance
    int high = stalls[n - 1] - stalls[0];  // Maximum possible distance
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, n, c, mid))// checking if all cows can be placed in positions given
        {
            result = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> stallPositions(n);

        for (int i = 0; i < n; ++i) {
            cin >> stallPositions[i];
        }

        int result = largestMinDistance(stallPositions, n, c);
        cout << result << endl;
    }

    return 0;
}
