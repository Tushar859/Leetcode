class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int> dist(n + 1, 1e9);

        dist[k] = 0;

        
        for(int i = 1; i <= n - 1; i++) {

            for(int j = 0; j < times.size(); j++) {

                int u = times[j][0];
                int v = times[j][1];
                int w = times[j][2];

       
                if(dist[u] != 1e9 && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        int ans = 0;

        for(int i = 1; i <= n; i++) {

          
            if(dist[i] == 1e9) {
                return -1;
            }

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};