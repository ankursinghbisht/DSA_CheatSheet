"""
Idea:
Iterating the string, checking if character matches, else there is ? or *
then iterating the string till next character matches , if not , returning false
"""


class Solution:
    def match(self, wild, pattern):
        patternIndex, wildIndex, = 0, 0
        lastWildCardIndex, patternBackTrackIndex, nextToWildCardIndex = -1, -1, -1

        while patternIndex < len(pattern):
            if wildIndex < len(wild) and (wild[wildIndex] == '?' or pattern[patternIndex] == wild[wildIndex]):
                patternIndex += 1
                wildIndex += 1
            elif wildIndex < len(wild) and wild[wildIndex] == '*':
                lastWildCardIndex = wildIndex  # wildcard, so chars match - store index.
                wildIndex += 1
                nextToWildCardIndex = wildIndex
                patternBackTrackIndex = patternIndex
                # storing the pidx+1 as from there I want to match the remaining pattern

            elif lastWildCardIndex == -1:  # no match, and no wildcard has been found.
                return False
            else:
                # backtrack - no match, but a previous wildcard was found.
                wildIndex = nextToWildCardIndex
                patternBackTrackIndex += 1
                patternIndex = patternBackTrackIndex
                # backtrack string from previousbacktrackidx + 1 index to see if then new pidx and sidx have same chars, if that is the case that means wildcard can absorb the chars in b/w and still further we can run the algo, if at later stage it fails we can backtrackbacktrack string from previousbacktrackidx + 1 index to see if then new pidx and sidx have same chars,
                # if that is the case that means wildcard can absorb the chars in b/w and still further we can run the algo, if at later stage it fails we can backtrack

        for i in range(wildIndex, len(wild)):
            if wild[i] != '*':  # if last elements of wild string aren't * , then string can't be matched
                return False
        return True


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        wild = input()
        pattern = input()

        ob = Solution()
        if ob.match(wild, pattern):
            print("Yes")
        else:
            print("No")
# } Driver Code Ends
