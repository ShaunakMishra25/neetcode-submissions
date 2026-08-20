#include <vector>
#include <algorithm>

class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        if (nums.empty()) return false;
        
        // 1. Sort the vector in-place. 
        // Elements are now perfectly contiguous in memory (excellent cache locality).
        std::sort(nums.begin(), nums.end());
        
        // 2. Scan linearly. The CPU prefetcher will load this instantly into L1 cache.
        for (size_t i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};
