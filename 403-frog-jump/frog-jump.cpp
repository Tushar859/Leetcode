class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int pos,int k,vector<int>& stones,unordered_map<int,int>& mp){
        // last stone reached
        if(pos==stones.size()-1){
            return true;
        }

        if(dp[pos][k]!=-1){
            return dp[pos][k];
        }

        // k-1 , k, k+1 valid moves are allowerd
        int next=stones[pos]+(k-1);
        bool op1=false;
        if(k-1>0&&mp.count(next))
            op1=solve(mp[next],k-1,stones,mp);

        bool op2=false;
        next=stones[pos]+(k+1);
        if(mp.count(next))
            op2=solve(mp[next],k+1,stones,mp);

        bool op3=false;
        next=stones[pos]+k;
        if(mp.count(next))
            op3=solve(mp[next],k,stones,mp);

        return dp[pos][k]=op1||op2||op3;
    }

    bool canCross(vector<int>& stones){
        unordered_map<int,int>mp;

        for(int i=0;i<stones.size();i++){
            mp[stones[i]]=i;
        }

        if(stones[1]!=1){
            return false;
        }

        dp.assign(stones.size()+1,vector<int>(stones.size()+1,-1));

        return solve(1,1,stones,mp);
    }
};