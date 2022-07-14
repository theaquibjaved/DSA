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
    int maxi = INT_MIN;
    int findMaxPath(TreeNode* node){
        if(!node)
            return 0;
        
        int leftMaxPath = max(0, findMaxPath(node->left));
        int rightMaxPath = max(0, findMaxPath(node->right));
        
        int temp = (leftMaxPath + rightMaxPath) + node->val;
        maxi = max(maxi, temp);
        
        return max(leftMaxPath, rightMaxPath) + node->val;
    }
    
    int maxPathSum(TreeNode* root) {

        findMaxPath(root);
        return maxi;
    }

    
    //  int max_sum=INT_MIN;
    // int max_gain(TreeNode* root)
    // {
    //     if(!root)return 0;
    //     int l=max(max_gain(root->left),0);
    //     int r=max(max_gain(root->right),0);
    //     int new_price=root->val+l+r;
    //     max_sum=max(max_sum,new_price);
    //     return root->val+max(l,r);
    // }
    // int maxPathSum(TreeNode* root) {
    //     max_gain(root);
    //     return max_sum;
    // }
};