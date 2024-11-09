// Leetcode 1829. Maximum XOR for Each Query

class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        int n = nums.size(), xorr = nums[0], maxxorr = pow(2, maximumBit) - 1;
        for (int i = 1; i < n; i++)
            xorr ^= nums[i];
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = xorr ^ maxxorr;
            xorr ^= nums[n - 1 - i];
        }
        return ans;
    }
};

// Explanation:

// We are given an array of integers nums and an integer maximumBit. We need to find the maximum XOR value for each query.
// We can find the maximum XOR value for each query by following the below steps:
// 1. Calculate the XOR of all the elements of the array.
// 2. Calculate the maximum XOR value that can be obtained by using the maximumBit number of bits.
// 3. For each query, calculate the XOR of the array elements from the last element to the current element and then XOR it with the maximum XOR value calculated in step 2.
// 4. Store the result in the answer array and return it.
