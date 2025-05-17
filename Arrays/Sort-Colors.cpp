// Leetcode 75. Sort Colors

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high)
            if (nums[mid] == 0)
                swap(nums[mid++], nums[low++]);
            else if (nums[mid] == 1)
                mid++;
            else
                swap(nums[mid], nums[high--]);
    }
};

// Explaination:

// Using the Dutch National Flag algorithm, we can sort the colors in a single pass through the array. The algorithm maintains three pointers: `low`, `mid`, and `high`. The `low` pointer tracks the position of the last 0, the `mid` pointer tracks the current element being processed, and the `high` pointer tracks the position of the last 2. The algorithm works as follows:
// 1. Initialize `low`, `mid`, and `high` pointers.
// 2. While `mid` is less than or equal to `high`, check the value of `nums[mid]`.
// 3. If `nums[mid]` is 0, swap it with `nums[low]`, increment both `low` and `mid`.
// 4. If `nums[mid]` is 1, just increment `mid`.
// 5. If `nums[mid]` is 2, swap it with `nums[high]`, decrement `high`.
// 6. Repeat until `mid` is greater than `high`.
// 7. The time complexity of this algorithm is O(n), where n is the number of elements in the input array.
// 8. The space complexity is O(1) since we are sorting the array in place without using any additional data structures.