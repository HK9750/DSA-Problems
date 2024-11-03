// Leetcode 2261. K-Divisible Elements in Subarray
// We can use Brute Force :)

class Solution
{
public:
    int countDistinct(vector<int> &nums, int k, int p)
    {
        set<vector<int>> uniqueSubarrays;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            vector<int> subarray;
            int countDivisible = 0;

            for (int j = i; j < n; ++j)
            {
                subarray.push_back(nums[j]);
                if (nums[j] % p == 0)
                    countDivisible++;

                if (countDivisible > k)
                    break;

                uniqueSubarrays.insert(subarray);
            }
        }

        return uniqueSubarrays.size();
    }
};

// Explanation:
// We can use a set to store the unique subarrays.
// We can iterate over the nums array and create subarrays starting from each index.
// We can keep track of the count of elements divisible by p in the subarray.
// If the count exceeds k, we can break out of the loop.
// Otherwise, we can insert the subarray into the set.
// Finally, we can return the size of the set, which gives us the count of distinct subarrays.
