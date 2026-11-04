class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low =0;
         long long high = num;
        while(low <=high){
             long long mid = (low+high)/2;
            if(mid*mid==num){
                // perfect dq
                return true;
            }
            if(mid*mid>num){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
    return false;
        
    }
};