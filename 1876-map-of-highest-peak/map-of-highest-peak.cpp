class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>>dist(m,vector<int>(n,0));
        vector<vector<int>>visited(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
               q.push({{i,j},0});
               visited[i][j]=1;


                }
            }
 
        }

            int delrow[]={-1,0,0,1};
            int delcol[]={0,1,-1,0};

            while(!q.empty()){
                int row=q.front().first.first;
                int col=q.front().first.second;
                int step=q.front().second;
                q.pop();
                dist[row][col]=step;
                for(int i=0;i<4;i++){
                   int nrow=row+delrow[i];
                   int ncol=col+delcol[i];


                   if(nrow>=0 && nrow<m && ncol>=0 && ncol<n){
                      if(visited[nrow][ncol]==0){
                        visited[nrow][ncol]=1;
                        q.push({{nrow,ncol},step+1});
                      }
                      else{
                        int val=step+1;
                       dist[nrow][ncol]=min(dist[nrow][ncol],val);
                      }



                   }
                }

            }


        return dist;
    }
};