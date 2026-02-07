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
    map<int, map<int, multiset<int>>> mp;

    void fill(TreeNode* root, int row, int col){
        if(!root) return;

        mp[col][row].insert(root->val);

        fill(root->left, row+1, col-1);
        fill(root->right, row+1, col+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};

        fill(root, 0, 0);

        vector<vector<int>> ans;
        for(auto &c : mp){
            vector<int> temp;
            for(auto &r : c.second){
                temp.insert(temp.end(), r.second.begin(), r.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};