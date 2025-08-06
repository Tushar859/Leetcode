class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> feq;
        for(int i =0;i<nums.size();i++){
           feq[nums[i]]++;  

        }
        for(auto x : feq){
            if(x.second>1){
                ans = x.first;

            }

        }
        return ans;
    }
};