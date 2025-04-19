// Leetcode 2563. Count the Number of Fair Pairs

class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        long long ans = 0;
        sort(begin(nums), end(nums));

        for (int i = 0; i < nums.size(); ++i)
        {
            // 1 --- 5 => 3 - 0 => 3
            int left =
                lower_bound(begin(nums) + i + 1, end(nums), lower - nums[i]) -
                begin(nums);
            int right =
                upper_bound(begin(nums) + i + 1, end(nums), upper - nums[i]) -
                begin(nums) - 1;

            if (left <= right)
            {
                ans += (right - left + 1);
            }
        }

        return ans;
    }
};

// Explaination:

// The function countFairPairs counts the number of fair pairs in the given array nums, where a fair pair is defined as a pair of indices (i, j) such that i < j and lower <= nums[i] + nums[j] <= upper.
// The function uses a two-pointer technique to efficiently find the valid pairs within the specified range.
// It first sorts the array nums, and then iterates through each element, using binary search to find the range of valid pairs for each element. The left pointer finds the first index where the sum is greater than or equal to lower, and the right pointer finds the last index where the sum is less than or equal to upper. The difference between these two pointers gives the count of valid pairs for that element. The total count is accumulated in the variable ans, which is returned at the end.
// The time complexity of this solution is O(n log n) due to the sorting step and the binary search for each element, where n is the size of the input array. The space complexity is O(1) as no additional data structures are used that depend on the input size.