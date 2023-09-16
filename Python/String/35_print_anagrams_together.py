"""
Idea:
Using dictionary to store key value pair of each string
with key being sorted form of each string, and appending values to it's key each time a value is matched, returned the result
"""

from collections import defaultdict


class Solution:

    def Anagrams(self, string_list,n):

        anagramGroups = defaultdict(list)

        for s in string_list:
            key = ''.join(sorted(s))  # Sort the characters in the string to create a unique key
            anagramGroups[key].append(s)

        result = []
        for key, group in sorted(anagramGroups.items()):
            result.append(group)

        return result


if __name__ == '__main__':
    t = int(input())
    for tcs in range(t):
        n = int(input())
        words = input().split()

        ob = Solution()
        ans = ob.Anagrams(words, n)

        for grp in sorted(ans):
            for word in grp:
                print(word, end=' ')
            print()
