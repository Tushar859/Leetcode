class Solution {
public: 
  vector<int>dp;
   bool isPal(int i , int j,string &s){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
            break;
        }
        i++;
        j--;
    }
    return true;
   }
    int f(int i,string &s){
     int n = s.size();
      if(i==n){
        return 0;
      }
      if(dp[i]!=-1){
        return dp[i];
      }
     int mini=INT_MAX;
      for(int j = i;j<n;j++){
         if(isPal(i,j,s)){
            int cost =1+f(j+1,s);
            mini=min(mini,cost);
         }
      }
     return dp[i] = mini;


    }
    int minCut(string s) {
        dp.assign(s.size()+1,-1);
       return f(0,s)-1; 
    }
};