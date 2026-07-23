class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        arr = set(nums)
        return len(nums) != len(arr)
        