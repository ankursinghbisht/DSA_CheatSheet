"""
Idea:
1. Store amount of all persons to be settled in a set. If a person is in debt his amount will be negative else +ve.
2. Traverse until only 1 person is left to be settled.
3. Begin of set will be debit guy and end will be credit guy.
4. If debt is less then settle debit guy. Compute new credit by adding debit and store in set.
5. Else settle credit guy and compute new debit by adding credit and store in set.

(debit is -ve therefore adding credit will reduce debt. Similarly adding debt to credit will reduce credit.)
"""

from typing import List


class Solution:
    def minCashFlow(self, n: int, ts: List[List[int]]) -> List[List[int]]:
        # Comparator for sorting pairs based on the first element
        class cmp:
            def __lt__(self, a, b):
                if a[0] == b[0]:
                    if a[0] < 0 and b[0] < 0:
                        return a[1] < b[1]
                    return a[1] > b[1]
                return a[0] < b[0]

        s = set()

        # Calculate the net amount for each person and add to the set if not zero
        for i in range(n):
            a = sum(ts[j][i] - ts[i][j] for j in range(n))
            if a != 0:
                s.add((a, i))

        ans = [[0] * n for _ in range(n)]

        # Continue settling until there are at least two people with non-zero net amounts
        while len(s) > 1:
            # Sort the set and get the first and last elements
            debit, credit = sorted(s)[0], sorted(s)[-1]
            ad, ac = debit[0], credit[0]
            from_, to = debit[1], credit[1]

            # Remove the settled pairs from the set
            s.remove(debit)
            s.remove(credit)

            # Settle the amounts
            if -ad <= ac:
                ans[from_][to] = -ad
                ac += ad
                if ac != 0:
                    s.add((ac, to))
            else:
                ans[from_][to] = ac
                ad += ac
                if ad != 0:
                    s.add((ad, from_))

        return ans


# {
# Driver Code Starts
class IntMatrix:
    def __init__(self) -> None:
        pass

    def Input(self, n, m):
        matrix = []
        # matrix input
        for _ in range(n):
            matrix.append([int(i) for i in input().strip().split()])
        return matrix

    def Print(self, arr):
        for i in arr:
            for j in i:
                print(j, end=" ")
            print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())

        g = IntMatrix().Input(n, n)

        obj = Solution()
        res = obj.minCashFlow(n, g)

        IntMatrix().Print(res)

# } Driver Code Ends