class Compare {
public:
    bool operator()(pair<int,string>& a, pair<int,string>& b) {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int> freq;
        for(string w : words){
            freq[w]++;
        }

        priority_queue<pair<int,string>, vector<pair<int,string>>, Compare> p;

        for(auto it : freq){
            p.push({it.second, it.first});
        }

        vector<string> ans;

        while(k-- && !p.empty()){
            ans.push_back(p.top().second);
            p.pop();
        }

        return ans;
    }
};