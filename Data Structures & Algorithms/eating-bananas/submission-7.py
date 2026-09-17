class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        low, high = 1, max(piles)
        ans = high

        while low <= high:
            mid = (low + high) // 2

            totalTime = 0

            for i in piles:
                totalTime += (i + mid - 1) // mid
            
            if totalTime <= h :
                ans = mid
                high = mid - 1
                
            else:
                low = mid + 1
            
        return ans