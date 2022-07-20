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
    TreeNode* deleteNode(TreeNode* root, int val) {
        if(root == NULL) return root;




	else if(val < root->val) root->left = deleteNode(root->left,val);


	else if (val > root->val) root->right = deleteNode(root->right,val);


	// Wohoo... I found you, Get ready to be deleted	


	else {


		// Case 1:  No child


		if(root->left == NULL && root->right == NULL) {


			//delete root;


			root = NULL;


		}


		//Case 2: One child


		else if(root->left == NULL) {


			 TreeNode *temp = root;


			root = root->right;


//delete temp;


		}


		else if(root->right == NULL) {


			 TreeNode *temp = root;


			root = root->left;


			delete temp;


		}


		// case 3: 2 children


		else {


			 TreeNode *temp = FindMin(root->right);


			root->val = temp->val;


			root->right = deleteNode(root->right,temp->val);


		}


	}


	return root;


    }
    
    TreeNode* FindMin(TreeNode* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}
};