"""
Idea:
setup base case where if supply is less than demand, return -1.
else count days to buy to reach end goal
"""



class Solution:
    def minimumDays(self, S, N, M):
        # If we can not buy at least a week supply of food during the first week
        # OR We can not buy a day supply of food on the first day then we can't survive.
        if (N * 6 < M * 7 and S > 6) or M > N:
            return -1
        else:
            # If we can survive then we can buy ceil(A/N) times where A is total units of food required.
            days = (M * S) // N
            if (M * S) % N != 0:
                days += 1
            return days

# code here


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        S, N, M = [int(x) for x in input().split()]

        ob = Solution()
        print(ob.minimumDays(S, N, M))
# } Driver Code Ends