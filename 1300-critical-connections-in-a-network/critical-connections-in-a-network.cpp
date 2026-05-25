class Solution {
public:

    void dfs(int node,
             int parent,
             vector<int>& lowest,
             vector<int>& current,
             vector<int>& visited,
             vector<vector<int>>& adj,
             int& count,
             vector<vector<int>>& ans) {

        visited[node] = 1;

        current[node] = lowest[node] = count;
        count++;

        for (int j = 0; j < adj[node].size(); j++) {

            int neigh = adj[node][j];

         
            if (neigh == parent) {
                continue;
            }


            else if (visited[neigh]) {

                lowest[node] =
                    min(lowest[node], current[neigh]);
            }

         
            else {

                dfs(neigh, node, lowest, current,
                    visited, adj, count, ans);

                lowest[node] =
                    min(lowest[node], lowest[neigh]);

               
                if (lowest[neigh] > current[node]) {

                    ans.push_back({node, neigh});
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(
        int n,
        vector<vector<int>>& connections) {

        vector<vector<int>> adj(n);

        for (int i = 0; i < connections.size(); i++) {

            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> lowest(n, 0);
        vector<int> current(n, 0);
        vector<int> visited(n, 0);

        int count = 1;

        vector<vector<int>> ans;

        dfs(0, -1, lowest, current,
            visited, adj, count, ans);

        return ans;
    }
};