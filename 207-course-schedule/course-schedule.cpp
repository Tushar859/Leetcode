class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

    
        for(int i = 0; i < prerequisites.size(); i++) {

            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adj[u].push_back(v);

            indegree[v]++;
        }

        queue<int> q;

   
        for(int i = 0; i < numCourses; i++) {

            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            count++;

            for(int i = 0; i < adj[node].size(); i++) {

                int neighbour = adj[node][i];

                indegree[neighbour]--;

                if(indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

    
        if(count == numCourses) {
            return true;
        }

        return false;
    }
};