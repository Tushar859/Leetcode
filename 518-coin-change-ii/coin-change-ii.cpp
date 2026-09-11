class Solution {
public:
  vector<vector<int>>dp;
int solve(int n,vector<int>& coins, int amt){
    if(amt==0){
        return 1;
    }
    if(amt<0){
        return 0;
    }
    if(n==0){
        return 0;
    }
    if(dp[n][amt]!=-1){
        return dp[n][amt];
    }
   
  int take = solve(n,coins,amt-coins[n-1]);
  int nt = solve(n-1,coins,amt);
  return dp[n][amt]=take+nt;

   }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.assign(n+100,vector<int>(amount+1,-1));
        return solve(n,coins,amount);
        
    }
};