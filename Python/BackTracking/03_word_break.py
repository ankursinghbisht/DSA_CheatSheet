"""
Idea:
using loop to find word which is in dictionary & recursively calling itself for next words till all words match the dictionary
"""


# User function Template for python3
class Solution:
    def wordBreak(self, n, dict, s):
        # Function to find all possible word break combinations

        def solve(arr, st, l, res):

            # If the entire string has been processed, append the current combination to the result
            if st == len(s):
                res.append(l[:])

            # Try all possible words from the dictionary and check if they match the substring
            for word in arr:
                if s[st:st + len(word)] == word:
                    l.append(word)  # Add the word to the current combination
                    solve(arr, st + len(word), l, res)  # Recursively check for the remaining substring
                    l.pop()  # Remove the last word from the current combination to backtrack

        # Initialize an empty list to store the result
        res = []

        # Call the recursive function to find all possible word break combinations
        solve(dict, 0, [], res)

        # Convert the combinations to string format
        res = [" ".join(x) for x in res]

        # Return the final result
        return res


# code here


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        dicti = input().split()
        s = input()

        ob = Solution()
        ans = ob.wordBreak(n, dicti, s)
        if (len(ans) == 0):
            print("Empty")
        else:
            ans.sort()
            for it in (ans):
                print("(" + it, end=")")
            print()
# } Driver Code Ends