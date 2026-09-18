class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> q;
        if(root == NULL){
            return ans;
        }
        // root - level
        q.push({root, 0});
        while(!q.empty()){
            vector<int> l;
            int n = q.size();
            for(int i = 0; i < n; i++){
                auto it = q.front();
                TreeNode* val = it.first;
                int level = it.second;
                q.pop();
                l.push_back(val->val);
                if(val->left){
                    q.push({val->left, level + 1});
                }
                if(val->right){
                    q.push({val->right, level + 1});
                }
            }
            ans.push_back(l);
        }

        return ans;
    }
};