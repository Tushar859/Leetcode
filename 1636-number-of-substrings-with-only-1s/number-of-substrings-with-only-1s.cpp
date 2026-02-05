class Solution {
public:
    int numSub(string s) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        long long len = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                len++;        
                ans = (ans + len) % MOD;
            } else {
                len = 0;      
            }
        }

        return ans;
    }
};