// Leetcode 1. Two Sum

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int second = target - nums[i];
            if (map.count(second))
            {
                return {map[second], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

// Explaination

// The idea is to use a hash map to store the index of each element in the array.
// For each element in the array, calculate the second element required to get the target sum.
// If the second element is present in the hash map, return the index of the second element and the current index.
// If the second element is not present in the hash map, store the current element in the hash map.
// If no such pair is found, return an empty vector.
