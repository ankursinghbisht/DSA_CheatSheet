/*
Idea:
have 2D array to keep track of visited cells, and using BFS to find the shortest path.
using a queue to store all possible cells of knight. and iterating each till final cell is reached
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    struct cell {
        int x; // x-coordinate of current position
        int y; // y-coordinate of current position
        int steps; // number of steps taken so far
    };
public:
    //Function to check if a position is valid or not.
    bool isValid(int x, int y, int N) {
        return (x >= 0 and x < N and y >= 0 and y < N); //check if x and y are within bounds
    }

    //Function to find the minimum number of steps to reach the target position.
    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N)
    {
        KnightPos[0]--; //decrement the x-coordinate of Knight's position
        KnightPos[1]--; //decrement the y-coordinate of Knight's position
        TargetPos[0]--; //decrement the x-coordinate of Target's position
        TargetPos[1]--; //decrement the y-coordinate of Target's position
        vector<vector<bool>>vis(N, vector<bool>(N, false)); //create a matrix to keep track of visited positions
        vector<vector<int>>dxy = { {2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2} }; //possible x and y movements for the Knight
        queue<cell>q; //create a queue to perform BFS

        q.push({ KnightPos[0], KnightPos[1], 0 }); //push the initial position of Knight with steps=0
        vis[KnightPos[0]][KnightPos[1]] = true; //mark the initial position as visited
        while (!q.empty())
        {
            int x = q.front().x; //get the x-coordinate of current position
            int y = q.front().y; //get the y-coordinate of current position
            int steps = q.front().steps; //get the number of steps taken so far
            q.pop(); //remove the current position from the queue
            if (x == TargetPos[0] and y == TargetPos[1]) //if current position is the target position
                return steps; //return the number of steps taken to reach the target position
            //check all possible movements from the current position
            for (int i = 0; i < dxy.size(); i++)
            {
                int n_x = x + dxy[i][0]; //calculate the new x-coordinate
                int n_y = y + dxy[i][1]; //calculate the new y-coordinate
                if (isValid(n_x, n_y, N) and !vis[n_x][n_y])  //if the new position is valid and not visited
                {
                    q.push({ n_x, n_y, steps + 1 }); //push the new position with updated steps
                    vis[n_x][n_y] = true; //mark the new position as visited
                }
            }
        }
        return -1; //if target position is not reachable, return -1
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        vector<int>KnightPos(2);
        vector<int>TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends