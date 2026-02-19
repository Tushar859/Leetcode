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
    void Inorder(TreeNode*root, vector<int>&ans){
            if(!root){
                return;
            }
            Inorder(root->left,ans);
            ans.push_back(root->val);
            Inorder(root->right,ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        Inorder(root, ans);
        for(int i=0; i<ans.size();i++){
            for(int j=i+1 ; j<ans.size();j++){
                if(ans[i]+ans[j]==k){
                    return true;
                    break;
                }
            }
        }

        return false;
    }
};