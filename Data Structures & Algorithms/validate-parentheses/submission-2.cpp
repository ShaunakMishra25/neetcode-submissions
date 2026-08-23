class Solution {
public:
    bool isValid(string s) {
        string stack = "";
        stack.reserve(s.length()); 

        for (char c : s) {
            if (c == ')' || c == ']' || c == '}') {
                if (stack.empty()) return false;
                
                char top = stack.back();
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    return false;
                }
                stack.pop_back(); 
            } else {
                stack.push_back(c); 
            }
        }
        return stack.empty();
    }
};
