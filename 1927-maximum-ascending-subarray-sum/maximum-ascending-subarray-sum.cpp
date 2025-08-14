
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxv = nums[0];
        int sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                sum += nums[i]; // continue ascending
            } else {
                sum = nums[i]; // reset sum
            }
            maxv = max(maxv, sum);
        }

        return maxv;
    }
};
