"""
Using 2 loops:one from left to right & other from right to left.
if left==right, setting answer to twice of left or right.
and resetting left and right if left> right on 1st traversal and on left<right on 2nd traversal
"""


# User function Template for python3

class Solution:
    def findMaxLen(self, s: str) -> int:
        n = len(s)

        # Variables for left and right counter. maxlength to store the maximum length found so far
        left = 0
        right = 0
        maxlength = 0

        # Iterating the string from left to right
        for i in range(n):
            # If "(" is encountered, then left counter is incremented else right counter is incremented
            if s[i] == '(':
                left += 1
            else:
                right += 1

            # Whenever left is equal to right, it signifies that the subsequence is valid
            if left == right:
                maxlength = max(maxlength, 2 * right)

            # Reseting the counters when the subsequence becomes invalid
            elif right > left:
                left = right = 0

        left = right = 0

        # Iterating the string from right to left
        for i in range(n - 1, -1, -1):
            # If "(" is encountered, then left counter is incremented else right counter is incremented
            if s[i] == '(':
                left += 1
            else:
                right += 1

            # Whenever left is equal to right, it signifies that the subsequence is valid
            if left == right:
                maxlength = max(maxlength, 2 * left)

            # Reseting the counters when the subsequence becomes invalid
            elif left > right:
                left = right = 0

        return maxlength



# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        S = input()

        ob = Solution()
        print(ob.findMaxLen(S))
# } Driver Code Ends