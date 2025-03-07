// Leetcode 34. Find First and Last Position of Element in Sorted Array

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        if (l == nums.size() || nums[l] != target)
            return {-1, -1};
        int left = l;
        r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return {left, r};
    }
};

// Explanation

// We can use the binary search algorithm to find the first and last position of the target element in the sorted array. We can first find the leftmost position of the target element by using the binary search algorithm. We can then find the rightmost position of the target element by using the binary search algorithm again. Finally, we can return the leftmost and rightmost positions of the target element. If the target element is not found, we can return {-1, -1}.