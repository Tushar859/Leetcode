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
    bool inorder(TreeNode* root, int& target,int sum){
    if( root == nullptr) return false;
     if(root->left == nullptr && root->right == nullptr){
        if(sum + root->val == target) return true;
        else return false;
     }

     // l n r
     
   
    
      sum+=root->val;
    bool lef = inorder(root->left,target,sum);
     bool  righ =inorder(root->right,target,sum);
    return lef||righ;
    }
    bool hasPathSum(TreeNode* root, int target) {
        // if(root==nullptr && target==0){
        //     return true;
        // }
        if (!root) return false;
      int sum =0;
       return inorder(root,target,0);
    
    }

};