class Solution {
public:

    void letter(string s, string si, vector<string>& ans, int index) {

        if (index == s.length()) {
            ans.push_back(si);
            return;
        }

        char ch = s[index];

        if (isdigit(ch)) {
            si += ch;
            letter(s, si, ans, index + 1);
        }
        else {
            si += tolower(ch);
            letter(s, si, ans, index + 1);

            si.pop_back();

            si += toupper(ch);
            letter(s, si, ans, index + 1);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string si = "";

        letter(s, si, ans, 0);

        return ans;
    }
};