# questionLink: https://leetcode.com/problems/custom-sort-string/description
# difficulty:   Easy
# toolInvolved: HashMap, Frequency Counting, String Manipulation


class Solution:
    def customSortString(self, order: str, s: str) -> str:
        res = {}
        for i in range(0,26):
            res[chr(i+97)] = 0
        ans = ""
        for c in s:
            res[c] += 1
        for c in order:
            if res[c] > 0:
                ans = ans + c*res[c]
        for c in s:
            if c not in order:
                ans = ans + c
        return ans