class Solution {
public:

    int solve(vector<int>& cost, int idx , int &minCost ,vector<int> &dp ){
    if(idx>=cost.size()){
        return 0;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    // 1 step 
    int option1 = cost[idx] + solve(cost,idx+1,minCost,dp);
    // 2 step
    int option2 = cost[idx] + solve(cost,idx+2,minCost,dp);
     minCost = min(option1 , option2);
     
    return dp[idx]= minCost;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int minCost = 0;
        int n= cost.size();
     vector<int>dp(n+1,-1);

     // jab 0 se suru kiye
     int ans1 = solve(cost,0,minCost,dp);
     // jab 1 se suru kiye
     int ans2 = solve(cost,1,minCost,dp);
     return min(ans1,ans2);
        
    }
};