class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
   int start = 0, end = 0;
    double sum = 0;
    double maxSum = INT_MIN;

while (end < nums.size()) {

    sum += nums[end];

    // Window k se badi ho gayi
    while (end - start + 1 > k) {
        sum -= nums[start];
        start++;
    }

    // Window exactly k ki hai
    if (end - start + 1 == k) {
        maxSum = max(maxSum, sum);
    }

    end++;
}

return maxSum / k;
        
    }
};