class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> st;

        for(auto& ch : tokens) {
            if (ch != "+" && ch != "-" && ch != "*" && ch != "/") { 
                st.push(stoi(ch)); 
                continue; 
            }

            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            if(ch == "+") {
                st.push(b + a);
            }
            if(ch == "-") {
                st.push(b - a);
            }
            if(ch == "*") {
                st.push(b * a);
            }
            if(ch == "/") {
                st.push(b / a);
            }
            
        } 

        if(st.empty()) return 0;
        return st.top();
    }
};
