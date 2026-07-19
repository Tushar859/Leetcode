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
      void bfs(TreeNode*root, int &count){

           if(root==nullptr){
         
             return ;
           }

           int maxi=root->val;
           int ori=maxi;
           queue<TreeNode*>qp;
           qp.push(root);
           while(!qp.empty()){
             TreeNode* node=qp.front();
             qp.pop();
             maxi=max(maxi,node->val);
            

             if(node->left){
                qp.push(node->left);
             }
             if(node->right){
                qp.push(node->right);
             }

           }
           if(maxi==ori){
            count++;
           }

           bfs(root->left,count);
           bfs(root->right,count);


      }


    int countDominantNodes(TreeNode* root) {
        int count=0;
        bfs(root, count);
        return count;
    }
};