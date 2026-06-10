class Solution {
public:

  void subset(vector<int>&nums,vector<vector<int>>&ans,vector<int>&number,int index){
          if(index==nums.size()){
            if(number.size()!=0){
                ans.push_back(number);
            }
            return ;
          }
          number.push_back(nums[index]);
          subset(nums,ans,number,index+1);
          number.pop_back();
          subset(nums,ans,number,index+1);



  }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        ans.push_back({});
        vector<int>number;
        int num=0;
        int index=0;
        subset(nums,ans,number, index);
        set<vector<int>>st;
       for(auto& v:ans){
        st.insert(v);
       }

       vector<vector<int>>uniques(st.begin(),st.end());
       return uniques;
        
    }
};