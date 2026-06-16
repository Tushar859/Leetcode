class Solution {
public:
    string processStr(string s) {
        string ans="";
        
        for(int i=0;i<s.length();i++){
            if(s[i]!='*'&&s[i]!='#'&&s[i]!='%'){
            ans+=s[i];
            }
            else if(s[i]=='*'){
                if(ans.length()>0){
                   ans.pop_back();
                }
            
            }
            else if(s[i]=='#'){
                if(ans.length()>0){
                 ans+=ans;
                }
                
            }
            else{
                
                reverse(ans.begin(),ans.end());
                  
            }
  
        }


        return ans;
    }
};