/*
Idea:
Iterating through array, keeping count of number of elements passed
- As MEDIAN, is middle elements of the resultant array, stopping once we reached the middle point
- Adding next lowest elements to the answer & returning.
*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int findMidSum(int ar1[], int ar2[], int n) {
        int i = 0, j = 0, count = 1, sum = 0;

        //finding the indices of arrays, which include elements which are median
        for (int count = 1;count < n;++count)
            if (ar1[i] <= ar2[j])
                ++i;
            else
                ++j;

        //appending the smaller number to answer
        if (ar1[i] < ar2[j])
            sum += ar1[i++];
        else
            sum += ar2[j++];

        //checking if element was last in array, if so, appending first element of last array
        if (i == n)
            sum += ar2[0];
        else if (j == n)
            sum += ar1[0];
        else
            // else adding lower value from both the array indices.
            sum += min(ar1[i], ar2[j]);

        return sum;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}