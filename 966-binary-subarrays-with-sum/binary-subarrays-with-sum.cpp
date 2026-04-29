class Solution {
public:
      int atmostk(vector<int>&nums, int goal, int total){
            if (goal < 0) return 0;
        int start=0;
        int end=0;
        int sum=0;
        while(end<nums.size()){
            sum+=nums[end];
            while(sum>goal){
                sum-=nums[start];
                start++;
            }
            total+=end-start+1;
            end++;
        }
        return total;
      }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //atmostk -atmostk-1;
      int t1=atmostk(nums,goal,0);
      int t2=atmostk(nums,goal-1,0);
      return t1-t2;

    }
};