// Leetcode 102 - Binary Tree Level Order Traversal

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int s = q.size();
            vector<int> a;
            for (int i = 0; i < s; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                a.push_back(node->val);
            }
            ans.push_back(a);
        }

        return ans;
    }
};

// Explanation

// The idea is to traverse the tree level by level. So, we start by pushing the root node into the queue. Then, we start a while loop that runs until the queue is empty. In each iteration of the while loop, we find the size of the queue and iterate over all the nodes at that level. We push the left and right children of the current node into the queue if they exist. We also push the value of the current node into a vector. Finally, we push the vector into the answer vector. This way, we get the level order traversal of the binary tree.
