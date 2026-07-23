import math

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
      
        
      
        def can_eat_all(k):
            hours = 0
            for pile in piles:
                hours += math.ceil(pile / k)
            return hours <= h

        left, right = 1, max(piles)
        result = right

        while left <= right:
            mid = (left + right) // 2
            if can_eat_all(mid):
                result = mid       
                right = mid - 1
            else:
                left = mid + 1     
                

        return result
