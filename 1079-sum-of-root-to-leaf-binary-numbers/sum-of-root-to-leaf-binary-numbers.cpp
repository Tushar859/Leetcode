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
     void Traversal(TreeNode*root, int value,vector<int>&ans,int count){
        if(!root){
            return;
        }
          value = value * 2 + root->val;
  
        if(!root->left &&!root->right){
            ans.push_back(value);
           value=0;
            return;
        }
        Traversal(root->left , value, ans,count);
        Traversal(root->right, value, ans,count);
     }
    int sumRootToLeaf(TreeNode* root) {
        vector<int>ans;
        Traversal(root,0, ans, 0);
        int sum=0;

        for(int i=0;i<ans.size();i++ ){
           sum+=ans[i];
        }

        return sum;
    }
};