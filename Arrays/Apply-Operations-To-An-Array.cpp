// Leetcode 2460. Apply Operations to an Array

class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        int insertPos = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                nums[insertPos++] = nums[i];
            }
        }

        while (insertPos < n)
        {
            nums[insertPos++] = 0;
        }

        return nums;
    }
};

// Explaination:

// We will iterate over the array and check if the current element is equal to the next element.
// If it is, we will multiply the current element by 2 and set the next element to 0.
// We will then iterate over the array again and copy all the non-zero elements to the beginning of the array.
// Finally, we will fill the remaining elements with 0.
// This will give us the desired result.