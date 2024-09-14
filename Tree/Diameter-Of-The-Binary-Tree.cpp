// Leetcode 543. Diameter of Binary Tree

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int right = maxDepth(root->right);
        int left = maxDepth(root->left);

        return 1 + max(right, left);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int opt1 = diameterOfBinaryTree(root->left);
        int opt2 = diameterOfBinaryTree(root->right);
        int opt3 = maxDepth(root->left) + maxDepth(root->right);

        return max({opt1, opt2, opt3});
    }
};

// Explaination:

// We will calculate the diameter of the binary tree using a recursive approach.

// If the root is null, we will return 0.

// We will recursively calculate the diameter of the left subtree.

// We will recursively calculate the diameter of the right subtree.

// We will calculate the maximum depth of the left subtree and the right subtree.

// We will return the maximum of the diameter of the left subtree, the diameter of the right subtree, and the sum of the maximum depth of the left and right subtrees.

// Time Complexity: O(N), where N is the number of nodes in the tree.