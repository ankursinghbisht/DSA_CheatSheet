"""
Idea:
Implementing sliding window technique using queue.
At each window, popping all positive elements till negative is at first.
inserting in answer array (if queue is empty, inserting 0 )
"""

# User function Template for python3

from collections import deque


def printFirstNegativeInteger(A, N, K):
    ans = []
    q = deque()

    # Process the first window of size K
    for i in range(K):
        q.append(A[i])

    # Find the first negative integer in the initial window
    while q and q[0] >= 0:
        q.popleft()

    # Add the result to the answer list
    ans.append(q[0] if q else 0)

    # Process the remaining elements
    for i in range(K, N):
        # Add the current element to the window
        q.append(A[i])

        # Remove elements from the front until a negative integer is encountered
        # or the window size is reduced to K
        while q and (q[0] >= 0 or len(q) > K):
            q.popleft()

        # Add the result to the answer list
        ans.append(q[0] if q else 0)

    return ans


# {
# Driver Code Starts
# Initial Template for Python 3

def main():
    T = int(input())

    while (T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        k = int(input())

        answer = printFirstNegativeInteger(a, n, k)
        for i in answer:
            print(i, end=" ")
        print()

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends