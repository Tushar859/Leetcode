class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        if(edges.size()==0){
            return true;
        }
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            // u se v
            adj[edges[i][0]].push_back(edges[i][1]);
            // v se u 
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>vis(n,0);
        queue<int>q;
        q.push(src);
        vis[src]=1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
             vis[node]=1;
            for(int j=0;j<adj[node].size();j++){
                if(adj[node][j]==dest){
                    return true;
                }
                else if(!vis[adj[node][j]]){
                    q.push(adj[node][j]);
                    vis[adj[node][j]]=1;
                }
            }
        }
    return false;
    }
};