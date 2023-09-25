"""
Idea:
using hashmap to store indices of elements in input vector & copying the vector & sort it for reference
Steps:
iterating each element, if an element is not in position, swap it using hashmap & sorted vector.
"""


class Solution:

    def minSwaps(self, nums):
        n = len(nums)
        sortedArray = nums[:]
        sortedArray.sort()  # sorting the copy of input vector
        hashMap = {}
        for i in range(n):
            if nums[i] not in hashMap:  # creating hashmap
                hashMap[nums[i]] = i
            else:
                hashMap[nums[i]] += 1
        ans = 0
        for i in range(n):
            if nums[i] != sortedArray[i]:  # if element is not in optimum position
                ans += 1
                s, t = nums[i], sortedArray[i]
                nums[i], nums[hashMap[sortedArray[i]]] = nums[hashMap[sortedArray[i]]], nums[i]  # swapping the element using hashmap
                hashMap[s] = hashMap[t]  # updating the hashmap

        return ans


if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n = int(input())
        nums = list(map(int, input().split()))
        obj = Solution()
        ans = obj.minSwaps(nums)
        print(ans)

# } Driver Code Ends
