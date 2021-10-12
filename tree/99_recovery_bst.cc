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
public:
    void inorder(TreeNode* root, TreeNode*& prev, TreeNode*& m1, TreeNode*& m2) {
        if (!root) {
            return;
        }
        if (root->left) {
            inorder(root->left, prev, m1, m2);
            //prev = root->left;
        }
        if (prev && prev->val > root->val) {
            if (m1) {
                m2 = root;
            } else {
                // first time
                m1 = prev;
                m2 = root;
            }
        }
        prev = root;
        if (root->right) {
            inorder(root->right, prev, m1, m2);
            //prev = root->right;            
        }
    }
    
    void recoverTree(TreeNode* root) {
        // 6 8 15 10 11 12 9, swap 15 and 9, 
        // 6 8 10 9 11 12 15, swap 10 and 9
        // traveral from small to large
        TreeNode* m1 = NULL, *m2 = NULL, *prev = NULL;
        inorder(root, prev, m1, m2);
        if (m1 && m2) {
            int tmp = m1->val;
            m1->val = m2->val;
            m2->val = tmp;
            //swap(m1->val, m2->val);
        }
    }
};
