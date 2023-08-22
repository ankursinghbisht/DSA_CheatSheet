"""
Idea:
Iterating element in a2, & searching if it's present in a1, if yes, remove it
,if any element in a2, not found in a1. return False
"""


def isSubset(a1, a2, n, m):
    for i in range(m):
        if a2[i] in a1:
            a1.remove(a2[i])
        else:
            return "No"

    return "Yes"


def main():
    T = int(input())

    while T > 0:
        sz = [int(x) for x in input().strip().split()]
        n, m = sz[0], sz[1]
        a1 = [int(x) for x in input().strip().split()]
        a2 = [int(x) for x in input().strip().split()]

        print(isSubset(a1, a2, n, m))

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends
