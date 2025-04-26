// Leetcode 2444. Count Subarrays With Fixed Bounds

class Solution
{
public:
#define ll long long
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        int n = nums.size();
        ll ans = 0;
        int lastInvalid = -1;
        int lastMin = -1;
        int lastMax = -1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < minK || nums[i] > maxK)
                lastInvalid = i;
            if (nums[i] == minK)
                lastMin = i;
            if (nums[i] == maxK)
                lastMax = i;

            ans += max(0, min(lastMin, lastMax) - lastInvalid);
        }

        return ans;
    }
};

// Explaination:

// 1. We iterate through the array and keep track of the last invalid index, last min index, and last max index.
// 2. If the current number is less than minK or greater than maxK, we update the last invalid index.
// 3. If the current number is equal to minK, we update the last min index. If it is equal to maxK, we update the last max index.
// 4. For each index, we calculate the number of valid subarrays ending at that index by taking the minimum of last min and last max indices and subtracting the last invalid index. We add this to the answer.
// 5. Finally, we return the total count of valid subarrays.
// 6. The time complexity is O(n) since we are iterating through the array once.
// 7. The space complexity is O(1) since we are using a constant amount of extra space.