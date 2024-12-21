// Leetcode 2872. Maximum Number of K-Divisible Components

class Solution
{
public:
    int dfs(vector<vector<int>> &adj, int &ans, vector<int> &values, int k,
            int currNode, int parentNode)
    {
        int sum = 0;

        for (auto &neighbour : adj[currNode])
        {
            if (parentNode != neighbour)
            {
                sum += dfs(adj, ans, values, k, neighbour, currNode);
                sum %= k;
            }
        }
        sum += values[currNode];
        sum %= k;
        if (sum == 0)
            ans++;

        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                                vector<int> &values, int k)
    {
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }

        int ans = 0;

        int sum = dfs(adj, ans, values, k, 0, -1);

        return ans;
    }
};

// Explaination:

// We are given a tree with n nodes and n-1 edges. Each node has a value associated with it. We need to find the number of components in the tree such that the sum of values of nodes in the component is divisible by k.
// First we make an adjacency list of the tree.
// We will use a dfs to traverse the tree. We will keep track of the sum of values of nodes in the subtree rooted at the current node. We will also keep track of the sum of values of nodes in the path from the root to the current node.
// We will pass the sum of values of nodes in the path from the root to the current node to the parent node.
// We will add the value of the current node to the sum of values of nodes in the path from the root to the current node.
// We will take the modulo of the sum of values of nodes in the path from the root to the current node with k.
// If the sum of values of nodes in the path from the root to the current node is divisible by k, we will increment the answer.
// We will return the sum of values of nodes in the path from the root to the current node.