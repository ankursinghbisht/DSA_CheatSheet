"""
Idea:
from right to left forming the number. As smallest no. is required, filling rightmost numbers to min( N, 9),till N is 0
"""


# User function Template for python3
class Solution:
    def smallestNumber(self, S, D):
        # Check if it's possible to form a number with the given sum and digits
        if S > D * 9:
            return "-1"  # Not possible, return invalid result

        # Initialize the result string with D digits, all set to '0'
        ans = ['0'] * D

        # Set the first digit to '1' and decrement the sum
        ans[0] = '1'
        S -= 1

        # Distribute the remaining sum to the digits
        for i in range(D - 1, 0, -1):
            # Choose the smaller of S and 9 to set the digit
            digit = min(S, 9)
            ans[i] = str(digit)
            S -= digit

            # If remaining sum is zero, exit the loop
            if S == 0:
                break

        # If there's still a remaining sum after distributing, update the first digit
        if S:
            ans[0] = str(S + 1)

        return ''.join(ans)  # Return the generated smallest number


# code here


# {
# Driver Code Starts
# Initial Template for Python 3
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        S, D = map(int, input().strip().split(" "))

        ob = Solution()
        print(ob.smallestNumber(S, D))
# } Driver Code Ends
