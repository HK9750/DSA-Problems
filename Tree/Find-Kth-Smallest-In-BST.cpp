// Leetcode 230. Kth Smallest Element in a BST

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
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> ans;
        inOrderTraversal(root, ans);
        return ans[k - 1];
    }

private:
    void inOrderTraversal(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;
        inOrderTraversal(root->left, ans);
        ans.push_back(root->val);
        inOrderTraversal(root->right, ans);
    }
};

// Explaination:

// We will use a helper function to traverse the tree in inorder fashion.

// If the root is null, we will return.

// We will first traverse the left subtree.

// Then we will push the root value into the vector.

// Finally, we will traverse the right subtree.

// We will return the kth element from the vector containing the inorder traversal of the tree.