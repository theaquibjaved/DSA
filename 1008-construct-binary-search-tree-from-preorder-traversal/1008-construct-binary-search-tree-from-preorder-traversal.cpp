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
    TreeNode* bstFromPreorder(vector<int>& preOrder) {
        int preIndex = 0;

    // Return the util function.
    return util(preOrder, preIndex, INT_MIN, INT_MAX);
    }
    
    TreeNode* util(vector<int> &preOrder, int &preIndex, int startRange, int endRange){

    // If the preIndex is greater than the length of the array return NULL.
    if (preIndex >= preOrder.size()){
        return NULL;
    }

    int currNode = preOrder[preIndex];

    // If the current node lies inside the range then process the node.
    if (currNode > startRange && currNode < endRange){
        TreeNode* root = new TreeNode(currNode);

        // Increase the index by 1.
        preIndex += 1;

        // If left node exists process left.
        if (preIndex < preOrder.size()){
            root -> left = util(preOrder, preIndex, startRange, currNode);
        }
        // If right node exists process right.
        if (preIndex < preOrder.size()){
            root -> right = util(preOrder, preIndex, currNode , endRange);
        }

        // Return the root.
        return root;
    }

    // If node was not processed return NULL.
    return NULL;
}
};