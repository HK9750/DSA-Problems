// Leetcode 334. Increasing Triplet Subsequence

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        if (nums.size() < 3)
            return false;

        int first = INT_MAX;
        int second = INT_MAX;

        for (int num : nums)
        {
            if (num <= first)
            {
                first = num;
            }
            else if (num <= second)
            {
                second = num;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};

// Explaination:

// We are given an array of integers. We need to find if there exists an increasing triplet subsequence in the array.
// We can solve this problem using a greedy approach. We will keep track of the smallest and second smallest elements in the array.
// We will iterate through the array and update the smallest and second smallest elements.
// If we find a number greater than the second smallest element, we return true.
