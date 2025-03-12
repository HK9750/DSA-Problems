// Leetcode 2529. Maximum Count of Positive Integer and Negative Integer

class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, r = n - 1, negCount = 0, posCount = 0;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] < 0)
            {
                negCount = mid + 1;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] > 0)
            {
                posCount = n - mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return max(negCount, posCount);
    }
};

// Explaination:

// We are given an array of integers. We need to find the maximum count of positive integers and negative integers in the array. We can use binary search to solve this problem.
// We will find the count of negative integers in the array. We will use binary search to find the first negative integer in the array. We will keep track of the count of negative integers in the array.
// We will find the count of positive integers in the array. We will use binary search to find the first positive integer in the array. We will keep track of the count of positive integers in the array.
// We will return the maximum of the count of negative integers and the count of positive integers in the array.
// The time complexity of this approach is O(log n) where n is the size of the array. The space complexity of this approach is O(1).
