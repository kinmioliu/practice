/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:    
    int maxLength;
public:
    int postOrderCalMaxDepth(TreeNode* root) {
        // if this path pass through root, then the longest length is the longest of root->left + root->right
        // choose max
        // traveral method left right mid
        if (root == NULL) {
            return 0;
        }
        int l = 1 + postOrderCalMaxDepth(root->left);
        int r = 1 + postOrderCalMaxDepth(root->right);
        maxLength = max(maxLength, l + r - 2);
        return max(l, r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        postOrderCalMaxDepth(root);
        return maxLength;
    }
};
