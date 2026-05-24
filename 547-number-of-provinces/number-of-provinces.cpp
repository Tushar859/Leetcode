class Solution {
public:

    void dfs(int node, vector<bool>& visited,
             vector<vector<int>>& adj) {

        visited[node] = 1;

        for(int j = 0; j < adj[node].size(); j++) {

            int neighbour = adj[node][j];

            if(!visited[neighbour]) {

                dfs(neighbour, visited, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<vector<int>> adj(n + 1);

        for(int i = 0; i < n; i++) {

            int parent = i + 1;

            for(int j = 0; j < isConnected[i].size(); j++) {

                if(i != j && isConnected[i][j] == 1) {

                    int child = j + 1;

                    adj[parent].push_back(child);
                }
            }
        }

        int count = 0;

        vector<bool> visited(n + 1, 0);

      
        for(int i = 0; i <= n; i++) {

            if(!visited[i]) {

                dfs(i, visited, adj);

                count++;
            }
        }

        return count-1;
    }
};