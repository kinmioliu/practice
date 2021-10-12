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
    void preorder(TreeNode* root, vector<int>& trace) {
        if (!root) {
            return;
        }
        trace.push_back(root->val);
        preorder(root->left, trace);
        preorder(root->right, trace);            
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};

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
    void preorder(TreeNode* root, vector<int>& trace) {
        if (!root) {
            return;
        }
        trace.push_back(root->val);
        preorder(root->left, trace);
        preorder(root->right, trace);            
    }
    
    vector<int> preorderTraversal1(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> trace;
        if (!root) {
            return trace;
        }
        stack<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode* node = nodes.top();
            nodes.pop();
            trace.push_back(node->val);
            if (node->right) {
                nodes.push(node->right);
            }
            if (node->left) {
                nodes.push(node->left);
            }
        }
        return trace;
    }
    
};
