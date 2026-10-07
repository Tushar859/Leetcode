class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>Rhd(n);
        vector<int>lhd(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                Rhd[st.top()]=i;
                st.pop();
            }
          st.push(i);
        }
        while(!st.empty()){
            Rhd[st.top()]=n;
            st.pop();
        }
       for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>heights[i]){
                lhd[st.top()]=i;
                st.pop();
            }
          st.push(i);
        }
       while(!st.empty()){
            lhd[st.top()]=-1;
            st.pop();
        }
    int ans =0;
    for(int i=0;i<n;i++){
        ans = max(ans,heights[i]*(Rhd[i]-lhd[i]-1));
    }
  return ans;

    }
};