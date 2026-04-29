class Solution {
public:
   int atleastk(vector<int>&nums, int k, int total){
    int start=0;
    int end=0;
    int n=nums.size();
    int count=0;
    unordered_map<int,int>f;
    while(end<n){
        f[nums[end]]++;
        if(f[nums[end]]==1){
            count++;
        }
        while(count==k){
            f[nums[start]]--;
            total+=n-end;
            if(f[nums[start]]==0){
                count--;
            }
            start++;
        }
        end++;
    }
    return total;
   }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //atleastk, atleast k+1 additon;

       int total1= atleastk(nums,k,0);
        int total2= atleastk(nums,k+1,0);
        return total1-total2;

    }
};