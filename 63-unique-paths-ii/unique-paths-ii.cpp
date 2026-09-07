class Solution {
public:
    vector<vector<int>>dp;
     int solve(int m, int n, int row, int col,vector<vector<int>>& obstacleGrid){
    //   int count =0;
     if(row==n-1 && col==m-1){
        // count++;
        return 1;
     }
     // obstacle hain
     if(obstacleGrid[row][col]==1){
       return 0;
     }
     if(dp[row][col]!=-1){
        return dp[row][col];
     }
     
     int right=0;
     int down=0;
     // right
     if(row<n && col<m)
        if(col+1<m)
         right =  solve(m,n,row,col+1,obstacleGrid);   
    // down
    if(row<n && col <m)
     if(row+1<n)
         down = solve(m,n,row+1,col,obstacleGrid);
   
    
    return dp[row][col]= right+down;
     }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1]==1){
            return 0;
        }
        dp.assign(n,vector<int>(m,-1));
       return solve(m,n,0,0,obstacleGrid);
    }
};