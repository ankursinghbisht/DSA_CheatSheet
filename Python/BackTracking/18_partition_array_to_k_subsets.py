"""
Idea:
calculating target sum of each subset, and using backtracking to find , if there exist any combination
where each subset sums to target value.
"""


class Solution:
    def isKPartitionPossible(self, a, k):
        # Calculate the total sum of the array elements
        s = sum(a)

        # If the sum is not divisible evenly by k, return False
        if s % k != 0:
            return False

        # Calculate the target sum for each subset
        t = s // k

        # Initialize an array to track the sum of elements in each subset
        subset = [0] * k

        # Recursive function to check if it's possible to partition the array
        def fun(idx, n, subset, t):
            # If all elements are processed, return True
            if idx == n:
                return True

            # Try to add the current element to each subset
            for i in range(k):
                if subset[i] + a[idx] <= t:
                    subset[i] += a[idx]

                    # Recursively check the next element
                    if fun(idx + 1, n, subset, t):
                        return True

                    # Backtrack: undo the addition if it doesn't lead to a solution
                    subset[i] -= a[idx]

                    # Optimization: if the subset sum is 0, no need to try further
                    if subset[i] == 0:
                        break

            # If no subset is found, return False
            return False

        # Start the recursive function with initial parameters
        return fun(0, len(a), subset, t)


# Driver Code Starts


if __name__ == '__main__':
    tcs = int(input())
    for _ in range(tcs):
        N = int(input())
        arr = [int(x) for x in input().split()]
        k = int(input())
        if Solution().isKPartitionPossible(arr, k):
            print(1)
        else:
            print(0)
# } Driver Code Ends
