// Leetcode 238. Product of Array Except Self

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n);

        int prefix = 1;
        for (int i = 0; i < n; i++)
        {
            res[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            res[i] *= suffix;
            suffix *= nums[i];
        }

        return res;
    }
};

// Explaination

// The idea is to use two passes to calculate the product of all elements except the current element.
// In the first pass, calculate the prefix product of all elements before the current element.
// In the second pass, calculate the suffix product of all elements after the current element.
// Multiply the prefix and suffix products to get the final result.
// Return the result vector.

// Solution 2

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, 1);

        int product = 1;
        for (int i = 0; i < n; i++)
        {
            res[i] = product;
            product *= nums[i];
        }

        product = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            res[i] *= product;
            product *= nums[i];
        }

        return res;
    }
};

// Explaination
// The idea is to use two passes to calculate the product of all elements except the current element.
// In the first pass, calculate the product of all elements before the current element and store it in the result vector.
// In the second pass, calculate the product of all elements after the current element and multiply it with the result vector.
// Return the result vector.
