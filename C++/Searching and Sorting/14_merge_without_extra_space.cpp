/*
Idea: (as we can't use extra space)

Separating elements which will be in first or second array in final answer,
then sorting individual elements.

Steps (while sorting after separating):
-setting up indices as last element of 1st array and first element of 2nd array
-traversing & swapping elements, if 1st array has larger elements
-sorting arrays
*/

#include <bits/stdc++.h> 
using namespace std;


class Solution
{
public:
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        int ind1 = n - 1, ind2 = 0;
        while (ind1 >= 0 && ind2 < m)
        {
            // checking if any element in 1st array is bigger & swapping if any.
            if (arr1[ind1] >= arr2[ind2])
                swap(arr1[ind1], arr2[ind2]);
            ind1--;
            ind2++;
        }
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};


int main()
{

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        long long arr1[n], arr2[m];

        for (int i = 0;i < n;i++) {
            cin >> arr1[i];
        }

        for (int i = 0;i < m;i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);

        for (int i = 0; i < n; i++)
            cout << arr1[i] << " ";


        for (int i = 0; i < m; i++)
            cout << arr2[i] << " ";

        cout << endl;
    }

    return 0;
}
