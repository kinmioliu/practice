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
    TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return NULL;
        }
        int rootVal = preorder[0];
        auto leftTreePos = find(inorder.begin(), inorder.end(), rootVal);
        int leftSize = leftTreePos - inorder.begin(); // dont include root node
        vector<int> leftTreePreOrder = vector<int>(preorder.begin() + 1, preorder.begin() + 1 + leftSize);
        vector<int> leftTreeInOrder = vector<int>(inorder.begin(), inorder.begin() + leftSize);
        vector<int> rightTreePreOrder = vector<int>(preorder.begin() + 1 + leftSize, preorder.end());
        vector<int> rightTreeInOrder = vector<int>(inorder.begin() + leftSize + 1, inorder.end());
        /*
        for_each(leftTreePreOrder.begin(), leftTreePreOrder.end(), [](int v){cout << v << ",";}); cout << endl;
        for_each(leftTreeInOrder.begin(), leftTreeInOrder.end(), [](int v){cout << v << ",";}); cout << endl;        
        for_each(rightTreePreOrder.begin(), rightTreePreOrder.end(), [](int v){cout << v << ",";}); cout << endl;
        for_each(rightTreeInOrder.begin(), rightTreeInOrder.end(), [](int v){cout << v << ",";}); cout << endl;        
        */
        TreeNode *root = new TreeNode(preorder[0]);        
        root->left = buildTree(leftTreePreOrder, leftTreeInOrder);
        root->right = buildTree(rightTreePreOrder, rightTreeInOrder);
        return root;
    }
    
    /* range[) */
    TreeNode* buildTree(vector<int>& preorder, int pb, int pe, vector<int>& inorder, int ib, int ie) {
        if (pb == pe) {
            return NULL;
        }
        int rootVal = preorder[pb];        
        auto leftTreePos = find(inorder.begin() + ib, inorder.begin() + ie, rootVal);
        int leftSize = leftTreePos - (inorder.begin() + ib); // dont include root node
        //cout << rootVal << ":" << leftSize << ":" << pb << "," << pe << "|" << ib << "," << ie << endl;        
        /*
        vector<int> leftTreePreOrder = vector<int>(preorder.begin() + 1, preorder.begin() + 1 + leftSize);
        vector<int> leftTreeInOrder = vector<int>(inorder.begin(), inorder.begin() + leftSize);
        vector<int> rightTreePreOrder = vector<int>(preorder.begin() + 1 + leftSize, preorder.end());
        vector<int> rightTreeInOrder = vector<int>(inorder.begin() + leftSize + 1, inorder.end());
        */
        /*
        for_each(leftTreePreOrder.begin(), leftTreePreOrder.end(), [](int v){cout << v << ",";}); cout << endl;
        for_each(leftTreeInOrder.begin(), leftTreeInOrder.end(), [](int v){cout << v << ",";}); cout << endl;        
        for_each(rightTreePreOrder.begin(), rightTreePreOrder.end(), [](int v){cout << v << ",";}); cout << endl;
        for_each(rightTreeInOrder.begin(), rightTreeInOrder.end(), [](int v){cout << v << ",";}); cout << endl;        
        */
        TreeNode *root = new TreeNode(rootVal);        
        root->left = buildTree(preorder, pb + 1, pb + 1 + leftSize, inorder, ib, ib + leftSize);
        root->right = buildTree(preorder, pb + 1 + leftSize, pe, inorder, ib + leftSize + 1, ie);
        return root;
    }    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    
};
