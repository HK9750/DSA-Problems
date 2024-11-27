// Leetcode 665: Non Decreasing Array

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                cnt++;
                if (cnt > 1)
                    return false;
                if (i > 0 && nums[i - 1] > nums[i + 1])
                {
                    nums[i + 1] = nums[i];
                }
            }
        }

        return true;
    }
};

// Explaination

// We can change at most 1 element in the array to make it non-decreasing.
// Our thought process is to iterate through the array and check if the current element is greater than the next element.
// If it is, we increment the count of the number of elements that are greater than the next element.
// If the count is greater than 1, we return false.
// If the count is less than or equal to 1, we check if the element before the current element is greater than the element after the next element.
// If it is, we set the element after the next element to the current element.
// We return true if we have not returned false.