class Solution {
public:
    int countHomogenous(string s) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        long long len = 0;

        for (int i = 0; i < s.size(); i++) {
            if (i == 0 || s[i] == s[i - 1]) {
                len++;
            } else {
                len = 1;
            }
            ans = (ans + len) % MOD;
        }

        return ans;
    }
};