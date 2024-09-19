// Leetcode 987: Vertical Order Traversal of a Binary Tree
// My most favourite Leetcode hard

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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, vector<int>>> nodes;
        queue<pair<TreeNode *, pair<int, int>>> q;
        vector<vector<int>> ans;

        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty())
        {
            pair<TreeNode *, pair<int, int>> tr = q.front();
            q.pop();
            TreeNode *node = tr.first;
            int vd = tr.second.first;
            int lvl = tr.second.second;

            nodes[vd][lvl].push_back(node->val);

            if (node->left)
                q.push(make_pair(node->left, make_pair(vd - 1, lvl + 1)));
            if (node->right)
                q.push(make_pair(node->right, make_pair(vd + 1, lvl + 1)));
        }

        for (auto &x : nodes)
        {
            vector<int> col;
            for (auto &p : x.second)
            {
                sort(p.second.begin(), p.second.end());
                col.insert(col.end(), p.second.begin(), p.second.end());
            }
            ans.push_back(col);
            col.clear();
        }
        return ans;
    }
};

// Explaination:

// We will use a queue to store the nodes of the tree. We will also use a map to store the nodes based on their vertical distance and level. We will iterate over the queue until it is empty. For each node, we will store its value in the map based on its vertical distance and level.

// We will then iterate over the map and sort the nodes based on their level. We will then add the sorted nodes to the result vector. Finally, we will return the result vector.
