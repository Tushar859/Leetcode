class Solution {
public:
  
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n =nums.size(); 
        vector<int>lds(n,1);
        vector<int>parent(n,-1);
        int idx =0;
        int len=0;
        for(int i=1;i<n;i++){
            for(int j =0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(lds[i]<lds[j]+1){
                        lds[i]= lds[j]+1;
                        parent[i]=j;
                    }
                }
            }
            if(len<lds[i]){
                len = lds[i];
                idx = i;
            }
        }
      vector<int>ans;
      while(idx!=-1){
        ans.push_back(nums[idx]);
        idx = parent[idx];
      }
     sort(ans.begin(),ans.end());
     return ans;
        
    }
};