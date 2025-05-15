// Leetcode 2900. Longest Unequal Adjacent Groups Subsequence I

class Solution
{
public:
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        vector<string> ans;
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || groups[i] != groups[i - 1])
            {
                ans.emplace_back(words[i]);
            }
        }
        return ans;
    }
};

// Explaination:

// 1. The function `getLongestSubsequence` takes a vector of strings `words` and a vector of integers `groups` as input.
// 2. It initializes an empty vector `ans` to store the result.
// 3. It iterates through the `words` vector using a for loop.
// 4. For each word, it checks if it's the first word or if its group is different from the previous word's group.
// 5. If either condition is true, it adds the word to the `ans` vector.
// 6. Finally, it returns the `ans` vector containing the longest subsequence of unequal adjacent groups.
// 7. The time complexity of this solution is O(n), where n is the number of words in the input vector.
// 8. The space complexity is O(m), where m is the number of unique groups in the input vector.