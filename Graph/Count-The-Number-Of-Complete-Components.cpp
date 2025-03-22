// Leetcode 2685. Count The Number Of Complete Components

class Solution
{
public:
    bool bfs(int node, unordered_map<int, vector<int>> &adj, vector<bool> &visited)
    {
        queue<int> q;
        vector<int> comp;
        q.push(node);
        comp.push_back(node);
        visited[node] = true;

        while (!q.empty())
        {
            int temp = q.front();
            q.pop();

            for (auto &nbr : adj[temp])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    comp.push_back(nbr);
                    visited[nbr] = true;
                }
            }
        }

        for (int node : comp)
        {
            if (adj[node].size() != comp.size() - 1)
                return false;
        }

        return true;
    }

    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj;

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int count = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (adj[i].empty())
                {
                    count++;
                    visited[i] = true;
                }
                else if (bfs(i, adj, visited))
                {
                    count++;
                }
            }
        }

        return count;
    }
};

// Explaination:

// The idea is to check if the graph is a complete graph or not. A complete graph is a graph where each node is connected to all other nodes in the graph. So, we can check if the graph is a complete graph or not by checking if the degree of each node is equal to the number of nodes in the graph - 1. If the degree of each node is equal to the number of nodes in the graph - 1, then the graph is a complete graph. Otherwise, it is not a complete graph.
// First we will create an adjacency list representation of the graph using the given edges.
// Then we will iterate over all the nodes in the graph and check if the graph is a complete graph or not using the bfs function.
// The bfs function will perform a breadth first search starting from the given node and check if the degree of each node is equal to the number of nodes in the graph - 1.
// If the degree of each node is equal to the number of nodes in the graph - 1, then the graph is a complete graph and we will increment the count.
// Finally, we will return the count of complete components in the graph.
// Time Complexity: O(n + m), where n is the number of nodes in the graph and m is the number of edges in the graph.