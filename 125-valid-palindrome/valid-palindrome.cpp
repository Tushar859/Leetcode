class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
        string clear="";

        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if ((ch >= 'A' && ch <= 'Z') || 
              (ch >= 'a' && ch <= 'z') || 
                (ch >= '0' && ch <= '9')){

                clear+=tolower(ch);
                
            }

        }
        ans=clear;
        reverse(clear.begin(), clear.end());
        if(ans == clear){
            return true;
        }
        else{
            return false;
        }


        
    }
};