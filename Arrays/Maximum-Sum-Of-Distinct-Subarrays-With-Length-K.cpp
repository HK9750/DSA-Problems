// Leetcode 2461. Maximum Sum Of Distinct Subarrays With Length K

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        long long maxSum = 0;
        long long currSum = 0;
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
            currSum += nums[i];

            if (i >= k - 1)
            {
                if (mp.size() == k)
                {
                    maxSum = max(maxSum, currSum);
                }

                int left = nums[i - k + 1];
                currSum -= left;
                mp[left]--;
                if (mp[left] == 0)
                {
                    mp.erase(left);
                }
            }
        }

        return maxSum;
    }
};

// Explanation:

// We will use a sliding window approach to solve this problem.
// We will keep track of the current sum of the elements in the window and also keep track of the maximum sum found so far.
// We will use a hashmap to keep track of the frequency of the elements in the window.
// We will iterate through the array and add the elements to the window.
// If the size of the window is equal to k, we will check if the number of distinct elements in the window is equal to k.
// If it is, we will update the maximum sum found so far.
// We will then remove the leftmost element from the window and update the current sum and the hashmap accordingly.
// Finally, we will return the maximum sum found.
