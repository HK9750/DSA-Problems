// Leetcode 1752: Check If Array Is Sorted And Rotated

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        int cntD = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > nums[(i + 1) % n])
            {
                cntD++;
                if (cntD > 1)
                    return false;
            }
        }

        return true;
    }
};

// Explaination:

// If the array is sorted and rotated, then there will be only one point where the array will be decreasing.
// If there are more than one point where the array is decreasing, then the array is not sorted and rotated.
// So, we will iterate through the array and check if the array is decreasing at more than one point.
// If it is, then we will return false, else we will return true.
