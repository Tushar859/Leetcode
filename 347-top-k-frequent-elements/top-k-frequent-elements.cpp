class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> fre;
        for (int i = 0; i < nums.size(); i++) {
            fre[nums[i]]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto [num, freq] : fre) {
            pq.push({freq, num});
        }

        vector<int> ans;
        while (k-- && !pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
