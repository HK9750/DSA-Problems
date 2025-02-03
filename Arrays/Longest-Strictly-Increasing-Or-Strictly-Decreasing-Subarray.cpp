// Leetcode 3105. Longest Strictly Increasing Or Strictly Decreasing Subarray

class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int n = nums.size(), i = 0, ans = 0;
        int inc = 1, dec = 1;
        if (n == 1)
            return 1;
        for (i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
                inc++, dec = 1;
            else if (nums[i] < nums[i - 1])
                inc = 1, dec++;
            else
                inc = dec = 1;
            ans = max({ans, dec, inc});
        }
        return ans;
    }
};

// Explaination:

// We have to find the longest strictly increasing or strictly decreasing subarray in the given array.
// We will keep two variables inc and dec to keep track of the length of the increasing and decreasing subarray respectively.
// We will iterate through the array and if the current element is greater than the previous element, we will increment inc and set dec to 1.
// If the current element is less than the previous element, we will increment dec and set inc to 1.
// If the current element is equal to the previous element, we will set both inc and dec to 1.
// We will keep track of the maximum length of the subarray and return it as the answer.
// The time complexity of this approach is O(n) where n is the size of the input array.
// The space complexity of this approach is O(1).