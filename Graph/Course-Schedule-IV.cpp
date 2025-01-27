// Leetcode 1462. Course Schedule IV

class Solution
{
public:
    bool bfs(int src, int dest, unordered_map<int, vector<int>> &adj,
             vector<bool> &visited)
    {
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int temp = q.front();
            q.pop();

            for (auto &node : adj[temp])
            {
                if (!visited[node])
                {
                    if (dest == node)
                        return true;
                    visited[node] = true;
                    q.push(node);
                }
            }
        }

        return false;
    }

    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>> &prerequisites,
                                     vector<vector<int>> &queries)
    {
        unordered_map<int, vector<int>> adj;

        for (auto &edge : prerequisites)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        int n = queries.size();
        vector<bool> result(n);

        for (int i = 0; i < n; i++)
        {
            int src = queries[i][0];
            int dest = queries[i][1];

            vector<bool> visited(numCourses, false);

            result[i] = bfs(src, dest, adj, visited);
        }

        return result;
    }
};

// Explaination:

// We have to find that queries[i][0] is a prerequisite of queries[i][1] or not.
// Which is nothing but finding the path from queries[i][0] to queries[i][1] in the graph.
// So, we can use BFS to find the path from queries[i][0] to queries[i][1] in the graph.
// If we find dest node in the path then return true else return false.
// Then we store it in the result vector and return it.

class Solution
{
public:
    bool dfs(int src, int dest, unordered_map<int, vector<int>> &adj,
             vector<vector<int>> &cache)
    {
        if (cache[src][dest] != -1)
            return cache[src][dest];
        for (auto &neighbor : adj[src])
        {
            if (neighbor == dest || dfs(neighbor, dest, adj, cache))
            {
                return cache[src][dest] = true;
            }
        }
        return cache[src][dest] = false;
    }

    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>> &prerequisites,
                                     vector<vector<int>> &queries)
    {
        unordered_map<int, vector<int>> adj;
        for (auto &edge : prerequisites)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        vector<vector<int>> cache(numCourses, vector<int>(numCourses, -1));
        vector<bool> result;
        for (auto &query : queries)
        {
            int src = query[0];
            int dest = query[1];
            result.push_back(dfs(src, dest, adj, cache));
        }
        return result;
    }
};

// Explaination:

// We are now using cached DFS to find the path from queries[i][0] to queries[i][1] in the graph.
// If we find dest node in the path then return true else return false.
// Then we store it in the result vector and return it.
