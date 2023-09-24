/*
Idea:
Using sort with custom comparator
stable_sort- is used to maintain the relative order of elements with the same count of set bits
__builtin_popcount- counts the number of set bits in the binary representation of integer
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // custom comparator of std::sort
    static int cmp(int a, int b)
    {
        int count1 = __builtin_popcount(a);
        int count2 = __builtin_popcount(b);

        // this takes care of the stability of sorting algorithm too
        if (count1 <= count2)
            return false;
        return true;
    }

    // Function to sort according to bit count using  std::sort
    void sortBySetBitCount(int arr[], int n)
    {
        stable_sort(arr, arr + n, cmp);
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0;i < n;i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
