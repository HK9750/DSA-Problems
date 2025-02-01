// Leetcode:3151. Special Array I

class Solution
{
public:
    bool isArraySpecial(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] % 2 == nums[i - 1] % 2)
                return false;
        }
        return true;
    }
};

// Explaination:

// We iterate over the nums array and check if the current element and the previous element have the same parity. If they do, we return false. If we reach the end of the array without returning false, we return true.
// Time Complexity: O(n)