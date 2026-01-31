class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>ans;
        for(int i=0;i<s.length();i++){
            if(s.empty()){
                ans.push(s[i]);
            }
            else{
                if(!ans.empty()    && s[i]==')' && ans.top()=='('){
                    ans.pop();
                }
                else{
                   ans.push(s[i]);
                }
            }
        }

        int answer=ans.size();
        return answer;
    }
};