class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
         int n = nums.size();
        vector<int>lis(n,1);
        int res =1;// as single element lis hota hi h
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    lis[i]=max(lis[i],lis[j]+1);
                }
            }
           if(res<lis[i]){
              res = lis[i];
           }
        }   
        // int ans =0;    
        // for(int i=0;i<lis.size();i++){
        //      if(lis[i]>ans){
        //         ans = lis[i];
        //      }
        // }
        return res;
        
        
    }
};