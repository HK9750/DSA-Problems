// Leetcode 547. Number of Provinces

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int ans = 0;

        auto dfs = [&](int node, auto &&dfs) -> void
        {
            visited[node] = true;
            for (int neighbor = 0; neighbor < n; neighbor++)
            {
                if (!visited[neighbor] && isConnected[node][neighbor] == 1)
                {
                    dfs(neighbor, dfs);
                }
            }
        };

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                ans++;
                dfs(i, dfs);
            }
        }

        return ans;
    }
};

// Detailed Explanation:

// We can solve this problem using Depth First Search (DFS).
// We will create a 1D vector to store the visited status of each node.
// We will iterate through each node of the graph. If the node is not visited, we will call the DFS function.
// In the DFS function, we will mark the current node as visited and recursively call the DFS function on all the neighbors of the current node.
// We will keep track of the number of provinces by incrementing a counter each time we call the DFS function.
// Finally, we will return the counter, which will be the number of provinces in the graph.
// Time Complexity: O(n^2) where n is the number of nodes in the graph.