"""
Idea: (to cut board on edges with the highest cost.)
-sorting cost in ascending order , keeping track of cuts .adding cost from highest to lowest
"""



class Solution:
    def minimumCostOfBreaking(self, X, Y, M, N):
        # Sorting both vectors in ascending order of edge cut cost
        X.sort()
        Y.sort()

        horizontal_parts = 1  # Keeping track of part cut horizontally
        vertical_parts = 1    # Keeping track of part cut vertically
        i = len(X) - 1
        j = len(Y) - 1
        cost = 0

        while i >= 0 and j >= 0:
            if X[i] >= Y[j]:
                horizontal_parts += 1  # Incrementing horizontal parts after it's cut horizontally
                cost += vertical_parts * X[i]
                i -= 1
            else:
                vertical_parts += 1    # Incrementing vertical parts after it's cut vertically
                cost += horizontal_parts * Y[j]
                j -= 1

        # Adding cost of cutting remaining parts
        while i >= 0:
            cost += vertical_parts * X[i]
            i -= 1

        while j >= 0:
            cost += horizontal_parts * Y[j]
            j -= 1

        return cost



# code here


# {
# Driver Code Starts

class IntArray:
    def __init__(self) -> None:
        pass

    def Input(self, n):
        arr = [int(i) for i in input().strip().split()]  # array input
        return arr

    def Print(self, arr):
        for i in arr:
            print(i, end=" ")
        print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        a = IntArray().Input(2)
        m = a[0]
        n = a[1]

        tmp = IntArray().Input(a[0] - 1) + IntArray().Input(a[1] - 1)
        X = tmp[:m - 1]
        Y = tmp[m - 1:]

        obj = Solution()
        res = obj.minimumCostOfBreaking(X, Y, m, n)

        print(res)

# } Driver Code Ends