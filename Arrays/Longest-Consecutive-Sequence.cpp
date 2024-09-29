// Leetcode 128. Longest Consecutive Sequence

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int n = nums.size();
        sort(nums.begin(), nums.end());
        int currMax = 1, resMax = 1;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
            {
                continue;
            }
            else if (nums[i] == nums[i - 1] + 1)
            {
                currMax++;
            }
            else
            {
                currMax = 1;
            }
            resMax = max(resMax, currMax);
        }

        return resMax;
    }
};

// Explaination

// The idea is to sort the input array and then iterate over it to find the longest consecutive sequence.
// Sort the input array.
// Initialize two variables, currMax and resMax, to store the current and maximum consecutive sequence length.
// Iterate over the sorted array and check if the current element is consecutive to the previous element.
// If it is consecutive, increment the current sequence length.
// If it is not consecutive, reset the current sequence length to 1.
// Update the maximum sequence length with the maximum of the current sequence length and the previous maximum.
// Return the maximum sequence length.

// Solution 2

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int> set(nums.begin(), nums.end());

        int longest = 0;

        for (int n : set)
        {
            if (set.find(n - 1) == set.end())
            {
                int len = 1;
                while (set.find(n + len) != set.end())
                    len++;
                longest = max(len, longest);
            }
        }
        return longest;
    }
};

// Explaination

// The idea is to use a hash set to store the elements of the input array.
// Iterate over the hash set and for each element, check if the previous element is present in the hash set.
// If the previous element is not present, it means the current element is the start of a new sequence.
// Increment the length of the sequence by checking the next consecutive elements in the hash set.
// Update the longest sequence length with the maximum of the current sequence length and the previous longest length.
// Return the longest sequence length.
