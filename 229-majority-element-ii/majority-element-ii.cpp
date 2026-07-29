class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans ;
        int n = nums.size();
        unordered_map<int,int>freq;
        for(auto it : nums){
            freq[it]++;
        }
        for(auto fre : freq){
            if(fre.second>n/3){
                ans.push_back(fre.first);
            }
        }
    return ans;
    }
};