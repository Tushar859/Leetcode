class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '(') {
                cnt++;
               if(cnt>1){
                 ans += ch;
               }
            }
            
            if (ch == ')') {
                cnt--;
                if (cnt > 0) {
                    ans += ch;
                }
            }
        }
    return ans;
    }
};