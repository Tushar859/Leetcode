

class Solution {
public:
 
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
      vector<int>count;
      for(int i=0;i<messages.size();i++){
        int c=1;
        string word=messages[i];
        for(int j=0;j<word.length();j++){
             if(word[j]==' '){
                c++;
             }
        }

        count.push_back(c);
      } 

           int n=senders.size();
           unordered_map<string,int>freq;
           for(int i=0;i<n;i++){

            freq[senders[i]]+=count[i];

           }
        priority_queue<pair<int,string>>p;
        for(auto it:freq){
            p.push({it.second,it.first});
        }
        string ans="";
        pair<int,string>element;
        if(!p.empty()){
          element=p.top();
          ans+=element.second;
          
        }


        return ans;



    }
};