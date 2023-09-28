"""
Idea:
finding min & max time required to cook all parathas.
using binary search to find optimum time to cook
with each 'mid' value, check if it's possible to cook in time limit.
returning minimum time value.
"""


class Solution:
    def isPossible(self, cookRanks, count, timeLimit):
        pratasCooked = 0
        for rank in cookRanks:
            time = rank
            pratasCookedRank = 0
            while time <= timeLimit:  # counting parathas cooked by a chef in certain time.
                pratasCookedRank += 1
                time += rank * pratasCookedRank
            pratasCooked += pratasCookedRank
        return pratasCooked >= count

    def minuteToCook(self, chefs, count):
        chefs.sort()
        n = len(chefs)
        low = 0
        high = chefs[-1] * (n * n * (n - 1) // 2)  # setting low =0 & high as max time required to cook all parathas
        while low <= high:
            mid = low + (high - low) // 2
            if self.isPossible(chefs, count, mid):  # finding if current time is enough to cook parathas
                high = mid
            else:
                low = mid + 1
        return low


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        k, n = map(int, input().split())
        chefs = list(map(int, input().split()))
        obj = Solution()
        print(obj.minuteToCook(chefs, n))
