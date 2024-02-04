    // Question link - https://leetcode.com/problems/implement-queue-using-stacks/description/
    // Difficulty - Hard
    // Date Attempted - 04 Feb 2024

/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t) {
     if (t.length > s.length) return '';
    
    const neededChars = {};
    
    for (let char of t) {
        neededChars[char] = (neededChars[char] || 0) + 1;
    }
    
    let left = 0;
    let right = 0;
    let neededLength = Object.keys(neededChars).length;
    let substring = '';
    
    while (right < s.length) {
        const rightChar = s[right];
        neededChars[rightChar]--;
        if (neededChars[rightChar] === 0) neededLength--;
        
        while (neededLength === 0) {
            if (!substring || substring.length > right - left + 1) {
                substring = s.slice(left, right + 1);
            }
            
            const leftChar = s[left];
            // If the leftChar in charMap is at exactly 0 before being 
            // incremented, we now need more leftChars so that its count
            // in charMap goes down to exactly 0
            if (neededChars[leftChar] === 0) {
                neededLength++;
            }
            neededChars[leftChar]++;
            left++;
               
        }
        
        right++;
    }
    
    return substring;
};


I will implement it again - 

The use of left and right pointers to solve the minimum window substring problem is a classic example of the sliding window technique, which is particularly effective for problems involving contiguous sequences or substrings within an array or string. Here's a step-by-step explanation of how this technique works for our problem:

Problem Statement Recap:
Given two strings s and t, find the minimum window in s which will contain all the characters in t. If there is no such window in s that covers all characters in t, return the empty string.

Using Left and Right Pointers:
Initialize Pointers: Both left and right pointers start at the beginning of s. The right pointer is used to expand the window, and the left pointer is used to contract it.

Expand the Window: Move the right pointer to the right (increment right), adding characters to the current window until it contains all the characters of t.

Character Count: Keep track of how many characters from t are currently in the window using a map or array to count the occurrences of each character. You also need a counter to know when the window is valid (i.e., contains all characters from t).

Check for Valid Window: Once all characters from t are in the window, you have a potential solution, but it may not be the minimum window yet. At this point, the window is "valid."

Contract the Window: Start moving the left pointer to the right (increment left), removing characters from the start of the window to make it smaller. Contract the window until it no longer contains all characters from t. Each time you remove a character that is required by t, update your character counts and the validity of the window.

Update Minimum: If the current window is valid and smaller than the previously recorded minimum window, update the minimum window size and start position.

Repeat: Continue expanding and contracting the window by moving the right and left pointers until the right pointer reaches the end of s.

Example:
Let's say s = "ADOBECODEBANC" and t = "ABC".

Initially, both left and right are at 0. The window is empty.
Expand the window by moving right until the window contains A, B, and C. After expansion, the window might be ADOBEC. This window is valid but not necessarily minimum.
Start contracting the window by moving left to find a smaller window with all t characters. After contracting, the window might become DOBEC. This window is still valid.
Keep contracting until the window is no longer valid, say OBEC. Now, A from t is missing.
Expand the window again until it becomes valid, and then attempt to contract again to find a smaller valid window.
The process repeats until the right pointer has scanned all of s. The smallest valid window during this process is BANC.
Visualization:
css
Copy code
ADOBECODEBANC
[-------]        <- Initial expansion to make the window valid
 [-]              <- Contraction to remove unnecessary characters
       [---]      <- Another expansion to find the next valid window
         [---]    <- Contraction to find the minimum window
Using the left and right pointers in this way allows you to efficiently find the smallest substring of s that contains all the characters in t, satisfying the problem's 
