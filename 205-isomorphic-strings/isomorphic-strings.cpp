class Solution {
public:
    bool isIsomorphic(string s, string t) {
     map<char,char>m1;
     map<char,char>m2;
      if(s.length()!= t.length()){
        return false;
      }
      // s->t ki mapping
    for(int i=0;i<s.size();i++){
            if(m1.find(s[i])!=m1.end()){
                // char mil gya  , mapping check kro ki s se t hain ya nhi
                 if(m1[s[i]]!=t[i]){
                    return false;
                 }
                
            }
            else{
                // map me nhi hain usko addd krdo
                m1[s[i]] = t[i];
            }
    }
  // t -> s ki mapping check karte hain
  for(int i=0;i<s.size();i++){
      if(m2.find(t[i])!=m2.end()){
          if(m2[t[i]]!=s[i]){
                    return false;
                 }
                
            }
            else{
                // map me nhi hain usko addd krdo
                m2[t[i]] = s[i];
            }
      }
    return true;

  }















};