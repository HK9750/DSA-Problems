// Leetcode 2799. Count Complete Subarrays in an Array

class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;

        int k = unordered_set<int>(nums.begin(), nums.end()).size();
        int ans = 0;
        int l = 0;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
            while (mp.size() == k)
            {
                ans += (n - i);
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }
        }

        return ans;
    }
};

// Explaination:

// 1. We use a set to find the number of unique elements in the array, which is stored in `k`.
// 2. We use a map to count the frequency of each element in the current window. The left pointer `l` is used to shrink the window when we have all unique elements in the current window.
// 3. For each valid window, we add the number of complete subarrays that can be formed with the current right pointer `i` to the answer. The number of complete subarrays is equal to the number of elements remaining in the array after `i`, which is `n - i`.
// 4. Finally, we return the total count of complete subarrays.
// 5. The time complexity of this solution is O(n), where n is the size of the input array, as we are iterating through the array only once and using a map to keep track of the frequency of elements in the current window.
// 6. The space complexity is O(n) in the worst case, where all elements are unique and stored in the map.