class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int n =s.size();
        for(int i=0;i<n;i++){
            if(i + 2 < n && s[i] == s[i + 1] && s[i + 1] == s[i + 2]){
                // same 3  ch to bs 2 daldo baki chhod
              ans.push_back(s[i]);
              ans.push_back(s[i+1]);
               //skip third  ch
             while (i + 1 < n && s[i] == s[i + 1]) {
                    i++;
                }
            }
            else{
                ans.push_back(s[i]);
            }
        }
     return ans;
    }
};