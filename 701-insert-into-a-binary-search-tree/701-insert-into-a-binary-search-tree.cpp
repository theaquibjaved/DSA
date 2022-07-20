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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode* newNode = new TreeNode(val);
        
        if(!root)
            return newNode;
        
        TreeNode* cur = root;
        
        while(cur){
            if(cur->val <= val){
                if(cur->right)
                    cur = cur->right;
                else{
                    cur->right = newNode;
                    break;
                }
            }
            else{
                if(cur->left)
                    cur = cur->left;
                else{
                    cur->left = newNode;
                    break;
                }
            }
        }
        return root;
    }
};