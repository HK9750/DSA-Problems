// Leetcode 3362. Zero Array Transformation III

class Solution
{
public:
    int maxRemoval(vector<int> &nums, vector<vector<int>> &queries)
    {
        sort(queries.begin(), queries.end());
        priority_queue<int> available;
        priority_queue<int, vector<int>, greater<int>> assigned;
        int count = 0;

        for (int time = 0, k = 0; time < nums.size(); time++)
        {
            while (!assigned.empty() && assigned.top() < time)
                assigned.pop();
            while (k < queries.size() && queries[k][0] <= time)
                available.push(queries[k++][1]);
            while (assigned.size() < nums[time] &&
                   !available.empty() && available.top() >= time)
            {
                assigned.push(available.top());
                available.pop();
                count++;
            }
            if (assigned.size() < nums[time])
                return -1;
        }
        return queries.size() - count;
    }
};

// Explaination:

// 1. The function `maxRemoval` takes a vector of integers `nums` and a 2D vector of queries as input.
// 2. It sorts the queries based on the first element of each query.
// 3. It initializes two priority queues: `available` to keep track of available queries and `assigned` to keep track of assigned queries.
// 4. It also initializes a counter `count` to keep track of the number of assigned queries.
// 5. The outer loop iterates through the `nums` vector, and the inner loops manage the assignment of queries based on their availability.
// 6. If the size of the `assigned` queue is less than the current value in `nums`, it returns -1.
// 7. Finally, it returns the difference between the total number of queries and the count of assigned queries.
// 8. The time complexity of this algorithm is O(n log n + m log m), where n is the size of `nums` and m is the number of queries.
// 9. The space complexity is O(n + m) due to the `available` and `assigned` priority queues.