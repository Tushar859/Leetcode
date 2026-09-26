class Solution {
public:
    int row[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int col[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
     int R;
     int C;
     bool valid(int r , int c , vector<vector<int>>& grid, vector<vector<bool>> &vis ){
        if (r>=0&&r<R && c>=0&&c<C && grid[r][c]!=1){
            return true;
        }
        else{
            return false;
        }
     }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         R = grid.size();
         C = grid[0].size();
       vector<vector<bool>> vis(R, vector<bool>(C, false));
      queue<pair<int,int>>q;
      vector<vector<int>>dist(R,vector<int>(C, 0));

      int cnt =1;
      if (grid[0][0] == 1 || grid[R-1][C-1] == 1){
            return -1;}
      q.push({0,0});
      vis[0][0]=1;
      dist[0][0] = 1;
      while(!q.empty()){
       int r = q.front().first;
      int c = q.front().second;
    //   q.pop();
          if(r==R-1 && c==C-1){
            return dist[r][c];
          }
        q.pop();
        for(int k=0;k<8;k++){
            int new_r = r + row[k];
            int new_c = c + col[k];
           if(valid(new_r,new_c,grid,vis) && !vis[new_r][new_c]){
                 q.push({new_r,new_c});
                 vis[new_r][new_c]=1;
                 dist[new_r][new_c] = dist[r][c] + 1;
            

            }
        }
      }
     return -1;
    }
};