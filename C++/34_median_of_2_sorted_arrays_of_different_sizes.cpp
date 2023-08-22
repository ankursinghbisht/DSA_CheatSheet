/*
Idea:
If arrays are merged, then finding the indices which include the median (M+N+1)/2
, partitioning the array (finding the elements which will be in left part of merged array).
-Checking if partitioning is done correct, returning the median
( keeping in mind the length of combined arrays)-else, shifting the mid-pointers.
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        int n = A.size(), m = B.size();

        if (n > m)
            return MedianOfArrays(B, A); // Swapping to make A smaller

        int start = 0;
        int end = n;
        int realmidinmergedarray = (n + m + 1) / 2;

        while (start <= end) {
            int mid = (start + end) / 2;
            int leftAsize = mid;
            int leftBsize = realmidinmergedarray - mid;

            //declaring & checking overflow of indices
            int leftA = (leftAsize > 0) ? A[leftAsize - 1] : INT_MIN;
            int leftB = (leftBsize > 0) ? B[leftBsize - 1] : INT_MIN;
            int rightA = (leftAsize < n) ? A[leftAsize] : INT_MAX;
            int rightB = (leftBsize < m) ? B[leftBsize] : INT_MAX;

            // if correct partition is done
            if (leftA <= rightB and leftB <= rightA)
            {
                if ((m + n) % 2 == 0)
                    return (max(leftA, leftB) + min(rightA, rightB)) / 2;
                return max(leftA, leftB);
            }
            else if (leftA > rightB)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return 0;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        cin >> n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i) {
            cin >> array2[i];
        }
        Solution ob;
        cout << ob.MedianOfArrays(array1, array2) << endl;
    }
    return 0;
}



// } Driver Code Ends