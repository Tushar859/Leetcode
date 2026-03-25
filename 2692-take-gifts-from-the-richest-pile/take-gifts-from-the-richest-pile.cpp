class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long>p;
        for(long long i=0;i<gifts.size();i++){
            p.push(gifts[i]);
        }
        int c=p.top();
        if(c==1){
            return gifts.size();
        }
        while(k){
            int value=p.top();
            p.pop();
           
            int sqr=sqrt(value);
            if(sqr>0){
             p.push(sqr);
            }
         

            
            k--;
           

        }
        long long  ans=0;
        while(!p.empty()){
            ans+=p.top();
            p.pop();
        }

        return ans;


    }
};