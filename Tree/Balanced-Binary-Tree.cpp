// Leetcode 110. Balanced Binary Tree

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

        auto right = maxDepth(root->right);
        auto left = maxDepth(root->left);

        return 1 + max(right, left);
    }

public:
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return 1;

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        if (l > r + 1 || r > l + 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};

// Explaination:

// We will check if the binary tree is balanced using a recursive approach.

// If the root is null, we will return true.

// We will calculate the maximum depth of the left subtree.

// We will calculate the maximum depth of the right subtree.

// If the difference between the maximum depth of the left and right subtrees is greater than 1, we will return false.

// We will recursively check if the left subtree is balanced.

// We will recursively check if the right subtree is balanced.

// We will return true if the tree is balanced.

// Time Complexity: O(N^2), where N is the number of nodes in the tree. The time complexity is O(N^2) because for each node, we are calculating the maximum depth of the left and right subtrees, which takes O(N) time. In the worst case, we will have to calculate the maximum depth of the left and right subtrees for each node, resulting in a time complexity of O(N^2). The space complexity is O(N) due to the recursive calls on the stack.