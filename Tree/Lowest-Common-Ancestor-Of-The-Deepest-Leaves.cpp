// Leetcode 1123. Lowest Common Ancestor of Deepest Leaves

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
    int findDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + max(findDepth(root->left), findDepth(root->right));
    }
    TreeNode *dfs(TreeNode *root, int maxi, int curr)
    {
        if (!root)
            return nullptr;
        if (maxi - 1 == curr)
            return root;

        TreeNode *left = dfs(root->left, maxi, curr + 1);
        TreeNode *right = dfs(root->right, maxi, curr + 1);

        if (left && right)
            return root;

        return left ? left : right;
    }
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        int maxi = findDepth(root);
        return dfs(root, maxi, 0);
    }
};

// Explaination

// We will first find the depth of the tree using the findDepth function. The findDepth function will return the maximum depth of the tree.
// When curr level is equal to the maximum depth - 1, we will return the root node.
// Then we will check if the left and right subtree of the root node is not null. If both are not null then we will return the root node.
// If only one of them is not null then we will return the non-null node. If both are null then we will return null.
// Finally we will return the root node of the deepest leaves.
// The time complexity of this solution is O(n) and the space complexity is O(h) where h is the height of the tree.