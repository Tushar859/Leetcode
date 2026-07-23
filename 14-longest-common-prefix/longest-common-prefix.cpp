class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        bool flag = false;
        for (int idx = 0; idx < strs[0].size(); idx++) {
        
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][idx] != strs[0][idx]){
                        flag = true;
                      // return ans;
                          break;
                }
                
            }
            if(flag){
                break;
            }
            else{
                 ans += strs[0][idx];
            }
           
        }
        
        return ans;
    }
};