// Leetcode 2416: Sum of Prefix Scores of Strings

struct TrieNode
{
    TrieNode *next[26] = {};
    int cnt = 0;
};

class Solution
{
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        TrieNode *node = new TrieNode();
        for (auto &x : words)
            addWord(node, x);
        vector<int> ans;
        for (auto &x : words)
            ans.push_back(count(node, x));
        return ans;
    }

private:
    void addWord(TrieNode *node, string &s)
    {
        for (auto &c : s)
        {
            if (!node->next[c - 'a'])
            {
                node->next[c - 'a'] = new TrieNode();
            }
            node = node->next[c - 'a'];
            node->cnt++;
        }
    }

    int count(TrieNode *node, string &s)
    {
        int ans = 0;

        for (auto &c : s)
        {
            node = node->next[c - 'a'];
            ans += node->cnt;
        }

        return ans;
    }
};

// Explaination

// The idea is to build a trie and store the count of words that pass through each node.
// For each word, we will find the count of words that have the prefix of the current word.
// For example, if we have words ["abc", "ab", "a"], the count of words that have the prefix "abc" is 3, the count of words that have the prefix "ab" is 2, and the count of words that have the prefix "a" is 1.
// We will use a trie to store the count of words that pass through each node.
// For each word, we will add the word to the trie and increment the count of each node that the word passes through.
// To find the count of words that have the prefix of the current word, we will traverse the trie and sum the count of each node that the word passes through.
// The time complexity is O(n * m), where n is the number of words and m is the length of the longest word.