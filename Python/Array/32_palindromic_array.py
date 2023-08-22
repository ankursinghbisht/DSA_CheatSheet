"""
Idea: Iterating through each element & finding if it's palindrome or not.
"""


def PalinArray(arr, n):
    for i in range(n):
        temp = 0
        num = arr[i]
        while num > 0:
            temp = temp * 10 + num % 10
            num //= 10
        if temp != arr[i]:
            return False
    return True


if __name__ == '__main__':
    t = int(input())
    for j in range(t):
        nn = int(input())
        a = list(map(int, input().strip().split()))
        if PalinArray(a, nn):
            print(1)
        else:
            print(0)
