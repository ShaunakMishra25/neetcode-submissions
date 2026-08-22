#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;

        while (i < j) { 
            int sum1 = numbers[i] + numbers[j];
            
            if (sum1 == target) return {i + 1, j + 1}; 
            
            if (sum1 < target) {
                i++; 
            } else {
                j--; 
            }
        }
        
        return {}; 
    }
};
