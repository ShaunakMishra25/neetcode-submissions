class Solution:
    def search(self, nums: List[int], target: int) -> int:
        return self.bs(nums,target,0,len(nums)-1)

    def bs(self,nums,target,l,h):
        if l>h:
            return -1

        mid = (l+h)//2

        if nums[mid]==target:
            return mid
        elif nums[mid]>target:
            return self.bs(nums,target,l,mid-1)
        else:
            return self.bs(nums,target,mid+1,h)
