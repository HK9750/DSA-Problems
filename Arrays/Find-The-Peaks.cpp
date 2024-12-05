// Leetcode 2951. Find the Peaks

class Solution
{
public:
    vector<int> findPeaks(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();

        for (int i = 1; i < n - 1; i++)
        {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                ans.push_back(i);
        }

        return ans;
    }
};

// Explaination:

// A peak is an element that is strictly greater than its neighbors. We can iterate over the array and check if the element at index i is greater than the elements at indices i - 1 and i + 1. If the condition is satisfied, then the element at index i is a peak. We can store the indices of the peaks in a vector and return the vector as the answer.
// The time complexity of this approach is O(n), where n is the length of the input array nums. The space complexity is O(k), where k is the number of peaks in the array.