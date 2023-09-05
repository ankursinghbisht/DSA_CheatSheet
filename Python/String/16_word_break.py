"""
Idea:
using recursion to find all possible combinations of words & searching if all exist in dictionary.
"""


def wordBreak(line, dictionary):
    if len(line) == 0:  # Base case: an empty string can always be broken.
        return 1

    for i in range(1, len(line) + 1):
        # trying all possible combination of words
        prefix = line[:i]
        # If the prefix is in the dictionary and the remaining part can be broken
        if prefix in dictionary and wordBreak(line[i:], dictionary):
            return 1
    return 0


if __name__ == '__main__':
    test_case = int(input())
    for _ in range(test_case):
        number_of_elements = int(input())
        dictionary = [word for word in input().strip().split()]
        line = input().strip()
        res = wordBreak(line, dictionary)
        if res:
            print(1)
        else:
            print(0)
