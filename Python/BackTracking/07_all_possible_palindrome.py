"""
Idea:
loop through substrings and recursively calling function after one palindromic substring is found.
"""


# User function Template for python3
class Solution:
    def __init__(self):
        # Store the result of palindromic partitions
        self.ans = []

    # Function to check if a string is palindrome or not
    def isPalindrome(self, s):
        return s == s[::-1]

    # Recursive function to find palindromic partitions
    def solve(self, s, vc):
        if not s:
            # If the remaining string is empty, add the current partition to the result
            self.ans.append(vc[:])
            return

        current_str = ""
        for i in range(len(s)):
            current_str += s[i]
            if self.isPalindrome(current_str):
                # If the current substring is a palindrome, add it to the current partition
                vc.append(current_str)

                # Recursively find partitions for the remaining substring
                self.solve(s[i + 1:], vc)

                # Backtrack: remove the last added substring to explore other possibilities
                vc.pop()

    # Function to find all palindromic partitions of a given string
    def allPalindromicPerms(self, S):
        # Initialize the list to store the current partition
        vc = []

        # Start the recursive process to find palindromic partitions
        self.solve(S, vc)

        # Return the final result
        return self.ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        S = input()

        ob = Solution()
        allPart = ob.allPalindromicPerms(S)
        for i in range(len(allPart)):
            for j in range(len(allPart[i])):
                print(allPart[i][j], end=" ")
            print()
            # } Driver Code Ends
