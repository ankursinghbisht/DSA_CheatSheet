"""
Idea:
checking if A can be converted to B, by checking if count of all chars is equal
-then starting from last index, checking if chars match, else increase answer count till chars match
"""


class Solution:
    def transform(self, A, B):
        Asize, Bsize, ans = len(A), len(B), 0
        if Asize != Bsize:
            return -1
        arr = [0] * 256

        for i in range(Asize):
            arr[ord(A[i])] += 1
        for i in range(Bsize):
            if arr[ord(B[i])] == 0:
                return -1
            arr[ord(B[i])] -= 1  # checking if chars are equal in both string

        i = j = Asize - 1

        while i >= 0:
            while i >= 0 and A[i] != B[j]:
                # If chars don't match, decreasing the index of the 1st string till chars match
                ans += 1
                i -= 1
            i -= 1
            j -= 1
        return ans


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        line = input().strip().split()
        A = line[0]
        B = line[1]
        ob = Solution()
        print(ob.transform(A, B))
