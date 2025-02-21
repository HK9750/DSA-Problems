// Leetcode 1261: Find Elements in a Contaminated Binary Tree

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class FindElements
{
public:
    unordered_set<int> values;

    FindElements(TreeNode *root)
    {
        root->val = 0;
        makeTree(root);
    }

    bool find(int target)
    {
        return values.count(target);
    }

private:
    void makeTree(TreeNode *root)
    {
        if (!root)
            return;

        values.insert(root->val);

        if (root->left)
        {
            root->left->val = 2 * root->val + 1;
            makeTree(root->left);
        }
        if (root->right)
        {
            root->right->val = 2 * root->val + 2;
            makeTree(root->right);
        }
    }
};

// Explaination:

// The idea is to recover the original tree from the contaminated tree. We can do this by traversing the tree and assigning the value to each node. The value of the root node is 0. The value of the left child of a node is 2 * value of the parent node + 1. The value of the right child of a node is 2 * value of the parent node + 2. We can use a set to store the values of the nodes. To find a target value, we can check if the set contains the target value. The time complexity is O(n) for the constructor and O(1) for the find method. The space complexity is O(n) for the set.
