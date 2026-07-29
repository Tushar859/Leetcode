class Solution {
public:
    void wiggleSort(vector<int>& nums) {
    int n = nums.size();
    vector<int>ans(n);
    sort(nums.begin(),nums.end());
     int i=1;
     int j = n-1;
     while(i<n){
        ans[i]=nums[j];
        i+=2;
        j--;
     } 
     i=0;
      while(i<n){
        ans[i]=nums[j];
        i+=2;
        j--;
     } 
    nums = ans;

    }
};