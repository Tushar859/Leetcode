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
     int h (TreeNode* root){
     if(root==nullptr){
        return 0;
     } 
    int left = 1+h(root->left);
    int right = 1+h(root->right);
    return max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
       int l = h(root->left);
       int r =h(root->right);
       if(abs(l-r)>1){
        return false;
       }
    //    else{
    //     return false;
    //    }
   bool le= isBalanced(root->left);
   bool ri= isBalanced(root->right);
        return le&&ri;
    // return false;
    }
};