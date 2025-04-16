// Leetcode 2537. Count the Number of Good Subarrays

#define ll long long
class Solution
{
public:
    long long countGood(vector<int> &nums, int k)
    {
        int n = nums.size();
        ll count = 0;
        unordered_map<int, int> freq;
        ll pairs = 0;
        int i = 0;

        for (int j = 0; j < n; ++j)
        {
            pairs += freq[nums[j]];
            freq[nums[j]]++;

            while (pairs >= k)
            {
                count += (n - j);
                pairs -= (freq[nums[i]] - 1);
                freq[nums[i]]--;
                if (freq[nums[i]] == 0)
                    freq.erase(nums[i]);
                i++;
            }
        }

        return count;
    }
};

// Explaination:

// The function countGood takes a vector of integers nums and an integer k as input.
// It counts the number of good subarrays in nums such that the number of pairs (i, j) with i < j and nums[i] == nums[j] is at least k.
// The function uses a sliding window approach with two pointers (i and j) to maintain the current subarray.
// It also uses a frequency map (freq) to keep track of the count of each element in the current subarray.
// The variable pairs keeps track of the number of pairs (i, j) in the current subarray.
// The outer loop iterates through the array with the right pointer (j), while the inner loop adjusts the left pointer (i) to maintain the condition pairs < k.
// When the condition is satisfied, it adds the number of good subarrays ending at j to the count variable.
// Finally, the function returns the total count of good subarrays.
// The time complexity of this solution is O(n), where n is the size of the nums vector, as each element is processed at most twice (once by j and once by i).