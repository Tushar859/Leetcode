class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > p;  

        int minimum;
        int maximum = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++){
            if(!nums[i].empty()){   
                p.push(make_pair(nums[i][0], make_pair(i,0)));
                maximum = max(maximum, nums[i][0]);
            }
        }

        minimum = p.top().first;
        vector<int> ans(2);
        ans[0] = minimum;
        ans[1] = maximum;

        pair<int,pair<int,int>> Element;
        int row;
        int col;
        int ele;

        while(p.size() == nums.size()){
            Element = p.top();
            p.pop();

            ele = Element.first;
            row = Element.second.first;
            col = Element.second.second;

            if(col + 1 < nums[row].size()){
                col++;  

                p.push(make_pair(nums[row][col], make_pair(row, col)));
                maximum = max(maximum, nums[row][col]);

                minimum = p.top().first;

                if(maximum - minimum < ans[1] - ans[0]){
                    ans[1] = maximum;
                    ans[0] = minimum;
                }
            }
        }

        return ans;
    }
};