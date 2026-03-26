class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      vector<int>ans;
      unordered_map<int,int>freq;
      for(int  num:nums){
        freq[num]++;
      } 
        priority_queue<pair<int,int>>pq;
        for(auto it:freq){
            pq.push({it.second,it.first});
        }

        while(k&&!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;

    }
};