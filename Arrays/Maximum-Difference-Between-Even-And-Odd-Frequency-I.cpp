// Leetcode 3442. Maximum Difference Between Even and Odd Frequency I

class Solution
{
public:
    int maxDifference(string s)
    {
        int maxO = 0, minE = s.size();
        unordered_map<char, int> mp;

        for (auto &c : s)
            mp[c]++;

        for (const auto &ele : mp)
        {
            int freq = ele.second;
            if (freq % 2 == 1)
                maxO = max(maxO, freq);
            if (freq % 2 == 0 && freq > 0)
                minE = min(minE, freq);
        }

        return maxO - minE;
    }
};

// Explanation:

// 1. The function `maxDifference` takes a string `s` as input.
// 2. It initializes two variables: `maxO` to track the maximum frequency of characters with odd frequency and `minE` to track the minimum frequency of characters with even frequency.
// 3. An unordered map `mp` is used to count the frequency of each character in the string.
// 4. The first loop iterates through each character in the string and increments its count in the map.
// 5. The second loop iterates through the map to find the maximum odd frequency (`maxO`) and the minimum even frequency (`minE`).
// 6. If a character's frequency is odd, it updates `maxO` if the frequency is greater than the current `maxO`.
// 7. If a character's frequency is even and greater than zero, it updates `minE` if the frequency is less than the current `minE`.
// 8. Finally, the function returns the difference between `maxO` and `minE`.
// Time Complexity: O(n), where n is the length of the string s, as we traverse the string and the map.
// Space Complexity: O(1), as the size of the unordered map is limited to the number of unique characters in the string, which is constant for a fixed character set (e.g., lowercase English letters).