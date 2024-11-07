// Print adjacency list of a graph
// https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>> &edges)
    {
        // Code here
        vector<vector<int>> adj(V);

        for (auto &x : edges)
        {
            int u = x.first;
            int v = x.second;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }
};

// Explanation:

// The adjacency list is a vector of vectors. Each vector in the adjacency list represents a vertex and contains the vertices that are adjacent to it. The adjacency list is created by iterating over the edges and adding the vertices to the adjacency list.
// The adjacency list is returned as the output.
