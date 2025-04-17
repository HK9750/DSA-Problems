// Leetcode 2176. Count Equal and Divisible Pairs in an Array

class Solution
{
public:
    int countPairs(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (i * j % k == 0 && nums[i] == nums[j])
                    count++;
            }
        }

        return count;
    }
};

// Explaination:
// Simple brute force solution. We can use two loops to iterate through the array and check if the product of the indices is divisible by k and if the elements at those indices are equal. If both conditions are satisfied, we increment the count. Finally, we return the count.
// Time Complexity: O(n^2), where n is the size of the array. We are using two nested loops to iterate through the array.