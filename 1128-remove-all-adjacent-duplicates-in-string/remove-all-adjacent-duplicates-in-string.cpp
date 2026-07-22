class Solution {
public:
    string removeDuplicates(string s) {
        string str ="";
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            // same upar 
            char curr = s[i];
            if(!st.empty()&&st.top()==curr){
                st.pop();
            }
            // diff niche
            else{
            st.push(curr);
            }

        }
        while (!st.empty()){
            char cur = st.top();
            str.push_back(cur);
            st.pop();
        }
        reverse(str.begin(),str.end());
       return str;

    }
 
};