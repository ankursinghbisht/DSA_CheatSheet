"""
Idea:
Recursively exploring all combination of ATMs and combination with least max distance from an ATM.
"""


class Solution:
    def kCenterHelper(self, k, n, result, selected, mat):
        if k == 0:
            # Find the maximum distance of a city from the server.
            maxDist = 0
            for i in range(n):
                minDistServer = float('inf')
                for j in range(len(selected)):
                    minDistServer = min(minDistServer, mat[i][selected[j]])
                maxDist = max(maxDist, minDistServer)
            result[0] = min(result[0], maxDist)
        else:
            prev = selected[-1] if selected else -1
            for i in range(prev + 1, n):
                selected.append(i)

                # Recursively find ways of selecting the remaining cities.
                self.kCenterHelper(k - 1, n, result, selected, mat)

                # Backtrack to explore possible ways of selection without city 'i'.
                selected.pop()

    def selectKcities(self, n, k, mat):
        selected = []
        result = [float('inf')]

        # Recursively try all possible ways of selecting 'K' cities.
        self.kCenterHelper(k, n, result, selected, mat)

        return result[0]


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
        a = IntArray().Input(2)
        n, k = a[0], a[1]

        mat = IntMatrix().Input(a[0], a[0])

        obj = Solution()
        res = obj.selectKcities(n, k, mat)

        print(res)

# } Driver Code Ends
