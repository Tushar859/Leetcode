class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0;
        long long start = 0;
        long long end = 0;
        long long n = nums.size();
        long long ans = 0;

        if (k <= 1) return 0;

        while (end < n) {
            sum += nums[end];

            while (sum * (end - start + 1) >= k) {
                sum -= nums[start];
                start++;
            }


            ans += (end - start + 1);

            end++;
        }

        return ans;
    }
};