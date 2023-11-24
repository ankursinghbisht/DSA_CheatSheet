"""
Idea:
Loop till all processes are complete.
 use another loop to keep track of nodes with the shortest burst time that has arrived and not yet completed,
keep track of waiting & turnaround time of each process, and return average.
"""

from typing import List


class Solution:
    def round(self, var):
        value = int(var * 100 + 0.5)
        return float(value) / 100

    def averageTimes(self, n: int, arrival_time: List[int], burst_time: List[int]) -> List[float]:
        completion_time = [0] * n
        turn_around_time = [0] * n
        waiting_time = [0] * n
        completed = [0] * n

        system_time = 0
        total_processes = 0
        avg_waiting_time = 0
        avg_turn_around_time = 0

        # Initializing all processes as undone
        for i in range(n):
            completed[i] = 0

        # Until all processes are done
        while total_processes != n:
            check = n
            minimum = float('inf')

            for i in range(n):
                """
                    If the process arrival time is less than the system time and it is not completed
                    and burstTime is the smallest of this process, this process will be executed first
                """
                if arrival_time[i] <= system_time and completed[i] == 0 and burst_time[i] < minimum:
                    minimum = burst_time[i]
                    check = i

            # No process in the queue.
            if check == n:
                system_time += 1
            else:
                completion_time[check] = system_time + burst_time[check]
                system_time += burst_time[check]
                turn_around_time[check] = completion_time[check] - arrival_time[check]
                waiting_time[check] = turn_around_time[check] - burst_time[check]
                completed[check] = 1
                total_processes += 1

        # Sum for calculating averages
        for i in range(n):
            avg_waiting_time += waiting_time[i]
            avg_turn_around_time += turn_around_time[i]

        ans = [0.0, 0.0]

        ans[0] = float(avg_waiting_time / n)
        ans[1] = float(avg_turn_around_time / n)

        res1 = self.round(ans[0])
        res2 = self.round(ans[1])
        return [res1, res2]


# {
# Driver Code Starts
class IntArray:
    def __init__(self) -> None:
        pass

    def Input(self, n):
        arr = [int(i) for i in input().strip().split()]  # array input
        return arr

    def Print(self, arr):
        for i in arr:
            print(i, end=" ")
        print()


class DoubleArray:
    def __init__(self) -> None:
        pass

    def Input(self, n):
        arr = [float(i) for i in input().strip().split()]  # array input
        return arr

    def Print(self, arr):
        for i in arr:
            print("{0:.2f}".format(i), end=" ")
        print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())

        arrivalTime = IntArray().Input(n)

        burstTime = IntArray().Input(n)

        obj = Solution()
        res = obj.averageTimes(n, arrivalTime, burstTime)

        DoubleArray().Print(res)

# } Driver Code Ends
