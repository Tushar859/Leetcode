class Solution {
public:
     vector<vector<int>>dp;
     int solve(vector<vector<int>>& grid , int row, int col){
      int n = grid.size();
      int m = grid[0].size();
     if(row==n-1 && col==m-1){
        return grid[row][col];
     }
     if(dp[row][col]!=-1){
        return dp[row][col];
     }
     int right=INT_MAX;
     int down=INT_MAX;
     // right
     if(row<n && col<m)
        if(col+1<m)
         right = grid[row][col] + solve(grid,row,col+1);   
    // down
    if(row<n && col <m)
     if(row+1<n)
         down = grid[row][col] +solve(grid,row+1,col);
   
    
    return dp[row][col]= min(right,down);
     }


    int minPathSum(vector<vector<int>>& grid) {
     int r = grid.size();
     int c = grid[0].size();
     dp.assign(r,vector<int>(c,-1));
    return solve(grid,0,0);
    }
};