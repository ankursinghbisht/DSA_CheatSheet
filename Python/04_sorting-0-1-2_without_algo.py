class Solution:
    def sort012(self, arr, n):
        # counts all individual numbers in list using count function
        count0, count1, count2 = arr.count(0), arr.count(1), arr.count(2)

        # list slicing is done to insert desired numbers in designated positions
        arr[0:count0] = [0] * count0
        arr[count0:count0 + count1] = [1] * count1
        arr[count0 + count1:] = [2] * count2



if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = [int(x) for x in input().strip().split()]
        ob = Solution()
        ob.sort012(arr, n)
        for i in arr:
            print(i, end=' ')
        print()
