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
TreeNode*prev=NULL;
TreeNode*First=NULL;
TreeNode *sec=NULL;
 void inorder(TreeNode* root){
    if(!root){
        return;
    }

    inorder(root->left);
    if(prev!=NULL && prev->val>root->val){
        if(First==NULL){
            First=prev;
        }
        sec= root;
    }
       prev=root;
       inorder(root->right);


  }
    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp=First->val;
        First->val=sec->val;
        sec->val=temp;
    }
};