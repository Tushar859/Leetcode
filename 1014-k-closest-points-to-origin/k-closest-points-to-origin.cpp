class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         vector<vector<int>>temp;
      
        priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> p;
        for(int i=0;i<points.size();i++){
            int v1=points[i][0]*points[i][0];
            int v2=points[i][1]*points[i][1];
            double sum=sqrt(v1+v2);
            p.push(make_pair(sum, i));



        }
        pair<double,int>ele;
        int i;
        while(k){
             ele=p.top();
             p.pop();
             i=ele.second;
             temp.push_back({points[i][0],points[i][1]});
             k--;
        }

        return temp;

    }
};