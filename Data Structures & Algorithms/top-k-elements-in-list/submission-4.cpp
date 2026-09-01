class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> count;
        for(int i : nums) {
            count[i]++;
        }

        priority_queue<pair<int, int>> pq;

        for(auto& entry : count) {
            pq.push({entry.second, entry.first});
        }

        vector<int> res;
        
        while(k > 0) {
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return res;
        
    }
};
