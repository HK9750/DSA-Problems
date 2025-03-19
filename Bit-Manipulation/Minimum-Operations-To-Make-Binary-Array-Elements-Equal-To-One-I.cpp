// Leetcode 3191. Minimum Operations to Make Binary Array Elements Equal to One I

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++)
        {
            if (nums[i] == 0)
            {
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                count++;
            }
        }

        return (nums[n - 2] == 1 && nums[n - 1] == 1) ? count : -1;
    }
};

// Explanation: We can only change the elements in the array to 1. So, we can only change the elements which are 0. We can change the elements to 1 by changing the elements in the next two positions. So, we will iterate through the array and check if the current element is 0. If it is 0, we will change the current element and the next two elements to 1. We will increment the count. Finally, we will check if the last two elements are 1. If they are 1, we will return the count. Otherwise, we will return -1.