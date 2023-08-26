"""
Idea:
(Using area of histogram technique,)
finding max area at each row, where height will be sum of 1's above the current row.

"""


class Solution:
    def largestRectangleArea(self, a, n):
        n = len(a)
        st = []  # using list as a stack to store element's indices
        leftSmall, rightSmall = [], []

        for i in range(n):
            while st and a[i] <= a[st[-1]]:
                # checking if current element is greater than top of stack, till we find smaller one
                st.pop()

            # if stack is empty, means no smaller element, else appending right of smaller element
            if not st:
                leftSmall.append(0)
            else:
                leftSmall.append(st[-1] + 1)
            st.append(i)

        st.clear()  # clearing stack

        for i in range(n - 1, -1, -1):
            while st and a[i] <= a[st[-1]]:
                # checking if current element is greater than top of stack, till we find smaller one
                st.pop()

            # if stack is empty, means no smaller element, else appending right of smaller element
            if not st:
                rightSmall.append(n - 1)
            else:
                rightSmall.append(st[-1] - 1)
            st.append(i)

        rightSmall.reverse()  # reversing the list, as it's reversed to original array
        ans = 0
        for i in range(n):
            # returning the answer by calculating total area using difference of 2 lists & value at i
            ans = max(ans, a[i] * (abs(leftSmall[i] - rightSmall[i]) + 1))
        return ans

    def maxArea(self, M, n, m):

        arr = [0] * m  # setting up the array passing as histogram
        ans = 0

        for i in range(n):
            for j in range(m):
                # at each element, if it's 0, height will be 0, else 1 will be added to height
                if M[i][j] == 0:
                    arr[j] = 0
                else:
                    arr[j] += 1
            ans = max(ans, self.largestRectangleArea(arr))

        return ans


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        R, C = map(int, input().strip().split())
        A = []
        for i in range(R):
            line = [int(x) for x in input().strip().split()]
            A.append(line)
        print(Solution().maxArea(A, R, C))
