class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int count=0;
        int start=0;
        int end=0;
        int ans=INT_MIN;
        while(end<nums.size()){
            m[nums[end]]++;
            while(m[nums[end]]>k && start<=end){
            
                m[nums[start]]--;
                start++;
            }
            count=end-start+1;
            ans=max(ans,count);
            end++;
        }

        return ans;
    }
};