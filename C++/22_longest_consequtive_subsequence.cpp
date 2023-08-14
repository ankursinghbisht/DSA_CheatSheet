/*
Idea: using set to find unique elements,& storing longest consecutive elements.
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    int findLongestConseqSubseq(int arr[], int N)
    {
        set<int> nums;
        int count = 1, ans = 1;

        for (int i = 0; i < N; ++i)
            nums.insert(arr[i]);

        for (auto element = nums.begin(); next(element) != nums.end(); ++element)
        {
            // Check if the current element and the next element are consecutive
            if (*element == *next(element) - 1)
                ++count;
            else
                count = 1;  // Reset the count if elements are not consecutive
            ans = max(ans, count);
        }

        return ans;
    }
};

int main()
{
    int  t, n, i, a[100001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0;i < n;i++)
            cin >> a[i];
        Solution obj;
        cout << obj.findLongestConseqSubseq(a, n) << endl;
    }
    return 0;
}