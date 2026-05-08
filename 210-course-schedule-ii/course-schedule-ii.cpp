class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>in(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
             in[prerequisites[i][1]]++;
        }

       queue<int>q;
       stack<int>s;
        for(int i=0; i<in.size();i++){
            if(in[i]==0){
                q.push(i);
            }


        }

        while(!q.empty()){
            int node=q.front();
            s.push(node);
            q.pop();
            for(int i=0;i<adj[node].size();i++){
               in[adj[node][i]]--;
                if(in[adj[node][i]] == 0){
                    q.push(adj[node][i]);
                }
            }
        }

        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();        }

              

                if(ans.size() != numCourses) {
            return {};
        }

                return ans;
    }


};