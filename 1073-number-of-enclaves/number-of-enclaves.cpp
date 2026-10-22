class Solution {
public:
    int R;
    int C;
    int row[4] = {-1, 0, 0, 1};
    int col[4] = {0, -1, 1, 0};
    bool valid(int r, int c) {
        return (r >= 0 && r < R && c >= 0 && c < C);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid[0].size();
        queue<pair<int,int>> q;
    //    bourndayr wale 1 ko dALRW HAIN
  
     // First and last row
        for(int i = 0; i < C; i++) {
            if(grid[0][i] == 1) {
                q.push({0, i});
                grid[0][i] = 0;
            }
            if(grid[R-1][i] == 1) {
                q.push({R-1, i});
                grid[R-1][i] = 0;
            }
        }
        // First and last column
        for(int j = 0; j < R; j++) {
            if(grid[j][0] == 1) {
                q.push({j, 0});
                grid[j][0] = 0;
            }
            if(grid[j][C-1] == 1) {
                q.push({j, C-1});
                grid[j][C-1] = 0;
            }
        }
       
       
     while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // nbr explore krt hain
        for(int k=0;k<4;k++){
            int i = x + row[k];
            int j = y + col[k];
            if(valid(i,j)&&grid[i][j]==1){
                q.push({i,j});
                grid[i][j]=0;
            } 
        }
   }
     int cnt =0;
      for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(grid[i][j]==1){
                cnt++;
            }
        }
      }
    return cnt;
     
    }
};