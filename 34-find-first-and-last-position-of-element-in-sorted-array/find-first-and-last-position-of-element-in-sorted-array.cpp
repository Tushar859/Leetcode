class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==target){
                ans.push_back(i);
                
            }
            

        }
        if(ans.empty()){
            return {-1,-1};
        }
        else{
            return {ans.front(),ans.back()};
        }
        
    }
};