class Solution {
public:
    int calPoints(vector<string>& op) {
        vector<int> val;
        for (int i = 0; i < op.size(); i++) {
            if (op[i] == "C") {
                val.pop_back();
            }
            else if (op[i] == "D") {
                val.push_back(2 * val.back());
            }
            else if (op[i] == "+") {
                int n = val.size();
                val.push_back(val[n-1] + val[n-2]);
            }
            else {
                val.push_back(stoi(op[i]));
            }
        }
        
        int sum = 0;
        for (int x : val){ 
             sum += x;} 
          
        return sum;
    }
};
