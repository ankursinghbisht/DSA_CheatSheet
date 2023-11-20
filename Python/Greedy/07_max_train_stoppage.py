"""
Idea:
indexing each train , and sorting based on its departure time, if same, sort on indices given.
using vector to keep track of each platform, checking if current train can stay at designated station.
"""

class Solution():
    def maxStop(self, n, m, trains):
        for i in range(m):
            trains[i].append(i)

            # Sort trains based on  departure times and their indices
        trains.sort(key=lambda x: (x[1], x[3]))

        # Initialize an array to store the latest departure time for each station
        times = [-1] * (n + 1)

        # Initialize the count of stopped trains
        ans = 0

        # Iterate through sorted trains and stop them if possible
        for iter in trains:
            if iter[0] >= times[iter[2]]:
                times[iter[2]] = iter[1]
                ans += 1

        return ans


#{
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    for _ in range(int(input())):
        n,m = map(int, input().split())
        trains = []
        for i in range(m):
            trains.append([int(i) for i in input().split()])
        print(Solution().maxStop(n, m, trains))
# } Driver Code Ends