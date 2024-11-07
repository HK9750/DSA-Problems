// Number of undirected graphs that can be constructed using number of vertices
// https://www.geeksforgeeks.org/problems/graph-and-vertices/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    long long count(int n)
    {
        // your code here
        int maxedges = n * (n - 1) / 2;
        long long ans = pow(2, maxedges);
        return ans;
    }
};

// Explanation:

// The number of edges in a graph with n vertices can be at most nC2 = n(n-1)/2. So, the maximum number of edges that can be there in a graph with n vertices is n(n-1)/2. So, the number of possible graphs with n vertices is 2^(n(n-1)/2).