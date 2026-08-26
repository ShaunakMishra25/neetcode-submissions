class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        if(n==1) return {0};
        vector<int> result(n, 0);

        stack<int> st;
        st.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && temp[i] >= temp[st.top()]) st.pop();
            if(!st.empty()){
                result[i]=st.top()-i;
            }
            st.push(i);
        }

        return result;
    }
};
