// Leetcode 2845. Count of Interesting Subarrays

class Solution
{
public:
#define ll long long
    long long countInterestingSubarrays(vector<int> &nums, int mod, int k)
    {
        int n = nums.size();
        unordered_map<int, ll> freq;
        freq[0] = 1;

        ll count = 0;
        ll curr = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] % mod == k)
                curr++;

            int currMod = ((curr % mod) - k + mod) % mod;
            count += freq[currMod];

            freq[curr % mod]++;
        }

        return count;
    }
};

// Explaination:

// 1. We initialize a map `freq` to keep track of the frequency of the remainders when the count of interesting subarrays is divided by `mod`.
// 2. We also initialize a variable `count` to keep track of the total count of interesting subarrays and a variable `curr` to keep track of the current count of interesting subarrays.
// 3. We iterate through the array `nums`, and for each element, we check if it is interesting (i.e., if it is congruent to `k` modulo `mod`). If it is, we increment `curr`.
// 4. We then calculate the current remainder `currMod` by subtracting `k` from `curr` and taking modulo `mod`. This gives us the remainder we need to find in the map `freq`.
// 5. We add the frequency of `currMod` in the map to `count`, as it represents the number of interesting subarrays that can be formed with the current element.
// 6. Finally, we increment the frequency of the current remainder `curr % mod` in the map `freq`.
// 7. The time complexity of this solution is O(n), where n is the size of the input array, as we are iterating through the array only once and using a map to keep track of the frequency of remainders.
// 8. The space complexity is O(mod), as we are storing the frequencies of remainders in the map, which can have at most `mod` different values.
