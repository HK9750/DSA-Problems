// Leetcode 235. Lowest Common Ancestor of a Binary Search Tree

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};

// Explaination:

// We will recursively traverse the tree.

// If the root is null, we will return null.

// If the root value is greater than both p and q, then the LCA will be in the left subtree.

// If the root value is less than both p and q, then the LCA will be in the right subtree.

// Otherwise, the root is the LCA.

// We will return the LCA.