"""
Idea:
sorting array in non-descending order.
using recursion at each element with backtracking(with 2 cases, to choose or not to choose the element)
"""


class Solution:
    def __init__(self):
        self.ans = []

    # Recursive function to find combinations
    def solve(self, A, B, vc, ind):
        # Base cases
        if ind == len(A) or B < 0:
            return

        if B == 0:
            # If the target sum is reached, add the combination to the result
            self.ans.append(vc.copy())
            return

        for i in range(ind, len(A)):
            # Skip duplicates to avoid repeated combinations
            if i > ind and A[i] == A[i - 1]:
                continue

            # Include the current element in the combination
            vc.append(A[i])
            # Recursive call with updated target sum and index
            self.solve(A, B - A[i], vc, i)
            # Backtrack by removing the last added element
            vc.pop()

    # Function to return a list of combinations whose sum is equal to the given number
    def combinationalSum(self, A, B):
        vc = []  # List to store the current combination
        # Sort the input list to handle duplicates and for optimization
        A.sort()
        # Call the recursive function to find combinations
        self.solve(A, B, vc, 0)
        return self.ans  # Return the final result


# {
# Driver Code Starts.


if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        a = list(map(int, input().strip().split()))
        s = int(input())
        ob = Solution()
        result = ob.combinationalSum(a, s)
        if (not len(result)):
            print("Empty")
            continue
        for i in range(len(result)):
            print("(", end="")
            size = len(result[i])
            for j in range(size - 1):
                print(result[i][j], end=" ")
            if (size):
                print(result[i][size - 1], end=")")
            else:
                print(")", end="")
        print()

# } Driver Code Ends
