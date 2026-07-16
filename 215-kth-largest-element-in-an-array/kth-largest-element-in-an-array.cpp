class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int> minHeap; 
   // priority_queue<int, vector<int>, greater<int>> minHeap;  
    for(int i=0;i<nums.size();i++){
        minHeap.push(nums[i]);
    }
    while(k>1){
        minHeap.pop();
        k--;
    }
    return minHeap.top();


// 123456  
// 654321
  }
};