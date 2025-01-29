// Leetcode 684. Redundant Connection

class Solution
{
private:
    bool isConnected(int src, int target, vector<bool> &visited,
                     vector<vector<int>> &adjList)
    {
        visited[src] = true;

        if (src == target)
        {
            return true;
        }

        int isFound = false;
        for (int adj : adjList[src])
        {
            if (!visited[adj])
            {
                isFound = isFound || isConnected(adj, target, visited, adjList);
            }
        }

        return isFound;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();

        vector<vector<int>> adjList(n);
        for (auto edge : edges)
        {
            vector<bool> visited(n, false);

            if (isConnected(edge[0] - 1, edge[1] - 1, visited, adjList))
            {
                return edge;
            }

            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }

        return {};
    }
};

// Explaination:

// The problem is to find the redundant connection in a graph. We can solve this problem using DFS. We will start from the first edge and add it to the adjacency list. Then we will check if there is a path from the source to the target using DFS. If there is a path, then the edge is redundant and we return it. Otherwise, we continue adding edges to the adjacency list and checking for redundant edges. Finally, we return an empty vector if no redundant edge is found.
// We are using edge[0] - 1 and edge[1] - 1 because the edges are 1-indexed and we need to convert them to 0-indexed for the adjacency list. We are also using a visited array to keep track of the visited nodes to avoid visiting the same node multiple times. We are using a helper function isConnected to check if there is a path from the source to the target using DFS. If there is a path, then the edge is redundant and we return it. Otherwise, we continue adding edges to the adjacency list and checking for redundant edges. Finally, we return an empty vector if no redundant edge is found.