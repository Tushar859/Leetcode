class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // handle k > n
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            ans[i] = nums[(i - k + n) % n];  
        }

        for (int i = 0; i < n; i++) {
            nums[i] = ans[i];
        }
    }
};
