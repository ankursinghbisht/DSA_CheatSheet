"""
Idea:
Any number with factorial with 'n' following zeroes must have 'n' 5 in it
To solve:
finding element with 'n' 5 in its factorial

Steps:
Declaring low & high as 0 & 5* 'n' as,the maximum value whose factorial contain n trailing zeroes is 5*n.
doing binary search between it, and finding minimum val with 'n' 0s.
"""



class Solution:
    # Return true if number's factorial contains at least n trailing zero else false.
    def Check(self, num, n):
        count, temp, f = 0, num, 5
        while f <= temp:  # counts no. of factorial 5 present in factorial of 'p'
            count += temp // f
            f *= 5
        return count >= n

    # Return smallest number whose factorial contains at least n trailing zeroes
    def findNum(self, n: int):
        if n == 1:
            return 5
        low, high = 0, 5 * n  # the maximum value whose factorial contain n trailing zeroes is 5*n.
        while low < high:
            mid = (high + low) // 2
            if self.Check(mid, n):  # if mid has factorial with atleast n trailing 0s, finding smaller number with same
                high = mid
            else:
                low = mid + 1


if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        n = int(input())
        ob = Solution()
        print(ob.findNum(n))
