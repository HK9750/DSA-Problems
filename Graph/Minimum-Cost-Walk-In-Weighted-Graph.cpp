// Leetcode 3108. Minimum Cost Walk in Weighted Grid

class Solution
{
public:
    vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &queries)
    {
        vector<vector<pair<int, int>>> graph(n);
        for (auto &e : edges)
        {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        vector<bool> seen(n, false);
        vector<int> group(n);
        vector<int> groupCost;
        int id = 0;

        for (int i = 0; i < n; i++)
        {
            if (!seen[i])
            {
                groupCost.push_back(findCost(i, graph, seen, group, id));
                id++;
            }
        }

        vector<int> res;
        for (auto &q : queries)
        {
            int u = q[0], v = q[1];
            res.push_back(group[u] == group[v] ? groupCost[group[u]] : -1);
        }

        return res;
    }

private:
    int findCost(int src, vector<vector<pair<int, int>>> &graph, vector<bool> &seen, vector<int> &group, int id)
    {
        queue<int> q;
        int cost = INT_MAX;

        q.push(src);
        seen[src] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            group[node] = id;

            for (auto &[nbr, w] : graph[node])
            {
                cost &= w;
                if (seen[nbr])
                    continue;
                seen[nbr] = true;
                q.push(nbr);
            }
        }

        return cost;
    }
};

// Explaination:

// First we build the graph from the given edges. Then we find the connected components of the graph using BFS. For each connected component, we find the minimum cost of the edges in that component. Then for each query, we check if the two nodes are in the same connected component. If they are, we return the minimum cost of the edges in that component. Otherwise, we return -1.
// Time complexity: O(n + m + q), where n is the number of nodes, m is the number of edges, and q is the number of queries.
// Space complexity: O(n + m + q), where n is the number of nodes, m is the number of edges, and q is the number of queries.