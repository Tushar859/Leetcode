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
    bool f(TreeNode* root, int targetSum , int sum){
      if(root==nullptr) return false;
        if(root->left==nullptr && root->right==nullptr){
            // cout<<sum; leaf node
            return sum+root->val==targetSum;
        }
        // if(root!=nullptr) 
          sum += root->val;
     bool left = f(root->left,targetSum,sum);
      bool right = f(root->right,targetSum,sum);
      return left||right;
     
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return false;
        }
      return f (root,targetSum,0);
        
    }
};