class Solution {
public:
    int strStr(string h, string n) {
        int ans=-1;
       
            if(h.find(n) == -1){
                return -1;
            }
            else{
            ans = h.find(n);
            }
     
   
    return ans;
    }
};