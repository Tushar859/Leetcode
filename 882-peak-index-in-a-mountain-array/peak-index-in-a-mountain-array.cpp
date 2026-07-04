class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
      int ans =INT_MIN;
      int index =-1;
      for(int i=0;i<arr.size();i++){
        if(ans<=arr[i]){
            ans=arr[i];
             index=i;
        }
      }
    return index;
    }
};