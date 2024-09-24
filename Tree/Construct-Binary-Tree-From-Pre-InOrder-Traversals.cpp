// Leetcode 105. Construct Binary Tree from Preorder and Inorder Traversal

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return solve(0, inorder.size(), 0, preorder.size(), preorder, inorder);
    }

private:
    TreeNode *solve(int is, int ie, int ps, int pe, vector<int> &preorder, vector<int> &inorder)
    {
        if (is == ie)
            return nullptr;
        TreeNode *node = new TreeNode(preorder[ps]);
        int mid = mp[node->val];
        int leftTreeSize = mid - is;
        node->left = solve(is, mid, ps + 1, ps + 1 + leftTreeSize, preorder, inorder);
        node->right = solve(mid + 1, ie, ps + 1 + leftTreeSize, pe, preorder, inorder);
        return node;
    }
};

// Explaination

// The idea is to build the tree recursively. The preorder list gives us the root of the tree.

// We can find the root in the inorder list. The left of the root in the inorder list is the left subtree and the right of the root in the inorder list is the right subtree.

// We can find the size of the left subtree in the inorder list. We can also find the size of the left subtree in the preorder list.

// We can build the left subtree recursively. We can build the right subtree recursively.

// The base case is when the inorder list is empty. In this case, we return nullptr.

// The time complexity is O(n) where n is the number of nodes in the tree. We visit each node once. The space complexity is O(n) because of the recursion stack. The recursion stack has at most n frames.
