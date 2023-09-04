/*
Idea: finding the first point from end, where two elements are in increasing order
once found, replace the latter element with next greater element and reversing the array
*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> nextPermutation(int N, vector<int> arr)
    {
        int i, j;
        for (i = N - 2;i >= 0;--i)
        {
            // finding 2 elements which are in increasing order
            if (arr[i] < arr[i + 1])
                break;
        }
        if (i < 0)
            // if array is in decsending order, next permutation is reversed of current.
            reverse(arr.begin(), arr.end());
        else
        {
            //finding the next greater element in the array after the pivot point
            for (j = N - 1; j > i; j--)
                if (arr[j] > arr[i])
                    break;
            swap(arr[i], arr[j]);
            reverse(arr.begin() + i + 1, arr.end()); // reversing the rest of array
        }
        return arr;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0;i < N;i++)
            cin >> arr[i];

        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for (int u : ans)
            cout << u << " ";
        cout << "\n";
    }
    return 0;
}