// Leetcode 2762. Continuous Subarrays

class Solution
{
public:
    long long continuousSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        long long ans = 0;
        map<int, int> mp;
        int i = 0, j = 0;

        while (j < n)
        {
            mp[nums[j]]++;
            while (mp.rbegin()->first - mp.begin()->first > 2)
            {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                {
                    mp.erase(nums[i]);
                }
                i++;
            }
            ans += j - i + 1;
            j++;
        }

        return ans;
    }
};

// Explaination:

// Using the sliding window pattern, we can keep track of the number of subarrays that satisfy the condition.
// We can use a map to keep track of the frequency of the elements in the current window.
// We can keep track of the maximum and minimum element in the current window using the rbegin() and begin() functions of the map.
// If the difference between the maximum and minimum element in the current window is greater than 2, we can remove the elements from the left side of the window until the condition is satisfied.
// We can keep track of the number of subarrays that satisfy the condition by adding the length of the current window to the answer.
// Finally, we can return the answer.
// The time complexity of this approach is O(nlogn) and the space complexity is O(n).