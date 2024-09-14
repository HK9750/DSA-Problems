// Leetcode 144. Binary Tree Preorder Traversal

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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        preOrderHelper(root, ans);
        return ans;
    }

private:
    void preOrderHelper(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;
        ans.push_back(root->val);
        preOrderHelper(root->left, ans);
        preOrderHelper(root->right, ans);
    }
};

// Explanation:

// The preOrderHelper function is a recursive function that takes the root of the tree and a vector of integers as arguments. It traverses the tree in a pre-order manner and appends the values of the nodes to the vector.

// If the root is null, the function returns without doing anything.

// The function appends the value of the root node to the vector.

// The function then recursively calls itself on the left subtree of the root.

// The function then recursively calls itself on the right subtree of the root.

// The function returns the vector containing the pre-order traversal of the tree.

// Time Complexity: O(N), where N is the number of nodes in the tree.