class Solution {
public:
    void rev(int start , int end ,vector<int>& nums ){
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }

    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size()-1;
        k = k % nums.size();
       
        rev(n-k+1,n,nums);
        rev(0,n-k,nums);
        rev(0 , n , nums);

    }
};