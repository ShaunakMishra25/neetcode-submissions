class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;

        for(const string& str : strs) {
            string sortedStr = str;    
            sort(sortedStr.begin(), sortedStr.end());
            res[sortedStr].push_back(str);
        }   
        vector<vector<string>> result;
        for(auto& pair : res) {
            result.push_back(pair.second);
        }
        return result;
    }
};
