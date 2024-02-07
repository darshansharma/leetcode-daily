// Question link - https://leetcode.com/problems/sort-characters-by-frequency/description
// Difficulty - Easy
// Date Attempted - 07 Feb 2024

/**
 * @param {string} s
 * @return {string}
 */
var frequencySort = function(s) {
    s = s.split('').sort().reverse().join('');
    let freq = {};
    for(let i=0;i<s.length; i++){
        freq[s[i]] = (freq[s[i]] || 0) + 1;
    }
    return s.split("").sort((a,b)=>freq[b]-freq[a]).join("");
};