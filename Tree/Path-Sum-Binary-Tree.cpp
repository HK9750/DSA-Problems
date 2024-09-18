// Leetcode 112 - Path Sum

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
    bool hasPathSum(TreeNode *root, int sum)
    {
        return hasPathSum(root, sum, 0);
    }

    bool hasPathSum(TreeNode *root, int sum, int currentSum)
    {
        if (root == NULL)
        {
            return false;
        }

        currentSum += root->val;

        if (root->left == NULL && root->right == NULL)
        {
            return currentSum == sum;
        }

        return hasPathSum(root->left, sum, currentSum) || hasPathSum(root->right, sum, currentSum);
    }
};

class Solution
{
public:
    int sum = 0;
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;
        targetSum -= root->val;

        if (root->left == nullptr && root->right == nullptr)
        {
            return targetSum == 0;
        }

        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};

// Explanation

// The idea is to subtract the value of the current node from the sum when recurring down, and check to see if the sum is 0 when you run out of tree.
