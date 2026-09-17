class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        low, high = 1, max(piles)
        ans = high

        while low <= high:
            mid = (low + high) // 2

            totalTime = self.calculateSum(piles, mid)
            
            if totalTime <= h :
                ans = mid
                high = mid - 1
                
            else:
                low = mid + 1
            
        return ans

    def calculateSum(self, piles, k):
        ans = 0

        for i in piles:
            ans += (i + k - 1) // k

        return ans