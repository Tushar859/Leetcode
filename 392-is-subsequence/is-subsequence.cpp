class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int i, int j, string &s, string &t) {

        if(i == s.size()) {
            return true;
        }

        if(j == t.size()) {
            return false;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        bool tk = 0;

        if(s[i] == t[j]) {
            tk = solve(i+1, j+1, s, t);
        }

        bool nt = solve(i, j+1, s, t);

        return dp[i][j] = (tk || nt);
    }

    bool isSubsequence(string s, string t) {

        int n = s.size();
        int m = t.size();

        dp.assign(n+1, vector<int>(m+1, -1));

        return solve(0, 0, s, t);
    }
};