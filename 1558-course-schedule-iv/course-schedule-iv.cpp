class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {

        vector<vector<int>> adj(numCourses);

        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<bool> ans(queries.size(), false);

        for(int i = 0; i < queries.size(); i++) {

            int p = queries[i][0];
            int c = queries[i][1];

            queue<int> q;
            vector<int> vis(numCourses, 0);

            q.push(p);
            vis[p] = 1;

            bool found = false;

            while(!q.empty()) {

                int node = q.front();
                q.pop();

                if(node == c) {
                    found = true;
                    break;
                }

                for(int j = 0; j < adj[node].size(); j++) {

                    int nbr = adj[node][j];

                    if(!vis[nbr]) {
                        vis[nbr] = 1;
                        q.push(nbr);
                    }
                }
            }

            ans[i] = found;
        }

        return ans;
    }
};