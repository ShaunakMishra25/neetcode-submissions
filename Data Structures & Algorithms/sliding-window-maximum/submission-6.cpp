class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dequeue; 
        vector<int> result;
        int left = 0;
        
        for( int right = 0; right<nums.size(); right++)
        {
            while(dequeue.size() != 0 && nums[right]>nums[dequeue.back()])
                dequeue.pop_back();
            dequeue.push_back(right);

            if(right - left + 1 == k)
            {
                result.push_back(nums[dequeue.front()]);
                if(dequeue.front() == left)
                    dequeue.pop_front();
                left++;
            }
        }

        return result;
    }
};
