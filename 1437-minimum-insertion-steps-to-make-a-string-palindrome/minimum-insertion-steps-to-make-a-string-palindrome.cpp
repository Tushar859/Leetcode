class Solution {
public:
   vector<vector<int>>dp;
 int lcs(int st,int end, string &s ){
    if(st==end){
        return 1;
    }
   if(st>end){
    return 0;
   }
   if(dp[st][end]!=-1){
    return dp[st][end];
   }


    // match 
    if(s[st]==s[end]){
        return dp[st][end]=2 + lcs(st+1,end-1,s);
    }
   // no mtch
   else
     return dp[st][end]=max(lcs(st,end-1,s),lcs(st+1,end,s));
    

    }
    int minInsertions(string s) {
     int n = s.size()-1;
     int m=  s.size();
     dp.assign(n+2,vector<int>(n+2,-1));
     int ans = lcs(0,n,s);
     return m-ans;
        
    }
};