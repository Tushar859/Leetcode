class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int single = 0;
        int doub = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 10) {
                single += nums[i];
            } else {
                doub += nums[i];
            }
        }

        return single != doub;
    }
};