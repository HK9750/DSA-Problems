// Leetcode 3355. Zero Array Transformation I

class Solution
{
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();

        vector<int> diff(n, 0);
        for (auto &query : queries)
        {
            int start = query[0];
            int end = query[1];
            int x = 1;

            diff[start] += x;
            if (end + 1 < n)
            {
                diff[end + 1] -= x;
            }
        }

        vector<int> result(n, 0);
        int cumSum = 0;
        for (int i = 0; i < n; i++)
        {
            cumSum += diff[i];
            result[i] = cumSum;
        }

        for (int i = 0; i < n; i++)
        {
            if (result[i] < nums[i])
            {
                return false;
            }
        }

        return true;
    }
};

// Explaination:

// 1. The function `isZeroArray` takes two parameters: a vector of integers `nums` and a vector of queries.
// 2. It initializes a vector `diff` of the same size as `nums` to keep track of the differences.
// 3. For each query, it updates the `diff` vector to mark the start and end of the range where the value should be incremented.
// 4. It then calculates the cumulative sum of the `diff` vector to get the final result.
// 5. Finally, it checks if the result is less than the corresponding value in `nums`. If so, it returns false.
// 6. If all values in the result are greater than or equal to the corresponding values in `nums`, it returns true.
// 7. The time complexity of this algorithm is O(n + m), where n is the size of the `nums` array and m is the number of queries.
// 8. The space complexity is O(n) due to the `diff` and `result` vectors.