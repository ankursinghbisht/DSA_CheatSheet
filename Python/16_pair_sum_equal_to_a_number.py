"""
Idea:
using unordered map to store elements
& checking if any element (int the map) adds with current element to form value 'k'

Steps:
-iterating through array
-checking if any element with value (k-arr[i]) is present in the map, if any, adds total count to answer
-adding the current element in map
"""


class Solution:
    def getPairsCount(self, arr, n, k):
        # code here
        value_map = {}
        ans = 0
        for i in range(n):
            # iterating through each value, and checking if elements in dictionary adds to k
            if k - arr[i] in value_map:
                ans += value_map[k - arr[i]]
            # if value is not present in dictionary, insert one, else add one to it's count
            if arr[i] in value_map:
                value_map[arr[i]] += 1
            else:
                value_map[arr[i]] = 1
        return ans


if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n, k = list(map(int, input().strip().split()))
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.getPairsCount(arr, n, k)
        print(ans)
        tc -= 1
