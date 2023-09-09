"""
Idea:
Iterating each string & keeping temporary string to store common chars
"""


class Solution:
    def longestCommonPrefix(self, str):

        ans = str[0]  # var to store  common prefix
        for string in str:
            i = 0
            while i < len(ans) and i < len(string) and ans[i] == string[i]:
                i += 1
            ans = ans[:i]

            if not ans:
                break
        return ans


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        str = []
        for i in range(n):
            str.append(int(input()))
        ob = Solution()
        print(ob.longestCommonPrefix(str))
