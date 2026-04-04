class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product=1;
        int start=0;
        int end=0;
        int n=nums.size();
        int count=0;
        if(k<=1){
            return 0;
        }

        while(end<n){
            product*=nums[end];
            while(product>=k){
          
   product/=nums[start];
                start++;

                
             
            }
            count+=end-start+1;
            end++;
        }
        return count;
    }
};