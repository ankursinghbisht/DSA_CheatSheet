"""
Idea:
making 'k' negative elements to positive or no negative elements are left
if k is odd after changing elements, remove twice of smallest element from sum
"""


# Back-end complete function Template for Python 3

class Solution:
    # Function to maximize the sum
    def maximizeSum(self, a, n, k):
        # Sorting the array
        a.sort()
        sum = 0
        for i in range(0, n):
            # If the element is negative, and we have available k operations
            if a[i] < 0 and k > 0:
                # Making the element positive
                a[i] *= -1
                # Decreasing the k value
                k -= 1

        # Sorting the array again
        a.sort()
        for i in range(0, n):
            # Adding all the elements
            sum += a[i]

        # Adjusting the sum based on remaining k value
        if k & 1:
            sum -= 2 * a[0]
        return sum


# {
# Driver Code Starts
# Initial Template for Python 3

def main():
    T = int(input())

    while (T > 0):
        sz = [int(x) for x in input().strip().split()]
        n, k = sz[0], sz[1]
        a = [int(x) for x in input().strip().split()]
        ob = Solution()
        print(ob.maximizeSum(a, n, k))

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends