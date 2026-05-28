class Solution {
public:

    bool valid(int i,int j, int r, int c ){
        return i>=0 && i<r && j>=0 && j<c;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int r=image.size();
        int c=image[0].size();

        int original=image[sr][sc];

    
        if(original==color) return image;

        int row[4]={0,0,-1,1};
        int col[4]={1,-1,0,0};

        queue<pair<int,int>> qp;

        qp.push({sr,sc});
        image[sr][sc]=color;

        while(!qp.empty()){

            int i=qp.front().first;
            int j=qp.front().second;
            qp.pop();

            for(int k=0;k<4;k++){

                int new_i=i+row[k];
                int new_j=j+col[k];

                if(valid(new_i,new_j,r,c) &&
                   image[new_i][new_j]==original){

                    image[new_i][new_j]=color;
                    qp.push({new_i,new_j});
                }
            }
        }

        return image;
    }
};