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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root)
            return root;
        else if(key < root->val)
            root->left = deleteNode(root->left, key);
        else if(key > root->val)
            root->right = deleteNode(root->right, key);
        
        //found the node to be deleted
        else{
            //case 1: no child
            if(root->left == NULL && root->right == NULL){
               // delete root;
                root = NULL;
               // return NULL;
            }
            
            //case 2: one child
            else if(root->left == NULL){
                TreeNode *temp = root;
                root = root->right;
                // delete temp;
                // return root->right;
            }
            else if(root->right == NULL){
                TreeNode *temp = root;
                root = root->left;
                // delete temp;
                // return root->left;
            }
            
            //case 3: two children
            else{
                TreeNode* temp = findMin(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        
        return root;
    }
    
    TreeNode* findMin(TreeNode* node){
        while(node->left != NULL)
            node = node->left;
        
        return node;
    }
};