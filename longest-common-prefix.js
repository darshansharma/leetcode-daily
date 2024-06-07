// Question link - https://leetcode.com/problems/longest-common-prefix/
// difficulty - Medium

/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    
    let common = "";
    let smIndex=0;
    for(let i=0; i<strs[smIndex].length; i++) {
        for(let j=0; j<strs.length; j++) {
                if (strs[smIndex][i] !== strs[j][i]) {
                    return common;
                }
        }
        common += strs[smIndex][i];
    }
    
    return common;
    
};