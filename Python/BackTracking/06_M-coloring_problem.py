"""
Idea:
iterating graph one node at a time, checking if it's valid to color the node(i.e.) no adjacent is colored the same.
recursively calling the function for next nodes, till all nodes are colored.
If count of colors is greater than required, returning false
"""


# User function Template for python3


def isSafe(node_to_colour, colour_to_assign, graph, n, curr_colour):
    # Function to check if it's safe to assign 'curr_colour' to 'node_to_colour'
    # without violating the coloring constraint (no adjacent nodes have the same color).
    for k in range(n):
        # Check all nodes (k) in the graph.
        if k != node_to_colour and graph[k][node_to_colour] == 1 and colour_to_assign[k] == curr_colour:
            # If 'k' is an adjacent node of 'node_to_colour' and has the same color 'curr_colour',
            # it's not safe to assign this color.
            return False
    # If no conflict is found, it's safe to assign 'curr_colour' to 'node_to_colour'.
    return True


def solve(node_to_colour, colour_to_assign, m, n, graph):
    # Recursive function to solve the graph coloring problem.
    if node_to_colour == n:
        # If all nodes are colored successfully, return true, indicating a valid coloring.
        return True

    for i in range(1, m + 1):
        if isSafe(node_to_colour, colour_to_assign, graph, n, i):
            # If it's safe to assign color 'i' to 'node_to_colour', proceed.
            colour_to_assign[node_to_colour] = i  # Assign color 'i' to 'node_to_colour'.
            if solve(node_to_colour + 1, colour_to_assign, m, n, graph):
                # Recursively try to color the next node. If it returns true,
                # it means the coloring is valid, so return true.
                return True
            colour_to_assign[node_to_colour] = 0  # Reset the color assignment for backtracking.

    # If no valid coloring is found for 'node_to_colour', return false.
    return False


def graphColoring(graph, m, n):
    # Function to determine if the graph can be coloured with at most M colours such
    # that no two adjacent vertices of the graph are coloured with the same colour.
    # The colour_to_assign array is of size n, where n is the number of nodes in the graph.
    # Each element in this array represents the color assigned to a node in the graph.
    # Initially, all elements of the colour_to_assign array are set to 0, which can be considered as no color assigned.
    # This means that at the beginning of the graph coloring process, none of the nodes in the graph have been assigned a color.
    colour_to_assign = [0] * n
    if solve(0, colour_to_assign, m, n, graph):
        # If a valid coloring is found for the entire graph, return true.
        return True
    else:
        # If no valid coloring is possible, return false.
        return False


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while (t > 0):
        V = int(input())
        k = int(input())
        m = int(input())
        list = [int(x) for x in input().strip().split()]
        graph = [[0 for i in range(V)] for j in range(V)]
        cnt = 0
        for i in range(m):
            graph[list[cnt] - 1][list[cnt + 1] - 1] = 1
            graph[list[cnt + 1] - 1][list[cnt] - 1] = 1
            cnt += 2
        if (graphColoring(graph, k, V) == True):
            print(1)
        else:
            print(0)

        t = t - 1

# } Driver Code Ends
