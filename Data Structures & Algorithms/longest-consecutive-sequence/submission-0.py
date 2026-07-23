class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        num_set= set(nums)
        longest=0

        for n in num_set:
            if n-1 not in num_set:
                curr=n
                leng=1

                while curr+1 in num_set:
                    curr+=1
                    leng+=1

                longest= max(longest,leng)
        return longest