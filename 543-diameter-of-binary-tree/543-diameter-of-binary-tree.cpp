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
    
    int height(TreeNode* &node, int &maxi){
        if(node == NULL)
            return 0;
        
        int leftHeight = height(node->left, maxi);
        int rightHeight = height(node->right, maxi);
        
        maxi = max(maxi, leftHeight + rightHeight);
        
        return 1 + max(leftHeight, rightHeight);
    } 
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};