class Solution {
public:
    vector<vector<int>>dp;
   int solve(int m , int n,string &s, string &t ){
   if(m==0 && n==0){
    return 0;
   }
   if(m==0 && n!=0){
    return n;
   }
   if(m!=0 && n==0){
    return m;
   }
   if(dp[m][n]!=-1){
     return dp[m][n];
   }
   // mtch rhe to no op
    if(s[m-1]==t[n-1]){
        return dp[m][n]= 0+solve(m-1,n-1,s,t);
    }  
    // no mtch 
    return dp[m][n]=1+min(solve(m-1,n,s,t),solve(m,n-1,s,t)); 
   }
    int minDistance(string word1, string word2) {
        int m = word1.size();
         int n = word2.size();
     dp.assign(m+1,vector<int>(n+1,-1));
    return solve(m,n,word1,word2);
        
    }
};