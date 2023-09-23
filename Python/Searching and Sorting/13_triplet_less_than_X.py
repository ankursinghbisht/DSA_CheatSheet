"""
Idea:
Using static pointer 'i' for one element, and 2 variable pointers 'low & high' for rest elements to count sum
If sum of 3 elements >= desired sum, decrease the high pointer, else increase count var
"""


class Solution:
    def countTriplets(self, arr, n, sumo):
        ans = 0
        arr.sort()
        for i in range(n - 2):
            low, high = i + 1, n - 1  # setting up 2 pointers to access rest 2 elements
            while low < high:
                if arr[i] + arr[low] + arr[high] >= sumo:  # if sum> desired sum, decrease high pointer
                    high -= 1
                else:
                    # increasing count var as all elements below high will fulfill the condition
                    ans += high - low
                    low += 1

        return ans


# {
# Driver Code Starts

t = int(input())
for _ in range(0, t):
    l = list(map(int, input().split()))
    n = l[0]
    k = l[1]
    a = list(map(int, input().split()))
    ob = Solution()
    ans = ob.countTriplets(a, n, k)
    print(ans)
# } Driver Code Ends
