"""
Idea:
sorting the string on basis of frequency of each character.
iterating the original string, and placing characters on even places, then on odd places.
(rechecking if any adjacent characters are same, and return false)
"""


# User function Template for python3

class Solution:
    def rearrangeString(self, s):
        m = [0] * 26  # List to store the frequency of each character

        # Count the frequency of each character in the input string
        for char in s:
            m[ord(char) - ord('a')] += 1

        # Sort the string based on frequency and lexicographical order
        s = sorted(s, key=lambda x: (m[ord(x) - ord('a')], x), reverse=True)

        # Initialize the result list with spaces
        ans = [' '] * len(s)
        index, i = 0, 0

        # Fill the result list by placing characters at even positions
        while index < len(s):
            if i >= len(s):
                i = 1
            ans[i] = s[index]
            i += 2
            index += 1

        # Check for adjacent repeated characters
        for i in range(1, len(ans)):
            if ans[i - 1] == ans[i]:
                return "-1"

        return ''.join(ans)

# code here


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        str1 = input()
        solObj = Solution()
        str2 = solObj.rearrangeString(str1)
        if str2 == '-1':
            print(0)
        elif sorted(str1) != sorted(str2):
            print(0)
        else:
            for i in range(len(str2) - 1):
                if str2[i] == str2[i + 1]:
                    print(0)
                    break
            else:
                print(1)

# } Driver Code Ends
