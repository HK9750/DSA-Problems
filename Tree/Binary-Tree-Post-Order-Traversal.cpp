// Leetcode 145. Binary Tree Postorder Traversal

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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        postOrderHelper(root, ans);
        return ans;
    }

private:
    void postOrderHelper(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;
        postOrderHelper(root->left, ans);
        postOrderHelper(root->right, ans);
        ans.push_back(root->val);
    }
};

// Explaination:

// Postorder Traversal: Left -> Right -> Root

// We will use a helper function to traverse the tree in postorder fashion.

// If the root is null, we will return.

// We will first traverse the left subtree.

// Then we will traverse the right subtree.

// Finally, we will push the root value into the vector.

// We will return the vector containing the postorder traversal of the tree.

// Time Complexity: O(N), where N is the number of nodes in the tree.
