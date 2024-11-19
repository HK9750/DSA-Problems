// Leetcode 881. Boats to Save People

class Solution
{
public:
    int numRescueBoats(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int boats = 0;

        while (left <= right)
        {
            if (nums[left] + nums[right] <= k)
            {
                left++;
            }
            right--;
            boats++;
        }

        return boats;
    }
};

// Explanation:

// Sort the people by their weight.
// Take the heaviest person and try to pair him with the lightest person. If the sum of their weight is less than or equal to the limit, then they can be placed in the same boat.
// If the sum of their weight is greater than the limit, then the heaviest person can be placed in the boat alone.
// Repeat the process until all the people are placed in the boats.
// Return the number of boats required.
