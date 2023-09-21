/*
Idea:
While traversing, use the absolute value of every element as an index and make the value at this index negative to mark it visited.
If something is already marked negative then this is the repeating element.
To find the missing, traverse the array again and look for a positive value.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findTwoElement(vector<int> arr, int n)
    {
        vector<int>ans = { 0,0 };

        // finding repeating element, if any element through indexing is already negative, index is repeating element
        for (int i = 0;i < n;++i)
        {
            if (arr[abs(arr[i]) - 1] < 0)
                ans[0] = abs(arr[i]);
            else
                arr[abs(arr[i]) - 1] *= -1;
        }

        // finding missing element, any positive index element means , index is missing element
        for (int i = 0;i < n;++i)
            if (arr[i] > 0)
            {
                ans[1] = i + 1;
                break;
            }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
