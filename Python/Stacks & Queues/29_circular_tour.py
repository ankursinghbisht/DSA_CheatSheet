"""
Idea:
keeping track of sum of difference between petrol & distance. if sum<0 , reset to 0 and set answer to that index
& check if total sum>0
"""

'''
    lis[][0]:Petrol
    lis[][1]:Distance
'''


class Solution:

    # Function to find starting point where the truck can start to get through
    # the complete circle without exhausting its petrol in between.
    def tour(self, p, n):
        # Initialize variables to keep track of temporary and total petrol surplus,
        # the difference between petrol and distance, and the answer (starting point).
        temp, total, ans = 0, 0, 0

        # Iterate through the petrol pumps.
        for i in range(n):
            # Calculate the surplus petrol at the current petrol pump.
            diff = p[i][0] - p[i][1]

            # Update temporary and total surplus petrol.
            temp += diff
            total += diff

            # If the total surplus becomes negative, reset it to zero
            # and update the potential starting point.
            if total < 0:
                total = 0
                ans = i + 1

        # If the total surplus is negative overall, there is no valid starting point.
        if temp < 0:
            return -1

        # Return the index of the valid starting point.
        return ans


# {
# Driver Code Starts
if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        lis = []
        for i in range(1, 2 * n, 2):
            lis.append([arr[i - 1], arr[i]])
        print(Solution().tour(lis, n))
    # Contributed by: Harshit Sidhwa
# } Driver Code Ends