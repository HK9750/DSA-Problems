// Leetcode 1760. Minimum Limit of Balls in a Bag

class Solution
{
public:
    bool check(vector<int> &nums, int maxOp, int mid)
    {
        int totalOps = 0;
        for (int &num : nums)
        {
            int op = num / mid;
            if (num % mid == 0)
            {
                op -= 1;
            }
            totalOps += op;
        }
        return totalOps <= maxOp;
    }

    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        int ans = r;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (check(nums, maxOperations, mid) == true)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return ans;
    }
};

// Explanation:

// The problem is to find the minimum size of the bag such that we can perform at most maxOperations operations on the bag.
// We can use binary search to solve this problem.
// We can start with the range of 1 to max element in the nums array.
// We can then find the mid of the range and check if we can perform at most maxOperations operations on the bag with the mid size.
// If we can perform the operations, then we can update the answer and move to the left side of the mid.
// If we cannot perform the operations, then we can move to the right side of the mid.
// We can continue this process until we find the minimum size of the bag such that we can perform at most maxOperations operations on the bag.
// The time complexity of this approach is O(n * log(maxElement)) where n is the size of the nums array and maxElement is the maximum element in the nums array.