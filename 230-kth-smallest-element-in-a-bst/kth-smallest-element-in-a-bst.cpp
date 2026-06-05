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
     void traversal(TreeNode*root, vector<int>& order){
        if(root==nullptr){
            return;
        }
        traversal(root->left, order);
        order.push_back(root->val);
        traversal(root->right, order);
     }
    int kthSmallest(TreeNode* root, int k) {
         vector<int>order;
         traversal(root,order);
         int ans=order[k-1];
         return ans;
    }
};