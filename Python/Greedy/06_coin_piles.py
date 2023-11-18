"""
Idea:
Sorting the list in increasing order, we iterate over all the coin pile sizes,
and for the rest of the piles if the pile size is less than the current size then remove that pile entirely
otherwise if the pile size is greater than current pile size plus K then remove the excess coins.
The minimum number of coins removed in any of the turns is the answer.

"""


# User function Template for python3
def upper_bound(A, L, R, K):
    pos = R + 1
    while L <= R:
        M = (L + R) // 2
        if A[M] > K:
            pos = M
            R = M - 1
        else:
            L = M + 1

    return pos


class Solution:
    def minSteps(self, a, N, K):
        # array to store prefix sums
        p = [0] * N

        # sorting the array
        a.sort()

        # calculating prefix sums
        p[0] = a[0]
        for i in range(1, N):
            p[i] = p[i - 1] + a[i]

        # initializing answer as maximum integer value
        ans = (1 << 31) - 1  # INT_MAX
        prev = 0

        # iterating over the array
        for i in range(N):
            # finding the upper bound index of a[i] + K
            pos = upper_bound(a, i, N - 1, a[i] + K)

            # calculating previous prefix sum if a[i] is not equal to a[i-1]
            if i > 0 and a[i] != a[i - 1]:
                prev = p[i - 1]

            # calculating the current answer by subtracting appropriate values
            ans = min(ans, prev + p[N - 1] - p[pos - 1] - (N - pos) * (a[i] + K))

        return ans


# code here


# {
# Driver Code Starts
# Initial Template for Python 3

t = int(input())
for _ in range(t):
    N, K = map(int, input().split())
    A = list(map(int, input().split()))

    ob = Solution()
    print(ob.minSteps(A, N, K))
# } Driver Code Ends
