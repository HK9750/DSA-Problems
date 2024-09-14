// Leetcode 226. Invert Binary Tree

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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        auto temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

// Explaination:

// We will invert the binary tree using a recursive approach.

// If the root is null, we will return null.

// We will swap the left and right children of the root.

// We will recursively call the invertTree function on the left subtree.

// We will recursively call the invertTree function on the right subtree.

// We will return the root of the inverted tree.

// Time Complexity: O(N), where N is the number of nodes in the tree.