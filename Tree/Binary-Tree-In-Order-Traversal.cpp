// Leetcode 94. Binary Tree Inorder Traversal

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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        inOrderHelper(root, ans);
        return ans;
    }

private:
    void inOrderHelper(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;
        inOrderHelper(root->left, ans);
        ans.push_back(root->val);
        inOrderHelper(root->right, ans);
    }
};

// Explaination:

// Inorder Traversal: Left -> Root -> Right

// We will use a helper function to traverse the tree in inorder fashion.

// If the root is null, we will return.

// We will first traverse the left subtree.

// Then we will push the root value into the vector.

// Finally, we will traverse the right subtree.

// We will return the vector containing the inorder traversal of the tree.

// Time Complexity: O(N), where N is the number of nodes in the tree.