/*
Idea:
modifying the binary search, by checking if left or right subarray is sorted & contains the element
as at-least one half will be sorted, and checking if element lies there.
*/

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int low = 0, high = nums.size() - 1, mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;

            // if left half [low--mid] is sorted
            if (nums[low] <= nums[mid])
                if (nums[low] <= target && target < nums[mid]) // checking if element lies here in left half
                    high = mid - 1;
                else
                    low = mid + 1;
            else
                // if right half [mid--high] is sorted
                if (nums[mid] < target && target <= nums[high]) // checking if element lies here in right half
                    low = mid + 1;
                else
                    high = mid - 1;
        }
        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> n >> target;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.valueEqualToIndex(arr, n);
    }
    return 0;
}