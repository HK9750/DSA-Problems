// Leetcode 617. Merge Two Binary Trees

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}

class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {

        if (root1 == nullptr && root2 == nullptr)
            return nullptr;
        if (root1 == nullptr)
            return root2;
        if (root2 == nullptr)
            return root1;

        TreeNode *newRoot = new TreeNode(root1->val + root2->val);

        newRoot->left = mergeTrees(root1->left, root2->left);
        newRoot->right = mergeTrees(root1->right, root2->right);

        return newRoot;
    }
};

// Explaination

// We will merge two binary trees using a recursive approach.

// If both the roots are null, we will return null.

// If the first root is null, we will return the second root.

// If the second root is null, we will return the first root.

// We will create a new node with the sum of the values of the two roots.

// We will recursively merge the left subtrees of the two roots.

// We will recursively merge the right subtrees of the two roots.

// We will return the new root.