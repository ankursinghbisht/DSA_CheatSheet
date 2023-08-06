/*
Idea:
Searching the element which is smaller than it's just next one,
and swapping it with the element next bigger than it
-now reversing the array from the point of swapping till last element
*/

#include<bits/stdc++.h>
using namespace std;


void nextPermutation(vector<int>& nums)
{
    int n = nums.size();
    int i = n - 2;


    while (i >= 0 && nums[i] >= nums[i + 1])
        //finding the index, where element are in non decending order
        --i;

    if (i >= 0)
    {
        int j = n - 1;
        while (nums[j] <= nums[i])
            //finding the index to swap with
            --j;

        //swapping 
        swap(nums[i], nums[j]);

        //reversing the array, from the index it was swapped till last
        reverse(nums.begin() + i + 1, nums.end());
        return;
    }
    reverse(nums.begin(), nums.end());
    // swapping incase the permutation was the last actual permutation, as next permutation will be first one.
}


int main()
{
    vector<int> nums;
    int t, temp;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0;i < n;i++)
        {
            cin >> temp;
            nums.push_back(temp);
        }

        nextPermutation(nums);
        for (int i = 0;i < n;++i)
            cout << nums[i] << ' ';
        cout << "\n";
    }
    return 0;
}