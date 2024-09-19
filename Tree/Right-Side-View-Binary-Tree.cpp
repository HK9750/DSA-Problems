// Leetcode 199: Binary Tree Right Side View

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
    vector<int> rightSideView(TreeNode *root)
    {
        map<int, int> rightNode;
        queue<pair<TreeNode *, pair<int, int>>> q;
        vector<int> ans;
        if (root == nullptr)
            return ans;
        q.push({root, {0, 0}});

        while (!q.empty())
        {
            pair<TreeNode *, pair<int, int>> tr = q.front();
            q.pop();

            TreeNode *node = tr.first;
            int vd = tr.second.first;
            int lvl = tr.second.second;
            rightNode[lvl] = node->val;

            if (node->left)
                q.push(make_pair(node->left, make_pair(vd - 1, lvl + 1)));
            if (node->right)
                q.push(make_pair(node->right, make_pair(vd + 1, lvl + 1)));
        }
        for (auto &x : rightNode)
        {
            ans.push_back(x.second);
        }

        return ans;
    }
};

// Explaination:

// We will use a queue to store the nodes of the tree. We will also use a map to store the nodes based on their vertical distance and level. We will iterate over the queue until it is empty. For each node, we will store its value in the map based on its vertical distance and level.

// We will then iterate over the map and add the rightmost node of each level to the result vector. Finally, we will return the result vector.
