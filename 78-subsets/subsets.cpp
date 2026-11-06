class Solution {
public:

      void solve(int idx,vector<int>& nums , vector<int> temp,  vector<vector<int>>&ans){
        // base case
        int n = nums.size();
         if(idx>=n){
           ans.push_back(temp);
           return;
         }
        // pick/
         temp.push_back(nums[idx]);
         solve(idx+1,nums,temp,ans);
         //not pick
          temp.pop_back();
         solve(idx+1,nums,temp,ans);

      }
    vector<vector<int>> subsets(vector<int>& nums) {
          vector<int> temp;
        vector<vector<int>>ans;
        // ams
        solve(0,nums,temp,ans);
        // sort(ans.begin(),ans.end());
        return ans;
    }
};