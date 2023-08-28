"""
Idea:
using for loop for each element for half-length & comparing it to its counterpart.
"""


class Solution:
    def isPalindrome(self, S):
        # code here
        for i in range(len(S) // 2):
            if S[i] != S[len(S) - i - 1]:
                return 0
        return 1


if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        S = input()
        ob = Solution()
        answer = ob.isPalindrome(S)
        print(answer)
