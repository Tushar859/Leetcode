class Solution {
public:
   
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
         string str = words[i];
            string temp = str;
          reverse(temp.begin(),temp.end());
          
          if(str == temp){
          return str;
          } 
        }
        return "";
    }
};