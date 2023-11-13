"""
Idea:
making a pair of end and start times, & sorting pairs basis on their end times.
Iterating the array of pairs, and choosing pairs whose start time is greater than last  selected pair's end time
"""


# User function Template for python3

class Solution:

    # Function to find the maximum number of meetings that can
    # be performed in a meeting room.
    def maximumMeetings(self, n, start, end):
        # Combine start and end times into a list of pairs
        # The pair format is (end_time, start_time)
        meetings = list(zip(end, start))

        # Sort the meetings based on their end times in ascending order
        meetings.sort()

        # Initialize variables for counting meetings and tracking the ending time
        count = 1  # At least one meeting can be scheduled
        ending = meetings[0][0]  # Ending time of the first meeting

        # Iterate through the sorted meetings
        for i in range(1, n):
            # If the start time of the current meeting is greater than the ending time
            # of the previous meeting, it can be scheduled, and update count and ending time
            if meetings[i][1] > ending:
                count += 1
                ending = meetings[i][0]

        # Return the maximum number of non-overlapping meetings
        return count


# code here


# {
# Driver Code Starts
# Initial Template for Python 3
import atexit
import io
import sys


if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        start = list(map(int, input().strip().split()))
        end = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.maximumMeetings(n, start, end))
# } Driver Code Ends