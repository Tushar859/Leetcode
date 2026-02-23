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
    void Traversal(TreeNode*root, vector<int>& ans,int value){
        if(!root){
            return;
        }
          value=value*10+root->val;
        if(!root->left &&!root->right){
            ans.push_back(value);
            value=0;
            return;
           
        }
      
        Traversal(root->left , ans, value);
        Traversal(root->right, ans, value);
    }
    int sumNumbers(TreeNode* root) {
        int value=0;
        vector<int>ans;
        Traversal(root, ans, value);
        int sum=0;
        for(int i=0;i<ans.size();i++){
           sum+=ans[i];
        }

        return sum;
    }
};