class Solution {
public:

    int row[4]={1,-1,0,0};
    int col[4]={0,0,1,-1};
    bool valid(int i,int j,int r, int c){
        return i>=0&& i<r && j>=0 && j<c;
            }

    void dfs(int i,int j,int r , int c,vector<vector<bool>>&visited, vector<vector<char>>&grid){
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            int new_i=row[k]+i;
            int new_j=col[k]+j;
            if(valid(new_i, new_j, r,c) && !visited[new_i][new_j] && grid[new_i][new_j]=='1'){
                dfs(new_i,new_j,r,c,visited,grid);
            }
        }
    }


    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<bool>>visited(r,vector<bool>(c));
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1' &&!visited[i][j]){
                    count++;
                    dfs(i,j,r,c ,visited,grid);
                }
            }
        }
        return count;
    }
};