"""
Idea:
-Perform DFS from appropriate houses to find all different connected components.
The number of different connected components is our answer t.

-The next t lines of the output are the beginning of the connected component,
end of the connected component and the minimum diameter from the start to the end of the connected component in each line.

-Since, tanks can be installed only on the houses having outgoing pipe and no incoming pipe,
therefore these are appropriate houses to start DFS from i.e. perform DFS from such unvisited houses.
"""


# User function Template for python3
class Solution:
    def __init__(self):
        # number of houses and number of pipes
        self.n = 0
        self.p = 0
        # Array rd stores the ending vertex of pipe
        self.rd = []
        # Array wd stores the value of diameters between two pipes
        self.wt = []
        # Array cd stores the starting end of pipe
        self.cd = []
        self.ans = 0

    def dfs(self, w):
        if self.cd[w] == 0:
            return w
        if self.wt[w] < self.ans:
            self.ans = self.wt[w]
        return self.dfs(self.cd[w])

    def solve(self, n, p, a, b, d):
        self.n = n
        self.p = p
        self.rd = [0] * (n + 1)
        self.wt = [0] * (n + 1)
        self.cd = [0] * (n + 1)
        res = []

        i = 0
        while i < p:
            q, h, t = a[i], b[i], d[i]
            self.cd[q] = h
            self.wt[q] = t
            self.rd[h] = q
            i += 1

        for j in range(1, n + 1):
            # If a pipe has no ending vertex but has starting vertex, i.e., is an outgoing pipe,
            # then we need to start DFS with this vertex.
            if self.rd[j] == 0 and self.cd[j]:
                self.ans = 1000000000
                w = self.dfs(j)

                # We put the details of the component in the final output res array
                res.append([j, w, self.ans])

        return res



# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):

        n, p = map(int, input().strip().split())
        a = []
        b = []
        d = []
        for i in range(p):
            x, y, z = map(int, input().strip().split())
            a.append(x)
            b.append(y)
            d.append(z)

        ob = Solution()
        ans = ob.solve(n, p, a, b, d)
        print(len(ans))
        for i in ans:
            print(str(i[0]) + " " + str(i[1]) + " " + str(i[2]))

# } Driver Code Ends