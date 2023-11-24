"""
Idea:
sorting in descending order,  finding the sum of total array.
Then, from start, sum till difference between temporary sum and original sum is greater than temporary sum.
"""


# User function Template for python3

class Solution:

    # Function to find the minimum subset with the given conditions.
    def minSubset(self, A, N):

        # Calculating the sum of all elements in the list.
        s = sum(A)
        res = 0

        # Sorting the list in descending order.
        A.sort()
        A.reverse()

        # Iterating through the list.
        for i in range(0, N):

            # Adding the current element to the result subset.
            res += A[i]

            # Subtracting the current element from the total sum.
            s -= A[i]

            # Checking if the sum of the result subset is greater than the remaining sum. If yes, returning the number of elements in the result subset.
            if res > s:
                return i + 1

        # Returning the total number of elements in the list if no subset is found.
        return N


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        A = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.minSubset(A, N)
        print(ans)
# } Driver Code Ends
