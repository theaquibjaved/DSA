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
    struct nodeData{
        TreeNode* node;
        int low, high;
        nodeData(TreeNode* root, int left, int right){
            node = root;
            low  = left;
            high = right;
        }
    };
    
    TreeNode* sortedArrayToBST(vector<int>& arr) {
        
        int n = arr.size();
        TreeNode* root = new TreeNode(-1);
        stack<nodeData> st;

        nodeData node = nodeData(root, 0, n - 1);
        st.push(node); 

        while (st.empty() == false)
        {
            nodeData curNode = st.top();
            st.pop();

            // Find 'mid' for the currNode and update node with arr[mid].
            int mid = curNode.low + (curNode.high - curNode.low) / 2;
            curNode.node -> val = arr[mid];

            // Push the left part of array, that makes left subtree of current node.
            if (curNode.low < mid)
            {
                curNode.node -> left = new TreeNode(-1);

                node = nodeData(curNode.node -> left, curNode.low, mid - 1);
                st.push(node);
            }

            // Push the right part of array, that makes right subtree of current node.
            if (curNode.high > mid) 
            {
                curNode.node -> right = new TreeNode(-1);

                node = nodeData(curNode.node -> right, mid+1, curNode.high);
                st.push(node);
            }
        }

        // Return root of tree.
        return root;
    }
};