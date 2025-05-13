// Leetcode 3335. Total Characters In A String After Transformations I

// Without Dp

class Solution
{
public:
    const int mod = 1e9 + 7;
    int lengthAfterTransformations(std::string s, int t)
    {
        vector<int> cnt(26, 0);

        for (char c : s)
        {
            cnt[c - 'a']++;
        }

        for (int j = 0; j < t; j++)
        {
            vector<int> tmp(26, 0);
            for (int i = 0; i < 26; i++)
            {
                if (i == 25)
                {
                    tmp[0] = (tmp[0] + cnt[i]) % mod;
                    tmp[1] = (tmp[1] + cnt[i]) % mod;
                }
                else
                {
                    tmp[i + 1] = (tmp[i + 1] + cnt[i]) % mod;
                }
            }
            cnt = tmp;
        }

        int ans = 0;
        for (int c : cnt)
        {
            ans = (ans + c) % mod;
        }

        return ans;
    }
};

// Explanation:

// 1. The function `lengthAfterTransformations` takes a string `s` and an integer `t` as input.
// 2. It initializes a vector `cnt` of size 26 to count the occurrences of each character in the string.
// 3. It iterates through the string `s` and increments the corresponding index in `cnt` based on the character's ASCII value.
// 4. It then enters a loop that runs `t` times, where it creates a temporary vector `tmp` to store the transformed counts.
// 5. Inside the loop, it iterates through the `cnt` vector and updates the `tmp` vector based on the transformation rules.
// 6. If the current index is 25 (representing 'z'), it adds the count to the first two indices of `tmp` (0 and 1).
// 7. For all other indices, it adds the count to the next index in `tmp`.
// 8. After processing all indices, it updates `cnt` with the values from `tmp`.
// 9. After completing the transformations, it initializes a variable `ans` to store the final result.
// 10. It iterates through the `cnt` vector and sums up all the counts, taking modulo `mod` to avoid overflow.
// 11. Finally, it returns the total count of characters after all transformations.
// // The time complexity of this solution is O(n + t * 26), where n is the length of the string `s` and t is the number of transformations.
// // The space complexity is O(1) since the size of the `cnt` and `tmp` vectors is constant (26).

// With Dp

class Solution
{
public:
    const int mod = 1e9 + 7;
    int lengthAfterTransformations(string s, int t)
    {
        vector<int> dp(t + 26);
        for (int i = 0; i < 26; i++)
            dp[i] = 1;
        for (int i = 26; i < t + 26; i++)
            dp[i] = (dp[i - 26] + dp[i - 26 + 1]) % mod;
        int ans = 0;
        for (char ch : s)
            ans = (ans + dp[ch - 'a' + t]) % mod;
        return ans;
    }
};

// Explanation:

// 1. The function `lengthAfterTransformations` takes a string `s` and an integer `t` as input.
// 2. It initializes a constant `mod` to 1e9 + 7 to handle large numbers.
// 3. It creates a vector `dp` of size `t + 26` to store the number of characters after transformations.
// 4. It initializes the first 26 elements of `dp` to 1, representing the base case where each character can be transformed into itself.
// 5. It then iterates from index 26 to `t + 26`, updating the `dp` vector based on the transformation rules.
// 6. For each index `i`, it sets `dp[i]` to the sum of `dp[i - 26]` and `dp[i - 26 + 1]`, taking modulo `mod`.
// 7. This represents the number of characters after `t` transformations.
// 8. After processing the transformations, it initializes a variable `ans` to store the final result.
// 9. It iterates through the string `s`, and for each character, it adds the corresponding value from `dp` to `ans`, taking modulo `mod`.
// 10. Finally, it returns the total count of characters after all transformations.
// // The time complexity of this solution is O(n + t), where n is the length of the string `s` and t is the number of transformations.
// // The space complexity is O(t) due to the `dp` vector.