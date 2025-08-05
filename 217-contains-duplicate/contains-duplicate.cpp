class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> feq;
        for(int i=0;i<nums.size();i++){
            feq[nums[i]]++;  
        }
       
        for(auto x: feq){
            if(x.second>=2){
                return true;
            }
        }
        return false;
    }
};