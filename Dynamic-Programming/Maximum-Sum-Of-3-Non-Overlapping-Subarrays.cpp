// Leetcode 689. Maximum Sum of 3 Non-Overlapping Subarrays

class Solution
{
private:
    int t[20001][4];

    int helper(vector<int> &sums, int k, int idx, int rem)
    {
        if (rem == 0)
            return 0;
        if (idx >= sums.size())
            return INT_MIN;
        if (t[idx][rem] != -1)
            return t[idx][rem];

        int take = sums[idx] + helper(sums, k, idx + k, rem - 1);
        int not_take = helper(sums, k, idx + 1, rem);

        return t[idx][rem] = max(take, not_take);
    }

    void solve(vector<int> &sums, int k, int idx, int rem, vector<int> &indices)
    {
        if (rem == 0 || idx >= sums.size())
            return;

        int take = sums[idx] + helper(sums, k, idx + k, rem - 1);
        int not_take = helper(sums, k, idx + 1, rem);

        if (take >= not_take)
        {
            indices.push_back(idx);
            solve(sums, k, idx + k, rem - 1, indices);
        }
        else
        {
            solve(sums, k, idx + 1, rem, indices);
        }
    }

public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        memset(t, -1, sizeof(t));
        vector<int> sums;
        int windowSum = 0, i = 0, j = 0;

        while (j < nums.size())
        {
            windowSum += nums[j];
            if (j - i + 1 == k)
            {
                sums.push_back(windowSum);
                windowSum -= nums[i++];
            }
            j++;
        }

        vector<int> indices;
        solve(sums, k, 0, 3, indices);

        return indices;
    }
};

// Explanation:

// We will first calculate the sum of every k elements in the array and store it in a vector sums.
// We will then use a helper function to calculate the maximum sum of 3 non-overlapping subarrays.
// The helper function will take the following parameters:
// 1. The vector sums
// 2. The value of k
// 3. The current index
// 4. The number of subarrays remaining
// The helper function will return the maximum sum of 3 non-overlapping subarrays.
// The helper function will be a recursive function.
// The base cases will be:
// 1. If the number of subarrays remaining is 0, then return 0.
// 2. If the current index is greater than or equal to the size of the sums vector, then return INT_MIN.
// 3. If the value is already calculated, then return the value.
// The recursive cases will be:
// 1. Take the current element and call the helper function with the current index + k, the number of subarrays remaining - 1.
// 2. Do not take the current element and call the helper function with the current index + 1, the number of subarrays remaining.
// The helper function will return the maximum of the two values.
// We will then use another function to solve the problem.
// The solve function will take the following parameters:
// 1. The vector sums
// 2. The value of k
// 3. The current index
// 4. The number of subarrays remaining
// 5. A vector to store the indices of the subarrays
// The solve function will be a recursive function.
// The base cases will be:
// 1. If the number of subarrays remaining is 0 or the current index is greater than or equal to the size of the sums vector, then return.
// The recursive cases will be:
// 1. Take the current element and call the helper function with the current index + k, the number of subarrays remaining - 1.
// 2. Do not take the current element and call the helper function with the current index + 1, the number of subarrays remaining.
// If the value of take is greater than or equal to the value of not_take, then add the current index to the indices vector and call the solve function with the current index + k, the number of subarrays remaining - 1.
// Otherwise, call the solve function with the current index + 1, the number of subarrays remaining.
// Finally, we will call the solve function with the initial values and return the indices vector.
// The time complexity of this approach is O(n) where n is the size of the input array. The space complexity is O(n) where n is the size of the input array.