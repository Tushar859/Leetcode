class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
   int n = nums.size();
   int end =0,start=0;
   long long sum =0;
   long long maxi = 0;
   unordered_map<int,int>m;
    while(end<n){
    // freq count kr rhe h
     sum+=nums[end];
    m[nums[end]]++;
   
       
    
    while(m[nums[end]]>1){
        sum-=nums[start];
        // freq ghtao
        m[nums[start]]--;
        start++;
    }
    // size k se bda hua to ghtayenge
    while(end-start+1>k){
        sum-=nums[start];
        // freq bhi htao uss no ki
         m[nums[start]]--;
        start++;
    }
    if(end-start+1==k){
        maxi=max(sum,maxi);

    }


   end++;
    }


 
 return maxi;
    }
};