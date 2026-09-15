class Solution {
public:
    vector<vector<int>>dp;
    int solve(int n , int m,string &s, string &t){
      if(m==0){
        return 1;
      }
      if(n==0 && m!=0){
        return 0;
      }
    
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
     if(s[n-1]==t[m-1]){
        return dp[n][m] = solve(n-1,m-1,s,t) + solve(n-1,m,s,t);
     }
     // no mtch
     return dp[n][m]= solve(n-1,m,s,t);
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return solve(n,m,s,t);
    }
};