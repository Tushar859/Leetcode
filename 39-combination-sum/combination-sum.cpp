class Solution {
public:
   void solve(int idx,vector<int>& candidates, int target, vector<vector<int>>&ans , vector<int>temp,int n){
    // base case 
     if (idx >= n || target < 0) {
            return;
        }
    //  if(target<0){
    //     return
    //  }
     if(target==0){
        ans.push_back(temp);
        return;
     }

    // pick
      if(candidates[idx]<=target){
        temp.push_back(candidates[idx]);
        solve(idx,candidates,target-candidates[idx],ans,temp,n);
         // lia phr usko nikal dia as possible combinaions lene hain  
         temp.pop_back();
      }
        
     
     
    // notpick
      solve(idx+1,candidates,target,ans,temp,n);

   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        int n = candidates.size();
       solve(0,candidates,target,ans,temp,n);
       return ans;
    }
};