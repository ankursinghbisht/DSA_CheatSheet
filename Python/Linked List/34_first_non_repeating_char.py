"""
Idea:
using 2 vectors to store frequency of each character & it's last occurrence
While iterating the string-checking if element has occurred before or not & if yes, finding the second unique element occured
& updating the answer string.
"""


# User function Template for python3

class Solution:
    def FirstNonRepeating(self, A):

        # Code here
        # storing the size of the string.
        n = len(A)

        # creating a frequency array for all the characters in the string.
        f = [0] * 26

        # creating an array to store the last occurrence of each character.
        last = [-1] * 26

        # iterating over the string to update the last occurrence of each character.
        for i in range(n):
            if last[ord(A[i]) - ord('a')] == -1:
                last[ord(A[i]) - ord('a')] = i

        # string to store the answer.
        ans = ""

        # iterating over the string again to update the frequency of each character
        # and find the first non-repeating character.
        for i in range(n):
            f[ord(A[i]) - ord('a')] += 1

            # character to store the first non-repeating character.
            ch = '#'

            # variable to store the last occurrence index of the first non-repeating character.
            x = n + 1

            # iterating over the frequency array to find the first non-repeating character.
            for j in range(26):
                if f[j] == 1 and x > last[j]:
                    ch = chr(j + ord('a'))
                    x = last[j]

            # appending the first non-repeating character to the answer string.
            ans += ch

        # returning the answer string.
        return ans


# {
# Driver Code Starts

# Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        A = input()
        ob = Solution()
        ans = ob.FirstNonRepeating(A)
        print(ans)

# } Driver Code Ends
