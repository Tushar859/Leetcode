class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int>p;
        for(int i=0;i<stones.size();i++){
            p.push(stones[i]);
        }
      
        
        while(p.size()>1){
            int value=p.top();
            p.pop();
            value-=p.top();
            p.pop();
            if(value!=0){
                p.push(value);
            }
        }
        return p.empty() ? 0 :p.top();

        
   

        
         
    }
};