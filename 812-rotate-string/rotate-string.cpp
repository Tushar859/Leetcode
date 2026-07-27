class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        // last ch leke usko suru meijn daal rhe agr original string bn ja rhi to return true   else  return false;
        while(n!=0){
            char ch  = goal.back();
            goal.pop_back();
            goal.insert(goal.begin(),ch);
            if(goal == s){
                return true;
            }
            n--;
        }
        return false;
    }
};