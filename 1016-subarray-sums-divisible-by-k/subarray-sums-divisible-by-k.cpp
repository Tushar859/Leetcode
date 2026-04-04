class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int>m;
        m[0]=1;
        int ps=0;
        int r=0;
        int total=0;
        for(int i=0;i<nums.size();i++){
            ps+=nums[i];
                 r=ps%k;
                 if(r<0){
                    r+=k;
                 }

                 if(m.count(r)){
                    total+=m[r];
                    m[r]++;
                 }
                 else{
                     m[r]=1;
                 }
        }

        return total;
    }
};