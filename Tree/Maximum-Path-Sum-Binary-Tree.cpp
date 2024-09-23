// Leetcode 124. Binary Tree Maximum Path Sum

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
    int maxPathSum(TreeNode *root)
    {
        int maxSum = INT_MIN;
        maxPathSum(root, maxSum);
        return maxSum;
    }

    int maxPathSum(TreeNode *root, int &maxSum)
    {
        if (root == nullptr)
            return 0;

        int left = max(0, maxPathSum(root->left, maxSum));
        int right = max(0, maxPathSum(root->right, maxSum));

        maxSum = max(maxSum, left + right + root->val);

        return max(left, right) + root->val;
    }
};

// Explaination

// We will first check if the root is null or not.

// Then we will calculate the left and right path sum of the root.

// If the left path sum is less than 0 then we will take it as 0.

// If the right path sum is less than 0 then we will take it as 0.

// Then we will calculate the maxSum by adding the left path sum, right path sum and the root value.

// Then we will return the maximum of left path sum and right path sum plus the root value.

// We will keep updating the maxSum with the maximum of maxSum and the left path sum, right path sum and the root value.

// At the end we will return the maxSum.
