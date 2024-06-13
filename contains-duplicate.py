# questionLink - https://leetcode.com/problems/contains-duplicate/description/
# questionDifficulty - Easy

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        freq = {}
        for i in range(len(nums)):
            if nums[i] in freq:
                freq[nums[i]] += 1
                return True
            else:
                freq[nums[i]] = 1
        return False