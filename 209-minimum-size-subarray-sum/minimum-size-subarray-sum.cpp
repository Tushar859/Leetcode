class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int total=INT_MAX;
        int sum=0;
        int start=0;
        int end=0;
        int n=nums.size();
        while(end<n){
            sum+=nums[end];//add kr rahe numbers ko

              while(sum>=target){
                total=min(total,end-start+1);
                sum-=nums[start];
                start++;
              }


            end++;
        }

        if(total==INT_MAX){
            return 0;
        }
        else{
            return total;
        }
    }
};