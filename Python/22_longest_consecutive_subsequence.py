"""
Idea: using set to find unique elements,& storing longest consecutive elements.
"""


def findLongestConseqSubseq(arr, N):
    ans = count = 1
    nums = set()
    for i in range(N):
        nums.add(arr[i])
    for element in nums:
        # Check if the current element and the next element are consecutive
        if element + 1 in nums:
            count += 1
        else:
            count = 1  # Reset the count if elements are not consecutive
        ans = max(count, ans)
    return ans


if __name__ == '__main__':
    t = int(input())
    for tt in range(t):
        n = int(input())
        a = list(map(int, input().strip().split()))
        print(findLongestConseqSubseq(a, n))
