class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int large=0;
        int addition=0;
        for(int i=0;i<gain.size();i++){
            addition+=gain[i];
            large=max(large,addition);
        }

        return large;
    }
};