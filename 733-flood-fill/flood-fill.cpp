class Solution {
public:
     int R;
     int C;
    int row[4] ={-1,0,0,1};
    int  col[4] ={0,-1,1,0};
     bool valid(int r , int c){
      return (r>=0&&r<R&&c>=0&&c<C);
     }
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        if(img[sr][sc]==color){
            return img;
        }
        int ori =img[sr][sc];
        img[sr][sc] = color;
        q.push({sr,sc});
        R = img.size();
        C= img[0].size();
        while(!q.empty()){
            int i= q.front().first;
            int j= q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int new_i = i + row[k];
                int new_j = j + col[k];
             if(valid(new_i,new_j) && img[new_i][new_j]==ori){
                  img[new_i][new_j]=color;
                  q.push({new_i,new_j});
             }
            }
         
        }
    return img;
    }
};