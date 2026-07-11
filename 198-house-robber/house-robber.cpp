class Solution {
public:
    int solve(vector<int>& nums , int idx , int n,vector<int>&dp){

        // base case 
        if (idx >= n){
            return 0;
        }
        if(dp[idx]!=-1){
           return dp[idx];
        }
        // include
        int rightAns = nums[idx]+solve(nums,idx+2,n,dp);
        // exclude
        int leftAns = 0 + solve(nums,idx+1,n,dp);
         
   
     int finalAns = max(rightAns,leftAns);
      dp[idx] = finalAns;
     return finalAns;
// since one var is only changing so 1d dp will be used 
    }

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n,-1);
  
     int idx =0;
    int ans = solve(nums,idx,n,dp);
    return ans;
   
    }
};