class Solution {
public:
     bool valid(int i,int j,int r, int c){
        return i>=0 && i<r && j>=0 && j<c;
     }

    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>>pq;
        int r=grid.size();
        int c=grid[0].size();
        //boundary top
        for(int i=0;i<c;i++){
            if(grid[0][i]==1){
                pq.push({0,i});
                grid[0][i]=0;
            }
            if(grid[r-1][i]){
                pq.push({r-1,i});
                grid[r-1][i]=0;
            }
        }

        for(int i=1;i<r-1;i++){
          if(grid[i][0]==1){
            pq.push({i,0});
            grid[i][0]=0;
          }
          if(grid[i][c-1]==1){
            pq.push({i,c-1});
            grid[i][c-1]=0;
          }
        }
        int row[4]={1,-1,0,0};
        int col[4]={0,0,1,-1};

        while(!pq.empty()){
            int i=pq.front().first;
            int j=pq.front().second;
            pq.pop();
            for(int k=0;k<4;k++){
                int new_i=row[k]+i;
                int new_j=col[k]+j;
                if(valid(new_i,new_j,r,c) && grid[new_i][new_j]==1){
                   pq.push({new_i,new_j});
                   grid[new_i][new_j]=0;
                }
            }
        }

       int count=0;
       
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
             if(grid[i][j]==1){
                count++;
             }
            }
        }



        return count;
        


        // down
    
    }
};