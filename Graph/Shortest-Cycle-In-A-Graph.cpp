// Leetcode 2608. Shortest Cycle in Undirected Graph

class Solution
{
public:
    int bfs(int src, vector<vector<int>> &adj, int n)
    {
        vector<int> dist(n, -1);
        queue<pair<int, int>> q;
        q.push({src, -1});
        dist[src] = 0;

        int shortestCycle = INT_MAX;

        while (!q.empty())
        {
            auto [node, parent] = q.front();
            q.pop();

            for (int neighbor : adj[node])
            {
                if (dist[neighbor] == -1)
                {
                    dist[neighbor] = dist[node] + 1;
                    q.push({neighbor, node});
                }
                else if (neighbor != parent)
                {
                    shortestCycle =
                        min(shortestCycle, dist[node] + dist[neighbor] + 1);
                }
            }
        }
        return shortestCycle;
    }

    int findShortestCycle(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int shortestCycle = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            shortestCycle = min(shortestCycle, bfs(i, adj, n));
        }

        return shortestCycle == INT_MAX ? -1 : shortestCycle;
    }
};

// Explaination

// The problem is to find the shortest cycle in an undirected graph. A cycle is a path in the graph that starts and ends at the same node and contains at least one edge. The length of a cycle is the number of edges in the cycle.
// The graph is represented as an undirected graph with n nodes and edges. The edges are given as a list of pairs of nodes. The nodes are numbered from 0 to n-1.
// The shortest cycle in the graph is the cycle with the minimum number of edges. If there is no cycle in the graph, return -1.
// Approach
// We can find the shortest cycle in the graph using BFS. We start a BFS traversal from each node in the graph and keep track of the distance of each node from the source node. If we encounter a node that is already visited and is not the parent of the current node, we have found a cycle. The length of the cycle is the sum of the distances of the two nodes from the source node plus one.
// We repeat this process for each node in the graph and return the minimum length of the cycle found. If no cycle is found, we return -1.
