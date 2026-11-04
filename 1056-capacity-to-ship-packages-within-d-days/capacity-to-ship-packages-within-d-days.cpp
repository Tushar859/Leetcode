class Solution {
public:
    bool poss(int t,vector<int>& weights, int days){
        int day =1;
        // wei rep the curr load one the ship
        int wei =weights[0];
        for(int i=1;i<weights.size();i++){
            if(wei+weights[i]<=t){
                wei+=weights[i];
                // continue;
            }
            else{
                // jyada  hain
                day++;
                wei = weights[i];

            }
        }
     return day<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // min will be largest of the weights so that every elemet get shipped
        // high will be sum of all weights as it is the point from where
        // we can ship in one day
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans =0;
        while(low<=high){
            int mid = (low + high )/2;
            if(poss(mid,weights,days)){
                ans = mid;
                // shrink
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        // opp polarity concept 
        // we can also return theans variable
    return low;

    }
};