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
    void f(TreeNode* root, vector<int>&ans,int val){
     if(root==nullptr){
        return ;
     }
     val = val*10+root->val;
     if(!root->left &&!root->right){
            ans.push_back(val);
            val=0;
            return; 
        }

     
     f(root->left,ans,val);
      
     f(root->right,ans,val);
     


    
    }
    int sumNumbers(TreeNode* root) {
      
      vector<int>ans;
      f(root,ans,0);
      int sum =0;
      for(auto i : ans){
        // cout<<i<<endl;
        sum+=i;
      }
      return sum;

    }
};