// Leetcode 3243. Shortest Distance After Road Addition Queries I

// Breadth First Search (BFS) approach
class Solution
{
public:
    int bfs(int n, vector<vector<int>> &adj)
    {
        queue<int> q;
        q.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;
        int level = 0;

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int node = q.front();
                q.pop();

                if (node == n - 1)
                    return level;

                for (int neighbour : adj[node])
                {
                    if (!visited[neighbour])
                    {
                        q.push(neighbour);
                        visited[neighbour] = true;
                    }
                }
            }
            level++;
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>> &queries)
    {
        vector<vector<int>> adj(n);

        for (int i = 0; i < n - 1; i++)
        {
            adj[i].push_back(i + 1);
        }

        int q = queries.size();
        vector<int> result;

        for (auto &query : queries)
        {
            int u = query[0];
            int v = query[1];

            adj[u].push_back(v);

            int d = bfs(n, adj);
            result.push_back(d);
        }

        return result;
    }
};

// Explanation:

// We are given a graph with n nodes and n-1 edges. We need to find the shortest distance between the first and the last node. We can add a new edge between two nodes in the graph. We need to find the shortest distance after adding each edge.
// We can solve this problem using the Breadth First Search (BFS) approach. We can start from the first node and traverse the graph using BFS. We can keep track of the level of each node from the first node. We can stop the traversal when we reach the last node. We can return the level of the last node as the shortest distance.
// We can add a new edge between two nodes in the graph and find the shortest distance after adding the edge. We can repeat this process for each query and return the result.

// Dijkstra's Algorithm approach

class Solution
{
public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>> &queries)
    {
        vector<vector<int>> adj(n);
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        for (int i = 0; i < n - 1; i++)
        {
            adj[i].push_back(i + 1);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();

            for (int v : adj[u])
            {
                if (dist[u] + 1 < dist[v])
                {
                    dist[v] = dist[u] + 1;
                    pq.push({dist[v], v});
                }
            }
        }

        vector<int> result;

        for (auto &query : queries)
        {
            int u = query[0];
            int v = query[1];

            adj[u].push_back(v);

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, 0});

            vector<int> new_dist(n, INT_MAX);
            new_dist[0] = 0;

            while (!pq.empty())
            {
                auto [d, u] = pq.top();
                pq.pop();

                for (int v : adj[u])
                {
                    if (new_dist[u] + 1 < new_dist[v])
                    {
                        new_dist[v] = new_dist[u] + 1;
                        pq.push({new_dist[v], v});
                    }
                }
            }

            result.push_back(new_dist[n - 1]);
        }

        return result;
    }
};

// Explanation:

// We are given a graph with n nodes and n-1 edges. We need to find the shortest distance between the first and the last node. We can add a new edge between two nodes in the graph. We need to find the shortest distance after adding each edge.
// We can solve this problem using Dijkstra's Algorithm. We can start from the first node and traverse the graph using Dijkstra's Algorithm. We can keep track of the distance of each node from the first node. We can stop the traversal when we reach the last node. We can return the distance of the last node as the shortest distance.
// We can add a new edge between two nodes in the graph and find the shortest distance after adding the edge. We can repeat this process for each query and return the result.
// Time Complexity: O(n^2 + q*n^2) = O(q*n^2)