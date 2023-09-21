"""
Idea:
Starting from -inf to +inf, using ternary search to find the minimum distance at each iteration

( Ternary search is a divide-and-conquer search algorithm that iteratively narrows down a search space
 into "three" equal parts and eliminates one-third of the space in each iteration)
"""

import math


class Solution:
    def findOptimumCost(self, line: list[int], n: int, points: list[list[int]]) -> float:

        # calculating distance between two points...
        def distance(x, y, point):

            dis = math.sqrt((x - point[0]) ** 2 + (y - point[1]) ** 2)

            return dis

        def compute(line, points, n, x):

            summ_distance = 0
            # calculate y.. coordinate...
            # since..   ax + by +c = 0..
            # calculate y..
            if line[1] != 0:
                y = -1 * (line[0] * x + line[2]) / line[1]
            else:
                y = float("inf")
            # now, we have both x, y points ..
            # find the distances from the given points and add them

            for i in range(n):
                summ_distance += distance(x, y, points[i])

            return summ_distance

        # ternary serach...
        # finding x .. from -1e6 to 1e6 .. and find y corresponding to x from line equation

        low = -1e3  # denotes the lowest x value on x-axis
        high = 1e3  # denotes the highest x value on x_axis

        precision = 1e-6
        while (high - low) > precision:

            # both mid denotes the value of x...
            mid1 = low + (high - low) / 3
            mid2 = high - (high - low) / 3

            dis1 = compute(line, points, n, mid1)
            dis2 = compute(line, points, n, mid2)

            if dis1 < dis2:
                #  go towards lower distance point .. and eliminate other 1/3 part.
                high = mid2  # can be candidate for ans

            elif dis1 > dis2:
                low = mid1  # can be candidate for ans

            else:
                low = mid1
                high = mid2

        return compute(line, points, n, (low + high) / 2)



