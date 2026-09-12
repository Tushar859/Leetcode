class Solution {
public:
    bool solve(int index,int k,vector<int>& stones,unordered_map<int,int>& mp,vector<vector<int>>& dp){
        // last stone reached
        if(index==stones.size()-1){
            return true;
        }

        if(dp[index][k]!=-1)
            return dp[index][k];

        // k-1 , k, k+1 valid moves are allowerd
        int next=stones[index]+(k-1);
        bool op1=false;
        if(k-1>0&&mp.count(next))
            op1=solve(mp[next],k-1,stones,mp,dp);

        bool op2=false;
        next=stones[index]+(k+1);
        if(mp.count(next))
            op2=solve(mp[next],k+1,stones,mp,dp);

        bool op3=false;
        next=stones[index]+k;
        if(mp.count(next))
            op3=solve(mp[next],k,stones,mp,dp);

        return dp[index][k]=op1||op2||op3;
    }

    bool canCross(vector<int>& stones){
        unordered_map<int,int>mp;
        for(int i=0;i<stones.size();i++){
            mp[stones[i]]=i;
        }

        if(stones[1]!=1)
            return false;

        vector<vector<int>>dp(stones.size(),vector<int>(stones.size()+1,-1));

        return solve(1,1,stones,mp,dp);
    }
};