class Solution {
public:
    vector<vector<int>>dp;
     int solve(int m, int n, int row, int col){
    //   int count =0;
     if(row==n-1 && col==m-1){
        // count++;
        return 1;
     }
     if(dp[row][col]!=-1){
        return dp[row][col];
     }
     int right=0;
     int down=0;
     // right
     if(row<n && col<m)
        if(col+1<m)
         right =  solve(m,n,row,col+1);   
    // down
    if(row<n && col <m)
     if(row+1<n)
         down = solve(m,n,row+1,col);
   
    
    return dp[row][col]= right+down;
     }

    int uniquePaths(int m, int n) {
     dp.assign(m+100,vector<int>(n+100,-1));
     if(m-1==0&&n-1==0){
        return 1;
     }
    // int count =0;
    return solve(m,n,0,0);
        
    }
};