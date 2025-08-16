class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i =0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        int ans =0;
            for(auto t: freq){
            if(t.second>nums.size()/2){
                ans=t.first;
            }
        }
        return ans;
        
    }
};