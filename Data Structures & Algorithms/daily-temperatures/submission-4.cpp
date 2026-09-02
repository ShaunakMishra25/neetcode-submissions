class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        std::stack<int> s;
        vector<int> result(n, 0);
        for(int i = 0; i < n; i++) {
            while(!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int index = s.top();
                s.pop();
                result[index] = i - index; 
            }
            s.push(i);
        }
        
        return result;
    }
};
