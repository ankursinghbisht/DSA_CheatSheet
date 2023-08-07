"""
Idea:
-moving index of each array only if the element is smallest.
-storing the last inserted element in answer list, to check if any repetition is happening,
as it's sorted , we  only need to store last element
"""


def commonElements(A, B, C, n1, n2, n3):
    # setting up indices
    i = 0
    j = 0
    k = 0

    # setting up variable to store last element stored in answer list
    last = -12345678
    ans = []

    while i < n1 and j < n2 and k < n3:
        # checking if element is common in all 3
        if A[i] == B[j] == C[k]:
            if last != A[i]:
                # checking if element isn't already inserted
                ans.append(A[i])
                last = A[i]
            i += 1
            j += 1
            k += 1

        # moving index of minimum value list
        elif min(A[i], B[j], C[k]) == A[i]:
            i += 1
        elif min(A[i], B[j], C[k]) == B[j]:
            j += 1
        else:
            k += 1
    return ans


if __name__ == '__main__':
    t = int(input())
    for tc in range(t):
        m, n, o = list(map(int, input().split()))
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        c = list(map(int, input().split()))

        res = commonElements(a, b, c, m, n, o)

        if len(res) == 0:
            print(-1)
        else:
            for i in range(len(res)):
                print(res[i], end=" ")
            print()
