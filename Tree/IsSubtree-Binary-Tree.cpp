// Leetcode 572. Subtree of Another Tree

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSametree(TreeNode *root, TreeNode *subRoot)
    {

        if (root == nullptr && subRoot == nullptr)
            return true;
        if (root == nullptr || subRoot == nullptr)
            return false;

        return root->val == subRoot->val &&
               isSametree(root->left, subRoot->left) &&
               isSametree(root->right, subRoot->right);
    };
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr)
            return false;
        if (subRoot == nullptr)
            return true;

        if (isSametree(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

// Explaination

// We will first check if the root and subRoot are same or not.

// If they are same then we will return true.

// If they are not same then we will check if the subRoot is present in the left subtree of the root or not.

// If it is present then we will return true.

// If it is not present then we will check if the subRoot is present in the right subtree of the root or not.

// If it is present then we will return true.

// If it is not present then we will return false.
