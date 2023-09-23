/*
Idea:
we fix 2 pointers at a time(i& j), and 2 variable pointers(left & right) to find sum of 4 pointer values
*/


#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:

    vector<vector<int> > fourSum(vector<int>& arr, int k)
    {
        vector<vector<int>>ans;
        int n = arr.size(), left, right;

        sort(arr.begin(), arr.end());

        for (int i = 0;i < n;++i)
        {
            // avoid the duplicates while moving i:
            if (i > 0 && arr[i] == arr[i - 1])
                continue;
            for (int j = i + 1;j < n;++j)
            {
                // avoid the duplicates while moving j:
                if (j > i + 1 && arr[j] == arr[j - 1])
                    continue;

                left = j + 1;
                right = n - 1;
                while (left < right)
                {
                    if (arr[i] + arr[j] + arr[left] + arr[right] == k)
                    {
                        vector<int> temp = { arr[i],arr[j],arr[left],arr[right] };
                        ans.push_back(temp);
                        left++;
                        right--;

                        //skip the duplicates:
                        while (left < right && arr[left] == arr[left - 1])
                            left++;
                        while (left < right && arr[right] == arr[right + 1])
                            --right;
                    }
                    else if (arr[i] + arr[j] + arr[left] + arr[right] < k)
                        left++;
                    else
                        --right;
                }
            }
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto& v : ans) {
            for (int& u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}