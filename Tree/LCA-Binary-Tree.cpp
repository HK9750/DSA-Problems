// Leetcode 236. Lowest Common Ancestor of a Binary Tree

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;

        return root;
    }
};

// Explaination

// We will first check if the root is null or if the root is equal to p or q then we will return the root.

// Then we will check if the left subtree of the root contains p or q or not.

// If it contains p or q then we will store the result in left.

// Then we will check if the right subtree of the root contains p or q or not.

// If it contains p or q then we will store the result in right.