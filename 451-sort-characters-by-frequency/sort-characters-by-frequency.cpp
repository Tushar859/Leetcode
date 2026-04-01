class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int> freq;
        
     
        for(int i = 0; i < s.length(); i++){
            freq[s[i]]++;
        }


        priority_queue<pair<int,char>> p;
        
        for(auto it : freq){
            p.push({it.second, it.first});
        }

        string ans = "";

        while(!p.empty()){
            int count = p.top().first;
            char ch = p.top().second;
            p.pop();

     
            while(count--){
                ans += ch;
            }
        }

        return ans;
    }
};