class Solution {
public:
  
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));
                }
            }
        }

        int count=0;
        while(!q.empty()){

           
            int size=q.size();

            while(size--){
                            int i=q.front().first;
            int j=q.front().second;
            q.pop();
                //up

                if(i-1>=0 && i<r && j>=0 && j<c){
                    if(grid[i-1][j]==1){
                        grid[i-1][j]=2;
                        q.push(make_pair(i-1,j));
                    }
                }
                //left
                 if(i>=0 && i<r && j-1>=0 && j<c){
                    if(grid[i][j-1]==1){
                        grid[i][j-1]=2;
                        q.push(make_pair(i,j-1));
                    }
                }
                //right
                 if(i>=0 && i<r && j>=0 && j+1<c){
                    if(grid[i][j+1]==1){
                        grid[i][j+1]=2;
                        q.push(make_pair(i,j+1));
                    }
                }
                //down
                 if(i>=0 && i+1<r && j>=0 && j<c){
                    if(grid[i+1][j]==1){
                        grid[i+1][j]=2;
                        q.push(make_pair(i+1,j));
                    }
                }
            }
             count++;
        }

      

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
          if(count==0){
            return 0;
        }

        return count-1;
    }
};