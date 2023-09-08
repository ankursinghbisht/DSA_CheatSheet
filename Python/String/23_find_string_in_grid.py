"""
Idea:
Recursively calling function in a particular direction at once & returning origin value once each letter is found.
"""


# User function Template for python3
class Solution:
    def search2D(self, grid, row, col, word, x, y):
        R = len(grid)
        C = len(grid[0])

        # If the first character of the word doesn't match with the given starting point in the grid.
        if grid[row][col] != word[0]:
            return False

        length = len(word)

        # Search the word in all 8 directions starting from (row, col)
        for direction in range(8):
            # Initialize the starting point for the current direction
            k, rd, cd = 1, row + x[direction], col + y[direction]

            # First character is already checked, match remaining characters
            while k < length:
                # If out of bounds, break
                if rd >= R or rd < 0 or cd >= C or cd < 0:
                    break

                # If not matched, break
                if grid[rd][cd] != word[k]:
                    break

                # Moving in a particular direction
                rd += x[direction]
                cd += y[direction]
                k += 1

            # If all characters matched, the value of 'k' must be equal to the length of the word
            if k == length:
                return True

        return False

    def searchWord(self, grid, word):
        row = len(grid)
        col = len(grid[0])
        x = [-1, -1, -1, 0, 0, 1, 1, 1]
        y = [-1, 0, 1, -1, 1, -1, 0, 1]
        ans = []

        for i in range(row):
            for j in range(col):
                if self.search2D(grid, i, j, word, x, y):
                    ans.append([i, j])
        return ans


if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n, m = input().split()
        n = int(n)
        m = int(m)
        grid = []
        for _ in range(n):
            cur = input()
            temp = []
            for __ in cur:
                temp.append(__)
            grid.append(temp)
        word = input()
        obj = Solution()
        ans = obj.searchWord(grid, word)
        for _ in ans:
            for __ in _:
                print(__, end=" ")
            print()
        if len(ans) == 0:
            print(-1)
