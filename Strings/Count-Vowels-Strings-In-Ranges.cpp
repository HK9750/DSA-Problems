// Leetcode 2559. Count Vowels in Strings In Ranges

class Solution
{
public:
    bool isVowel(char c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    vector<int> vowelStrings(vector<string> &words,
                             vector<vector<int>> &queries)
    {
        int m = words.size();
        vector<int> psum(m + 1, 0);
        for (int i = 0; i < m; i++)
        {
            string s = words[i];
            if (isVowel(s.front()) && isVowel(s.back()))
            {
                psum[i + 1] = psum[i] + 1;
            }
            else
            {
                psum[i + 1] = psum[i];
            }
        }
        vector<int> ans;
        for (auto &q : queries)
        {
            ans.push_back(psum[q[1] + 1] - psum[q[0]]);
        }
        return ans;
    }
};

// Explaination:

// We are given a list of strings and a list of queries. Each query is a pair of integers [l, r]. We have to find the number of strings in the range [l, r] which start and end with a vowel.
// We can solve this problem by creating a prefix sum array. We will iterate over the list of strings and calculate the number of strings that start and end with a vowel. We will store this information in a prefix sum array. The prefix sum array will store the number of strings that start and end with a vowel up to the ith index.
// We will then iterate over the list of queries and calculate the number of strings that start and end with a vowel in the range [l, r] using the prefix sum array.
// Finally, we will return the list of counts for each query.
