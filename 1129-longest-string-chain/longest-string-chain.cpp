class Solution {
public:
    bool isComp(string &w1 , string &w2){
        if(w1.size()!=w2.size()+1){
            return false;
        }
      int i =0;
      int j =0;
      while(i<w1.size()){
        if(w1[i]==w2[j]){
            i++;
            j++;
        }
        else{
            i++;
        }
      }
     if(i==w1.size()&&j==w2.size()){
        return true;
     }
     else{
        return false;
     }
    }
    bool static comp(string &s1 ,string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
      int n = words.size();
      vector<int>lis(n,1);
      int res = 1;
      sort(words.begin(),words.end(),comp);
      for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(isComp(words[i],words[j])){
               if(lis[i]<lis[j]+1){
                lis[i]=lis[j]+1;
               }
            }
        }
        res = max(lis[i],res);
      }
    return res;
    }
};