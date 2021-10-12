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
    unordered_map<int, int> prePathSumCnt;
    int targetSum;
    int numbers;
    void inOrderTraveralAccumlate(TreeNode* root, int preSum = 0) {
        if (root == NULL) {
            return;
        }
        int sum = root->val + preSum;
        numbers += prePathSumCnt[sum - targetSum];
        //if (numbers > 0) {
            //cout << root->val << ":" << sum << endl;
        //}
        prePathSumCnt[sum]++;
        inOrderTraveralAccumlate(root->left, sum);
        // after process left node, need clear
        //prePathSumCnt.clear();
        //prePathSumCnt[0] = 1;
        inOrderTraveralAccumlate(root->right, sum);
        prePathSumCnt[sum]--; // each inner process pop out        
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        this->targetSum = targetSum;
        prePathSumCnt[0] = 1;
        numbers = 0;
        inOrderTraveralAccumlate(root, 0);
        return numbers;
    }

int pathSumStartFromRoot(TreeNode* root, int sum) {
        if (!root) {
            return 0;
        }
        int count = (sum + root->val) == targetSum ? 1 : 0; 
        /*
        if (count == 1) {
            cout << root->val << ":" << sum + root->val << endl;            
        }
        */
        count += pathSumStartFromRoot(root->left, sum + root->val);
        count += pathSumStartFromRoot(root->right, sum + root->val);
        return count;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return 0;
        }
        this->targetSum = targetSum;
        int rootC = pathSumStartFromRoot(root, 0);
        int lC = pathSum(root->left, targetSum);
        int rC = pathSum(root->right, targetSum);
        return rootC + lC + rC;
    }        
};
