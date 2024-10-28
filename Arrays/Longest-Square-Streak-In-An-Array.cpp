// Leetcode 2501. Longest Square Streak In An Array

class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans = -1;

        unordered_set<long long> numSet(nums.begin(), nums.end());

        for (int num : nums)
        {
            long long current = num;
            int count = 1;

            while (numSet.find(current * current) != numSet.end())
            {
                current = current * current;
                count++;
            }

            if (count > 1)
            {
                ans = max(ans, count);
            }
        }

        return ans;
    }
};

// Explanation:
// 1. Sort the array
// 2. Create a set of all the numbers in the array
// 3. For each number in the array, check if the square of the number is present in the set
// 4. If it is present, keep squaring the number and increment the count
// 5. If the count is greater than 1, update the answer
// 6. Return the answer