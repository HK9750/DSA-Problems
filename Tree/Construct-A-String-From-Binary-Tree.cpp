// Leetcode 606. Construct String from Binary Tree

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    string tree2str(TreeNode *root)
    {
        string ans = "";
        solve(root, ans);
        return ans;
    }

private:
    void solve(TreeNode *root, string &ans)
    {
        if (root == nullptr)
            return;

        ans += to_string(root->val);

        if (root->left)
        {
            ans += "(";
            solve(root->left, ans);
            ans += ")";
        }

        if (root->right)
        {
            if (root->left == nullptr)
                ans += "()";
            ans += "(";
            solve(root->right, ans);
            ans += ")";
        }
    }
};

// Explaination

// We will first check if the root is null or not.

// Then we will add the root value to the ans.

// Then we will check if the left subtree of the root is null or not.

// If it is not null then we will add "(" to the ans and call the solve function for the left subtree of the root.

// Then we will add ")" to the ans.

// Then we will check if the right subtree of the root is null or not.

// If it is null then we will add "()" to the ans.

// Then we will add "(" to the ans and call the solve function for the right subtree of the root.

// Then we will add ")" to the ans.

// At the end we will return the ans.
