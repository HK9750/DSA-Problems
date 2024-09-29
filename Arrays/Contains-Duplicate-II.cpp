// Leetcode 219. Contains Duplicate II

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            if (mp.find(nums[i]) != mp.end())
            {
                if (abs(i - mp[nums[i]]) <= k)
                {
                    return true;
                }
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};

// Explaination

// We are going to use hash map.
// We will iterate over the array and check if the element is already present in the hash map.
// If it is present, then we will check if the difference between the current index and the index of the element in the hash map is less than or equal to k.
// If it is less than or equal to k, then we will return true.
// Otherwise, we will update the index of the element in the hash map.
// If we don't find any such element, then we will return false.
