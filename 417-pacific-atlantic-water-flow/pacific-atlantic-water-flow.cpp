class Solution {
public:

    bool valid(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m=heights.size();
        int n=heights[0].size();

        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));

        queue<pair<int,int>> pac;
        queue<pair<int,int>> atl;

        for(int i=0;i<n;i++){
            pac.push({0,i});
            pacific[0][i]=true;
        }

        for(int j=0;j<m;j++){
            pac.push({j,0});
            pacific[j][0]=true;
        }

        for(int i=0;i<m;i++){
            atl.push({i,n-1});
            atlantic[i][n-1]=true;
        }

        for(int j=0;j<n;j++){
            atl.push({m-1,j});
            atlantic[m-1][j]=true;
        }

        int row[4]={-1,1,0,0};
        int col[4]={0,0,-1,1};

        while(!pac.empty()){

            int i=pac.front().first;
            int j=pac.front().second;
            pac.pop();

            for(int k=0;k<4;k++){

                int new_i=row[k]+i;
                int new_j=col[k]+j;

                if(valid(new_i,new_j,m,n) &&
                   heights[new_i][new_j] >= heights[i][j] &&
                   !pacific[new_i][new_j]){

                    pac.push({new_i,new_j});
                    pacific[new_i][new_j]=true;
                }
            }
        }

        while(!atl.empty()){

            int i=atl.front().first;
            int j=atl.front().second;
            atl.pop();

            for(int k=0;k<4;k++){

                int new_i=row[k]+i;
                int new_j=col[k]+j;

                if(valid(new_i,new_j,m,n) &&
                   heights[new_i][new_j] >= heights[i][j] &&
                   !atlantic[new_i][new_j]){

                    atl.push({new_i,new_j});
                    atlantic[new_i][new_j]=true;
                }
            }
        }

        vector<vector<int>> ans;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};