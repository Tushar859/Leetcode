class Solution {
public:
    string reverseWords(string s) {
    vector<string>ans;
    string word = "";
    for(int i=0;i<s.size();i++){
    ///  jo space ni h usko dalo 
      if(s[i]!=' ')
          word+=s[i];
   
      if(s[i]==' '){
        if(word!=""){
        ans.push_back(word);
        word = "";
      }
      }
    }
    if(word != "")
    ans.push_back(word);

 reverse(ans.begin(),ans.end());

 string str;
 for(auto x : ans){
    str+=x;
    str+=" ";
 }
 // last mein jo space aa rha usko htaa rhe hain
 str.pop_back();
 return str;
    }

};