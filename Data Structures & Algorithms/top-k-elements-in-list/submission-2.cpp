class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::array<int, 20001> freq{};

        for(int num : nums){
            freq[num + 1000]++;
        }

        std::vector<std::vector<int>> buckets(nums.size() + 1);

        for(int i = 0; i < 2001; i++){
            if(freq[i] > 0){
                buckets[freq[i]].push_back(i - 1000);
            }
        }

        std::vector<int> res;
        res.reserve(k);

        for(int i = buckets.size() - 1; i >= 0; i--){
            for(int num : buckets[i]){
                res.push_back(num);
                if(res.size() == k) return res;
            }
        }

        return res;
    }
};
