"""
Idea:
for min element, popping till empty and returning the min element
"""


def push(arr, ele):
    arr.append(ele)


def pop(arr):
    return arr.pop(0)


def isFull(n, arr):
    return len(arr) == n


def isEmpty(arr):
    return arr == []


def getMin(n, arr):
    return min(arr)


# {
# Driver Code Starts
if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        stack = []
        while not isEmpty(stack):
            pop(stack)

        for i in range(n):
            push(stack, arr[i])
        print(getMin(n, stack))

# } Driver Code Ends
