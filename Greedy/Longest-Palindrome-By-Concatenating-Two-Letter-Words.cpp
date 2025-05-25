// Leetcode 2131. Longest Palindrome by Concatenating Two Letter Words

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> mpp;
        for (string w : words)
            mpp[w]++;

        int count = 0, alreadyPalindrome = 0;
        for (auto &[w, freq] : mpp)
        {
            string s = w;
            reverse(s.begin(), s.end());
            if (w == s)
            {
                count += (freq / 2) * 4;
                if (freq % 2)
                    alreadyPalindrome = 1;
            }
            else if (w < s && mpp.count(s))
            {
                count += min(freq, mpp[s]) * 4;
            }
        }
        return count + alreadyPalindrome * 2;
    }
};

// Explaination:

// 1. We use an unordered map to count the frequency of each word.
// 2. For each word, we check if it is a palindrome (i.e., it reads the same forwards and backwards).
// 3. If it is a palindrome, we add the maximum even frequency of that word multiplied by 4 to the count.
// 4. If it is not a palindrome, we check if its reverse exists in the map and add the minimum frequency of both words multiplied by 4 to the count.
// 5. Finally, we check if there is any palindrome word with an odd frequency, which can be used as the center of the palindrome, and add 2 to the count if it exists.
// 6. The final count is returned as the result.
// Time Complexity: O(n * k), where n is the number of words and k is the average length of the words.
// Space Complexity: O(n), where n is the number of unique words in the input vector.