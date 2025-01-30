// Leetcode 785. Is Graph Bipartite?

class Solution
{
public:
    bool bfs(vector<vector<int>> &adj, vector<int> &colors, int src)
    {
        queue<int> q;
        q.push(src);
        colors[src] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto &neighbour : adj[node])
            {
                if (colors[node] == colors[neighbour])
                    return false;
                if (colors[neighbour] == -1)
                {
                    q.push(neighbour);
                    colors[neighbour] = (colors[node] + 1) % 2;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> colors(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (colors[i] != -1)
                continue;
            if (!bfs(adj, colors, i))
                return false;
        }
        return true;
    }
};

// DFS Solution

class Solution
{
public:
    bool dfs(vector<vector<int>> &adj, vector<int> &colors, int src)
    {
        for (auto &neighbour : adj[src])
        {
            if (colors[neighbour] == -1)
            {
                colors[neighbour] = (colors[src] + 1) % 2;
                if (!dfs(adj, colors, neighbour))
                    return false;
            }
            else if (colors[neighbour] == colors[src])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> colors(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (colors[i] != -1)
                continue;
            colors[i] = 0;
            if (!dfs(adj, colors, i))
                return false;
        }
        return true;
    }
};

// Explaination

// The problem is to check if a graph is bipartite. A graph is bipartite if it can be divided into two sets of nodes such that no two nodes in the same set are connected by an edge. The graph is represented as an undirected graph with n nodes and edges. The edges are given as a list of pairs of nodes. The nodes are numbered from 0 to n-1.
// The solution uses a breadth-first search (BFS) or depth-first search (DFS) to color the nodes of the graph with two colors such that no two adjacent nodes have the same color. The colors are represented as 0 and 1. The algorithm starts by coloring the first node with color 0 and then colors the neighbors of the node with the opposite color. If a neighbor is already colored and has the same color as the current node, the graph is not bipartite. The algorithm continues this process for all nodes in the graph. If all nodes are colored without any conflicts, the graph is bipartite.
// The time complexity of the algorithm is O(V+E), where V is the number of nodes and E is the number of edges in the graph. The algorithm visits each node and edge once during the BFS or DFS traversal. The space complexity is O(V) for the colors array and the queue or stack used for the BFS or DFS traversal.