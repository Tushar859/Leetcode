class Solution {
public:
  vector<vector<int>>dp;
    bool solve(int n,vector<int>& nums, int target){
    if(n==0){
        return 0;
    }
   if(target==0){
    return true;
   }
   if(target<0){
    return false;
   }
   if(dp[n][target]!=-1){
     return dp[n][target];
   }
   // take 
    return dp[n][target]= solve(n-1,nums,target-nums[n-1])||
                    solve(n-1,nums,target);   


    }
    bool canPartition(vector<int>& nums) {
      int sum =0;
      for(auto i : nums){
        sum+=i;
      }
      if(sum%2!=0){
        return false;
      }
      int n = nums.size();
      dp.assign(n+1,vector<int>((sum/2)+1,-1));
      return solve(n,nums,sum/2);
    }
};