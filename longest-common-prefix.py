# Question Link - https://leetcode.com/problems/longest-common-prefix/
#Difficulty - Medium

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        commonPrefix = ""
        for i in range(len(strs[0])):
            for word in strs:
                if i >= len(word) or word[i] != strs[0][i]:
                    return commonPrefix
            commonPrefix += strs[0][i]

        return commonPrefix