class Solution {
public:
    void sortColors(vector<int>& nums) {
    int cntzero =0;
    int cntone=0;
    int cnttwo=0;
    for(int i=0;i<nums.size();i++){
     if(nums[i]==0){
        cntzero++;
     }
     else if(nums[i]==1){
        cntone++;
     }
     else{
        cnttwo++;
     }
    }
    vector<int> ans;
    
    while(cntzero--){
        ans.push_back(0);
    }
    while(cntone--){
    ans.push_back(1);}
 
    while(cnttwo--){
         ans.push_back(2);
    }
 
  nums = ans;

    }



    
};