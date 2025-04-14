// Leetcode 1534. Count Good Triplets

class Solution
{
public:
    int countGoodTriplets(vector<int> &nums, int a, int b, int c)
    {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (abs(nums[i] - nums[j]) <= a &&
                        abs(nums[j] - nums[k]) <= b &&
                        abs(nums[i] - nums[k]) <= c)
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

// Explaination:

// The function countGoodTriplets takes a vector of integers nums and three integers a, b, and c as input.
// It counts the number of good triplets (i, j, k) such that i < j < k and the following conditions are satisfied:
// 1. |nums[i] - nums[j]| <= a
// 2. |nums[j] - nums[k]| <= b
// 3. |nums[i] - nums[k]| <= c
// The function uses three nested loops to iterate through all possible triplets (i, j, k) in the nums vector.
// For each triplet, it checks if the conditions are satisfied using the abs function to calculate the absolute differences.
// If all conditions are satisfied, it increments the count variable.
// Finally, the function returns the total count of good triplets.
// The time complexity of this solution is O(n^3), where n is the size of the nums vector, as it uses three nested loops to iterate through all possible triplets.