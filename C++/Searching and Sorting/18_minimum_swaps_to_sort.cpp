
/*
Idea:
using hashmap to store indices of elements in input vector & copying the vector & sort it for reference
Steps:
iterating each element, if an element is not in position, swap it using hashmap & sorted vector.
*/

#include<bits/stdc++.h>
using namespace std;



class Solution
{
public:
    int minSwaps(vector<int>& nums)
    {
        int n = nums.size(), ans = 0;
        vector<int> sortedArray = nums;
        sort(sortedArray.begin(), sortedArray.end()); // sorting the copy of input vector
        unordered_map<int, int>hashMap;

        for (int i = 0; i < n; i++)
            hashMap[nums[i]] = i; // creating hashmap

        for (int i = 0;i < n;++i)
            if (nums[i] != sortedArray[i]) // if element is not in optimum position
            {
                ans++;
                int s = nums[i], t = sortedArray[i];
                swap(nums[i], nums[hashMap[sortedArray[i]]]); // swapping the element using hashmap
                swap(hashMap[s], hashMap[t]); // updating the hashmap
            }
        return ans;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.minSwaps(nums);
        cout << ans << "\n";
    }
    return 0;
}