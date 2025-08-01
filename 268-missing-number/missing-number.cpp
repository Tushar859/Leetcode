class Solution {
public:
    int missingNumber(vector<int>& nums) {
             int max=0;
            sort(nums.begin(), nums.end());
            max=nums.size();
           
            vector<int> ans;
            for(int j=0;j<=max;j++){
               ans.push_back(j);
            }
          int i =0;
          int miss=0;
            for(int j=0;j<ans.size();j++){
                if( i<nums.size()&& ans[j]==nums[i]){
                    i++;
                }
               else{
                    miss=ans[j];
                  break;
                }

                
            }
           

           return miss; 
        
     
    }
};