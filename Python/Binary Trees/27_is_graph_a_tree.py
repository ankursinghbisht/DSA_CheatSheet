"""
Idea:
if a graph is connected and has n – 1 edges exactly then the graph is a tree.
"""


# A Python Program to check whether a graph is tree or not

# Class for an undirected graph
class Graph:
    def __init__(self, V):
        self.V = V  # No. of vertices
        self.E = 0  # No. of edges
        # Pointer to an array for adjacency lists
        self.adj = [[] for i in range(V)]

    # to add an edge to graph
    def addEdge(self, v, w):
        self.E += 1  # increase the number of edges
        self.adj[v].append(w)  # Add w to v’s list.
        self.adj[w].append(v)  # Add v to w’s list.

    # A recursive dfs function that uses visited[] and parent to traverse the graph and mark visited[v] to true for visited nodes
    def dfsTraversal(self, v, visited, parent):
        # Mark the current node as visited
        visited[v] = True

        # Recur for all the vertices adjacent to this vertex
        for i in self.adj[v]:

            # If an adjacent is not visited, then recur for that adjacent
            if not visited[i]:
                self.dfsTraversal(i, visited, v)

    # Returns true if the graph is connected, else false.
    def isConnected(self):
        # Mark all the vertices as not visited and not part of recursion stack

        visited = [False] * self.V

        # Performing DFS traversal of the graph and marking reachable vertices from 0 to true
        self.dfsTraversal(0, visited, -1)

        # If we find a vertex which is not reachable from 0 (not marked by dfsTraversal(), then we return false since graph is not connected
        for u in range(self.V):
            if not visited[u]:
                return False

        # since all nodes were reachable, so we returned true and hence graph is connected
        return True

    def isTree(self):
        # as we proved earlier if a graph is connected and has V - 1 edges then it is a tree i.e. E = V - 1

        return self.isConnected() and self.E == self.V - 1


# Driver program to test above functions
if __name__ == '__main__':
    g1 = Graph(5)
    g1.addEdge(1, 0)
    g1.addEdge(0, 2)
    g1.addEdge(0, 3)
    g1.addEdge(3, 4)

    print("Graph is Tree" if g1.isTree() == True else "Graph is not Tree")

    g2 = Graph(5)
    g2.addEdge(1, 0)
    g2.addEdge(0, 2)
    g2.addEdge(2, 1)
    g2.addEdge(0, 3)
    g2.addEdge(3, 4)

    print("Graph is Tree" if g2.isTree() == True else "Graph is not Tree")
