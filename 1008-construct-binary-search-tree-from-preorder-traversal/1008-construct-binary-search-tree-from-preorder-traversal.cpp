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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        
        int preStart = 0, preEnd = preorder.size() - 1;
        int inStart = 0, inEnd = inorder.size() - 1;
        
        map<int, int> map;
        for(int i = inStart; i <= inEnd; i++)
            map[inorder[i]] = i;
        
        TreeNode* root = constructTree(preorder, preStart, preEnd,
                            inorder, inStart, inEnd, map);
        
        return root;        
    }
    
    TreeNode* constructTree(vector<int>& preorder, int preStart, int preEnd, 
                            vector<int>& inorder, int inStart, int inEnd, map<int, int> &map){
        
        if(preStart > preEnd || inStart > inEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = map[root->val];
        int numsLeft = inRoot - inStart;
        
        root->left = constructTree(preorder, preStart + 1, preStart + numsLeft, 
                                   inorder, inStart, inRoot - 1, map);
        
        root->right = constructTree(preorder, preStart + numsLeft + 1, preEnd, 
                                   inorder, inRoot + 1, inEnd, map);
        
        return root;
    }
};