// Leetcode 2415. Reverse Odd Levels of a Binary Tree

// DFS Approach

class Solution
{
public:
    void dfs(TreeNode *left, TreeNode *right, int level)
    {
        if (!left || !right)
            return;

        if (level % 2 == 1)
        {
            swap(left->val, right->val);
        }

        dfs(left->left, right->right, level + 1);
        dfs(left->right, right->left, level + 1);
    }

    TreeNode *reverseOddLevels(TreeNode *root)
    {
        if (!root)
            return root;
        dfs(root->left, root->right, 1);
        return root;
    }
};

// Explanation:

// The idea is to perform a DFS traversal of the tree and reverse the values of the nodes at odd levels. We can achieve this by recursively traversing the tree and swapping the values of the corresponding nodes at odd levels.
// To implement this, we define a helper function dfs that takes two nodes (left and right) and the current level as arguments. The function first checks if either of the nodes is null, in which case it returns without performing any operations. If both nodes are present, the function checks if the current level is odd. If it is, it swaps the values of the nodes.
// After swapping the values, the function recursively calls itself on the left and right children of the current nodes with the incremented level. This process continues until we reach the leaf nodes of the tree.
// Finally, we call the dfs function on the left and right children of the root node with the initial level set to 1. This will start the DFS traversal from the root node and reverse the values of the nodes at odd levels.
// The time complexity of this approach is O(N), where N is the number of nodes in the tree, as we visit each node once during the DFS traversal. The space complexity is O(H), where H is the height of the tree, due to the recursive calls on the call stack.

// BFS Approach

class Solution
{
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        if (!root)
        {
            return nullptr; // Return null if the tree is empty.
        }

        queue<TreeNode *> q;
        q.push(root); // Start BFS with the root node.
        int level = 0;

        while (!q.empty())
        {
            int size = q.size();
            vector<TreeNode *> currentLevelNodes;

            // Process all nodes at the current level.
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                currentLevelNodes.push_back(node);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            // Reverse node values if the current level is odd.
            if (level % 2 == 1)
            {
                int left = 0, right = currentLevelNodes.size() - 1;
                while (left < right)
                {
                    int temp = currentLevelNodes[left]->val;
                    currentLevelNodes[left]->val =
                        currentLevelNodes[right]->val;
                    currentLevelNodes[right]->val = temp;
                    left++;
                    right--;
                }
            }

            level++;
        }

        return root; // Return the modified tree root.
    }
};

// Explainaion:

// The idea is to perform a BFS traversal of the tree and reverse the values of the nodes at odd levels. We can achieve this by maintaining a level variable that keeps track of the current level of the tree. If the level is odd, we reverse the values of the nodes at that level.
// To implement this, we start by pushing the root node into a queue and setting the level to 0. We then enter a while loop that continues until the queue is empty. In each iteration of the loop, we process all the nodes at the current level by popping them from the queue and storing them in a vector.
// After processing all the nodes at the current level, we check if the level is odd. If it is, we reverse the values of the nodes in the vector by swapping the values of the nodes at the corresponding positions. Finally, we increment the level variable and continue the BFS traversal.
// Once the BFS traversal is complete, we return the modified root node of the tree. The time complexity of this approach is O(N), where N is the number of nodes in the tree, as we visit each node once during the BFS traversal. The space complexity is also O(N) due to the use of the queue and the vector to store the nodes at each level.