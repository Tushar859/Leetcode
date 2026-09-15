class Solution {
public:

    vector<vector<int>> dp;

    bool solve(int n, int m, string &s, string &p) {

        if(m == 0 && n == 0) {
            return true;
        }

        if(m == 0) {
            return false;
        }

        if(n == 0) {
            for(int i = 0; i < m; i++) {
                if(p[i] != '*') {
                    return false;
                }
            }
            return true;
        }

        // already calculated
        if(dp[n][m] != -1) {
            return dp[n][m];
        }

        // match or ?
        if(s[n-1] == p[m-1] || p[m-1] == '?') {
            return dp[n][m] = solve(n-1, m-1, s, p);
        }

        // *
        else if(p[m-1] == '*') {

            // star ko empty maan lo
            bool a = solve(n, m-1, s, p);

            // star ek character match kare
            bool b = solve(n-1, m, s, p);

            return dp[n][m] = a || b;
        }

        else {
            return dp[n][m] = false;
        }
    }

    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        dp.resize(n+1, vector<int>(m+1, -1));

        return solve(n, m, s, p);
    }
};