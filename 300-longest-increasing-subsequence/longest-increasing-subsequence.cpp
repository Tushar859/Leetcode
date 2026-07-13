class Solution {
public:
     int solvebyrec(vector<int>& nums, int curr , int prev , vector<vector<int>>& dp){
    // base case
    if(curr >= nums.size()){
        return 0;
    }
    // +1 iss liye kia hu as prev -1 hain nd dp[][-1] donot exist
    if(dp[curr][prev+1]!=-1){
        return dp[curr][prev+1];
    }
    // incldue
    int include =0;
    if(prev==-1 || nums[curr]>nums[prev]){
         include = 1 + solvebyrec(nums,curr+1,curr,dp);
    }
    

    // exclude
     int exclude = 0 + solvebyrec(nums,curr+1,prev,dp);

    int ans = max(include ,exclude);
        dp[curr][prev+1] = ans;
    return ans;
    
     }
// two var are changing so 2d dp will be used
    int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+200,vector<int>(n+200,-1));
    int curr =0;
    int prev =-1;
    return solvebyrec(nums,curr,prev,dp);
    }
};