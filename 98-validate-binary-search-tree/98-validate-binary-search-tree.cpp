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
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validateBST(root, prev);
    }
    
    bool validateBST(TreeNode* node, TreeNode* &prev){
        if(!node)
            return true;
        
        if(!validateBST(node->left, prev))
            return false;
        
        bool notAscending = prev != NULL && prev->val >= node->val;
        if(notAscending)
            return false;
        
        prev = node;
        return validateBST(node->right, prev);
            
    }
};