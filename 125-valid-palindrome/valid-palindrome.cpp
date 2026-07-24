class Solution {
public:
    bool isPalindrome(string& s) {
        for (auto &ch : s) {
            ch = tolower(ch);
        }
        
        string ans;
        for (auto t : s) {
            if (t >= 'a' && t <= 'z' ) {
                // valid alphanumeric chat
                ans += t;
            }
            if(t>='0'&&t<='9'){
                 ans += t;
                
            }
        }
      
        int start = 0;
        int end = ans.size() - 1;
        while (start <= end) {
            if (ans[start] != ans[end]) {
                return false;
                break;
            }
            start++;
            end--;
        }
        // yha tak aa gye to matched
        return true;
    }
};