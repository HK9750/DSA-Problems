// Leetcode 2503. Maximum Number of Points from Grid Queries

class Solution
{
public:
    typedef pair<int, int> P;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {
        int m = grid.size();
        int n = grid[0].size();
        int k = queries.size();

        vector<pair<int, int>> sortedQueries(k);
        for (int i = 0; i < k; i++)
        {
            sortedQueries[i] = {queries[i], i};
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> ans(k, 0);
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        priority_queue<pair<int, P>, vector<pair<int, P>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        int count = 0;

        for (const auto &[value, index] : sortedQueries)
        {
            while (!pq.empty() && pq.top().first < value)
            {
                auto [height, cell] = pq.top();
                pq.pop();
                count++;
                int i = cell.first, j = cell.second;

                for (auto &dir : dirs)
                {
                    int newI = i + dir[0];
                    int newJ = j + dir[1];

                    if (newI >= 0 && newI < m && newJ >= 0 && newJ < n && !visited[newI][newJ])
                    {
                        visited[newI][newJ] = true;
                        pq.push({grid[newI][newJ], {newI, newJ}});
                    }
                }
            }
            ans[index] = count;
        }

        return ans;
    }
};

// Explaination:

// First, we sort the queries in increasing order of their values. We will maintain a priority queue to store the cells in the grid in increasing order of their values. We will also maintain a visited array to keep track of the cells that have been visited.
// We start by pushing the cell (0, 0) into the priority queue and mark it as visited. We will also maintain a count variable to keep track of the number of cells that have been visited.
// For each query, we will pop the cells from the priority queue until the value of the top cell is less than the value of the query. For each cell popped, we will increment the count and mark its neighbors
// as visited and push them into the priority queue if they have not been visited before.
// Finally, we update the answer for the current query with the count and return the answer array.
// Complexity Analysis:
// The time complexity for this approach is O(m*n*log(m*n) + k*log(k)), where m and n are the dimensions of the grid and k is the number of queries. The space complexity is O(m*n) for the visited array and O(k) for the answer array.
// The priority queue can have at most m*n elements, and each query can have at most m*n elements in the priority queue. Therefore, the time complexity is O(m*n*log(m*n) + k*log(k)). The space complexity is O(m*n) for the visited array and O(k) for the answer array.