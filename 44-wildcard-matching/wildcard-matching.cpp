class Solution {
public:

    vector<vector<int>> dp;

    bool solve(int n, int m, string &s, string &p) {

        // dono khatam
        if(n == 0 && m == 0) {
            return true;
        }

        // pattern khatam but string baaki
        if(m == 0) {
            return false;
        }

        // string khatam but pattern baaki
        // sirf '*' hone chahiye
        if(n == 0) {
            for(int i = 0; i < m; i++) {
                if(p[i] != '*') {
                    return false;
                }
            }
            return true;
        }

        if(dp[n][m] != -1) {
            return dp[n][m];
        }

        // match
        if(s[n-1] == p[m-1] || p[m-1] == '?') {
            return dp[n][m] = solve(n-1, m-1, s, p);
        }

        // star
        else if(p[m-1] == '*') {

            // star ko empty lo
            // ya star se ek character match karao
            return dp[n][m] = solve(n, m-1, s, p) ||
                               solve(n-1, m, s, p);
        }

        // mismatch
        else {
            return dp[n][m] = false;
        }
    }

    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        dp.assign(n + 1, vector<int>(m + 1, -1));

        return solve(n, m, s, p);
    }
};