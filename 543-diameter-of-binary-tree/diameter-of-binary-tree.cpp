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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int l = h(root->left);
        int r = h(root->right);
        int dia = 0;
        dia  = max(dia,l+r);
        int leftDia= diameterOfBinaryTree(root->left);
        int rightDia= diameterOfBinaryTree(root->right);

        dia = max(dia,leftDia);
        dia = max(dia,rightDia);

    return dia;
    }
};