class Solution {
public:
         vector<vector<int>> dp;
     int f(int i, int j,vector<int>& cuts){
       if(i>j){
        return 0;
       }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
       int mini = INT_MAX;
       for(int k =i;k<=j;k++){
         int cost = cuts[j+1]-cuts[i-1] + f(i,k-1,cuts)+f(k+1,j,cuts);
         mini = min(mini,cost);
       }
     return dp[i][j] = mini;

     }


    int minCost(int n, vector<int>& cuts) {
     cuts.push_back(n);
     cuts.push_back(0);
     sort(cuts.begin(),cuts.end());
     int y = cuts.size()-2;
      dp.assign(y + 2, vector<int>(y + 2, -1));
     return f(1,y,cuts);
        
    }
};