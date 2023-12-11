"""
Idea:
sorting intervals in descending order of start time & inserting in a stack.
Taking 2 top elements and merging (if required) & inserting in stack.
"""


class Solution:
    def overlappedInterval(self, intervals):
        ans = []

        # Sort intervals in ascending order based on the start time
        intervals.sort()

        # Reverse intervals to get them in descending order based on the start time
        intervals.reverse()

        stack = []

        for it in intervals:
            stack.append(it)

        while len(stack) > 1:
            t1 = stack.pop()
            t2 = stack.pop()

            # Check for overlapping intervals
            if t1[1] >= t2[0]:
                # Merge overlapping intervals
                temp = [t1[0], max(t2[1], t1[1])]
                stack.append(temp)
            else:
                # No overlap, add t1 to the result and push back t2 for further comparisons
                ans.append(t1)
                stack.append(t2)

        # Push the remaining interval to the result
        ans.append(stack[0])

        return ans


# {
# Driver Code Starts

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n = int(input())
        a = list(map(int, input().strip().split()))
        Intervals = []
        j = 0
        for i in range(n):
            x = a[j]
            j += 1
            y = a[j]
            j += 1
            Intervals.append([x, y])
        obj = Solution()
        ans = obj.overlappedInterval(Intervals)
        for i in ans:
            for j in i:
                print(j, end=" ")
        print()
# } Driver Code Ends