class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2]; // initial sum
        
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                // Update closest sum if needed
                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }
                
                if (sum < target) {
                    left++; // need a bigger sum
                } else if (sum > target) {
                    right--; // need a smaller sum
                } else {
                    return sum; // exact match
                }
            }
        }
        
        return closestSum;
    }
};
