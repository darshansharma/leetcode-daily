// Question: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/
// Difficulty: Easy

/**
 * @param {string[]} words
 * @return {string}
 */

const isPalindromic = (str) => {
    if(str.length === 0) return true;
    if(str.length === 1) return true;
    let j=str.length-1;
    let isPalindrome = true;
    for(let i=0;i<str.length; i++){
        if(str[i] !== str[j]){
            isPalindrome = false;
            break;
        }
        if(j<=i) break;
        j--;
    }
    return isPalindrome;
}

var firstPalindrome = function(words) {
    let str = "";
    for(let i=0; i<words.length; i++){
        if(isPalindromic(words[i])){
            str = words[i];
            break;
        }
    }
    return str;
};