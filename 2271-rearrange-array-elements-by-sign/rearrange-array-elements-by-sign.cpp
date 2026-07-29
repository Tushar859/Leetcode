class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        vector<int> pos;
        vector<int> neg;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }
            else{
                pos.push_back(nums[i]);
            }
        }
    
     int x = 1;
     int y=0;
     int m = neg.size();
       ans.push_back(pos[0]);
     while(x<m || y<m){
        // alternate positivve neg dalna hain and first willbe pos
        if(ans.back()<0){
            cout<<"inside pos";
            ans.push_back(pos[x]);
            x++;
            
        }
         if(ans.back()>0){
              cout<<"inside neg";
            ans.push_back(neg[y]);
            y++;
        }

     }
    //  ans.push_back(neg[]);


return ans;


    }
};