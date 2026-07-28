class Solution {
public:
    string frequencySort(string s) {
        string op="";
       map<char,int>freq;
       for(int i=0;i<s.length();i++){
          freq[s[i]]++;
       } 

       priority_queue<pair<int,char>>ans;
       for(auto x : freq){
           ans.push({x.second , x.first});
       }
    
       while(!ans.empty()){
          int count = ans.top().first;
          char ch = ans.top().second;
            ans.pop();
         while(count!=0){
            op+=ch;
            count--;
         }

       }
        return op;
       
    }
};