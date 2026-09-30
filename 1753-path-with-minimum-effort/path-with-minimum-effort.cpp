class Solution {
public:
   int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
    bool valid(int r, int c, vector<vector<int>>& heights){
        return (r>=0&&r<heights.size()&&c>=0&&c<heights[0].size());
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
         int R = heights.size();
         int C = heights[0].size();
        int ans =INT_MAX;
        int pathS = 0;
        // effort , int row,int col
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > q;
        q.push({0, {0, 0}});
       vector<vector<int>> dist(R, vector<int>(C, INT_MAX));
      dist[0][0]=0;
      while(!q.empty()){
        int pathS = q.top().first;
         int i = q.top().second.first;
        int j = q.top().second.second;
         q.pop();
         if (i == R - 1 && j == C - 1) {
                return pathS;
            }
        for(int k=0;k<4;k++){
            int new_i = i+ row[k];
            int new_j = j + col[k];
            if(valid(new_i,new_j,heights)){
                 int edge = abs(heights[new_i][new_j] - heights[i][j]);
                 int newEffort = max(pathS, edge);
                    if (newEffort < dist[new_i][new_j]) {
                        dist[new_i][new_j] = newEffort;
                        q.push({newEffort, {new_i, new_j}});}

            } 
        }
      } 
    return ans;

    }
};