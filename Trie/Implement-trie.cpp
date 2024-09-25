// Leetcode 208. Implement Trie (Prefix Tree)

struct Node
{
    Node *next[26] = {};
    bool flag = false;
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (auto &c : word)
        {
            if (!node->next[c - 'a'])
                node->next[c - 'a'] = new Node();
            node = node->next[c - 'a'];
        }
        node->flag = true;
    }

    bool search(string word)
    {
        Node *node = root;
        for (auto &c : word)
        {
            if (!node->next[c - 'a'])
                return false;
            node = node->next[c - 'a'];
        }
        return node->flag;
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (auto &c : prefix)
        {
            if (!node->next[c - 'a'])
                return false;
            node = node->next[c - 'a'];
        }
        return true;
    }
};

// Explaination

// The idea is to build a trie and store the flag to indicate the end of the word.
// For each word, we will add the word to the trie and set the flag to true for the last node.
// To search for a word, we will traverse the trie and return false if the node is null.
// To search for a prefix, we will traverse the trie and return false if the node is null.
// The time complexity is O(n * m), where n is the number of words and m is the length of the longest word.