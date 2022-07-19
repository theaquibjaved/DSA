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
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
//         int postStart = 0, postEnd = postorder.size() - 1;
//         int inStart = 0, inEnd = inorder.size() - 1;
        
//         unordered_map<int, int> mpp;
//         for(int i = inStart; i <= inEnd; i++)
//             mpp[inorder[i]] = i;
        
//         return constructTree(postorder, postStart, postEnd,
//                             inorder, inStart, inEnd, mpp);
 
//     }
    
    
//     TreeNode* constructTree(vector<int>& postorder, int postStart, int postEnd, 
//                             vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int> &mpp){
        
//         if(postStart > postEnd || inStart > inEnd)
//             return NULL;
        
//         TreeNode* root = new TreeNode(postorder[postEnd]);
//         int inRoot = mpp[postorder[postEnd]];
//         int numsLeft = inRoot - inStart;
        
//         root->left = constructTree(postorder, postStart, postStart + 1, 
//                                    inorder, inStart, inRoot - 1, mpp);
        
//         root->right = constructTree(postorder, postStart + numsLeft, postEnd - 1, 
//                                    inorder, inRoot + 1, inEnd, mpp);
        
//         return root;
//     }
    
    TreeNode *Tree(vector<int>& in, int x, int y,vector<int>& po,int a,int b){
        if(x > y || a > b)return nullptr;
        TreeNode *node = new TreeNode(po[b]);
        int SI = x;  
        while(node->val != in[SI])SI++;
        node->left  = Tree(in,x,SI-1,po,a,a+SI-x-1);
        node->right = Tree(in,SI+1,y,po,a+SI-x,b-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& po){
        return Tree(in,0,in.size()-1,po,0,po.size()-1);
    }
};