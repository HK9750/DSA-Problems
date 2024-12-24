// Leetcode 3203. Find Minimum Diameter After Merging Two Trees

class Solution
{
public:
    int minimumDiameterAfterMerge(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);

        for (auto &edge : edges1)
        {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for (auto &edge : edges2)
        {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis1(n, false);
        auto ans1 = bfs(adj1, vis1, 0);
        fill(vis1.begin(), vis1.end(), false);
        ans1 = bfs(adj1, vis1, ans1.first);

        vector<bool> vis2(m, false);
        auto ans2 = bfs(adj2, vis2, 0);
        fill(vis2.begin(), vis2.end(), false);
        ans2 = bfs(adj2, vis2, ans2.first);

        int maxDiam = max(ans1.second, ans2.second);
        int combineMax = (ans1.second + 1) / 2 + (ans2.second + 1) / 2 + 1;

        return max(maxDiam, combineMax);
    }

private:
    pair<int, int> bfs(vector<vector<int>> &adj, vector<bool> &vis, int node)
    {
        queue<int> q;
        q.push(node);
        vis[node] = true;
        int len = 0;
        int last = node;

        while (!q.empty())
        {
            int size = q.size();
            len++;
            for (int i = 0; i < size; i++)
            {
                int temp = q.front();
                q.pop();
                last = temp;
                for (int neighbor : adj[temp])
                {
                    if (!vis[neighbor])
                    {
                        vis[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
        return {last, len - 1};
    }
};

// Explaination:

// We are given two edges, we create two adjacency lists for the two trees. We then perform a BFS on both trees to find the diameter of the two trees.
// We then calculate the maximum diameter of the two trees and the diameter of the tree formed by connecting the two trees.
// We return the maximum of the two diameters.