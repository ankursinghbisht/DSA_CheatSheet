"""
Idea:
Finding left & right smaller element of each element & multiplying the difference with value at index
storing the max result & returning.
"""


class Solution:

    def getMaxArea(self, a):
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
        ans = float('-inf')
        for i in range(n):
            # returning the answer by calculating total area using difference of 2 lists & value at i
            ans = max(ans, a[i] * (abs(leftSmall[i] - rightSmall[i]) + 1))
        return ans

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        a = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.getMaxArea(a))
