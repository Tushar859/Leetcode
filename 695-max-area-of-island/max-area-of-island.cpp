class Solution {
public:
   int row[4]={1,-1,0,0};
   int col[4]={0,0,1,-1};
    bool valid(int i,int j,int r,int c){
        return i>=0 && i<r && j>=0 && j<c;
    }
   void dfs(int i,int j,int r,int c,vector<vector<int>>& grid , int &count,vector<vector<bool>>&visited){
           visited[i][j]=true;
           for(int k=0;k<4;k++){
            int new_i=row[k]+i;
            int new_j=col[k]+j;
            if(valid(new_i,new_j,r,c)&& grid[new_i][new_j]==1 && !visited[new_i][new_j]){
                visited[new_i][new_j]=true;
                count++;
                dfs(new_i,new_j,r,c,grid,count,visited);
            }
           }

   }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
         vector<vector<bool>>visited(r,vector<bool>(c));
            int maxi=0;

            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
              
                    if(grid[i][j]==1 &&!visited[i][j]){
                          int count=1;
                      dfs(i,j,r,c,grid,count,visited);
                       maxi=max(maxi, count);
                    }
                    
                }
               
            }
        
      
    

        return maxi;



    }
};