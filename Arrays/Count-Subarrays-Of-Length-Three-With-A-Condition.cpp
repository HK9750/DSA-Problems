// Leetcode  3392. Count Subarrays of Length Three With a Condition

class Solution
{
public:
    int countSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;

        for (int i = 1; i < n - 1; i++)
        {
            if (nums[i] == (nums[i - 1] + nums[i + 1]) * 2)
                ans++;
        }

        return ans;
    }
};

// Explaination:

// 1. We iterate through the array starting from the second element and ending at the second last element (i.e., from index 1 to n-2).
// 2. For each element, we check if it is equal to the average of its two neighbors multiplied by 2 (i.e., nums[i] == (nums[i - 1] + nums[i + 1]) * 2).
// 3. If the condition is satisfied, we increment the count of valid subarrays (ans).
// 4. Finally, we return the total count of valid subarrays (ans).
// 5. The time complexity is O(n) since we are iterating through the array once.
// 6. The space complexity is O(1) since we are using a constant amount of extra space.