class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> lis(n, 1);
        vector<int> cnt(n, 1);
        int maxLen = 1;

        // Find LIS length + count
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < i; j++) {

                if(nums[i] > nums[j]) {

                    // Better length found
                    if(lis[i] < lis[j] + 1) {
                        lis[i] = lis[j] + 1;
                        cnt[i] = cnt[j];
                    }

                    // Same maximum length found
                    else if(lis[i] == lis[j] + 1) {
                        cnt[i] += cnt[j];
                    }
                }
            }

            maxLen = max(maxLen, lis[i]);
        }

        // Count all LIS having maximum length
        int ans = 0;

        for(int i = 0; i < n; i++) {

            if(lis[i] == maxLen) {
                ans += cnt[i];
            }
        }

        return ans;
    }
};