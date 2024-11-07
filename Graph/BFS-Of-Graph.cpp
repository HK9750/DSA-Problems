// Breadth First Search of a graph
// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj)
    {
        // Code here
        int n = adj.size();
        vector<bool> v(n, false);

        int s = 0;
        v[s] = true;

        queue<int> q;
        vector<int> res;

        q.push(s);

        while (!q.empty())
        {
            int temp = q.front();
            res.push_back(temp);
            q.pop();

            for (auto &x : adj[temp])
            {
                if (!v[x])
                {
                    v[x] = true;
                    q.push(x);
                }
            }
        }

        return res;
    }
};

// Explanation:

// The idea is to start from the source node and visit all the nodes in the graph.
// We will use a visited array to keep track of the nodes that we have visited.
// We will use a queue to visit all the nodes in the graph.
// We will start from the source node and visit all the nodes that are connected to it.
// We will mark the node as visited and add it to the answer vector.
// We will then visit all the nodes that are connected to the current node.
// We will keep track of the nodes that we have visited using the visited array.
// We will return the answer vector which contains the BFS traversal of the graph.
