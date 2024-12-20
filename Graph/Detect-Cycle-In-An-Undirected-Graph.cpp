// GFG-Link:https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

// BFS Solution

class Solution
{
public:
    bool bfs(int src, vector<int> &visited, vector<vector<int>> &adj)
    {
        queue<pair<int, int>> q;
        q.push({src, -1});
        visited[src] = 1;

        while (!q.empty())
        {
            pair<int, int> temp = q.front();
            int node = temp.first;
            int parent = temp.second;
            q.pop();

            for (auto &adjnode : adj[node])
            {
                if (!visited[adjnode])
                {
                    q.push({adjnode, node});
                    visited[adjnode] = 1;
                }
                else if (parent != adjnode)
                {
                    return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>> &adj)
    {
        // Code here
        int n = adj.size();
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (bfs(i, visited, adj))
                    return true;
            }
        }

        return false;
    }
};

// DFS Solution

class Solution
{
public:
    bool dfs(int src, int parent, vector<int> &visited, vector<vector<int>> &adj)
    {
        visited[src] = 1;

        for (auto &adjnode : adj[src])
        {
            if (!visited[adjnode])
            {
                if (dfs(adjnode, src, visited, adj))
                    return true;
            }
            else if (adjnode != parent)
                return true;
        }

        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>> &adj)
    {
        // Code here
        int n = adj.size();
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, -1, visited, adj))
                    return true;
            }
        }

        return false;
    }
};