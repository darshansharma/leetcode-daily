#   Question Link: https://leetcode.com/problems/bitwise-and-of-numbers-range/description
#      Difficulty: Medium
#     Date Solved: 22-02-2024

class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        shift = 0
        while left < right:
            left = left >> 1
            right = right >> 1
            shift += 1
        return left << shift