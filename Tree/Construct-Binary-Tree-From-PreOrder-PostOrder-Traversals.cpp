// Leetcode 889. Construct Binary Tree from Preorder and Postorder Traversal

class Solution
{
public:
    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
    {
        int index = 0;
        return construct(pre, post, index, 0, pre.size() - 1);
    }

private:
    TreeNode *construct(vector<int> &pre, vector<int> &post, int &index, int l, int h)
    {
        if (index >= pre.size() || l > h)
            return nullptr;

        TreeNode *root = new TreeNode(pre[index++]);
        if (l == h)
            return root;

        int i = l;
        while (i <= h && post[i] != pre[index])
            i++;

        if (i <= h)
        {
            root->left = construct(pre, post, index, l, i);
            root->right = construct(pre, post, index, i + 1, h - 1);
        }

        return root;
    }
};

// Explaination

// The first element of pre[] is always root. We increment index of pre[] to pick next element.
// If the picked element of pre[] has a postorder index next to it, i.e., the element is leaf of Binary Tree. So we return the node.
// Else the picked element has a postorder index not next to it, i.e., the element is internal node. So we will construct the left and right subtrees of the node and return the node.
// The construct function is called for the left and right subtrees. The left subtree is constructed using elements pre[l+1..l+i-l+1] and post[l..i], and the right subtree is constructed using elements pre[l+i-l+2..h] and post[i+1..h-1].
// The index in pre[] is incremented by 1 as the next element in pre[] is the left child of the current node.
// The index in post[] is decremented by 1 as the next element in post[] is the right child of the current node.
// The base cases of recursion are when a null pointer is passed as the current node, or the l > h condition is satisfied, in which case a null pointer is returned.
// The constructed binary tree is returned.
