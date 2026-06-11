class Solution {
public:

    void happy(string s, int open, int close, vector<string>& ans) {
        if (open == 0 && close == 0) {
            ans.push_back(s);
            return;
        }

        if (open > 0) {
            happy(s + '(', open - 1, close, ans);
        }

        if (close > open) {
            happy(s + ')', open, close - 1, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        happy("", n, n, ans);
        return ans;
    }
};