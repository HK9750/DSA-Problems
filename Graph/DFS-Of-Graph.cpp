// Depth First Search of a graph
// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &ans)
    {
        visited[node] = true;
        ans.push_back(node);

        for (auto &neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, adj, visited, ans);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>> &adj)
    {
        // Code here
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> ans;
        dfs(0, adj, visited, ans);
        return ans;
    }
};

// Explanation:

// The idea is to start from the source node and visit all the nodes in the graph.
// We will use a visited array to keep track of the nodes that we have visited.
// We will use a recursive function to visit all the nodes in the graph.
// We will start from the source node and visit all the nodes that are connected to it.
// We will mark the node as visited and add it to the answer vector.
// We will then recursively visit all the nodes that are connected to the current node.
// We will keep track of the nodes that we have visited using the visited array.
// We will return the answer vector which contains the DFS traversal of the graph.
