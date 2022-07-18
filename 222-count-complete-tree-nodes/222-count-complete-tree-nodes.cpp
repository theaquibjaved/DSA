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
    int countNodes(TreeNode* root) {
        if (root == NULL)
        return 0;
    // Find the left height and the
    // right heights
    int lh = findLeftHeight(root);
    int rh = findRightHeight(root);
    // If left and right heights are
    // equal return 2^height(1<<height) -1
    if (lh == rh)
        return (1 << lh) - 1;
    // Otherwise, recursive call
    return 1 + countNodes(root->left)
           + countNodes(root->right);
    }
    
    int findLeftHeight(TreeNode* node){
       int ht = 0;
    while (node) {
        ht++;
        node = node->left;
    }
    // Return the left height obtained
    return ht;
    }
    
    int findRightHeight(TreeNode* node){
        int height = 0;
        
        if(node){
            height++;
            node = node->right;
        }
        return height;
    }
};