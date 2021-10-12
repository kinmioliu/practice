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
    int getDepth(TreeNode* root) {
        return root ? 1 + max(getDepth(root->left), getDepth(root->right)) : 0;
    }
public:
    bool isBalanced(TreeNode* root) {
        int d = 0;
        return isBalanced(root, d);
        if (root == NULL) {
            return true;
        }
        bool balance = abs(getDepth(root->left) - getDepth(root->right)) <= 1;
        return balance && isBalanced(root->left) && isBalanced(root->right);
    }
    
    bool isBalanced(TreeNode* root, int &d) {
        if (root == NULL) {
            return true;
        }
        int ld = 0, rd = 0;
        bool lb = isBalanced(root->left, ld);
        bool rb = isBalanced(root->right, rd);
        d = 1 + max(ld, rd);
        return (abs(ld - rd) <= 1) && lb && rb;
    }
};
