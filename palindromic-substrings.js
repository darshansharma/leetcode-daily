// Question Link: https://leetcode.com/problems/palindromic-substrings/description
// Difficulty: Hard

/**
 * @param {string} s
 * @return {number}
 */
var countSubstrings = function(s) {
    const n = s.length;
    let count = 0;

    // Helper function to check if a substring is a palindrome
    const isPalindrome = (start, end) => {
        while (start < end) {
            if (s[start++] !== s[end--]) {
                return false;
            }
        }
        return true;
    };

    // Loop through each possible substring and count palindromic substrings
    for (let i = 0; i < n; i++) {
        for (let j = i; j < n; j++) {
            if (isPalindrome(i, j)) {
                count++;
            }
        }
    }

    return count;
};