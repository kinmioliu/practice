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
    vector<double> averageOfLevels(TreeNode* root) {
        // bfs
        vector<double> ans;
        queue<TreeNode*> que;
        if (root == NULL) {
            return ans;
        }
        que.push(root);
        while (!que.empty()) {
            int count = que.size();
            double sum = 0;
            for (int i = 0; i < count; i++) {
                TreeNode *node = que.front();
                que.pop();
                sum += node->val;
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
            ans.push_back(sum / count);
        }        
        return ans;
    }
};
