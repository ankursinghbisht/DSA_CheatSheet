"""
Idea:
using vector to store length of longest prefix & suffix till that current index
'i' is used for suffix & 'j' for prefix
"""



class Solution:
    def lps(self, s):
        n = len(s)
        lps = [0] * n
        i, j = 1, 0
        while i < n:
            # if both elements at i & j are equal, adding index value of prefix pointer
            if s[i] == s[j]:
                lps[i] = j + 1
                j += 1
                i += 1
            else:
                # else incrementing suffix initial index value to find equal suffix to prefix
                if j == 0:
                    i += 1
                else:
                    # resetting the value of index of prefix
                    j = lps[j - 1]

        return lps[-1]


if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        s = input()

        ob = Solution()
        answer = ob.lps(s)
        print(answer)

