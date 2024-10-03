// Leetcode 1590. Make Sum Divisible by P

class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        int n = nums.size();
        int target = 0;
        for (int a : nums)
        {
            target = (target + a) % p;
        }
        if (target == 0)
            return 0;
        unordered_map<int, int> lastSeen;
        lastSeen[0] = -1;
        int sum = 0;
        int ans = n;
        for (int i = 0; i < n; i++)
        {
            sum = (sum + nums[i]) % p;
            int need = (sum - target + p) % p;
            if (lastSeen.count(need))
            {
                ans = min(ans, i - lastSeen[need]);
            }
            lastSeen[sum] = i;
        }
        return ans == n ? -1 : ans;
    }
};

// Explanation:

// We will calculate the target sum by taking the sum of the array and taking the modulo with p.
// If the target sum is 0, we will return 0.
// We will keep a map of the sum and the last index where it was seen.
// We will iterate over the array and calculate the sum.
// We will calculate the need by taking the difference of the sum and the target sum and taking the modulo with p.
// If the need is present in the map, we will update the answer.
// We will update the last seen index of the sum.
// We will return the answer.
