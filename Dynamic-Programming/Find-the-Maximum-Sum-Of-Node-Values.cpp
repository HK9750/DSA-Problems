// Leetcode 3068. Find the Maximum Sum Of Node Values

// Approach DP

class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        vector<long long> dp = {0, LLONG_MIN};
        for (int n : nums)
        {
            vector<long long> cnt = {dp[0] + n, dp[1] + n};
            cnt[1] = max(cnt[1], dp[0] + (n ^ k));
            cnt[0] = max(cnt[0], dp[1] + (n ^ k));
            dp = cnt;
        }
        return dp[0];
    }
};

// Explaination:
// 1. The function `maximumValueSum` takes a vector of integers `nums`, an integer `k`, and a 2D vector of edges as input.
// 2. It initializes a vector `dp` with two elements: the first element is 0 and the second element is the minimum long long value.
// 3. The first loop iterates through each element `n` in the `nums` vector.
// 4. Inside the loop, it creates a temporary vector `cnt` to store the maximum values based on the current element `n`.
// 5. The first element of `cnt` is updated to be the maximum of the previous first element plus `n` and the second element plus `n`.
// 6. The second element of `cnt` is updated to be the maximum of the previous first element plus `n ^ k` and the second element plus `n ^ k`.
// 7. The `dp` vector is then updated to be the `cnt` vector.
// 8. Finally, the function returns the first element of the `dp` vector, which represents the maximum value sum.
// 9. The time complexity of this algorithm is O(n), where n is the size of the `nums` vector.
// 10. The space complexity is O(1) since we are using a constant amount of extra space for the `dp` and `cnt` vectors.

// Approach Greedy

class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        long long sum = 0;
        vector<long long> res;
        for (int x : nums)
        {
            sum += x;
            int y = x ^ k;
            res.push_back(y - x);
        }
        sort(res.begin(), res.end());
        reverse(res.begin(), res.end());

        for (int i = 0; i < res.size() - 1; i += 2)
        {
            if (res[i] + res[i + 1] <= 0)
                break;
            sum += res[i] + res[i + 1];
        }
        return sum;
    }
};

// Explaination:

// 1. The function `maximumValueSum` takes a vector of integers `nums`, an integer `k`, and a 2D vector of edges as input.
// 2. It initializes a variable `sum` to store the sum of elements in `nums`.
// 3. It also initializes a vector `res` to store the differences between the XOR of each element with `k` and the element itself.
// 4. The first loop iterates through each element `x` in the `nums` vector, adding it to `sum` and calculating the difference `y - x`, where `y` is `x ^ k`.
// 5. The differences are stored in the `res` vector.
// 6. The `res` vector is then sorted in descending order.
// 7. The second loop iterates through the `res` vector in pairs, adding the differences to `sum` as long as they are positive.
// 8. If the sum of the current pair is less than or equal to 0, the loop breaks.
// 9. Finally, the function returns the total sum.
// 10. The time complexity of this algorithm is O(n log n), where n is the size of the `nums` vector.
// 11. The space complexity is O(n) due to the `res` vector.