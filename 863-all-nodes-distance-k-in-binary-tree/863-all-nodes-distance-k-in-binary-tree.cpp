/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent, TreeNode* target){
        if(!root || (root == target)) return;
    
        if(root->left){
            parent[root->left] = root;
            dfs(root->left, parent, target);
        }
        if(root->right){
            parent[root->right] = root;
            dfs(root->right, parent, target);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        dfs(root, parent, target);
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        
        q.push(target);
        visited[target] = true;
        int curr_level = 0;
        
        while(!q.empty()){
            int size = q.size();
            if(curr_level++ == k)
                break;
            
            for(int i = 0; i < size; i++){
                TreeNode* current = q.front();
                q.pop();
                
                bool leftNotVisisted = current->left && !visited[current->left];
                bool rightNotVisited = current->right && !visited[current->right];
                bool parentNotVisited = parent[current] && !visited[parent[current]];
                
                if(leftNotVisisted){
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if(rightNotVisited){
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if(parentNotVisited){
                    q.push(parent[current]);
                    visited[parent[current]] = true;
                }
            }
        }
        
        vector<int> res;
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            res.push_back(current->val);
        }
        
        return res;
    }
};