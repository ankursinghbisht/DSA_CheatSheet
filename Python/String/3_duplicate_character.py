"""
Idea:
using dictionary to store count of each element , if count exceeds 1, print the answer.dea:
"""


def printDups(Str):
    dic = {}
    for i in range(len(Str)):
        if Str[i] in dic:
            dic[Str[i]] += 1
        else:
            dic[Str[i]] = 1

    for i, j in dic.items():
        if j > 1:
            print(i, end=' ')


if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        S = input()
        print(printDups(S))
