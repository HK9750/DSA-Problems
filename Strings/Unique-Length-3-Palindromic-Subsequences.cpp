// Leetcode 1930: Unique Length 3 Palindromic Subsequences

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        int n = s.size();
        unordered_set<char> letters;

        for (auto &c : s)
            letters.insert(c);

        int ans = 0;

        for (char letter : letters)
        {
            int ri = -1;
            int li = -1;

            for (int i = 0; i < n; i++)
            {
                if (letter == s[i])
                {
                    if (li == -1)
                    {
                        li = i;
                    }
                    ri = i;
                }
            }

            unordered_set<char> chars;

            for (int j = li + 1; j < ri; j++)
            {
                chars.insert(s[j]);
            }

            ans += chars.size();
        }

        return ans;
    }
};

// Explanation:

// We need to find the number of unique length 3 palindromic subsequences in the given string. We can do this by iterating over all the unique characters in the string and finding the number of unique characters between the first and last occurrence of the current character. This is because the first and last occurrence of the current character will be the first and last character of the palindromic subsequence, and the characters between them will be the middle character of the palindromic subsequence.
// To find the number of unique characters between the first and last occurrence of the current character, we can use a set to store the characters between the first and last occurrence of the current character. We can then return the size of the set as the number of unique characters between the first and last occurrence of the current character.
// We can iterate over all the unique characters in the string and calculate the number of unique characters between the first and last occurrence of each character. We can then sum up the number of unique characters between the first and last occurrence of each character to get the total number of unique length 3 palindromic subsequences in the string.
// The time complexity of this approach is O(n), where n is the length of the input string. This is because we iterate over the string once to find the first and last occurrence of each character and calculate the number of unique characters between them. The space complexity is also O(n) because we use a set to store the characters between the first and last occurrence of each character.