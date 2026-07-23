class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min=float('inf')
        mp=0

        for p in  prices:
            if p<min:
                min=p
            else:
                mp=max(mp,p-min)
        return mp