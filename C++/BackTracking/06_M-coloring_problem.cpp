/*
Idea:
iterating graph one node at a time, checking if it's valid to color the node(i.e.) no adjacent is colored the same.
recursively calling the function for next nodes, till all nodes are colored.
If count of colors is greater than required, returning false
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
private:
    // Function to check if it's safe to assign 'currColour' to 'nodeToColour'
    // without violating the coloring constraint (no adjacent nodes have the same color).
    bool isSafe(int nodeToColour, int colourToAssign[], bool graph[101][101], int n, int currColour)
    {
        for (int k = 0; k < n; k++)

            // Check all nodes (k) in the graph.
            if (k != nodeToColour && graph[k][nodeToColour] == 1 && colourToAssign[k] == currColour)
                // If 'k' is an adjacent node of 'nodeToColour' and has the same color 'currColour',
                // it's not safe to assign this color.
                return false;

        // If no conflict is found, it's safe to assign 'currColour' to 'nodeToColour'.
        return true;
    }

    // Recursive function to solve the graph coloring problem.
    bool solve(int nodeToColour, int colourToAssign[], int m, int n, bool graph[101][101])
    {
        if (nodeToColour == n)
            // If all nodes are colored successfully, return true, indicating a valid coloring.
            return true;


        for (int i = 1; i <= m; i++) {
            if (isSafe(nodeToColour, colourToAssign, graph, n, i))
            {
                // If it's safe to assign color 'i' to 'nodeToColour', proceed.
                colourToAssign[nodeToColour] = i;  // Assign color 'i' to 'nodeToColour'.
                if (solve(nodeToColour + 1, colourToAssign, m, n, graph))
                {
                    // Recursively try to color the next node. If it returns true,
                    // it means the coloring is valid, so return true.
                    return true;
                }
                colourToAssign[nodeToColour] = 0;  // Reset the color assignment for backtracking.
            }
        }
        // If no valid coloring is found for 'nodeToColour', return false.
        return false;
    }
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n)
    {
        // The colour[] array is of size n, where n is the number of nodes in the graph. 
        // Each element in this array represents the color assigned to a node in the graph.
        // Initially, all elements of the colour[] array are set to 0, which can be considered as no color assigned. 
        // This means that at the beginning of the graph coloring process, none of the nodes in the graph have been assigned a color.
        int colourToAssign[n] = { 0 };

        if (solve(0, colourToAssign, m, n, graph))
            // If a valid coloring is found for the entire graph, return true.
            return true;

        else
            // If no valid coloring is possible, return false.
            return false;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends