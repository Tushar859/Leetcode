class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if (root == nullptr)
            return ans;

        queue<TreeNode*> q;

        q.push(root);
        q.push(nullptr);

        vector<int> level;

        while (!q.empty()) {

            TreeNode* front = q.front();
            q.pop();

            // Level complete
            if (front == nullptr) {

                ans.push_back(level);
                level.clear();

                // Agar queue mein abhi nodes hain,
                // toh next level ke end ke liye nullptr
                if (!q.empty())
                    q.push(nullptr);

            }
            else {

                level.push_back(front->val);

                if (front->left != nullptr)
                    q.push(front->left);

                if (front->right != nullptr)
                    q.push(front->right);
            }
        }

        return ans;
    }
};