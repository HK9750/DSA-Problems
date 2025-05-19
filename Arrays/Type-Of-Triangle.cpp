// Leetcode 3024. Type of Triangle

class Solution
{
public:
    string triangleType(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums[0] + nums[1] <= nums[2])
        {
            return "none";
        }
        else if (nums[0] == nums[2])
        {
            return "equilateral";
        }
        else if (nums[0] == nums[1] || nums[1] == nums[2])
        {
            return "isosceles";
        }
        else
        {
            return "scalene";
        }
    }
};

// Explaination:

// 1. Sort the array `nums` in non-decreasing order.
// 2. Check if the sum of the two smallest sides (`nums[0]` and `nums[1]`) is less than or equal to the largest side (`nums[2]`). If so, return "none".
// 3. If all three sides are equal, return "equilateral".
// 4. If two sides are equal, return "isosceles".
// 5. If all sides are different, return "scalene".
// 6. The time complexity of this algorithm is O(n log n) due to the sorting step, where n is the number of elements in the input array.
// 7. The space complexity is O(1) since we are sorting the array in place without using any additional data structures.