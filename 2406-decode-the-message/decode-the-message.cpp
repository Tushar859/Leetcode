class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char,char>mp;
        char ch = 'a';
        for(int i=0;i<key.size();i++){
            if (key[i] == ' '){
              continue;
            }
               
            if(mp.find(key[i])==mp.end()){
                // char present ni hain crreate mapping
                mp[key[i]] = ch;
                ch++;
            }
        }
        
       /// now decode the msg
        for(int j=0;j<message.size();j++){
            if (message[j] == ' ')
                continue;
            message[j]= mp[message[j]];
        }
    return message;
    }
};