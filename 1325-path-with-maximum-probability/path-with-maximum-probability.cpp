class Solution {
public:
    double maxProbability(int n,
                          vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start_node,
                          int end_node) {

        vector<vector<pair<int,double>>> adj(n);

        for(int i=0; i<edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<bool> explore(n,0);
        vector<double> maxi(n,0);

        maxi[start_node] = 1;

        priority_queue<pair<double,int>> pq;

        pq.push({1,start_node});

        while(!pq.empty()) {

            int node = pq.top().second;
            double currProb = pq.top().first;

            pq.pop();

            if(explore[node] == 1) {
                continue;
            }

            explore[node] = 1;

            for(int i=0; i<adj[node].size(); i++) {

                int neighbour = adj[node][i].first;
                double weight = adj[node][i].second;

                if(!explore[neighbour] &&
                   currProb * weight > maxi[neighbour]) {

                    maxi[neighbour] = currProb * weight;

                    pq.push({maxi[neighbour], neighbour});
                }
            }
        }

        return maxi[end_node];
    }
};