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
    
//     int findMaxPath(TreeNode* node, int maxi){
//         if(!node)
//             return 0;
        
//         int leftMaxPath = max(0, findMaxPath(node->left, maxi));
//         int rightMaxPath = max(0, findMaxPath(node->right, maxi));
        
//         int temp = (leftMaxPath + rightMaxPath) + node->val;
//         maxi = max(maxi, temp);
        
//         return max(leftMaxPath, rightMaxPath) + node->val;
//     }
    
//     int maxPathSum(TreeNode* root) {
//         int maxi = INT_MIN;
//         findMaxPath(root, maxi);
//         return maxi;
//     }
    int solve(TreeNode* root,int &res)
    {
        // Base Case 
        if(root==NULL) return NULL;
        int ls = solve(root->left,res);
        int rs = solve(root->right,res);
        int temp = max(max(ls,rs)+root->val,root->val);
        int ans = max(temp,ls+rs+root->val);
        res = max(res,ans);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        solve(root,res);
        return res;
    }
};