class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> sorted;
        map<int,int> freq;
        for(int i =0;i<nums.size();i++){
            // yha hum freq count kr liye sare number ki
            freq[nums[i]]++;
        }
        for(auto x : freq){
            while(x.second--){
               sorted.push_back(x.first);
            }
           
        }
            nums = sorted;
    }
};