"""
Idea:
not including 0s in answer, and if odd no. of negative elements, excluding the highest negative value
(special case, if only 1 negative element and all 0s, return 0)
else multiply all elements within limit of 1e9+7
"""

MOD = 10 ** 9 + 7


class Solution:
    def findMaxProduct(self, arr, n):
        mod = 1000000007

        if n == 1:
            # Only 1 element in the array.
            return arr[0]

        maxNegative = -999999999
        negativeCnt = 0
        zeroCnt = 0
        ans = 1
        ind = -1

        # Find count of negative numbers, count of zeros, negative number with least absolute value and product of non-zero numbers
        for i in range(n):

            if arr[i] == 0:
                # Counting number of zeros.
                zeroCnt += 1
            elif arr[i] < 0:
                # Counting number of negative numbers.
                negativeCnt += 1
                if ind == -1 or arr[i] > maxNegative:
                    # Storing the index of negative element having least magnitude.
                    ind = i
                    maxNegative = arr[i]

        if zeroCnt == n:
            # If there are all zeros.
            return 0
        if negativeCnt == 1 and zeroCnt == n - 1:
            # If all elements are zero except one negative element, then return 0.
            return 0

        for i in range(n):

            if arr[i] == 0:
                continue
            if negativeCnt % 2 and i == ind:
                # Removing the negative element having least magnitude.
                continue
            ans = ((ans * arr[i]) % mod + mod) % mod

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int, input().split()))
        obj = Solution()
        ans = obj.findMaxProduct(a, n)
        print(ans)
# } Driver Code Ends
