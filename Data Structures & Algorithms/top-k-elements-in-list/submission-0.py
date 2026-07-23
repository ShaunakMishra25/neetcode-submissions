from collections import Counter
import heapq
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        frq_map=Counter(nums)
        min_heap=[]

        for num, frq in frq_map.items():
            heapq.heappush(min_heap, (frq,num))
            if len(min_heap)>k:
                heapq.heappop(min_heap)
        return [num for frq, num in min_heap]