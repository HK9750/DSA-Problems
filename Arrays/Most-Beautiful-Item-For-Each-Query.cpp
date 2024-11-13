// Leetcode 2070. Most Beautiful Item for Each Query

class Solution
{
public:
    vector<int> maximumBeauty(vector<vector<int>> &A, vector<int> &Q)
    {
        vector<pair<int, int>> queries;
        for (int i = 0; i < Q.size(); ++i)
            queries.push_back({Q[i], i});
        sort(begin(queries), end(queries));
        sort(begin(A), end(A));
        int i = 0, N = A.size(), maxBeauty = 0;
        vector<int> ans(Q.size());
        for (auto q : queries)
        {
            auto &[query, index] = q;
            for (; i < N && A[i][0] <= query; ++i)
                maxBeauty = max(maxBeauty, A[i][1]);
            ans[index] = maxBeauty;
        }
        return ans;
    }
};

// Explanation:

// Sort the queries in ascending order.
// Sort the items in ascending order of the first element.
// Initialize i = 0, maxBeauty = 0.
// Iterate over the queries.
// For each query, iterate over the items until the first element of the item is less than or equal to the query.
// Update the maxBeauty with the maximum of the current item's second element and the previous maxBeauty.
// Store the maxBeauty in the answer array at the corresponding index.
// Return the answer array.
