// Leetcode 2940. Find the building where Alice and Bob can meet

class Solution
{
public:
    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
    {
        int n = heights.size(), q = queries.size();
        vector<int> result(q, -1);
        vector<vector<pair<int, int>>> deferred(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (int i = 0; i < q; ++i)
        {
            int a = queries[i][0], b = queries[i][1];
            if (a > b)
                swap(a, b);
            if (a == b || heights[a] < heights[b])
                result[i] = b;
            else
                deferred[b].emplace_back(heights[a], i);
        }

        for (int i = 0; i < n; ++i)
        {
            for (auto &query : deferred[i])
                pq.push(query);
            while (!pq.empty() && pq.top().first < heights[i])
            {
                result[pq.top().second] = i;
                pq.pop();
            }
        }

        return result;
    }
};

// Explaination:

// We start off by creating a vector of vectors called deferred. This vector will store the queries that we cannot answer immediately because the building at the query's first index is taller than the building at the query's second index. We will answer these queries later when we reach the building at the second index.
// We also create a priority queue called pq. This priority queue will store the queries that we cannot answer immediately because the building at the query's first index is shorter than the building at the query's second index. We will answer these queries when we reach the building at the second index.
// We iterate through the queries and check if the building at the first index is taller than the building at the second index. If it is, we answer the query immediately by setting the result at the query's index to the second index. Otherwise, we add the query to the deferred vector.
// We iterate through the buildings and add the deferred queries to the priority queue. We then check if the building is taller than the building at the top of the priority queue. If it is, we answer the query at the top of the priority queue by setting the result at the query's index to the current building's index.
// Finally, we return the result vector. This vector contains the answers to the queries. If the result at a query's index is -1, it means that we could not find a building where Alice and Bob can meet. Otherwise, it contains the index of the building where Alice and Bob can meet.
// Real Time Complexity: O(nlogn + qlogq) where n is the number of buildings and q is the number of queries.