class Solution {
public:
    vector<vector<int>>dp;
    int solve(int r, int c, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // destination.. last pe pacuh gye now check the value of lst
        // agar +ve hai  to return 1 min healtg else 
        // return -val+1
        if(r == rows-1 && c == cols-1) {
            if(grid[r][c] >= 0)
                return 1;
            else
                return -grid[r][c] + 1;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int down = INT_MAX;
        int right = INT_MAX;

        if(r+1 < rows) {
            down = solve(r+1, c, grid);
        }

        if(c+1 < cols) {
            right = solve(r, c+1, grid);
        }

        int need = min(down, right);

        // current cell ko survive karne ke liye
        int ans = need - grid[r][c];

        // HP minimum 1 honi chahiye
        return dp[r][c]=max(1, ans);
    }

    int calculateMinimumHP(vector<vector<int>>& dug) {
        int rows = dug.size();
        int cols = dug[0].size();
        dp.assign(rows+1,vector<int>(cols+1,-1));

        return solve(0, 0, dug);
    }
};