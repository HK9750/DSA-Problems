// Leetcode 11. Container With Most Water

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1;
        int curr_sum = 0;
        int max_sum = 0;

        while (l <= r)
        {
            curr_sum = min(height[l], height[r]) * (r - l);
            max_sum = max(max_sum, curr_sum);
            if (height[l] < height[r])
                l++;
            else
                r--;
        }

        return max_sum;
    }
};

// Explaination

// We can use the two-pointer approach to solve this problem. We can initialize two pointers, l and r, to the start and end of the array, respectively. We can then calculate the area between the two pointers and update the maximum area. We can then move the pointer with the smaller height towards the other pointer. We can continue this process until the two pointers meet. The maximum area will be the maximum of all the areas calculated during this process.