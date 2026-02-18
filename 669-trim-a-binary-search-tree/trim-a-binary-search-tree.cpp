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

    TreeNode* Traversal(TreeNode* root, int low, int high) {

        if(!root) 
        return NULL;


        if(root->val < low) {
           return Traversal(root->right,low,high);
        }

    
        if(root->val > high) {
          return Traversal(root->left,low,high);
        }

      
        root->left = Traversal(root->left, low, high);
        root->right = Traversal(root->right, low, high);

        return root;
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return Traversal(root, low, high);
    }
};