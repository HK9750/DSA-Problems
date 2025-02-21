// Leetcode 257. Binary Tree Paths

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    void buildPaths(TreeNode *root, vector<string> &ans, string curr)
    {
        if (!root)
        {
            return;
        }

        curr += to_string(root->val);

        if (!root->left && !root->right)
        {
            ans.push_back(curr);
            return;
        }

        curr += "->";

        if (root->left)
        {
            buildPaths(root->left, ans, curr);
        }
        if (root->right)
        {
            buildPaths(root->right, ans, curr);
        }
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        if (root)
        {
            buildPaths(root, ans, "");
        }
        return ans;
    }
};