class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indegree(n+1,0);
        int ans=-1;

        if(trust.size()==0  && n!=1){
            return -1;
        }
        if(trust.size()==0 && n==1){
            return 1;
        }


        for(int i=0;i<trust.size();i++){
            int u=trust[i][0];
            int v=trust[i][1];
            //u trust v
            indegree[v]++;
            if(indegree[v]==n-1){
                ans=v;
            }


        }

        for(int i=0;i<trust.size();i++){
            if(ans== trust[i][0]){
                return -1;
            }
        }

      


        return ans;
    }
};