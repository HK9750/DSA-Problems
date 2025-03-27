// Leetcode 2780. Minimum Index Of A Valid Split

class Solution
{
public:
    int minimumIndex(vector<int> &nums)
    {
        int n = nums.size();

        int maj = -1;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (count == 0)
            {
                maj = nums[i];
                count = 1;
            }
            else if (nums[i] == maj)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        int majCount = 0;
        for (int &num : nums)
        {
            if (num == maj)
            {
                majCount++;
            }
        }

        count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == maj)
            {
                count++;
            }

            int remainingCount = majCount - count;
            int n1 = i + 1;
            int n2 = n - i - 1;

            if (count * 2 > n1 && remainingCount * 2 > n2)
            {
                return i;
            }
        }

        return -1;
    }
};

// First we find the majority element in the array using the Moore's Voting Algorithm.
// Then we find the count of the majority element in the array.
// Then we iterate over the array and check if the count of the majority element is greater than half of the current index and the remaining count of the majority element is greater than half of the remaining elements.
// If the above condition is satisfied, we return the current index.
// If no such index is found, we return -1.
// This approach has O(n) time complexity and O(1) space complexity.
// It is more effiecient way to solve this without using an unordered_map.