// Leetcode 1233. Remove Sub-Folders from the Filesystem

class Solution
{
    struct Node
    {
        unordered_map<string, Node *> next;
        bool flag = false;
    };

    class Trie
    {
    private:
        Node *root;

    public:
        Trie() { root = new Node(); }

        bool insert(const string &folder)
        {
            Node *node = root;
            stringstream ss(folder);
            string part;

            while (getline(ss, part, '/'))
            {
                if (part.empty())
                    continue;
                if (!node->next.count(part))
                {
                    node->next[part] = new Node();
                }

                node = node->next[part];

                if (node->flag)
                {
                    return false;
                }
            }

            node->flag = true;
            return true;
        }

        bool isParentExists(const string &folder)
        {
            Node *node = root;
            stringstream ss(folder);
            string part;

            while (getline(ss, part, '/'))
            {
                if (part.empty())
                    continue;
                if (!node->next.count(part))
                    return false;

                node = node->next[part];

                if (node->flag)
                {
                    return true;
                }
            }

            return false;
        }
    };

public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        auto trie = new Trie();
        sort(folder.begin(), folder.end());
        vector<string> res;

        for (auto &x : folder)
        {
            if (!trie->isParentExists(x))
            {
                res.push_back(x);
                trie->insert(x);
            }
        }

        return res;
    }
};

// Explaination
// We start by creating a Trie class with a Node
// We create a Trie object and sort the folders
// We iterate over the folders and check if the parent exists in the trie
// If the parent does not exist, we add the folder to the result and insert the folder into the trie
// Finally we return the result