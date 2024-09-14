// Leetcode 104. Maximum Depth of Binary Tree

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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        auto right = maxDepth(root->right);
        auto left = maxDepth(root->left);

        return 1 + max(right, left);
    }
};

// Explaination:

// We will calculate the maximum depth of the binary tree using a recursive approach.

// If the root is null, we will return 0.

// We will recursively calculate the maximum depth of the left subtree.

// We will recursively calculate the maximum depth of the right subtree.

// We will return 1 + the maximum of the maximum depth of the left and right subtrees.

// Time Complexity: O(N), where N is the number of nodes in the tree.