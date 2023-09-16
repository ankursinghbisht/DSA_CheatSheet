"""
Idea:
appending only one unique character of a type, and recursively calling the function with remaining characters
"""


class Solution:
    def removeConsecutiveCharacter(self, S):
        if len(S) == 0:
            return ""

        firstChar = S[0]
        index = 0
        while index < len(S) and S[index] == firstChar:
            index += 1  # getting to the last index of appearance of character in 1st place of string

        return firstChar + self.removeConsecutiveCharacter(S[index:])


if __name__ == '__main__':
    T = int(input())

    for tcs in range(T):
        s = input()
        ob = Solution()
        print(ob.removeConsecutiveCharacter(s))
