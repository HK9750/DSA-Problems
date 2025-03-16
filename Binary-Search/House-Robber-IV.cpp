// Leetcode 2560. House Robber IV

class Solution
{
public:
    bool canRob(vector<int> &nums, int mid, int k)
    {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= mid)
            {
                count++;
                i++;
            }
        }
        return count >= k;
    }

    int minCapability(vector<int> &nums, int k)
    {
        int left = *min_element(nums.begin(), nums.end()),
            right = *max_element(nums.begin(), nums.end()), ans = right;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (canRob(nums, mid, k))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};

// Explaination:
// We have to find the minimum capability of the robber such that he can rob at least k houses.
// We can use binary search to find the minimum capability.
// We can check if the robber can rob k houses with a given capability by iterating over the houses and checking if the house value is less than or equal to the capability.
// If the number of houses that can be robbed is greater than or equal to k, then we can update the answer and move to the left half of the binary search.
// Otherwise, we move to the right half of the binary search.
// We can find the minimum capability by iterating over the houses and finding the minimum and maximum house values.
// The minimum capability will be the minimum house value and the maximum capability will be the maximum house value.
// We can then use binary search to find the minimum capability.
// The time complexity of this approach is O(nlog(max-min)), where n is the number of houses and max-min is the difference between the maximum and minimum house values.
// The space complexity is O(1).