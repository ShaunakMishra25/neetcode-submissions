class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> newNums(nums.begin(), nums.end());
        int longest = 0;

        for(int num : newNums){
            if(newNums.find(num - 1) == newNums.end()){
                int curr = num;
                int currStreak = 1;

                while(newNums.find(curr + 1) != newNums.end()){
                    curr++; currStreak++;
                }

                longest = std::max(longest, currStreak);

            }
        }

        return longest;
    }
};