/*
Idea:
finding mid point at each iteration , summing difference between each element & mid found.
If sum is found , return.
*/


#include<bits/stdc++.h>
using namespace std;



class Solution
{
public:
    int solve(int arr[], int n, int m)
    {
        sort(arr, arr + n);
        int low = 0, high = arr[n - 1], result = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2; // assuming the required height is found
            long long sum = 0;

            for (int i = 0; i < n; ++i) // summming total height of wood cut
                if (arr[i] > mid)
                    sum += arr[i] - mid;

            if (sum >= m) // if cut wood is more than required
            {
                result = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        return result;
    }
};


int main() {

    int n, m;
    cin >> n >> m;
    int A[n];
    for (int i = 0;i < n;i++)
        cin >> A[i];
    Solution ob;
    cout << ob.solve(A, n, m) << endl;
    return 0;
}
