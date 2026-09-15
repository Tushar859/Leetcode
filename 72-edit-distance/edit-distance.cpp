class Solution {
public:
vector<vector<int>>dp;
   int solve(int n , int m, string &s, string &t){
       if(n==0 ){
        return m;
       }
       if(m==0){
        return n;
       }
       if(dp[n][m]!=-1){
        return dp[n][m];
       }
       
     // mtch 
     if(s[n-1]==t[m-1]){
        return dp[n][m]=solve(n-1,m-1,s,t);
     }
     // no mtch
     else{
        int insert = 1+solve(n,m-1,s,t);
        int del =1+ solve(n-1,m,s,t);
        int rep = 1+ solve(n-1,m-1,s,t);
        return dp[n][m] =min({insert,del,rep});
   }
   }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m= word2.size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return solve(n,m,word1,word2);
    }
};