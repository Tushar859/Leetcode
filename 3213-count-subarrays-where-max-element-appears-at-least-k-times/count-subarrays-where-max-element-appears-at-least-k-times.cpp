class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }

        long long total=0;
        int count=0, start=0,end=0;
        while(end<n){
            if(nums[end]==maxi){
                count++;
            }


            while(count==k){
                total+=n-end;
                if(nums[start]==maxi){
                    count--;
                }
                start++;
            }


            end++;
        }

        return total;
    }
};