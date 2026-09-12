class Solution {
public:
   vector<vector<int>>dp;
    int solve(int n, vector<int>& coins, int amt) {
        if (amt == 0)
            return 0;
        if (amt < 0)
            return 1e9;
        if (n == 0)
            return 1e9;
        if(dp[n][amt]!=-1){
            return dp[n][amt];
        }
            
        int take = solve(n, coins, amt - coins[n-1]);

        if (take != 1e9)
            take++;

        int nt = solve(n-1, coins, amt);

        return dp[n][amt]=min(take, nt);
    }
    int coinChange(vector<int>& coins, int amount) {
   // .... /// ////
      int n=coins.size();
      dp.assign(n+1,vector<int>(amount+1,-1));
       int ans = solve(coins.size(), coins, amount);

        if (ans == 1e9)
            return -1;

        return ans;     
    }
};





