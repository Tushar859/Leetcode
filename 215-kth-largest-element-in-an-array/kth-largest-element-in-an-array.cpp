class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int> maxHeap; 
   // ye max heap bnayega means largest element  top pe rhega 
    for(int i=0;i<nums.size();i++){
        maxHeap.push(nums[i]);
    }
 // kth largest yese nikal lenge
    while(k>1){
        maxHeap.pop();
        k--;
    }
    return maxHeap.top();


// 123456  
// 654321
  }
};