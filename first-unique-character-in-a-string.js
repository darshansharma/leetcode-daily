// Question link - https://leetcode.com/problems/first-unique-character-in-a-string/description/
// Difficulty - Easy
// Date Attempted - 05 Jan 2024


/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function(s) {
    let uniqueIndex = -1;
    let map = {};
    for(ch of s) {
       map[ch] = (map[ch] || 0) + 1;
    }
    // console.log(map);
    const keys = Object.keys(map);
    for(let i=0; i<keys.length; i++) {
        const key = keys[i];
        if(map[key] === 1) {
            uniqueIndex = s.indexOf(key);
            break;
        }
    }
    return uniqueIndex;
};

// Try to solve using O(1) Space Complexity