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
    int sumEvenGrandparent(TreeNode* root) {
        int ans=0;
        queue<TreeNode*>q;

        q.push(root);
        while(!q.empty()){
            TreeNode*temp=q.front();
            int value=temp->val;
            if(value%2==0){
                if( temp->right && temp->right->right){
                    ans+=temp->right->right->val;
                }
                 if(temp->right && temp->right->left){
                    ans+=temp->right->left->val;
                }
                 if(temp->left && temp->left->right){
                    ans+=temp->left->right->val;
                }
                 if( temp->left && temp->left->left){
                    ans+=temp->left->left->val;
                }
            }

            q.pop();
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

        return ans;
    }
};