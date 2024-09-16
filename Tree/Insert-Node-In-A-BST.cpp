// Leetcode 701: Insert Node In A BST

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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            return new TreeNode(val);
        }
        if (val < root->val)
        {
            root->left = insertIntoBST(root->left, val);
        }
        else
        {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};

// Explanation:

// If the root is null, then we return a new node with the value val.

// If the value is less than the root value, we recursively call the function on the left child.

// If the value is greater than the root value, we recursively call the function on the right child.

// Finally, we return the root.