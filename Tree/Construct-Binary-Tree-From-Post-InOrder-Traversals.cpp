// Leetcode 106. Construct Binary Tree from Inorder and Postorder Traversal

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
    unordered_map<int, int> mp;

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        return solve(0, inorder.size(), 0, postorder.size(), inorder, postorder);
    }

private:
    TreeNode *solve(int is, int ie, int ps, int pe, vector<int> &inorder, vector<int> &postorder)
    {
        if (is == ie)
            return nullptr;
        TreeNode *node = new TreeNode(postorder[pe - 1]);
        int mid = mp[node->val];
        node->left = solve(is, mid, ps, ps + mid - is, inorder, postorder);
        node->right = solve(mid + 1, ie, ps + mid - is, pe - 1, inorder, postorder);
        return node;
    }
};

// Explaination

// The idea is to take the last element in postorder array as the root, find the position of the root in the inorder array; then locate the range for left sub-tree and right sub-tree and do recursion. Use a HashMap to record the index of root in the inorder array.

// Then we can easily find the position of roots in inorder array and divide the tree into left and right subtrees. We can then divide the postorder array into two parts to build the left and right subtrees. Recursively, we can build up the tree.
