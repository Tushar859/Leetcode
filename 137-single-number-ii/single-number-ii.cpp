class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i =0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        int ans =0;
            for(auto n: freq){
            if(n.second<2){
                ans=n.first;
            }
        }
        return ans;
        
    }
};