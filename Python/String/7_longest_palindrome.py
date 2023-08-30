"""
Idea:
The LPS is either of even length or odd length.
So the idea is to traverse the input string and for each character check
if this character can be the center of a palindromic substring of odd length or even length.
"""


class Solution:
    def longestPalin(self, s: str) -> str:
        n = len(s)
        start = 0
        end = 1
        low, high = 0, 0

        # Traverse the input string
        for i in range(n):
            # Find longest palindromic substring of even size
            low = i - 1
            high = i

            # Expand substring while it is palindrome and in bounds
            while low >= 0 and high < n and s[low] == s[high]:
                # Update maximum length and starting index
                if high - low + 1 > end:
                    start = low
                    end = high - low + 1
                low -= 1
                high += 1

            # Find longest palindromic substring of odd size
            low = i - 1
            high = i + 1

            # Expand substring while it is palindrome and in bounds
            while low >= 0 and high < n and s[low] == s[high]:
                # Update maximum length and starting index
                if high - low + 1 > end:
                    start = low
                    end = high - low + 1
                low -= 1
                high += 1

        return s[start:start + end]


if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        S = input()

        ob = Solution()

        ans = ob.longestPalin(S)

        print(ans)
